#include <bits/stdc++.h>
const int W = 20, N = 300005;
int last[N], f[N][21], deep[N], Next[N << 1], to[N << 1], edge, x, y, n, Q;
long long ww1, ww2, w1[N << 1], w2[N << 1], dis[N << 1], a[N << 1];
long long g[N][21][2][2], ans0[2], ans1[2];
void add(int x, int y, long long ww1, long long ww2) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
  w1[edge] = ww1, w2[edge] = ww2;
}
void dfs(int x, int fa) {
  f[x][0] = fa;
  deep[x] = deep[fa] + 1;
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    dis[u] = std::min(dis[u], dis[x] + w1[i] + w2[i]);
    dfs(u, x);
  }
}
void dfs2(int x, int fa) {
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    dfs2(u, x);
    dis[x] = std::min(dis[x], dis[u] + w1[i] + w2[i]);
  }
}
void init(int x, int fa) {
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    g[u][0][0][0] = std::min(w1[i], dis[x] + dis[u] + w2[i]);
    g[u][0][1][1] = std::min(w2[i], dis[x] + dis[u] + w1[i]);
    g[u][0][0][1] = std::min(w1[i] + dis[x], w2[i] + dis[u]);
    g[u][0][1][0] = std::min(w2[i] + dis[x], w1[i] + dis[u]);
    init(u, x);
  }
}
int LCA(int x, int y) {
  if (deep[x] < deep[y]) std::swap(x, y);
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = W; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void solve(int x, int y, int tg, long long *ans) {
  ans[tg] = 0, ans[1 ^ tg] = dis[x];
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) {
      long long t0 = std::min(ans[0] + g[x][i][0][0], ans[1] + g[x][i][1][0]);
      long long t1 = std::min(ans[0] + g[x][i][0][1], ans[1] + g[x][i][1][1]);
      ans[0] = t0, ans[1] = t1;
      x = f[x][i];
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%lld%lld", &x, &y, &ww1, &ww2);
    add(x, y, ww1, ww2), add(y, x, ww1, ww2);
  }
  for (int i = 1; i <= n; i++) dis[i] = a[i];
  dfs2(1, 0);
  dfs(1, 0);
  init(1, 0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= W; j++) {
      int fa = f[i][j - 1];
      f[i][j] = f[fa][j - 1];
      for (int k1 = 0; k1 <= 1; k1++)
        for (int k2 = 0; k2 <= 1; k2++) {
          long long t = 1e18;
          for (int k = 0; k <= 1; k++)
            t = std::min(t, g[i][j - 1][k1][k] + g[fa][j - 1][k][k2]);
          g[i][j][k1][k2] = t;
        }
    }
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d", &x, &y);
    int tg0 = (x + 1) & 1, tg1 = (y + 1) & 1;
    x = (x + 1) / 2, y = (y + 1) / 2;
    int lca = LCA(x, y);
    memset(ans0, 0, sizeof(ans0));
    memset(ans1, 0, sizeof(ans1));
    solve(x, lca, tg0, ans0);
    solve(y, lca, tg1, ans1);
    printf("%lld\n", std::min(ans0[0] + ans1[0], ans0[1] + ans1[1]));
  }
}
