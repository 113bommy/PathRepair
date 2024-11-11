#include <bits/stdc++.h>
using namespace std;
void rot(int n, int *x, int *y, int rx, int ry) {
  if (ry == 0) {
    if (rx == 1) {
      *x = n - 1 - *x;
      *y = n - 1 - *y;
    }
    int t = *x;
    *x = *y;
    *y = t;
  }
}
void d2xy(int n, int d, int *x, int *y) {
  int rx, ry, s, t = d;
  *x = *y = 0;
  for (s = 1; s < n; s *= 2) {
    rx = 1 & (t / 2);
    ry = 1 & (t ^ rx);
    rot(s, x, y, rx, ry);
    *x += s * rx;
    *y += s * ry;
    t /= 4;
  }
}
int main() {
  int n, d;
  cin >> n >> d;
  int x, y;
  d2xy(n, d, &x, &y);
  cout << x << " " << y << endl;
  return 0;
}
