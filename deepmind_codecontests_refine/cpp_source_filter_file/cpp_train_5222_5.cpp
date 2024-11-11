#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
struct edge {
  long long next, to, fl;
} e[1000010 << 1];
long long head[1000010], cnt;
long long depth[1000010];
queue<long long> Q;
long long ans, dcnt;
long long n, h, m;
long long s, t;
inline void add_edge(long long from, long long to, long long fl) {
  e[++cnt].to = to;
  e[cnt].next = head[from];
  e[cnt].fl = fl;
  head[from] = cnt;
}
inline long long bfs() {
  memset(depth, 0, sizeof(depth));
  while (!Q.empty()) Q.pop();
  Q.push(s);
  depth[s] = 1;
  while (!Q.empty()) {
    long long x = Q.front();
    Q.pop();
    for (register long long i = head[x]; i; i = e[i].next) {
      if (e[i].fl && !depth[e[i].to])
        depth[e[i].to] = depth[x] + 1, Q.push(e[i].to);
    }
  }
  return depth[t];
}
long long dfs(long long now, long long flow) {
  if (now == t) return flow;
  long long ret = 0;
  for (register long long i = head[now]; i; i = e[i].next) {
    if (ret == flow) return ret;
    if (depth[e[i].to] == depth[now] + 1 && e[i].fl) {
      long long fl = dfs(e[i].to, min(e[i].fl, flow - ret));
      if (fl) {
        ret += fl;
        e[i].fl -= fl;
        e[i ^ 1].fl += fl;
      }
    }
  }
  if (!ret) depth[now] = 0;
  return ret;
}
inline long long Dinic() {
  long long sum = 0;
  while (bfs()) {
    while (long long x = dfs(s, 0x7fffffff / 2)) sum += x;
  }
  return sum;
}
inline long long idx(long long x, long long y) { return (x - 1) * (h + 2) + y; }
int main() {
  n = read(), h = read(), m = read();
  t = 1000010 - 10;
  for (register long long i = 1; i <= n; i++) ans += h * h;
  for (register long long i = 1; i <= n; i++) {
    for (register long long j = 1; j <= h + 1; j++)
      add_edge(idx(i, j), idx(i, j + 1), h * h - (j - 1) * (j - 1)),
          add_edge(idx(i, j + 1), idx(i, j), 0);
  }
  dcnt = n * (h + 2);
  for (register long long i = 1; i <= n; i++) {
    add_edge(s, idx(i, 1), 0x7fffffff / 2);
    add_edge(idx(i, 1), s, 0);
    add_edge(idx(i, h + 2), t, 0x7fffffff / 2);
    add_edge(t, idx(i, h + 2), 0);
  }
  for (register long long i = 1; i <= m; i++) {
    long long l = read(), r = read(), H = read(), val = read();
    ++dcnt;
    add_edge(dcnt, t, val);
    add_edge(t, dcnt, 0);
    for (register long long j = l; j <= r; j++) {
      add_edge(idx(j, H + 2), dcnt, 0x7fffffff / 2);
      add_edge(dcnt, idx(j, H + 2), 0);
    }
  }
  printf("%I64d\n", ans - Dinic());
  return 0;
}
