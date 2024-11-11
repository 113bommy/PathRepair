#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int u, v, n, ans[maxn], dep[maxn], d[maxn], fa[maxn], ed, hed[maxn], h[maxn];
int *dp[maxn], tmp[maxn * 8], *now;
struct edge {
  int to, nex;
  edge(int _ = 0, int __ = 0) : to(_), nex(__) {}
} e[maxn << 1];
inline void add_edge(int u, int v) {
  e[++ed] = edge(v, hed[u]);
  hed[u] = ed;
}
void dfs(int u) {
  d[u] = dep[u];
  for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
    if (v != fa[u])
      fa[v] = u, dep[v] = dep[u] + 1, dfs(v),
      h[u] = (d[h[u]] < d[v]) ? v : h[u], d[u] = max(d[u], d[v]);
}
void init(int u) {
  dp[u] = now;
  now += d[u] - dep[u] + 1;
}
void DP(int u) {
  if (h[u]) dp[h[u]] = dp[u] + 1, DP(h[u]), ans[u] = ans[h[u]] + 1;
  dp[u][0] = 1;
  for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
    if (v != h[u] && v != fa[u]) {
      init(v);
      DP(v);
      for (int j = (0); j <= (d[v] - dep[v] + 1); ++j) {
        dp[u][j + 1] += dp[v][j];
        if (dp[u][j + 1] > dp[u][ans[u]] ||
            dp[u][j + 1] == dp[u][ans[u]] && j + 1 < ans[u])
          ans[u] = j + 1;
      }
    }
  if (dp[u][ans[u]] == 1) ans[u] = 0;
}
void DSYAKIOI() { puts("DSYTXDY"); }
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); ++i)
    scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
  dfs(1);
  now = tmp;
  init(1);
  DP(1);
  for (int i = (1); i <= (n); ++i) printf("%d\n", ans[i]);
  return 0;
}
