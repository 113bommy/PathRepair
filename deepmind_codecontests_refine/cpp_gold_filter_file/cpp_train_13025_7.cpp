#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void chkmax(T &a, T b) {
  a = max(a, b);
}
inline long long fread(void) {
  long long ret = 0, op = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) ret = (ret << 1) + (ret << 3) - '0' + ch;
  return ret * op;
}
const long long MAXN = 2e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const long long MAXM = +10;
long long head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], ind = 1;
inline void add_edge(long long u, long long v, long long w) {
  nxt[++ind] = head[u];
  head[u] = ind;
  to[ind] = v;
  val[ind] = w;
}
inline void add(long long u, long long v, long long w) {
  add_edge(u, v, w);
  add_edge(v, u, 0);
}
long long n, m, a[MAXN], tot, S, T;
inline void init(void) {
  n = fread(), m = fread();
  S = n + m + 1, T = n + m + 2;
  long long u, v, w;
  for (long long i = 1; i <= n; ++i) a[i] = fread(), add(i + m, T, a[i]);
  for (long long i = 1; i <= m; ++i) {
    u = fread(), v = fread(), w = fread();
    add(S, i, w);
    add(i, u + m, INF);
    add(i, v + m, INF);
    tot += w;
  }
}
long long d[MAXN];
inline bool BFS(void) {
  queue<long long> Q;
  while (!Q.empty()) Q.pop();
  Q.push(S);
  memset(d, 0, sizeof(d));
  d[S] = 1;
  while (!Q.empty()) {
    long long u = Q.front();
    Q.pop();
    for (long long i = head[u]; i; i = nxt[i]) {
      long long v = to[i];
      if (!val[i] || d[v]) continue;
      d[v] = d[u] + 1;
      Q.push(v);
      if (v == T) return true;
    }
  }
  return false;
}
long long dinic(long long u, long long flow) {
  if (u == T) return flow;
  long long rest = flow;
  for (long long i = head[u]; i && rest; i = nxt[i]) {
    long long v = to[i];
    if (!val[i] || d[v] != d[u] + 1) continue;
    long long now = dinic(v, min(rest, val[i]));
    if (!now) d[v] = 0;
    val[i] -= now;
    val[i ^ 1] += now;
    rest -= now;
  }
  return flow - rest;
}
inline long long Dinic(void) {
  long long ret = 0;
  while (BFS()) ret += dinic(S, INF);
  return ret;
}
inline void work(void) { printf("%lld", tot - Dinic()); }
int main() {
  init();
  work();
  return 0;
}
