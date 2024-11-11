#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
const int maxn = 3001;
int dp[maxn][maxn][3], mf[maxn][3][3], f[maxn][3][3], mirror[maxn][3];
int sz[maxn], lst[maxn], fa[maxn];
vector<int> g[maxn];
int dfs_cnt;
int dfn[maxn], low[maxn];
int n, m, x, y;
void gao_circle(int root, int u) {
  int now = u;
  int cnt = 0;
  while (1) {
    lst[++cnt] = now;
    if (now == root) break;
    now = fa[now];
  }
  for (int i = 0; i <= sz[root]; i++)
    for (int a = 0; a <= 2; a++)
      for (int b = 0; b <= 2; b++) f[i][a][b] = -30000;
  for (int i = 0; i <= sz[root]; i++)
    for (int a = 0; a <= 2; a++) f[i][a][a] = dp[root][i][a];
  for (int t = 1; t <= cnt - 1; t++) {
    int v = lst[t];
    for (int i = 0; i <= sz[root]; i++)
      for (int a = 0; a <= 2; a++)
        for (int b = 0; b <= 2; b++) mf[i][a][b] = f[i][a][b];
    for (int i = 0; i <= sz[root] + sz[v]; i++)
      for (int a = 0; a <= 2; a++)
        for (int b = 0; b <= 2; b++) f[i][a][b] = -30000;
    for (int i = 0; i <= sz[root]; i++)
      for (int j = 0; j <= sz[v]; j++)
        for (int a = 0; a <= 2; a++) {
          f[i + j][a][0] =
              max(f[i + j][a][0],
                  dp[v][j][0] + *max_element(mf[i][a], mf[i][a] + 3));
          f[i + j][a][1] =
              max(f[i + j][a][1], dp[v][j][1] + max(mf[i][a][0], mf[i][a][1]));
          f[i + j][a][2] =
              max(f[i + j][a][2], dp[v][j][2] + max(mf[i][a][0], mf[i][a][2]));
        }
    sz[root] += sz[v];
  }
  for (int i = 0; i <= sz[root]; i++) {
    dp[root][i][0] = max(dp[root][i][0], *max_element(f[i][0], f[i][0] + 3));
    dp[root][i][1] = max(dp[root][i][1], max(f[i][1][0], f[i][1][1]));
    dp[root][i][2] = max(dp[root][i][2], max(f[i][2][0], f[i][2][2]));
  }
}
void tarjan(int u) {
  dfn[u] = low[u] = ++dfs_cnt;
  dp[u][0][0] = 0;
  dp[u][1][1] = 0;
  dp[u][0][2] = 1;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    if (!dfn[v]) {
      fa[v] = u;
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else
      low[u] = min(low[u], dfn[v]);
    if (dfn[u] < low[v]) {
      for (int tsz = 0; tsz <= sz[u] + sz[v]; tsz++)
        for (int p = 0; p <= 2; p++) mirror[tsz][p] = -30000;
      for (int i = 0; i <= sz[u]; i++)
        for (int j = 0; j <= sz[v]; j++) {
          mirror[i + j][0] = max(
              mirror[i + j][0],
              dp[u][i][0] + max(max(dp[v][j][0], dp[v][j][1]), dp[v][j][2]));
          mirror[i + j][1] = max(mirror[i + j][1],
                                 dp[u][i][1] + max(dp[v][j][0], dp[v][j][1]));
          mirror[i + j][2] = max(mirror[i + j][2],
                                 dp[u][i][2] + max(dp[v][j][0], dp[v][j][2]));
        }
      sz[u] += sz[v];
      for (int i = 0; i <= sz[u]; i++)
        for (int p = 0; p <= 2; p++)
          dp[u][i][p] = max(dp[u][i][p], mirror[i][p]);
    }
  }
  for (auto v : g[u]) {
    if (fa[v] != u && dfn[v] > dfn[u]) gao_circle(u, v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 0; k <= 2; k++) dp[i][j][k] = -30000;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  tarjan(1);
  for (int a = 0; a <= n; a++)
    printf("%d%c", max(max(dp[1][a][0], dp[1][a][1]), dp[1][a][2]),
           " \n"[a == n]);
}
