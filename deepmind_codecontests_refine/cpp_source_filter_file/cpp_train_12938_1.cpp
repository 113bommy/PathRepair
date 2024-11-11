#include <bits/stdc++.h>
const long long N = 1010;
const long long M = N * N;
long long n, m;
struct Edge {
  long long v, w, nxt;
  Edge() : v(0), w(0), nxt(0) {}
  Edge(long long _v, long long _w, long long _nxt) : v(_v), w(_w), nxt(_nxt) {}
} e[M];
long long head[N], edge_cnt = 1;
long long sum[N];
void AddEdge(long long u, long long v, long long w) {
  e[++edge_cnt] = Edge(v, w, head[u]);
  head[u] = edge_cnt;
}
long long idx[20][M];
const long long INF = 1e16;
long long cur[N], dep[N];
bool Bfs(long long s, long long t) {
  memcpy(cur, head, sizeof(cur));
  memset(dep, 0, sizeof(dep));
  std::queue<long long> q;
  q.push(s), dep[s] = 1;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = e[i].nxt) {
      long long v = e[i].v, w = e[i].w;
      if (!w || dep[v]) continue;
      q.push(v), dep[v] = dep[u] + 1;
    }
  }
  return dep[t] > 0;
}
long long Dfs(long long u, long long val, long long t) {
  if (u == t) return val;
  long long res = 0;
  for (long long& i = cur[u]; i; i = e[i].nxt) {
    long long v = e[i].v, w = e[i].w;
    if (!w || dep[v] != dep[u] + 1) continue;
    long long now = Dfs(v, std::min(val, w), t);
    e[i].w -= now, e[i ^ 1].w += now;
    val -= now, res += now;
  }
  if (res == 0) dep[u] = 0;
  return res;
}
long long Dinic(long long s, long long t) {
  long long res = 0;
  while (Bfs(s, t)) {
    res += Dfs(s, INF, t);
  }
  return res;
}
bool vis[M];
void Dfs(long long u) {
  vis[u] = true;
  for (long long i = head[u]; i; i = e[i].nxt) {
    long long v = e[i].v, w = e[i].w;
    if (w && !vis[v]) Dfs(v);
  }
}
signed main() {
  scanf("%lld%lld", &n, &m);
  long long cnt = 0;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) idx[i][j] = ++cnt;
  long long s = cnt + 1, t = s + 1;
  for (long long i = 1, u, v, w; i <= m; ++i) {
    scanf("%lld%lld%lld", &u, &v, &w);
    sum[u] += w, sum[v] -= w;
    for (long long j = 0; j < n; ++j)
      AddEdge(idx[v][j], idx[u][j + 1], INF),
          AddEdge(idx[u][j + 1], idx[v][j], 0);
  }
  for (long long i = 1; i <= n; ++i) {
    AddEdge(s, idx[i][0], INF), AddEdge(idx[i][0], s, 0);
    AddEdge(idx[i][n], t, INF), AddEdge(t, idx[i][n], 0);
    for (long long j = 0; j < n; ++j)
      AddEdge(idx[i][j], idx[i][j + 1], sum[i] * j),
          AddEdge(idx[i][j + 1], idx[i][j], 0);
  }
  Dinic(s, t);
  Dfs(s);
  for (long long i = 1; i <= n; ++i) {
    long long ans = 0;
    for (long long j = 0; j <= n; ++j)
      if (vis[idx[i][j]]) ans = j;
    printf("%lld ", ans);
  }
  return 0;
}
