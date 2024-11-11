#include <bits/stdc++.h>
using namespace std;
int Sig(double a) { return a < -1e-10 ? -1 : a > 1e-10; }
struct Point {
  double x, y, z;
  Point() {}
  Point(double x0, double y0, double z0) : x(x0), y(y0), z(z0) {}
  void in() { scanf("%lf%lf%lf", &x, &y, &z); }
  Point operator*(double h) { return Point(x * h, y * h, z * h); }
  Point operator+(Point h) { return Point(x + h.x, y + h.y, z + h.z); }
  Point operator-(Point h) { return Point(x - h.x, y - h.y, z - h.z); }
  double len2() const { return x * x + y * y + z * z; }
  double len() const { return sqrt(len2()); }
  Point turnlen(double l) const {
    double r = l / len();
    return Point(x * r, y * r, z * r);
  }
} p[10010];
int n;
double t[10010];
Point at(double m) {
  Point o;
  if (Sig(m) == 0)
    o = p[0];
  else {
    for (int i = 0; i <= n; i++) {
      if (Sig(m - t[i]) <= 0) {
        m -= t[i - 1];
        o = p[i - 1] + (p[i] - p[i - 1]) * (1.0 / (t[i] - t[i - 1])) * m;
        break;
      }
    }
  }
  return o;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) p[i].in();
  double v1, v2;
  scanf("%lf %lf", &v1, &v2);
  Point o;
  o.in();
  t[0] = 0;
  for (int i = 1; i <= n; i++) t[i] = t[i - 1] + (p[i] - p[i - 1]).len() / v2;
  double l = 0;
  double r = t[n];
  while (r - l > 1e-10) {
    double m = (l + r) / 2;
    Point now = at(m);
    if (Sig((o - now).len() - m * v1) <= 0)
      r = m;
    else
      l = m;
  }
  if (Sig(r - t[n]) == 0) {
    Point now = at(r);
    if (Sig((o - now).len() - r * v1) <= 0) {
      printf("YES\n");
      printf("%.8f\n", r);
      o = at(r);
      printf("%.8f %.8f %.8f\n", o.x, o.y, o.z);
    } else
      printf("NO\n");
  } else {
    printf("YES\n");
    printf("%.8f\n", r);
    o = at(r);
    printf("%.8f %.8f %.8f\n", o.x, o.y, o.z);
  }
  return 0;
}
