#include <bits/stdc++.h>
using namespace std;
inline int cmp(double a, double b = 0.0) {
  if (fabs(a - b) <= (1e-9)) return 0;
  if (a < b) return -1;
  return 1;
}
bool mark[1000123];
int n, m;
int y, x, mx, my;
void move() {
  int dx, dy;
  if (mx == -1)
    dx = x;
  else
    dx = m - x - 1;
  if (my == -1)
    dy = y;
  else
    dy = n - y - 1;
  dx = min(dx, dy);
  dy = min(dy, dx);
  y += my * dy;
  x += mx * dx;
  if (y == 0 || y == n - 1) my = -my;
  if (x == 0 || x == m - 1) mx = -mx;
}
void go(int _x, int d) {
  x = _x;
  mx = d;
  my = 1;
  do {
    mark[x] = true;
    do {
      move();
    } while (y != 0);
  } while (mark[x] == false);
}
int main() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (mark[i]) continue;
    cnt++;
    if (i == 0)
      go(i, 1);
    else if (i == n)
      go(i, -1);
    else {
      go(i, 1);
      go(i, -1);
    }
  }
  cout << cnt << endl;
  return 0;
}
