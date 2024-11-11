#include <bits/stdc++.h>
using namespace std;
stringstream soln;
int visited[501][501];
int n, x_0, y_0;
int a[501][501];
bool free(int x, int y, int dx, int dy) {
  for (int k = 1; (((x + k * dx) >= 1) && ((x + k * dx) <= n) &&
                   ((y + k * dy) >= 1) && ((y + k * dy) <= n));
       k++) {
    if (a[y + k * dy][x + k * dx] == 1) return true;
  }
  return false;
}
bool done() {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if ((visited[i][j] == 0) && (a[i][j] == 1)) return false;
    }
  }
  return true;
}
void dfs(int x, int y) {
  if (visited[y][x]) return;
  visited[y][x] = 1;
  if (a[y][x] == 0) soln << "1";
  a[y][x] = 1;
  int dx = 1, dy = 0;
  for (int i = 0; i < 4; i++) {
    if (free(x, y, dx, dy)) {
      if ((dx == 1) && (dy == 0)) soln << "R";
      if ((dx == -1) && (dy == 0)) soln << "L";
      if ((dx == 0) && (dy == 1)) soln << "D";
      if ((dx == 0) && (dy == -1)) soln << "U";
      dfs(x + dx, y + dy);
      if ((dx == 1) && (dy == 0)) soln << "L";
      if ((dx == -1) && (dy == 0)) soln << "R";
      if ((dx == 0) && (dy == 1)) soln << "U";
      if ((dx == 0) && (dy == -1)) soln << "D";
    }
    int d = dx;
    dx = -dy;
    dy = d;
  }
  if (a[y][x] == 1) soln << "2";
  a[y][x] = 0;
}
int main() {
  soln.str("");
  cin >> n >> x_0 >> y_0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      visited[i][j] = 0;
    }
  }
  for (int i = 1; i < (n + 1); i++) {
    for (int j = 1; j < (n + 1); j++) {
      cin >> a[j][i];
    }
  }
  dfs(x_0, y_0);
  if (done()) {
    cout << "YES\n";
    cout << soln.str();
  } else
    cout << "NO";
  return 0;
}
