#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long double R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  long double vx = x2 - x1, vy = y2 - y1;
  long double vs = sqrt(vx * vx + vy * vy);
  long double x0 = x1 - (vx / vs) * R, y0 = y1 - (vy / vs) * R;
  if (abs(vs) < 1e-7 || (abs(x1 - x2) < 1e-7 && abs(y1 - y2) < 1e-7)) {
    x0 = x1 - R;
    y0 = y1;
  }
  long double rx = (x2 + x0) / (long double)2, ry = (y2 + y0) / (long double)2;
  long double r = sqrt((rx - x0) * (rx - x0) + (ry - y0) * (ry - y0));
  if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) >= R * R) {
    rx = x1;
    ry = y1;
    r = R;
  }
  cout << setprecision(15) << rx << ' ' << ry << ' ' << r << '\n';
}
