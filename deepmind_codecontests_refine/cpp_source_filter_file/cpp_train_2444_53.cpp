#include <bits/stdc++.h>
using namespace std;
int colour;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char grid[60][60];
bool vis[60][60];
int n, m;
bool valid(int x, int y) {
  if (x < 0 || y < 0) return false;
  if (x >= n || y >= m) return false;
  return true;
}
void dfs(int x, int y, int px, int py) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int a = x + dir[i][0];
    int b = y + dir[i][1];
    if (valid(a, b)) {
      if (((grid[a][b] - 'a') == colour)) {
        if ((vis[a][b]) && (a != px && b != py)) {
          cout << "Yes\n";
          exit(0);
        }
        if (!vis[a][b]) dfs(a, b, x, y);
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j], vis[i][j] = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[n][m]) {
        colour = grid[i][j] - 'a';
        dfs(i, j, -1, -1);
      }
    }
  }
  cout << "No\n";
  return 0;
}
