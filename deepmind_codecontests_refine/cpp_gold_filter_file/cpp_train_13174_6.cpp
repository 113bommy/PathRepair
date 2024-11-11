#include <bits/stdc++.h>
using namespace std;
const int maxn = 209;
int f[maxn][maxn], b[maxn], c[maxn], d[maxn], g[maxn][maxn];
vector<int> e[maxn];
int n, K, u, v;
void dfs(int u, int fa) {
  for (int i = (0); i <= int(e[u].size() - 1); i++)
    if (e[u][i] != fa) dfs(e[u][i], u);
  for (int i = (1); i <= int(n); i++) {
    for (int j = (0); j <= int(e[u].size() - 1); j++)
      if (e[u][j] != fa)
        f[u][i] += min(f[e[u][j]][i], f[e[u][j]][b[e[u][j]]] + K);
  }
  b[u] = 1;
  for (int i = (2); i <= int(n); i++)
    if (f[u][i] < f[u][b[u]]) b[u] = i;
}
void dfs2(int u, int fa, int d) {
  c[u] = d;
  for (int i = (0); i <= int(e[u].size() - 1); i++)
    if (e[u][i] != fa)
      dfs2(e[u][i], u,
           (f[e[u][i]][d] < f[e[u][i]][b[e[u][i]]] + K ? d : b[e[u][i]]));
}
int main() {
  scanf("%d%d", &n, &K);
  for (int i = (1); i <= int(n - 1); i++) scanf("%d", &d[i]);
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(n); j++) g[i][j] = (i != j) << 20;
  for (int i = (1); i <= int(n - 1); i++) {
    scanf("%d%d", &u, &v);
    g[u][v] = g[v][u] = 1;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int k = (1); k <= int(n); k++)
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(n); j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(n); j++) f[i][j] = d[g[i][j]];
  dfs(1, 0);
  dfs2(1, 0, b[1]);
  printf("%d\n", f[1][b[1]] + K);
  for (int i = (1); i <= int(n); i++) printf("%d ", c[i]);
  return 0;
}
