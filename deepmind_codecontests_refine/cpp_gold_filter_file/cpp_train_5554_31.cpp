#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} p, s, O;
double vp, vs, r, dis, alpha;
double square(double x) { return x * x; }
double Dist(point p1, point p2) {
  return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}
point rotate(double T) {
  double theta = T * vp / dis;
  theta += alpha;
  point newp;
  newp.x = cos(theta) * dis;
  newp.y = sin(theta) * dis;
  return newp;
}
int main() {
  double L, R, mid, d1, d2, cxc, T, theta1, theta2, theta3, dc, ans;
  while (scanf("%lf%lf%lf", &p.x, &p.y, &vp) == 3) {
    scanf("%lf%lf%lf%lf", &s.x, &s.y, &vs, &r);
    O.x = 0.0;
    O.y = 0.0;
    dis = Dist(O, p);
    alpha = atan2(p.y, p.x);
    L = 0.0;
    R = 100000.0;
    ans = R;
    while ((R - L) > 1e-8) {
      mid = (L + R) / 2;
      point newp = rotate(mid);
      d1 = Dist(s, O);
      theta1 = acos(r / d1);
      d2 = Dist(newp, O);
      theta2 = acos(r / d2);
      dc = newp.x * s.x + newp.y * s.y;
      theta3 = acos(dc / (d1 * d2));
      if (theta1 + theta2 > theta3) {
        d1 = Dist(s, newp);
        T = d1 / vs;
      } else {
        T = 0.0;
        cxc = sqrt(d1 * d1 - r * r);
        T += cxc / vs;
        cxc = sqrt(d2 * d2 - r * r);
        T += cxc / vs;
        theta3 = theta3 - theta1 - theta2;
        T += r * theta3 / vs;
      }
      if ((mid - T) >= 1e-8) {
        R = mid - 1e-8;
        ans = min(ans, mid);
      } else
        L = mid + 1e-8;
    }
    printf("%.8lf\n", ans);
  }
  return 0;
}
