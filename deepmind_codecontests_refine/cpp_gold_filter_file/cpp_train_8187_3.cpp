#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const long long N = 1e5 + 5, M = 1e5;
struct edge {
  long long ver, edge, nxt;
} e[N];
long long tot = 1, head[N], deg[N], cur[N];
void add(long long u, long long v, long long w) {
  e[++tot] = {v, w, head[u]};
  head[u] = tot;
  deg[v]++;
}
long long d[N];
queue<long long> q;
bool bfs() {
  memcpy(cur, head, sizeof(head));
  memset(d, 0, sizeof(d));
  q.push(0);
  d[0] = 1;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = e[i].nxt) {
      long long v = e[i].ver, w = e[i].edge;
      if (w && !d[v]) {
        q.push(v);
        d[v] = d[u] + 1;
      }
    }
  }
  return d[M];
}
long long dinic(long long u, long long flow) {
  if (u == M) return flow;
  for (long long &i = cur[u]; i; i = e[i].nxt) {
    long long v = e[i].ver, w = e[i].edge;
    if (w && d[v] == d[u] + 1) {
      long long k = dinic(v, min(flow, w));
      if (k) {
        e[i].edge -= k;
        e[i ^ 1].edge += k;
        return k;
      }
    }
  }
  return 0;
}
long long n1, n2, m, mind = INT_MAX, id[N];
vector<long long> ans[N];
signed main() {
  n1 = read(), n2 = read(), m = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read() + n1;
    add(u, v, 1);
    add(v, u, 0);
    id[i] = tot;
  }
  for (long long i = 1; i <= n1 + n2; i++) mind = min(mind, deg[i]);
  for (long long i = 1; i <= n1; i++) add(0, i, deg[i] - mind), add(i, 0, 0);
  for (long long i = n1 + 1; i <= n1 + n2; i++)
    add(i, M, deg[i] - mind), add(M, i, 0);
  for (long long i = mind; i >= 0; i--) {
    while (bfs())
      while (dinic(0, INT_MAX))
        ;
    for (long long j = 1; j <= m; j++)
      if (!e[id[j]].edge) ans[i].push_back(j);
    for (long long j = head[0]; j; j = e[j].nxt) e[j].edge++;
    for (long long j = head[M]; j; j = e[j].nxt) e[j ^ 1].edge++;
  }
  for (long long i = 0; i <= mind; i++) {
    printf("%lu", ans[i].size());
    for (auto it : ans[i]) printf(" %lld", it);
    puts("");
  }
  return 0;
}
