#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> diffs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(const vector<string>& grid, vector<vector<int>>& visited, int y, int x,
         int num_walls, int& filled) {
  if (y < 0 || y >= (int)grid.size()) return;
  if (x < 0 || x >= (int)grid[y].size()) return;
  if (visited[y][x] || grid[y][x] == '#') return;
  visited[y][x] = 1;
  for (auto d : diffs)
    dfs(grid, visited, y + d.first, x + d.second, num_walls, filled);
  if (filled < num_walls) {
    visited[y][x] = 2;
    filled++;
  }
}
int main() {
  int h, w, num_walls;
  cin >> h >> w >> num_walls;
  vector<string> grid(h);
  for (int y = 0; y < h; y++) cin >> grid[y];
  pair<int, int> start;
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      if (grid[y][x] == '.') {
        start = {y, x};
        break;
      }
    }
  vector<vector<int>> visited(h, vector<int>(w, 0));
  int filled = 0;
  dfs(grid, visited, start.first, start.second, num_walls, filled);
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++)
      if (grid[y][x] == '#')
        cout << '#';
      else if (visited[y][x] == 2)
        cout << 'X';
      else
        cout << '.';
    cout << '\n';
  }
  return 0;
}
