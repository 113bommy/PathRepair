#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
bool cycleFound = false;
bool visited[3000][3000] = {0};
vector<string> grid;
bool valid(int x, int y, int px, int py) {
  return (x >= 0 && x < n && y >= 0 && y < m && px >= 0 && px < n && py >= 0 &&
          y < m && (grid[x][y] == grid[px][py]));
}
void dfs(int x, int y, int px, int py) {
  if (!valid(x, y, px, py) || visited[x][y]) return;
  visited[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(nx, ny, x, y)) {
      if (nx == px && ny == py)
        continue;
      else {
        if (visited[nx][ny]) {
          cycleFound = true;
          return;
        }
      }
    }
    dfs(nx, ny, x, y);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) dfs(i, j, i, j);
  }
  if (cycleFound)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
