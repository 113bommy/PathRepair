#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> maze;
  string a;
  for (int i = 0; i < 11; ++i) {
    getline(cin, a, '\n');
    maze.push_back(a);
  }
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  int tx = x, ty = y;
  tx = 3 * (x % 3);
  ty = 3 * (y % 3);
  if (tx > 3) tx++;
  if (tx > 6) tx++;
  if (ty > 3) ty++;
  if (ty > 6) ty++;
  int t = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (maze[tx + i][ty + j] == '.') {
        t++;
        maze[tx + i][ty + j] = '!';
      }
    }
  }
  if (!t) {
    for (int i = 0; i < (int)maze.size(); ++i) {
      for (int j = 0; j < (int)maze[i].size(); ++j) {
        if (maze[i][j] == '.')
          cout << '!';
        else {
          cout << maze[i][j];
        }
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < (int)maze.size(); ++i) {
      for (int j = 0; j < (int)maze[i].size(); ++j) {
        cout << maze[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
