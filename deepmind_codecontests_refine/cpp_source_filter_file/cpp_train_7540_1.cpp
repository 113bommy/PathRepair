#include <bits/stdc++.h>
using namespace std;
char maze[2005][2005];
int main() {
  int n, a[1005], sx, sy, dx, dy, up, down;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sx = 0;
  sy = 1000;
  up = down = 1000;
  memset(maze, ' ', sizeof(maze));
  for (int i = 1; i <= n; i++) {
    dx = sx + a[i];
    if (i % 2 == 0) {
      dy = sy - a[i] + 1;
      if (dy < down) down = dy;
      for (int j = 0; j < a[i]; j++) {
        maze[sx + j][sy - j] = '\\';
      }
    } else {
      dy = sy + a[i] - 1;
      if (dy > up) up = dy;
      for (int j = 0; j < a[i]; j++) {
        maze[sx + j][sy + j] = '/';
      }
    }
    sx = dx;
    sy = dy;
  }
  for (int i = up; i >= down; i--) {
    for (int j = 0; j <= sx; j++) cout << maze[j][i];
    cout << "\n";
  }
  return 0;
}
