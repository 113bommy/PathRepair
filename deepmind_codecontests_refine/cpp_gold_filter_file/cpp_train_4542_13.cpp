#include <bits/stdc++.h>
using namespace std;
int n, m, S, x, y, z, an, tot, f[55][55][55][55], d[55][55], du[55], sz[55],
    g[55];
bool vs[55][55][55][55];
vector<int> V[55];
void ins(int x, int y, int z) {
  V[x].push_back(y);
  d[x][y] = d[y][x] = z;
  du[x]++;
}
void dfs(int x, int fa) {
  for (int y : V[x])
    if (y != fa) dfs(y, x), sz[x] += sz[y];
}
int dp(int u, int v, int su, int sv) {
  if (!sv && !su) return 0;
  if (vs[u][v][su][sv]) return f[u][v][su][sv];
  vs[u][v][su][sv] = 1;
  if (du[v] == 1) {
    if (!su) return f[u][v][su][sv] = 0;
    return f[u][v][su][sv] = dp(v, u, 0, su) + d[u][v];
  }
  int i, j, y, g[55];
  g[0] = 1e9;
  for (int i = 1; i <= sv; i++) g[i] = -1e9;
  for (int y : V[v])
    if (y != u)
      for (i = sv; i; i--)
        for (j = 1; j <= i; j++)
          g[i] = max(g[i], min(g[i - j], dp(v, y, sv + su - j, j) + d[v][y]));
  return f[u][v][su][sv] = g[sv];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++)
    scanf("%d%d%d", &x, &y, &z), ins(x, y, z), ins(y, x, z);
  scanf("%d", &S);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &x), sz[x]++;
  dfs(S, 0);
  an = 1e9;
  for (int y : V[S]) an = min(an, dp(S, y, m - sz[y], sz[y]) + d[S][y]);
  printf("%d", an);
}
