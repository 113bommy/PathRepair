#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, x, y, y1, y2, zx, zy;
  cin >> x >> y;
  if (x > 0)
    zx = 1;
  else {
    zx = -1;
    x *= -1;
  }
  if (y > 0)
    zy = 1;
  else {
    zy = -1;
    y *= -1;
  }
  x1 = (x + y) * (zx > 0 ? 0 : zx);
  x2 = (x + y) * (zx < 0 ? 0 : zx);
  y2 = (x + y) * (zx < 0 ? zy : 0);
  y1 = (x + y) * (zx > 0 ? zy : 0);
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
  return 0;
}
