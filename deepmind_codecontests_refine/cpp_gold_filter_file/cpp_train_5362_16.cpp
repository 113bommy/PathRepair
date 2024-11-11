#include <bits/stdc++.h>
double eps = 1e-6;
double X, Y;
int VMax, T;
int Vx, Vy, Wx, Wy;
double length(double x, double y) { return sqrtl(x * x + y * y); }
double test(double time) {
  double x;
  double y;
  if (time <= T) {
    x = time * Vx;
    y = time * Vy;
  } else {
    x = T * Vx + (time - T) * Wx;
    y = T * Vy + (time - T) * Wy;
  }
  return length(X - x, Y - y) > 1.0 * VMax * time;
}
double search_time(double time) {
  double ls = 0;
  double ld = time;
  while (ld - ls >= eps) {
    double mid = ls + (ld - ls) / 2;
    if (test(mid))
      ls = mid;
    else
      ld = mid;
  }
  return ld;
}
int main() {
  int x, y;
  scanf(
      "%d%d%lf%lf"
      "%d%d"
      "%d%d%d%d",
      &x, &y, &X, &Y, &VMax, &T, &Vx, &Vy, &Wx, &Wy);
  X -= x;
  Y -= y;
  printf("%.12lf\n", search_time(100000000.0));
  return 0;
}
