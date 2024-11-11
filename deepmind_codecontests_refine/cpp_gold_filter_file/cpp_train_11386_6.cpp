#include <bits/stdc++.h>
const double EPS = 1e-8;
struct unit {
  double x, y;
  unit(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  double len() { return sqrt(x * x + y * y); }
  double operator*(const unit& a) { return x * a.y - y * a.x; }
};
bool eq(double a, double b) { return (fabs(a - b) < EPS); }
int main() {
  double y1, y2, yw, xb, yb, r;
  while (~scanf("%lf %lf %lf %lf %lf %lf", &y1, &y2, &yw, &xb, &yb, &r)) {
    double dy = (y1 + r);
    double y = (yw - r) + (yw - r - yb);
    unit a1(0, y1 - dy), a2(0, y2 - dy);
    unit b(xb, y - dy);
    if (fabs(a2 * b / b.len()) < r)
      puts("-1");
    else
      printf("%.10lf\n", xb * (yw - r - dy) / (y - dy));
  }
}
