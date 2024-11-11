#include <bits/stdc++.h>
using namespace std;
const int N = 105;
double sqr(double d) { return d * d; }
bool deql(double a, double b) { return fabs(a - b) < 1e-10; }
bool triangle(double a, double b, double c) { return a * a + b * b >= c * c; }
bool square(double a, double b, double c) {
  return deql(a * a + b * b, c * c) && deql(a, b);
}
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
  bool operator==(const Point &b) const { return x == b.x && y == b.y; }
} pt[N];
double dis(const Point &a, const Point &b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
Point *waixin(const Point &x, const Point &y, const Point &z) {
  static Point p;
  double A2, B2, A1, B1, C2, C1, d, d1, d2;
  A1 = 2 * (y.x - x.x);
  B1 = 2 * (y.y - x.y);
  C1 = sqr(y.x) - sqr(x.x) + sqr(y.y) - sqr(x.y);
  A2 = 2 * (z.x - y.x);
  B2 = 2 * (z.y - y.y);
  C2 = sqr(z.x) - sqr(y.x) + sqr(z.y) - sqr(y.y);
  d = A1 * B2 - B1 * A2;
  d1 = C1 * B2 - B1 * C2;
  d2 = A1 * C2 - C1 * A2;
  if (d == 0.0) return 0;
  return &(p = Point(d1 / d, d2 / d));
}
int n;
double getmin(Point x) {
  double r = 1e9;
  for (int i = 1; i <= n; ++i) r = min(r, dis(pt[i], x));
  return r;
}
int main() {
  Point C, w, *tmp;
  double ans = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      for (int k = j + 1; k <= n; ++k) {
        Point x = pt[i], y = pt[j], z = pt[k];
        double a = dis(y, z), b = dis(x, y), c = dis(x, z), d;
        if (square(b, c, a)) swap(c, a), swap(x, y);
        if (square(a, c, b)) swap(c, b), swap(y, z);
        if (square(a, b, c)) {
          C = Point((x.x + z.x) / 2, (x.y + z.y) / 2);
          w = Point(C.x * 2 - y.x, C.y * 2 - y.y);
          for (int l = 1; l <= n; ++l)
            if (pt[l] == w) {
              double t = getmin(C);
              if (t * 2 > a && ans < t) ans = t;
              break;
            }
        }
        tmp = waixin(x, y, z);
        if (!tmp) continue;
        if (!triangle(a, b, c) || !triangle(a, c, b) || !triangle(b, c, a))
          continue;
        double mx = max(a, max(b, c)), t = getmin(*tmp);
        if (t * 2 > mx && ans < t) ans = t;
      }
  if (ans < 0)
    puts("-1");
  else
    printf("%.9f", ans);
  return 0;
}
