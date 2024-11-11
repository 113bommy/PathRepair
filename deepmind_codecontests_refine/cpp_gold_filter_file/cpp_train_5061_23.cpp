#include <bits/stdc++.h>
using namespace std;
bool G[605][605];
int n, m, x, y, z, M, K, ans, c[605], f[605][605], use[605], match[605];
inline bool dfs(int u) {
  for (int v = 1; v <= n; v++) {
    if (!G[u][v]) continue;
    if (use[v]) continue;
    use[v] = 1;
    if (!match[v] || dfs(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}
inline bool check(int x) {
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= n; j++) {
      if (f[c[i]][j] <= x)
        G[i][j] = 1;
      else
        G[i][j] = 0;
    }
  ans = 0;
  memset(match, 0, sizeof(match));
  for (int i = 1; i <= M; i++) {
    memset(use, 0, sizeof(use));
    if (dfs(i)) ans++;
  }
  return ans >= K;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &M, &K);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i][j] = 1e9;
  for (int i = 1; i <= M; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    f[x][y] = f[y][x] = min(f[x][y], z);
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (int i = 1; i <= n; i++) f[i][i] = 0;
  int l = 0;
  int r = 1731311;
  if (!check(r)) return puts("-1"), 0;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l))
    printf("%d\n", l);
  else
    printf("%d\n", r);
  return 0;
}
