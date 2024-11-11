#include <bits/stdc++.h>
using namespace std;
const int MAX = 501;
char maps[MAX][MAX];
int r, c;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool check(int x, int y) {
  if (maps[x][y] != '*') return false;
  for (int i = 0; i < 4; i++) {
    int tx, ty;
    tx = x + dx[i], ty = y + dy[i];
    if (maps[tx][ty] != '*') return false;
  }
  return true;
}
pair<int, int> find_degree4() {
  int cnt = 0;
  pair<int, int> ret;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (check(i, j)) {
        cnt++;
        ret = {i, j};
      }
    }
  }
  if (cnt != 1)
    return {-1, -1};
  else
    return ret;
}
bool solve(int x0, int y0) {
  int x, y;
  maps[x0][y0] = '.';
  x = x0 - 1, y = y0;
  while (x >= 0 && maps[x][y] == '*') {
    maps[x][y] = '.';
    x--;
  }
  x = x0 + 1, y = y0;
  while (x < r && maps[x][y] == '*') {
    maps[x][y] = '.';
    x++;
  }
  x = x0, y = y0 + 1;
  while (y < c && maps[x][y] == '*') {
    maps[x][y] = '.';
    y++;
  }
  x = x0, y = y0 - 1;
  while (y >= 0 && maps[x][y] == '*') {
    maps[x][y] = '.';
    y--;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (maps[i][j] == '*') return false;
    }
  }
  return true;
}
void printmap() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << maps[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> maps[i][j];
    }
  }
  pair<int, int> loc = find_degree4();
  if (loc.first == -1 && loc.second == -1) {
    cout << "NO\n";
    return 0;
  }
  solve(loc.first, loc.second) == true ? cout << "YES\n" : cout << "NO\n";
}
