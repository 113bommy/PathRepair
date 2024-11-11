#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int sgn(double t) { return t > 1e-6 ? 1 : (t < -1e-6 ? -1 : 0); }
struct P {
  double x, y;
  P() {}
  P(double _x, double _y) : x(_x), y(_y) {}
  P operator+(const P& a) const { return P(x + a.x, y + a.y); }
  P operator-(const P& a) const { return P(x - a.x, y - a.y); }
  P operator*(const double& a) const { return P(x * a, y * a); }
  P operator/(const double& a) const { return P(x / a, y / a); }
  P left() { return P(-y, x); }
  P right() { return P(y, -x); }
  P cut(double a) {
    a /= sqrt(x * x + y * y);
    return P(x * a, y * a);
  }
  P rotate_left(double ang) const {
    double c = cos(ang), s = sin(ang);
    return P(x * c - y * s, y * c + x * s);
  }
  P rotate_right(double ang) const {
    double c = cos(ang), s = sin(ang);
    return P(x * c + y * s, y * c - x * s);
  }
  bool operator==(const P& a) const {
    return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
  }
  bool operator<(const P& a) const {
    return sgn(x - a.x) == 0 ? sgn(y - a.y) < 0 : x < a.x;
  }
};
double cross(const P& a, const P& b, const P& c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double squ(const double& t) { return t * t; }
double Dist(const P& a, const P& b) {
  return sqrt(squ(b.x - a.x) + squ(b.y - a.y));
}
bool check(const int& n, const double& A) {
  int tmp = A / (pi / n) + 0.1;
  return sgn(tmp * pi / n - A) == 0;
}
int main() {
  P p[3];
  for (int i = 0; i < 3; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  double a = Dist(p[1], p[2]);
  double b = Dist(p[2], p[0]);
  double c = Dist(p[0], p[1]);
  double A = acos((b * b + c * c - a * a) / (2 * b * c));
  double B = acos((c * c + a * a - b * b) / (2 * c * a));
  double C = acos((a * a + b * b - c * c) / (2 * a * b));
  double s = fabs(cross(p[0], p[1], p[2])) / 2;
  double r = a * b * c / 4 / s;
  int n;
  for (n = 3; n <= 100; n++)
    if (check(n, A) && check(n, B) && check(n, C)) break;
  double res = n * r * r * sin(2 * pi / n) / 2;
  printf("%.8lf\n", res);
  return 0;
}
