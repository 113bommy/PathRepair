#include <bits/stdc++.h>
using namespace std;
int main() {
  int y1, y2;
  char x1, x2, dx, dy, xd_ch, yd_ch;
  cin >> x1 >> y1 >> x2 >> y2;
  x1 -= 'a';
  x2 -= 'a';
  dx = x1 <= x2 ? 1 : -1;
  dy = y1 <= y2 ? 1 : -1;
  xd_ch = x1 <= x2 ? 'R' : 'L';
  yd_ch = y1 <= y2 ? 'U' : 'D';
  cout << max(abs(x1 - x2), abs(y1 - y2)) << endl;
  while ((x1 != x2) || (y1 != y2)) {
    if (x1 != x2) {
      x1 += dx;
      cout << xd_ch;
    }
    if (y1 != y2) {
      y1 += dy;
      cout << yd_ch;
    }
    cout << endl;
  }
  return 0;
}
