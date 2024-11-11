#include <bits/stdc++.h>
int x, y, X, Y, vx, vy, wx, wy, max, t;
double dis(double a, double b, double c, double d) {
  return sqrt((double)(a - c) * (double)(a - c) +
              (double)(b - d) * (double)(b - d));
}
int search(double T) {
  if (T > t)
    return dis(x + vx * t + wx * (T - t), y + vy * t + wy * (T - t), X, Y) >
                   max * T
               ? 0
               : 1;
  else
    return dis(x + vx * T, y + vy * T, X, Y) > max * T ? 0 : 1;
  return 0;
}
int main(void) {
  int k = 1e6;
  double L = 0, R = 1e12, mid;
  scanf("%d%d%d%d%d%d%d%d%d%d", &x, &y, &X, &Y, &max, &t, &vx, &vy, &wx, &wy);
  mid = (L + R) / 2;
  while (k--) {
    if (search(mid))
      R = mid;
    else
      L = mid;
    mid = (L + R) / 2;
  }
  printf("%f\n", mid);
  return 0;
}
