#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int N = 100100;
const double PI = 3.141592654;
const double eps = 0.00000001;
double sqr(double x) { return x * x; }
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point rotate(double alpha) {
    return Point(cos(alpha) * x - sin(alpha) * y,
                 sin(alpha) * x + cos(alpha) * y);
  }
  double kc() { return sqrt(x * x + y * y); }
  double operator*(Point A) {
    double s, ss;
    s = A.x * x + A.y * y;
    ss = A.kc() * kc();
    return acos(s / ss);
  }
  void print() { cout << x << " " << y << endl; }
} g, b, m;
double dis(Point A, Point B) { return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y)); }
struct line {
  double a, b, c;
  line() {}
  line(double a, double b, double c) : a(a), b(b), c(c) {}
} d, d1;
double vg, vb, r, R, res;
bool inside(Point A, Point B, Point C) {
  double dst1 = dis(A, B);
  double dst2 = dis(B, C);
  double dst3 = dis(A, C);
  return (abs(dst1 + dst2 - dst3) <= eps);
}
Point giao(line A, line B) {
  A.c = -A.c;
  B.c = -B.c;
  double d = A.a * B.b - A.b * B.a;
  double dx = A.c * B.b - A.b * B.c;
  double dy = A.a * B.c - A.c * B.a;
  return Point(dx / d, dy / d);
}
bool OK(double ttime) {
  double goc = ttime * vg / R;
  Point g2 = g.rotate(goc);
  double x = b.y - g2.y;
  double y = g2.x - b.x;
  double z = x * b.x + y * b.y;
  d = line(x, y, -z);
  d1 = line(y, -x, 0);
  m = giao(d, d1);
  bool flag = true;
  if (m.kc() >= r)
    flag = false;
  else
    flag = inside(g2, m, b);
  double ans;
  if (flag) {
    double total = b * g2;
    double t1 = acos(r / g2.kc());
    double t2 = acos(r / b.kc());
    total -= (t1 + t2);
    ans = r * total;
    ans += sqrt(sqr(g2.kc()) - sqr(r));
    ans += sqrt(sqr(b.kc()) - sqr(r));
    if (ans <= ttime * vb) return true;
  } else {
    ans = dis(g2, b);
    if (ans <= ttime * vb) return true;
  }
  return false;
}
int main() {
  double x, y;
  cin >> x >> y >> vg;
  g = Point(x, y);
  R = sqrt(sqr(x) + sqr(y));
  cin >> x >> y >> vb >> r;
  b = Point(x, y);
  double low, high, mid;
  low = 0;
  high = INF;
  for (int i = 1; i <= 100; i++) {
    mid = (low + high) / 2;
    if (OK(mid))
      res = mid, high = mid;
    else
      low = mid;
  }
  printf("%.17lf", res);
}
