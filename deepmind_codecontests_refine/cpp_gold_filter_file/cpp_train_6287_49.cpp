#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1605;
int a[MAXN][MAXN];
int n, m;
bool u[MAXN][MAXN];
int partn = 0;
int part[MAXN][MAXN];
int s[MAXN][MAXN];
int d[MAXN * MAXN];
int f[MAXN][MAXN];
int T = 25;
void dfs(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m || u[x][y] || a[x][y] == 0) return;
  u[x][y] = true;
  part[x][y] = partn;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}
void dfs2(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m || u[x][y] || a[x][y] == 0 ||
      f[x][y] > T)
    return;
  u[x][y] = true;
  dfs2(x - 1, y);
  dfs2(x + 1, y);
  dfs2(x, y - 1);
  dfs2(x, y + 1);
  dfs2(x - 1, y - 1);
  dfs2(x + 1, y + 1);
  dfs2(x + 1, y - 1);
  dfs2(x - 1, y + 1);
}
int Gets(int x, int y) {
  if (x < 0) x = 0;
  if (y < 0) y = 0;
  if (x > n) x = n;
  if (y > m) y = m;
  return s[x][y];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!u[i][j] && a[i][j] == 1) {
        partn++;
        dfs(i, j);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = Gets(i + 4, j + 4) + Gets(i - 5, j - 5) - Gets(i + 4, j - 5) -
                Gets(i - 5, j + 4);
  memset(u, 0, sizeof(u));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!u[i][j] && f[i][j] <= T && a[i][j] == 1) {
        d[part[i][j]]++;
        dfs2(i, j);
      }
  printf("%d\n", partn);
  sort(d + 1, d + partn + 1);
  for (int i = 1; i <= partn; i++) printf("%d ", d[i]);
  printf("\n");
  return 0;
}
