#include <bits/stdc++.h>
template <class T>
__inline__ __attribute__((always_inline)) T chkmax(T &a, const T b) {
  if (a < b) a = b;
  return a;
}
template <class T>
__inline__ __attribute__((always_inline)) T chkmin(T &a, const T b) {
  if (a > b) a = b;
  return a;
}
template <class T>
__inline__ __attribute__((always_inline)) T mymax(const T a, const T b) {
  return a > b ? a : b;
}
template <class T>
__inline__ __attribute__((always_inline)) T mymin(const T a, const T b) {
  return a < b ? a : b;
}
template <class T>
__inline__ __attribute__((always_inline)) T myabs(const T &a) {
  return a > 0 ? a : -a;
}
const int INF = 0X3F3F3F3F;
const double EPS = 1E-5, PI = acos(-1.0);
namespace ComputationalGeometry {
__inline__ __attribute__((always_inline)) int dcmp(double a, double b) {
  return myabs(a - b) < EPS ? -1 : a > b;
}
__inline__ __attribute__((always_inline)) bool isnan(double x) {
  return x != x;
}
__inline__ __attribute__((always_inline)) bool isinf(double x) {
  return !isnan(x) && isnan(x - x);
}
__inline__ __attribute__((always_inline)) bool isint(double x) {
  return dcmp(x, floor(x)) == -1 || dcmp(x, ceil(x)) == -1;
}
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
  __inline__ __attribute__((always_inline)) void read() {
    scanf("%lf%lf", &x, &y);
  }
};
bool operator<(const Point &a, const Point &b) {
  return dcmp(a.x, b.x) == 0 || (dcmp(a.x, b.x) == -1 && dcmp(a.y, b.y) == 0);
}
Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
Point operator*(const Point &a, double b) { return Point(a.x * b, a.y * b); }
Point operator/(const Point &a, double b) { return Point(a.x / b, a.y / b); }
__inline__ __attribute__((always_inline)) double Dot(const Point &a,
                                                     const Point &b) {
  return a.x * b.x + a.y * b.y;
}
__inline__ __attribute__((always_inline)) double Length(const Point &x) {
  return sqrt(Dot(x, x));
}
__inline__ __attribute__((always_inline)) double Angle(const Point &a,
                                                       const Point &b) {
  return acos(Dot(a, b) / (Length(a) * Length(b)));
}
__inline__ __attribute__((always_inline)) double Cross(const Point &a,
                                                       const Point &b) {
  return a.x * b.y - a.y * b.x;
}
__inline__ __attribute__((always_inline)) Point Rotate(const Point &x,
                                                       double rad) {
  return Point(x.x * cos(rad) - x.y * sin(rad),
               x.x * sin(rad) + x.y * cos(rad));
}
struct Line {
  Point p;
  Point v;
  Line() {}
  Line(const Point &a, const Point &b) : p(a), v(b - a) {}
};
__inline__ __attribute__((always_inline)) Point GetLineIntersection(
    const Line &u, const Line &v) {
  double t = Cross(v.v, u.p - v.p) / Cross(u.v, v.v);
  return u.p + u.v * t;
}
struct Circle {
  Point v;
  double r;
  Circle() {}
  Circle(const Point &x, double a) : v(x), r(a) {}
};
}  // namespace ComputationalGeometry
using namespace ComputationalGeometry;
__inline__ __attribute__((always_inline)) Circle GetCircumcircle(
    const Point &a, const Point &b, const Point &c) {
  Line x(a, b), y(a, c), m, n;
  m.p = x.p + x.v * 0.5, n.p = y.p + y.v * 0.5;
  m.v = Rotate(x.v, PI / 2), n.v = Rotate(y.v, PI / 2);
  Point t = GetLineIntersection(m, n);
  return Circle(t, Length(t - a));
}
int main() {
  Point a, b, c;
  a.read();
  b.read();
  c.read();
  if (b < a) std::swap(a, b);
  if (c < b) std::swap(b, c);
  if (b < a) std::swap(a, b);
  Circle x = GetCircumcircle(a, b, c);
  double rad1 = Angle(x.v - a, x.v - b), rad2 = Angle(x.v - b, x.v - c);
  for (int i = 1; i <= 1000; ++i) {
    double r = 2 * PI / i;
    if (isint(rad1 / r) && isint(rad2 / r)) {
      printf("%.8f\n", 0.5 * i * x.r * x.r * sin(r));
      break;
    }
  }
  return 0;
}
