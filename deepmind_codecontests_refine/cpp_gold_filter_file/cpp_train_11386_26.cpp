#include <bits/stdc++.h>
using namespace std;
long double dist(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  long double y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  long double target = y1 + r;
  long double a = yw - r - target;
  long double b = yw - r - yb;
  double xw = (a * xb) / (a + b);
  long double c = (yw - r - target) / xw;
  long double d = xw / (r + target - yw);
  long double xtemp = (y2 - target) / (c - d);
  long double ytemp = c * xtemp + target;
  long double mydist = dist(0, y2, xtemp, ytemp);
  if (mydist < r)
    cout << -1 << "\n";
  else
    printf("%.12f\n", xw);
  return 0;
}
