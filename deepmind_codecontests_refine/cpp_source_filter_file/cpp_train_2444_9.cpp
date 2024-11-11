#include <bits/stdc++.h>
using namespace std;
int vis[55][55] = {false};
bool done = false;
char c[55][55];
void dfs(int x, int y, int px, int py) {
  if (done) return;
  vis[x][y] = 1;
  if (c[x][y] == c[x + 1][y]) {
    if (vis[x + 1][y] == 0)
      dfs(x + 1, y, x, y);
    else if (vis[x + 1][y] == 1 and (px != x + 1 or py != y)) {
      done = true;
      return;
    }
  }
  if (c[x][y] == c[x][y + 1]) {
    if (vis[x][y + 1] == 0)
      dfs(x, y + 1, x, y);
    else if (vis[x][y + 1] == 1 and (px != x or py != y + 1)) {
      done = true;
      return;
    }
  }
  if (c[x][y] == c[x - 1][y]) {
    if (vis[x - 1][y] == 0)
      dfs(x - 1, y, x, y);
    else if (vis[x - 1][y] == 1 and (px != x - 1 or py != y)) {
      done = true;
      return;
    }
  }
  if (c[x][y] == c[x][y - 1]) {
    if (vis[x][y - 1] == 0)
      dfs(x, y - 1, x, y);
    else if (vis[x][y - 1] == 1 and (px != x or py != y - 1)) {
      done = true;
      return;
    }
  }
  vis[x][y] = 2;
}
int main() {
  int m, n;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    c[i][0] = '0';
    c[i][m + 1] = '0';
  }
  for (int i = 0; i <= m; i++) {
    c[0][i] = '0';
    c[0][n + 1] = '0';
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!done) {
        if (vis[i][j] == 0) dfs(i, j, 0, 0);
      } else
        break;
    }
  if (done)
    cout << "YES\n";
  else
    cout << "NO\n";
}
