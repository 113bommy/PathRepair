#include <bits/stdc++.h>
using namespace std;
bool found = false;
int w, h;
char grid[55][55];
bool visited[55][55];
void dfs(int x, int y, char color, int x2, int y2) {
  if (x >= w or y >= h or x < 0 or y < 0 or grid[x][y] != color) return;
  if (visited[x][y] && grid[x][y] == color) {
    found = true;
    return;
  }
  visited[x][y] = true;
  if (x + 1 != x2 || y != y2) dfs(x + 1, y, color, x, y);
  if (x - 1 != x2 || y != y2) dfs(x - 1, y, color, x, y);
  if (x != x2 || y + 1 != y2) dfs(x, y + 1, color, x, y);
  if (x != x2 || y - 1 != y2) dfs(x, y - 1, color, x, y);
}
int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[j][i];
      visited[j][j] = false;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!visited[j][i]) dfs(j, i, grid[j][i], -1, -1);
    }
  }
  if (found)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
