#include <bits/stdc++.h>
using namespace std;
struct T {
  double x, y;
};
T ball;
double g1, g2, r, h;
double ll, rr, eps = 1e-8;
int main() {
  scanf("%lf%lf%lf%lf%lf%lf", &g1, &g2, &h, &ball.x, &ball.y, &r);
  ll = 0;
  rr = ball.x;
  while (rr - ll > eps) {
    double m = (ll + rr) / 2;
    double xl = m - (ball.x - m);
    double a, b, c;
    a = ball.y - (h - r);
    b = m - xl;
    c = -a * m - b * (h - r);
    double yl = -c / b;
    if (yl <= g1)
      rr = m;
    else if (yl >= g2)
      ll = m;
    else {
      if ((b * g2 + c) / sqrt(a * a + b * b) <= r)
        ll = m;
      else if (yl - r <= g1)
        rr = m;
      else {
        printf("%.10lf", m);
        return 0;
      }
    }
  }
  printf("-1");
  return 0;
}
