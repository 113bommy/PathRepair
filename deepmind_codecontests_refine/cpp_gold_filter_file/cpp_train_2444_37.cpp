#include <bits/stdc++.h>
using namespace std;
template <class T>
using lim = numeric_limits<T>;
const int maxn = 50;
char grid[maxn + 1][maxn + 1];
bool vis[maxn + 1][maxn + 1];
bool dfs(int i, int j, int pi, int pj, int n, int m) {
  if (vis[i][j]) return false;
  vis[i][j] = true;
  bool ret = false;
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (abs(dx) + abs(dy) != 1) continue;
      int x = i + dx;
      int y = j + dy;
      if (x >= n || x < 0 || y >= m || y < 0) continue;
      if (grid[x][y] != grid[i][j]) continue;
      if (x == pi && y == pj) continue;
      if (vis[x][y]) return true;
      ret = ret || dfs(x, y, i, j, n, m);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(vis, 0, sizeof vis);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c;
    }
  }
  bool cycle = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cycle = cycle || dfs(i, j, -1, -1, n, m);
    }
  }
  cout << (cycle ? "Yes" : "No") << endl;
}
