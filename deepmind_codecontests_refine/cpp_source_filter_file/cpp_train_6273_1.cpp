#include <bits/stdc++.h>
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
const int N = 1e4 + 10, inf = 2147483647;
struct Network {
  static const int N = 1e4 + 10, M = 2e4 + 10, inf = 2147483647;
  int n, s, t, flow, tot = 1, fir[N], nex[M], got[M], tak[M];
  inline void AddEdge(int u, int v, int w) {
    nex[++tot] = fir[u], fir[u] = tot, got[tot] = v, tak[tot] = w;
    nex[++tot] = fir[v], fir[v] = tot, got[tot] = u, tak[tot] = w;
  }
  int dep[N], cur[N];
  inline int bfs() {
    for (int i = 1; i <= n; ++i) dep[i] = 0, cur[i] = fir[i];
    std::queue<int> que;
    que.push(s), dep[s] = 1;
    for (; !que.empty(); que.pop()) {
      int u = que.front();
      for (int i = fir[u]; i; i = nex[i])
        if (!dep[got[i]] && tak[i]) dep[got[i]] = dep[u] + 1, que.push(got[i]);
    }
    return dep[t];
  }
  inline int dfs(int u, int flow) {
    if (u == t) return flow;
    int rest = flow;
    for (int i = cur[u]; i; i = nex[i]) {
      cur[u] = i;
      if (dep[got[i]] != dep[u] + 1 || !tak[i]) continue;
      int tmp = dfs(got[i], std::min(rest, tak[i]));
      tak[i] -= tmp, tak[i ^ 1] += tmp, rest -= tmp;
      if (!tmp) dep[got[i]] = 0;
    }
    return flow - rest;
  }
  inline void dinic() {
    while (bfs()) flow += dfs(s, inf);
  }
  int pre[N];
  inline int BFS() {
    for (int i = 1; i <= n; ++i) pre[i] = 0;
    std::queue<int> que;
    que.push(s);
    for (; !que.empty(); que.pop()) {
      int u = que.front();
      for (int i = fir[u]; i; i = nex[i])
        if (!pre[got[i]] && tak[i]) {
          pre[got[i]] = i, que.push(got[i]);
          if (got[i] == t) return 1;
        }
    }
    return 0;
  }
  inline void Augment() {
    while (BFS()) {
      int f = inf;
      for (int i = t; i != s; i = got[pre[i] ^ 1]) f = std::min(f, tak[pre[i]]);
      for (int i = t; i != s; i = got[pre[i] ^ 1])
        tak[pre[i]] -= f, tak[pre[i ^ 1]] += f;
      flow += f;
    }
  }
} G;
int u[N], v[N], w[N], a[N], s[N], x[N];
inline void dfs(int i, int k, int s, Network G) {
  if (i > k) return a[s] = G.flow, void();
  dfs(i + 1, k, s | 1 << (i - 1), G);
  G.AddEdge(u[i], v[i], 25), G.Augment();
  dfs(i + 1, k, s, G);
}
inline int lowbit(int x) { return x & -x; }
int main() {
  int n = read(), m = read(), k = read(), q = read();
  for (int i = 1; i <= k; ++i) u[i] = read(), v[i] = read(), w[i] = read();
  for (int i = k + 1, u, v; i <= m; ++i)
    u = read(), v = read(), G.AddEdge(u, v, read());
  G.n = n, G.s = 1, G.t = n;
  G.dinic(), dfs(1, k, 0, G);
  for (int i = 0; i < k; ++i) x[1 << i] = i + 1;
  for (int T = 1; T <= q; ++T) {
    int res = inf;
    for (int i = 1; i <= k; ++i) w[i] = read();
    for (int i = 1; i < (1 << k); ++i)
      s[i] = s[i - lowbit(i)] + w[x[lowbit(i)]];
    for (int i = 0; i < (1 << k); ++i) res = std::min(res, s[i] + a[i]);
    printf("%d\n", res);
  }
  return 0;
}
