#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long INF = 1e18;
long long n, m, s, t, Begin[maxn], Next[maxn], To[maxn], e = 1, W[maxn];
long long dis[maxn], a[210][210], id1[210][210], id2[210][210], ans;
char S[210];
inline void add(long long u, long long v, long long w) {
  To[++e] = v;
  Next[e] = Begin[u];
  Begin[u] = e;
  W[e] = w;
  swap(u, v);
  w = 0;
  To[++e] = v;
  Next[e] = Begin[u];
  Begin[u] = e;
  W[e] = w;
}
inline bool BFS() {
  queue<long long> Q;
  Q.push(s);
  for (long long i = (1), _end_ = (t); i <= _end_; ++i) dis[i] = INF;
  dis[s] = 0;
  while (!Q.empty()) {
    long long u = Q.front();
    Q.pop();
    for (long long i = Begin[u]; i; i = Next[i]) {
      long long v = To[i];
      if (!W[i]) continue;
      if (dis[v] == INF) {
        dis[v] = dis[u] + 1;
        Q.push(v);
      }
    }
  }
  return dis[t] != INF;
}
inline long long DFS(long long u, long long flow) {
  if (u == t || !flow) return flow;
  long long f = 0;
  for (long long i = Begin[u]; i; i = Next[i]) {
    long long v = To[i];
    if (dis[v] != dis[u] + 1 || !W[i]) continue;
    long long x = DFS(v, min(flow, W[i]));
    if (x) {
      W[i] -= x;
      W[i ^ 1] += x;
      flow -= x;
      f += x;
    }
  }
  if (!f) dis[u] = INF;
  return f;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = (1), _end_ = (n); i <= _end_; ++i) {
    scanf("%s", S + 1);
    for (long long j = (1), _end_ = (m); j <= _end_; ++j) {
      a[i][j] = (S[j] == '#');
      ans += a[i][j];
    }
  }
  long long tot = 0;
  for (long long i = (1), _end_ = (n); i <= _end_; ++i)
    for (long long j = (1), _end_ = (m - 1); j <= _end_; ++j) {
      if (!a[i][j] || !a[i][j + 1]) continue;
      id1[i][j] = ++tot;
    }
  for (long long i = (1), _end_ = (n - 1); i <= _end_; ++i)
    for (long long j = (1), _end_ = (m); j <= _end_; ++j) {
      if (!a[i][j] || !a[i + 1][j]) continue;
      id2[i][j] = ++tot;
    }
  s = ++tot;
  t = ++tot;
  for (long long i = (1), _end_ = (n); i <= _end_; ++i)
    for (long long j = (1), _end_ = (m - 1); j <= _end_; ++j) {
      if (!id1[i][j]) continue;
      add(s, id1[i][j], 1);
      if (id2[i][j]) add(id1[i][j], id2[i][j], 1);
      if (id2[i][j + 1]) add(id1[i][j], id2[i][j + 1], 1);
      if (id2[i - 1][j]) add(id1[i][j], id2[i - 1][j], 1);
      if (id2[i - 1][j + 1]) add(id1[i][j], id2[i - 1][j + 1], 1);
    }
  for (long long i = (1), _end_ = (n - 1); i <= _end_; ++i)
    for (long long j = (1), _end_ = (m); j <= _end_; ++j)
      if (id2[i][j]) add(id2[i][j], t, 1);
  long long flow = 0;
  while (BFS())
    while (long long x = DFS(s, INF)) flow += x;
  printf("%lld\n", ans - (tot - 2 - flow));
  return 0;
}
