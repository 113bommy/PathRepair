#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double inf = 10000;
const int maxP = 1100;
const double PI = acos(-1.0);
inline double sqr(double d) { return d * d; }
inline int dcmp(double d) { return d < -eps ? -1 : d > eps; }
struct Point {
  double x, y;
  Point() {}
  Point(const double &_x, const double &_y) : x(_x), y(_y) {}
  bool operator==(const Point &p) const {
    return (dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0);
  }
  bool operator<(const Point &p) const {
    return y + eps < p.y || (y < p.y + eps && x + eps < p.x);
  }
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(const double &k) const { return Point(x * k, y * k); }
  Point operator/(const double &k) const { return Point(x / k, y / k); }
  double operator*(const Point &p) const { return x * p.y - y * p.x; }
  double operator/(const Point &p) const { return x * p.x + y * p.y; }
  double len2() { return x * x + y * y; }
  double len() { return sqrt(x * x + y * y); }
  Point scale(const double &k) {
    return dcmp(len()) ? (*this) * (k / len()) : (*this);
  }
  Point turnLeft() { return Point(-y, x); }
  Point turnRight() { return Point(y, -x); }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%.2lf %.2lf\n", x + eps, y + eps); }
  double Distance(Point p) { return sqrt(sqr(p.x - x) + sqr(p.y - y)); }
  Point rotate(const Point &p, double angle, double k = 1) {
    Point vec = (*this) - p;
    double Cos(cos(angle) * k), Sin(sin(angle) * k);
    return p + Point(vec.x * Cos - vec.y * Sin, vec.x * Sin + vec.y * Cos);
  }
};
struct Line {
  Point a, b;
  Line() {}
  Line(const Point &_a, const Point &_b) : a(_a), b(_b) {}
  Line(double c, double d, double e, double f)
      : a(Point(c, d)), b(Point(e, f)) {}
  double operator*(const Point &p) const { return (b - a) * (p - a); }
  double operator/(const Point &p) const { return (p - a) / (p - b); }
  void input() { a.input(), b.input(); }
  void output() { a.output(), b.output(); }
  double len() { return a.Distance(b); }
  bool parallel(Line v) { return !dcmp((b - a) * (v.b - v.a)); }
  bool SegCrossSeg(const Line &v, Point &p) {
    double s1 = v * a, s2 = v * b;
    if (dcmp(s2 - s1) == 0) return false;
    p = (a * s2 - b * s1) / (s2 - s1);
    return (dcmp(v / p) <= 0 && dcmp((*this) / p) <= 0);
  }
  int SegCrossSeg(const Line &v) {
    int d1 = dcmp((*this) * v.a);
    int d2 = dcmp((*this) * v.b);
    int d3 = dcmp(v * a);
    int d4 = dcmp(v * b);
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
    return ((d1 == 0 && dcmp((*this) / v.a) <= 0) ||
            (d2 == 0 && dcmp((*this) / v.b) <= 0) ||
            (d3 == 0 && dcmp(v / a) <= 0) || (d4 == 0 && dcmp(v / b) <= 0));
  }
  int LineCrossSeg(const Line &v) {
    int d1 = dcmp((*this) * v.a), d2 = dcmp((*this) * v.b);
    if ((d1 ^ d2) == -2) return 2;
    return (d1 == 0 || d2 == 0);
  }
  int LineCrossLine(const Line &v) {
    if ((*this).parallel(v)) {
      return (dcmp(v * a) == 0);
    }
    return 2;
  }
  Point CrossPoint(const Line &v) {
    double s1 = v * a, s2 = v * b;
    return (a * s2 - b * s1) / (s2 - s1);
  }
  double DisPointToSeg(Point p) {
    if (a == b) return a.Distance(p);
    Point q = p + (a - b).turnLeft();
    if (((p - a) * (q - a)) * ((p - b) * (q - b)) > 0) {
      return min(p.Distance(a), p.Distance(b));
    }
    return fabs((*this) * p) / a.Distance(b);
  }
  Point PointToSeg(Point p) {
    if (a == b) return a;
    Point q = p + (a - b).turnLeft();
    if (((p - a) * (q - a)) * ((p - b) * (q - b)) > 0) {
      return p.Distance(a) < p.Distance(b) ? a : b;
    }
    return CrossPoint(Line(p, q));
  }
  double DisPointToLine(const Point &p) {
    return fabs((*this) * p) / a.Distance(b);
  }
  Point PointToLine(const Point &p) {
    return CrossPoint(Line(p, p + (a - b).turnLeft()));
  }
  Point SymPoint(const Point &p) { return PointToLine(p) * 2 - p; }
  void Move(const double &d) {
    Point t = (b - a).turnLeft().scale(d);
    a = a + t, b = b + t;
  }
};
double areaTriangle(Point &a, Point &b, Point &c, Point &d) {
  Point z(0, 0);
  Point p[3];
  int len = 0;
  Line AB(a, b), CD(c, d), ZA(z, a), ZB(z, b), ZC(z, c), ZD(z, d);
  int ab = dcmp(a * b), ac = dcmp(a * c), ad = dcmp(a * d);
  int bc = dcmp(b * c), bd = dcmp(b * d), cd = dcmp(c * d);
  if ((ab == ac && bc == -ab) || (ac == 0 && dcmp(a / c) > 0) ||
      (bc == 0 && dcmp(b / c) > 0)) {
    if (ZC.SegCrossSeg(AB, p[len]))
      len++;
    else
      p[len++] = c;
  }
  if ((ab == ad && bd == -ab) || (ad == 0 && dcmp(a / d) > 0) ||
      (bd == 0 && dcmp(b / d) > 0)) {
    if (ZD.SegCrossSeg(AB, p[len]))
      len++;
    else
      p[len++] = d;
  }
  if (ac == -cd && ad == cd) {
    if (ZA.SegCrossSeg(CD, p[len]))
      len++;
    else
      p[len++] = a;
  }
  if (bc == -cd && bd == cd) {
    if (ZB.SegCrossSeg(CD, p[len]))
      len++;
    else
      p[len++] = b;
  }
  if (AB.SegCrossSeg(CD, p[len])) len++;
  if (len == 3) return fabs(p[0] * p[2]) * 0.5 + fabs(p[1] * p[2]) * 0.5;
  if (len == 2) return fabs(p[0] * p[1]) * 0.5;
  return 0;
}
double w, h, a;
Point p[5], q[5];
int main() {
  while (cin >> w >> h >> a) {
    double angle = a * PI / 180;
    p[0] = Point(w / 2, h / 2);
    p[1] = Point(-w / 2, h / 2);
    p[2] = Point(-w / 2, -h / 2);
    p[3] = Point(w / 2, -h / 2);
    p[4] = p[0];
    for (int i = 0; i < 4; i++) {
      q[i] = p[i].rotate(Point(0, 0), angle);
    }
    q[4] = q[0];
    double s = 0;
    for (int i = 0; i <= 4; i++) {
      for (int j = 0; j <= 4; j++)
        s += areaTriangle(p[i], p[i + 1], q[j], q[j + 1]);
    }
    printf("%.15lf\n", s);
  }
  return 0;
}
