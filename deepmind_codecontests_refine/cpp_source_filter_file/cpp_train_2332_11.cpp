#include <bits/stdc++.h>
int n, m;
char map[550][550], vis[550][550];
int xx[100100], yy[100100], top = 0;
char cc[100100];
int dfs(int x, int y) {
  vis[x][y] = 1;
  xx[top] = x, yy[top] = y, cc[top] = 'B';
  top++;
  if (map[x + 1][y] == '.' && !vis[x + 1][y]) dfs(x + 1, y);
  if (map[x][y + 1] == '.' && !vis[x][y + 1]) dfs(x, y + 1);
  if (map[x - 1][y] == '.' && !vis[x - 1][y]) dfs(x - 1, y);
  if (map[x][y - 1] == '.' && !vis[x][y - 1]) dfs(x, y - 1);
  xx[top] = x, yy[top] = y, cc[top] = 'D';
  top++;
  xx[top] = x, yy[top] = y, cc[top] = 'R';
  top++;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  gets(map[0]);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!vis[i][j] && map[i][j] == '.') {
        dfs(i, j);
        top -= 2;
      }
  printf("%d\n", top);
  for (int i = 0; i < top; i++) {
    printf("%c %d %d\n", cc[i], xx[i], yy[i]);
  }
  return 0;
}
