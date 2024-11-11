#include <bits/stdc++.h>
using namespace std;
char grid[2010][2010];
int deg[2010][2010];
int n, m;
void show_grid() {
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      cout << grid[x][y];
    }
    cout << "\n";
  }
}
void show_deg() {
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      cout << deg[x][y];
    }
    cout << "\n";
  }
}
queue<pair<int, int>> q;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
char ss[2][8] = {"^>v<", "v<^>"};
int ct, ans, rm, cm, dir, x, y;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == '.') ct++;
    }
  }
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c) {
      if (grid[r][c] == '.') {
        for (int k = 0; k < 4; ++k) {
          rm = r + dx[k], cm = c + dy[k];
          if (grid[rm][cm] == '.') deg[r][c]++;
        }
        if (deg[r][c] == 1) q.push({r, c});
      }
    }
  }
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if (grid[x][y] == '.') {
      int nx, ny, id = -1;
      bool tt = false;
      for (int k = 0; k < 4; ++k) {
        nx = x + dx[k], ny = y + dy[k];
        id = k;
        if (grid[nx][ny] == '.') {
          tt = true;
          break;
        }
      }
      if (!tt) {
        cout << "Not unique\n";
        return 0;
      }
      grid[x][y] = ss[0][id];
      grid[nx][ny] = ss[1][id];
      deg[x][y] = 0;
      deg[nx][ny] = 0;
      for (int k = 0; k < 4; ++k) {
        int nnx = nx + dx[k];
        int nny = ny + dy[k];
        deg[nnx][nny]--;
        if (deg[nnx][nny] == 1) q.push({nnx, nny});
      }
    }
  }
  for (int r = 1; r <= n; ++r) {
    for (int c = 1; c <= m; ++c) {
      if (grid[r][c] == '.') {
        { std::cout << "Not unique" << std::endl; };
        return 0;
      }
    }
  }
  show_grid();
  return 0;
}
