#include <bits/stdc++.h>
const double inf = 1e20;
using namespace std;
int n, m, i, j, f;
char a[55][55];
int vis[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y, int oldx, int oldy) {
  if (x == i && y == j && vis[i][j]) {
    f = 1;
    return;
  }
  for (int d = 0; d < 4 && !f; d++) {
    int xx = x + dx[d], yy = y + dy[d];
    if (a[xx][yy] == a[i][j] && xx >= 0 && yy >= 0 && xx < n && yy < m &&
        !vis[xx][yy] && (oldx != xx || oldy != yy))
      vis[xx][yy] = 1, dfs(xx, yy, x, y);
  }
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++)
    for (j = 0; j < m && !f; j++) {
      memset(vis, 0, sizeof(vis));
      dfs(i, j, -1, -1);
    }
  if (f)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
