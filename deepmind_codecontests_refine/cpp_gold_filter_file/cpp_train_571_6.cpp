#include <bits/stdc++.h>
using namespace std;
pair<double, double> point[1000005];
double xmult(double x1, double y1, double x2, double y2, double x0, double y0) {
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
double area_triangle(double x1, double y1, double x2, double y2, double x3,
                     double y3) {
  return fabs(xmult(x1, y1, x2, y2, x3, y3)) / 2;
}
double dis_ptoline(double x1, double y1, double x2, double y2, double ex,
                   double ey) {
  double k, b, dis, tem1, tem2, t1, t2,
      yd = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)), px, py;
  t2 = sqrt((x2 - ex) * (x2 - ex) + (y2 - ey) * (y2 - ey));
  t1 = sqrt((x1 - ex) * (x1 - ex) + (y1 - ey) * (y1 - ey));
  dis = area_triangle(x1, y1, x2, y2, ex, ey) * 2 / yd;
  tem1 = sqrt(t1 * t1 - dis * dis);
  tem2 = sqrt(t2 * t2 - dis * dis);
  if (tem1 > yd || tem2 > yd) {
    if (t1 > t2) {
      px = x2;
      py = y2;
      return t2;
    } else {
      px = x1;
      py = y1;
      return t1;
    }
  }
  px = x1 + (x2 - x1) * tem1 / yd;
  py = y1 + (y2 - y1) * tem1 / yd;
  return dis;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  double px, py;
  cin >> n >> px >> py;
  double ma = 0, mi = 1e18;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    point[i].first = x;
    point[i].second = y;
    ma = max(ma, (x - px) * (x - px) + (y - py) * (y - py));
    if (i)
      mi =
          min(mi, dis_ptoline(point[i].first, point[i].second,
                              point[i - 1].first, point[i - 1].second, px, py));
  }
  mi = min(mi, dis_ptoline(point[0].first, point[0].second, point[n - 1].first,
                           point[n - 1].second, px, py));
  cout << fixed << setprecision(18) << 3.1415926535897932384626 * (ma - mi * mi)
       << '\n';
}
