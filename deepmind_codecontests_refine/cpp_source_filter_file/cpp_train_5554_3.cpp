#include <bits/stdc++.h>
const double pi = 3.1415926535897932384;
double sqr(double a) { return a * a; }
double abbs(double a) {
  if (a < 0)
    return -a;
  else
    return a;
}
int main() {
  double xa, ya, va, xb, yb, vb, ra, rb, dgr, xc, yc, xd, yd, l, r, mid, dis,
      dgr1, dgr2, dgr3, dgr4;
  scanf("%lf%lf%lf", &xa, &ya, &va);
  ra = sqrt(xa * xa + ya * ya);
  scanf("%lf%lf%lf%lf", &xb, &yb, &vb, &rb);
  for (l = 0, r = 18.4; l < r - 1e-11;) {
    mid = (l + r) / 2;
    dgr = mid * va / ra;
    xc = cos(dgr) * xa - sin(dgr) * ya, yc = sin(dgr) * xa + cos(dgr) * ya;
    xd = yc - yb, yd = -(xc - xb);
    dis = abbs(xc * yb - xb * yc) / sqrt(sqr(xd) + sqr(yd));
    if (((xc - xd) * yc - xc * (yc - yd)) * ((xb - xd) * yb - xb * (yb - yd)) >
            0 ||
        dis > rb) {
      dis = sqrt(sqr(xc - xb) + sqr(yc - yb));
    } else {
      dis =
          sqrt(sqr(xc) + sqr(yc) - sqr(rb)) + sqrt(sqr(xb) + sqr(yb) - sqr(rb));
      dgr1 = (sqr(xc) + sqr(yc) + sqr(xb) + sqr(yb) - sqr(xc - xb) -
              sqr(yc - yb)) /
             (2 * sqrt(sqr(xc) + sqr(yc)) * sqrt(sqr(xb) + sqr(yb)));
      dgr2 = rb / sqrt(sqr(xc) + sqr(yc));
      dgr3 = rb / sqrt(sqr(xb) + sqr(yb));
      dgr4 = acos(dgr1) - acos(dgr2) - acos(dgr3);
      dis += dgr4 * rb;
    }
    if (dis > vb * mid)
      l = mid;
    else
      r = mid;
  }
  printf("%.9lf\n", l);
  return 0;
}
