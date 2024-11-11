#include <bits/stdc++.h>
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char g[55][55];
int vis[55][55];
int dfs(int a, int b) {
  if (g[a][b] != '#' || vis[a][b]) return 0;
  vis[a][b] = 1;
  for (int i = 0; i < 4; ++i) dfs(a + dx[i], b + dy[i]);
  return 1;
}
int main() {
  int pant = 0, regions = 0;
  scanf("%d%d", &n, &m);
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] != '#') continue;
      memset(vis, 0, sizeof(vis));
      ++pant;
      g[i][j] = '.';
      regions = 0;
      for (int k = 0; k < 4; ++k) regions += dfs(i + dx[k], j + dy[k]);
      if (regions > 1) {
        puts("1");
        return 0;
      }
      g[i][j] = '#';
    }
  printf("%d\n", pant > 2 ? 2 : -1);
  return 0;
}
