#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
bool vis[maxn][maxn];
char grid[maxn][maxn];
int n, m;
bool bad(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return true;
  if (vis[x][y]) return true;
  return false;
}
bool canPlaceRight(int x, int y) { return !bad(x, y) && !bad(x, y + 1); }
bool canPlaceLeft(int x, int y) { return !bad(x, y) && !bad(x, y - 1); }
bool canPlaceDown(int x, int y) { return !bad(x, y) && !bad(x + 1, y); }
bool canPlaceUp(int x, int y) { return !bad(x, y) && !bad(x - 1, y); }
void placeRight(int x, int y) {
  vis[x][y] = true;
  vis[x][y + 1] = true;
  grid[x][y] = '<';
  grid[x][y + 1] = '>';
}
void placeLeft(int x, int y) {
  vis[x][y] = true;
  vis[x][y - 1] = true;
  grid[x][y] = '>';
  grid[x][y - 1] = '<';
}
void placeDown(int x, int y) {
  vis[x][y] = true;
  vis[x + 1][y] = true;
  grid[x][y] = '^';
  grid[x + 1][y] = 'v';
}
void placeUp(int x, int y) {
  vis[x][y] = true;
  vis[x - 1][y] = true;
  grid[x][y] = 'v';
  grid[x - 1][y] = '^';
}
void discover(int x, int y) {
  for (int i = x - 3; i < x + 3; i++) {
    for (int j = y - 3; j < y + 3; j++) {
      if (canPlaceRight(i, j) && !canPlaceDown(i, j) && !canPlaceLeft(i, j) &&
          !canPlaceUp(i, j)) {
        placeRight(i, j);
        discover(i, j);
      } else if (!canPlaceRight(i, j) && canPlaceDown(i, j) &&
                 !canPlaceLeft(i, j) && !canPlaceUp(i, j)) {
        placeDown(i, j);
        discover(i, j);
      } else if (!canPlaceRight(i, j) && !canPlaceDown(i, j) &&
                 canPlaceLeft(i, j) && !canPlaceUp(i, j)) {
        placeLeft(i, j);
        discover(i, j);
      } else if (!canPlaceRight(i, j) && !canPlaceDown(i, j) &&
                 !canPlaceLeft(i, j) && canPlaceUp(i, j)) {
        placeUp(i, j);
        discover(i, j);
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      vis[i][j] = false;
    }
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      grid[i][j] = str[j];
      if (str[j] == '*') vis[i][j] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (canPlaceRight(i, j) && !canPlaceDown(i, j) && !canPlaceLeft(i, j) &&
          !canPlaceUp(i, j)) {
        placeRight(i, j);
        discover(i, j);
      }
      if (!canPlaceRight(i, j) && canPlaceDown(i, j) && !canPlaceLeft(i, j) &&
          !canPlaceUp(i, j)) {
        placeDown(i, j);
        discover(i, j);
      }
      if (!canPlaceRight(i, j) && !canPlaceDown(i, j) && canPlaceLeft(i, j) &&
          !canPlaceUp(i, j)) {
        placeLeft(i, j);
        discover(i, j);
      }
      if (!canPlaceRight(i, j) && !canPlaceDown(i, j) && !canPlaceLeft(i, j) &&
          canPlaceUp(i, j)) {
        placeUp(i, j);
        discover(i, j);
      }
    }
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') flag = true;
    }
  }
  if (flag) {
    cout << "Not unique\n";
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  }
}
