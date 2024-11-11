#include <bits/stdc++.h>
using namespace std;
double a, b;
double mx = 0.000, mn = 1e9;
double dist(double x, double y) { return hypot(x - a, y - b); }
void ck(double x, double y) { mx = max(mx, dist(x, y)); }
double shrt(double x1, double y1, double x2, double y2) {
  double area = a * y1 + x1 * y2 + x2 * b - (b * x1 + y1 * x2 + y2 * a);
  double d1 = dist(x1, y1);
  double d2 = dist(x2, y2);
  double d3 = hypot(x1 - x2, y1 - y2);
  double t1 = acos((d2 * d2 + d3 * d3 - d1 * d1) / (2 * d2 * d3));
  double t2 = acos((d1 * d1 + d3 * d3 - d2 * d2) / (2 * d1 * d3));
  if (t1 - 3.14159265358979323846264338327 / 2 <= 1e-8 &&
      t2 - 3.14159265358979323846264338327 / 2 <= 1e-8)
    return area / d3;
  return min(d1, d2);
}
int main() {
  int n;
  cin >> n;
  cin >> a >> b;
  double x, y, px, py, ox, oy;
  cin >> x >> y;
  ck(x, y);
  px = x;
  py = y;
  ox = x;
  oy = y;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    ck(x, y);
    mn = min(mn, shrt(x, y, px, py));
    px = x;
    py = y;
  }
  mn = min(mn, shrt(x, y, ox, oy));
  printf("%.20lf\n", 3.14159265358979323846264338327 * (mx * mx - mn * mn));
  return 0;
}
