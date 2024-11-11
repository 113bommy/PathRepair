#include <bits/stdc++.h>
using namespace std;
double a, b, l, w, wl, wr, ans, u, ul, ur, u1, u2;
double v(double ax, double ay, double bx, double by, double cx, double cy) {
  return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}
double f(double w, double u) {
  double vx, vy, ax, ay, bx, by, xi, xj, x, ox, oy;
  vx = cos(u);
  vy = sin(u);
  ax = vx * w;
  ay = vy * w;
  bx = ax - vy * l;
  by = ay + vx * l;
  ox = -vy * l;
  oy = vx * l;
  if (v(0, a, bx, by, b, a) >= 0) return -u;
  xi = 0;
  xj = 1e6;
  for (int it = 0; it < 75; ++it) {
    x = (xi + xj) / 2;
    if (v(ax + x, ay, bx + x, by, b, a) >= 0)
      xj = x;
    else
      xi = x;
  }
  x = (xi + xj) / 2;
  return b - (ox + x);
}
int main() {
  cin >> a >> b >> l;
  ans = 0.0;
  if (l <= b)
    ans = ((ans) > (a) ? (ans) : (a));
  else {
    if (l <= a)
      ans = ((ans) > (b) ? (ans) : (b));
    else {
      wl = 0;
      wr = ((a) < (b) ? (a) : (b)) + 1;
      for (int it1 = 0; it1 < 75; ++it1) {
        w = (wl + wr) / 2;
        ul = 0;
        ur = 3.14159265358979323846 / 2;
        for (int it2 = 0; it2 < 150; ++it2) {
          u1 = ul + (ur - ul) / 3;
          u2 = ur - (ur - ul) / 3;
          if (f(w, u1) > f(w, u2))
            ur = u2;
          else
            ul = u1;
        }
        u = (u1 + u2) / 2;
        if (f(w, u) > b)
          wr = w;
        else
          wl = w;
      }
      ans = ((ans) > (w) ? (ans) : (w));
    }
  }
  ans = ((ans) < (l) ? (ans) : (l));
  if (((ans) > 0 ? (ans) : -(ans)) < 1e-9)
    printf("My poor head =(\n");
  else
    printf("%.15lf\n", ans);
  return 0;
}
