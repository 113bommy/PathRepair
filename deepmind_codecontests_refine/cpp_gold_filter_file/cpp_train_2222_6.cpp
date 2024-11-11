#include <bits/stdc++.h>
using namespace std;
int a[55][55], vis[55][55], n, m, d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
void dfs(int x, int y) {
  int nx, ny;
  for (int i = 0; i < 4; i++) {
    nx = x + d[i][0];
    ny = y + d[i][1];
    if (nx >= 0 && ny >= 0 && nx < m && ny < n && vis[nx][ny] == 0 &&
        a[nx][ny] == 0) {
      vis[nx][ny] = 1;
      dfs(nx, ny);
    }
  }
}
void solve() {
  int i, j, k, u, v;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (a[i][j] == 0) {
        k = 0;
        memset(vis, 0, sizeof(vis));
        a[i][j] = 1;
        for (u = 0; u < m; u++)
          for (v = 0; v < n; v++)
            if (a[u][v] == 0 && vis[u][v] == 0) {
              dfs(u, v);
              k++;
              if (k > 1) {
                cout << 1 << endl;
                return;
              }
            }
        a[i][j] = 0;
      }
  cout << 2 << endl;
}
int main() {
  int i, j, s;
  char c;
  cin >> m >> n;
  s = 0;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
      cin >> c;
      if (c == '#') {
        a[i][j] = 0;
        s++;
      } else
        a[i][j] = 1;
    }
  if (s <= 2)
    cout << "-1\n";
  else
    solve();
  return 0;
}
