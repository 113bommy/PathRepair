#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const double eps = 1e-8, inf = 1e50, Pi = acos(-1.0);
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  point operator-(const point &ne) const { return point(x - ne.x, y - ne.y); }
  point operator+(const point ne) const { return point(x + ne.x, y + ne.y); }
  point operator*(const double t) const { return point(x * t, y * t); }
  point operator/(const double t) const {
    if (((t) > eps ? 1 : ((t) < -eps ? (-1) : (0))) == 0) exit(1);
    return point(x / t, y / t);
  }
};
struct line {
  point a, b;
  line() {}
  line(point _a, point _b) {
    a = _a;
    b = _b;
  }
};
double dmult(point a, point b) { return a.x * b.x + a.y * b.y; }
double lenth(point a) { return sqrt(dmult(a, a)); }
inline double xmult(point o, point a, point b) {
  return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
inline double xmult(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
inline double dmult(point o, point a, point b) {
  return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}
inline double xmult(point a, point b) { return a.x * b.y - a.y * b.x; }
point line_intersection(line u, line v) {
  point ret = u.a;
  double t = xmult(u.a - v.a, v.b - v.a) / xmult(u.b - u.a, v.b - v.a);
  t = fabs(t);
  ret.x += (u.b.x - u.a.x) * t;
  ret.y += (u.b.y - u.a.y) * t;
  return ret;
}
point line_intersection2(line u, line v) {
  double a1 = u.b.y - u.a.y, b1 = u.a.x - u.b.x;
  double c1 = u.b.y * (-b1) - u.b.x * a1;
  double a2 = v.b.y - v.a.y, b2 = v.a.x - v.b.x;
  double c2 = v.b.y * (-b2) - v.b.x * a2;
  double D = xmult(a1, b1, a2, b2);
  return point(xmult(b1, c1, b2, c2) / D, xmult(c1, a1, c2, a2) / D);
}
void counter(double &x, double &y, double th) {
  double tx = x, ty = y;
  x = tx * cos(th) - ty * sin(th);
  y = tx * sin(th) + ty * cos(th);
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 4) {
    printf("No solution\n");
    return 0;
  }
  point tmp, way(-800.0, 0), po[105];
  double delta = 0.999995, th = -2.0 * Pi / n;
  po[0] = point(0, 0);
  for (int i = 1; i <= n - 2; i++) {
    counter(way.x, way.y, th);
    way = way * delta;
    po[i] = po[i - 1] + way;
  }
  counter(way.x, way.y, th);
  way = way * delta;
  tmp = po[n - 2] + way;
  po[n - 1] = line_intersection(line(po[n - 2], tmp),
                                line(point(-1.0, 0.0), point(1.0, 0.0)));
  po[n] = po[0];
  for (int i = n - 1; i >= 0; i--) {
    printf("%lf %lf\n", po[i].x, po[i].y);
  }
  return 0;
}
