#include <bits/stdc++.h>
double xp, yp, vp;
double R, angel;
double x, y, v, r;
double min(double x, double y) { return x < y ? x : y; }
double max(double x, double y) { return x > y ? x : y; }
double init(double x1, double y1) {
  double tmp;
  if (fabs(x1 - 0) <= 0.0000000001 || fabs(y1 - 0) <= 0.0000000001) {
    if (fabs(x1 - 0) <= 0.0000000001 && y1 < 0) {
      return 3.0 * 3.1415926535897939 / 2.0;
    } else if (fabs(x1 - 0) <= 0.0000000001 && y1 > 0) {
      return 3.1415926535897939 / 2.0;
    } else if (fabs(y1 - 0) <= 0.0000000001 && x1 > 0) {
      return 0;
    } else if (fabs(y1 - 0) <= 0.0000000001 && x1 < 0) {
      return 3.1415926535897939;
    }
  }
  if (x1 > 0) {
    tmp = acos(x1 / sqrt(x1 * x1 + y1 * y1));
    if (y1 > 0)
      return tmp;
    else if (y1 < 0) {
      tmp = 2 * 3.1415926535897939 - tmp;
      return tmp;
    }
  } else {
    tmp = acos((-x1) / sqrt(x1 * x1 + y1 * y1));
    if (y1 > 0) {
      tmp = 3.1415926535897939 - tmp;
      return tmp;
    } else {
      tmp = 3.1415926535897939 + tmp;
      return tmp;
    }
  }
}
double judge(double t) {
  double x_now, y_now;
  double angel_sum;
  double angel_now, T;
  double len;
  double L;
  int k;
  angel_now = angel + (vp * t) / (R);
  k = 1;
  while (angel_now > 2.0 * 3.1415926535897939 * k) k *= 10;
  k /= 10;
  while (k) {
    while (angel_now > 2.0 * 3.1415926535897939 * k)
      angel_now -= 2.0 * 3.1415926535897939 * k;
    k /= 10;
  }
  x_now = R * cos(angel_now);
  y_now = R * sin(angel_now);
  L = sqrt((x - x_now) * (x - x_now) + (y - y_now) * (y - y_now));
  T = L / v;
  len = fabs(-(y - y_now) / (x - x_now) * x_now + y_now) /
        sqrt((y - y_now) / (x - x_now) * (y - y_now) / (x - x_now) + 1);
  if (len >= r) return T;
  double x_mid = (((y - y_now) / (x - x_now)) * x_now - y_now) /
                 ((y - y_now) / (x - x_now) - (x_now - x) / (y - y_now));
  if (x_mid <= min(x_now, x) || x_mid >= max(x_now, x))
    return T;
  else {
    T = 0;
    T += sqrt(x_now * x_now + y_now * y_now - r * r) / v;
    T += sqrt(x * x + y * y - r * r) / v;
    angel_sum = fabs(init(x, y) - init(x_now, y_now));
    if (angel_sum > 3.1415926535897939)
      angel_sum = 2 * 3.1415926535897939 - angel_sum;
    angel_sum -= acos(r / sqrt(x * x + y * y));
    angel_sum -= acos(r / sqrt(x_now * x_now + y_now * y_now));
    T += angel_sum * r / v;
    return T;
  }
}
int main() {
  double l1, r1, m;
  double tmp;
  scanf("%lf%lf%lf", &xp, &yp, &vp);
  scanf("%lf%lf%lf%lf", &x, &y, &v, &r);
  R = sqrt(xp * xp + yp * yp);
  angel = init(xp, yp);
  r1 = 1000000;
  l1 = 0;
  while (r1 - l1 > 0.000000001) {
    m = (r1 + l1) / 2;
    tmp = judge(m);
    if (tmp < m)
      r1 = m;
    else
      l1 = m;
  }
  long long st = (long long)(m * 10000000);
  st = st % 10;
  printf("%.9f\n", m);
  return 0;
}
