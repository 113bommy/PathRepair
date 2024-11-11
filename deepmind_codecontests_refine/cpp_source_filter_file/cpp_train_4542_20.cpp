#include <bits/stdc++.h>
const int maxn = 60, inf = 0x3f3f3f3f;
int head[maxn], cnt = 1, deg[maxn];
struct Edge {
  int to, nxt, w;
} e[maxn << 1];
inline void addedge(int a, int b, int c) {
  e[++cnt] = (Edge){b, head[a], c};
  head[a] = cnt;
  e[++cnt] = (Edge){a, head[b], c};
  head[b] = cnt;
  ++deg[a], ++deg[b];
}
int n, m, S, sz[maxn];
int f[maxn << 1][maxn][maxn];
void dfs(int u, int fa = 0) {
  for (int i = head[u], v; i; i = e[i].nxt) {
    v = e[i].to;
    if (v != fa) dfs(v, u), sz[u] += sz[v];
  }
}
int dp(int E, int x, int y) {
  if (!x && !y) return 0;
  int &F = f[E][x][y], u = e[E].to;
  if (~F) return F;
  if (deg[u] == 1) {
    if (y == 0) return 0;
    return F = dp(E ^ 1, y, 0) + e[E].w;
  }
  int g[maxn];
  memset(g, 0, sizeof g), g[0] = 0;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (i ^ E ^ 1) {
      v = e[i].to;
      for (int j = x; j; --j)
        for (int k = j; k; --k)
          g[j] =
              std::max(g[j], std::min(g[j - k], dp(i, k, x + y - k) + e[i].w));
    }
  return F = g[x];
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  std::cin >> n;
  for (int i = 1, a, b, c; i < n; ++i) {
    std::cin >> a >> b >> c;
    addedge(a, b, c);
  }
  std::cin >> S >> m;
  for (int i = 0, x; i < m; ++i) std::cin >> x, ++sz[x];
  dfs(S), memset(f, -1, sizeof f);
  int ans = inf;
  for (int i = head[S], v; i; i = e[i].nxt) {
    v = e[i].to;
    ans = std::min(ans, dp(i, sz[v], m - sz[v]) + e[i].w);
  }
  std::cout << ans << '\n';
  return 0;
}
