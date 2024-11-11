#include <bits/stdc++.h>
using namespace std;
int n, m;
int grid[250][250];
int deltax[] = {0, 1, 1, 1, 0, -1, -1, -1};
int deltay[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool valid(int x, int y) {
  if (x >= n || y >= m || x < 0 || y < 0) return false;
  return true;
}
int consider[][8] = {{0, 0, 0, 1, 1, 1, 1, 0},
                     {0, 0, 1, 1, 0, 1, 1, 0},
                     {0, 0, 0, 0, 1, 1, 1, 0},
                     {0, 0, 1, 0, 0, 0, 1, 0}};
bool isGood(int x, int y, int diag, int type, int corner) {
  if (!valid(x, y)) return false;
  if (grid[x][y] == 0) return false;
  int forward = 2 * type + diag;
  int row = (1 - diag) * 2 + (1 - corner);
  for (int i = 0; i < 8; i++) {
    if (consider[row][i]) {
      int dir = (forward + i) % 8;
      int u = x + deltax[dir];
      int v = y + deltay[dir];
      if (valid(u, v) && grid[u][v] == 1) return false;
    }
  }
  return true;
}
bool isSquare(int x, int y, int diag) {
  int xstart = x, ystart = y;
  int s = 0;
  int type = 0;
  if (!isGood(x, y, diag, type, 1)) return false;
  do {
    x += deltax[2 * type + diag];
    y += deltay[2 * type + diag];
    s++;
  } while (isGood(x, y, diag, type, 0));
  type = 1;
  if (!isGood(x, y, diag, type, 1)) return false;
  for (int k = 1; k < 3 * s; k++) {
    x += deltax[2 * type + diag];
    y += deltay[2 * type + diag];
    if (k % s == 0) type++;
    if (!isGood(x, y, diag, type, (k % s == 0))) {
      return false;
    }
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      string line;
      cin >> line;
      for (int j = 0; j < m; j++) grid[i][j] = line[j] - '0';
    }
    int nsquares = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] == 1) {
          if (isSquare(i, j, 0) || isSquare(i, j, 1)) nsquares++;
        }
    cout << nsquares << endl;
  }
  return 0;
}
