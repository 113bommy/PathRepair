#include <bits/stdc++.h>
using namespace std;
const int maxn = 49;
int n;
int grid[maxn][maxn];
int dx[6] = {2, 1, 0, -2, -1, 0};
int dy[6] = {0, 1, 2, 0, -1, -2};
bool works(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return 0;
  return grid[x][y] == -1;
}
int qry(int x, int y, int X, int Y) {
  if (x > X) swap(x, X), swap(y, Y);
  cout << "? " << x + 1 << " " << y + 1 << " " << X + 1 << " " << Y + 1 << endl;
  int ret;
  cin >> ret;
  return ret;
}
void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  while (!q.empty()) {
    x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (works(nx, ny)) {
        grid[nx][ny] = grid[x][y] ^ !qry(x, y, nx, ny);
        q.push({nx, ny});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  memset(grid, -1, sizeof(grid));
  grid[0][0] = 1;
  grid[n - 1][n - 1] = 0;
  bfs(0, 0);
  int f;
  for (f = 0; grid[f][f] == grid[f + 2][f + 2]; f += 2)
    ;
  bool s = qry(f + 1, f, f + 2, f + 1);
  if ((s && grid[f + 2][f]) || (!s && !grid[f + 2][f])) {
    grid[f + 2][f + 1] = grid[f][f] ^ !qry(f, f, f + 2, f + 1);
    bfs(f + 2, f + 1);
  } else {
    grid[f + 1][f] = grid[f + 2][f + 2] ^ !qry(f + 1, f, f + 2, f + 2);
    bfs(f + 1, f);
  }
  cout << "!" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << grid[i][j];
    cout << endl;
  }
  return 0;
}
