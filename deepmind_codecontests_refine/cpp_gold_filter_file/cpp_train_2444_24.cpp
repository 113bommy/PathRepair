#include <bits/stdc++.h>
using namespace std;
static char a[55][55];
bool vis[55][55];
bool dfs(int i, int j, int px, int py, int n, int m) {
  bool flag = false;
  if (i > n || j > m) return false;
  if (i == 0 || j == 0) return false;
  vis[i][j] = 1;
  int xi[] = {1, 0, -1, 0};
  int yi[] = {0, -1, 0, 1};
  for (int k = 0; k < 4; k++) {
    int x = xi[k] + i;
    int y = yi[k] + j;
    if (x == px && y == py) continue;
    if (a[x][y] == a[i][j]) {
      if (vis[x][y]) {
        return true;
      } else
        flag = dfs(x, y, i, j, n, m);
      if (flag) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  char ch;
  scanf("%d%d", &n, &m);
  memset(a, '.', sizeof(a));
  for (int i = 1; i <= n; i++) {
    scanf("%c", &ch);
    for (int j = 1; j <= m; j++) {
      scanf("%c", &a[i][j]);
    }
  }
  memset(vis, 0, sizeof(vis));
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j] == true)
        continue;
      else
        flag = dfs(i, j, 0, 0, n, m);
      if (flag) break;
    }
    if (flag) break;
  }
  if (flag)
    printf("Yes");
  else
    printf("No");
}
