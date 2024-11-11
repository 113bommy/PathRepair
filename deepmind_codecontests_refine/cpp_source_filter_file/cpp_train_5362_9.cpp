#include <bits/stdc++.h>
using namespace std;
double x[3], y[3];
double v_max, t;
double vx[3], vy[3];
bool judge(double m) {
  double dx, dy;
  if (m > t) {
    dx = x[1] + vx[1] * t + vx[2] * (m - t);
    dy = y[1] + vy[1] * t + vy[2] * (m - t);
  } else {
    dx = x[1] + vx[1] * m;
    dy = x[1] + vy[1] * m;
  }
  if (m * v_max * m * v_max <
      ((x[2] - dx) * (x[2] - dx) + (y[2] - dy) * (y[2] - dy)))
    return false;
  return true;
}
int main() {
  scanf("%lf %lf %lf %lf", &x[1], &y[1], &x[2], &y[2]);
  scanf("%lf %lf", &v_max, &t);
  scanf("%lf %lf %lf %lf", &vx[1], &vy[1], &vx[2], &vy[2]);
  int cou = 10000;
  double l, r, m;
  l = 0;
  r = 1e8;
  while (cou) {
    m = (l + r) / 2;
    if (judge(m))
      r = m;
    else
      l = m;
    cou--;
  }
  printf("%.18f\n", r);
  return 0;
}
