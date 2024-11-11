#include <bits/stdc++.h>
template <class T = double>
struct Point {
  T x, y;
  Point() : x(T()), y(T()) {}
  Point(T x, T y) : x(x), y(y) {}
  bool operator<(const Point p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  bool operator==(const Point p) const { return x == p.x && y == p.y; }
  Point operator+(const Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(T v) const { return Point(x * v, y * v); }
  Point operator/(T v) const { return Point(x / v, y / v); }
  template <class T2>
  operator Point<T2>() const {
    return Point<T2>(x, y);
  }
  T dot(Point p) const { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  double dist() const { return sqrt(static_cast<double>(dist2())); }
  T dist2() const { return x * x + y * y; }
  double angle() const { return atan2(y, x); }
  Point unit() const { return *this / dist(); }
  Point perp() const { return Point(-y, x); }
  Point rotate(double radians) {
    return Point(x * cos(radians) - y * sin(radians),
                 x * sin(radians) + y * cos(radians));
  }
};
template <class T = double>
struct Line {
  Point<T> a, ab;
  Line(Point<T> a, Point<T> b, bool twoPoints = true)
      : a(a), ab(twoPoints ? b - a : b) {}
  Line(T xa, T ya, T xb, T yb) : a(xa, ya), ab(xb - xa, yb - ya) {}
  template <class T2>
  operator Line<T2>() const {
    return Line<T2>(Point<T2>(a), Point<T2>(b), false);
  }
  Point<T> b() const { return a + ab; }
};
template <int D, class T>
inline bool checkEndpoint(const T &a, const T &b) {
  if (D > 0) {
    return true;
  }
  if (D < 0) {
    return a < b;
  }
  return a <= b;
}
template <int LA = 1, int LB = 1, int RA = 1, int RB = 1, class T, class T2>
bool lineIntersect(Line<T> &lhs, Line<T> &rhs, Point<T2> &result) {
  auto s = lhs.ab.cross(rhs.ab);
  if (s == 0) return false;
  auto ls = (rhs.a - lhs.a).cross(rhs.ab);
  auto rs = (rhs.a - lhs.a).cross(lhs.ab);
  if (s < 0) {
    s = -s;
    ls = -ls;
    rs = -rs;
  }
  bool intersect =
      checkEndpoint<LA>(decltype(ls)(0), ls) && checkEndpoint<LB>(ls, s) &&
      checkEndpoint<RA>(decltype(rs)(0), rs) && checkEndpoint<RB>(rs, s);
  if (intersect) {
    result = lhs.a + lhs.ab * static_cast<T2>(ls) / s;
  }
  return intersect;
}
int main() {
  int a, b, c;
  int x1, y1, x2, y2;
  scanf("%d %d %d", &a, &b, &c);
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  double dist = abs(x1 - x2) + abs(y1 - y2);
  if (x1 == x2 || y1 == y2 || a == 0 || b == 0) {
    printf("%.10f\n", dist);
    return 0;
  }
  Line<double> diag(0, -c / (double)b, 1, (-c - a) / (double)b);
  Line<double> h1(x1, y1, x2, y1);
  Line<double> v1(x1, y1, x1, y2);
  Line<double> h2(x1, y2, x2, y2);
  Line<double> v2(x2, y1, x2, y2);
  Point<double> p1, p2;
  bool hasShortcut = (lineIntersect<0, 0, 1, 1>(h1, diag, p1) ||
                      lineIntersect<0, 0, 1, 1>(v1, diag, p1)) &&
                     (lineIntersect<0, 0, 1, 1>(h2, diag, p2) ||
                      lineIntersect<0, 0, 1, 1>(v2, diag, p2));
  if (hasShortcut) {
    Point<double> start(x1, y1), end(x2, y2);
    dist = std::min(dist,
                    (p1 - start).dist() + (p2 - p1).dist() + (end - p2).dist());
  }
  printf("%.10f\n", dist);
  return 0;
}
