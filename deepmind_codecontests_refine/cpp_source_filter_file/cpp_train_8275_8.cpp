#include <bits/stdc++.h>
int a, v, l, d, w;
double t;
int main() {
  scanf("%d%d%d%d%d", &a, &v, &l, &d, &w);
  if (w > v) w = v;
  if (2 * a * d > w * w) {
    double t1 = sqrt((1.0 * w * w / a / a + 2.0 * d / a) / 2);
    if (a * t1 <= v)
      t = 2 * sqrt((1.0 * w * w / a / a + 2.0 * d / a) / 2) - 1.0 * w / a;
    else
      t = 1.0 * v / a + 1.0 * (v - w) +
          (d - v * v / 2.0 / a - (v * v - w * w) / 2.0 / a) / v;
    if (1.0 * (v * v - w * w) / 2 / a > l - d)
      t += (sqrt(w * w + 2 * a * (l - d)) - w) / a;
    else
      t += 1.0 * (v - w) / a + (l - d - (v * v - w * w) / (2.0 * a)) / v;
  } else if (2 * a * l > v * v)
    t = 1.0 * v / a + (l - v * v / 2.0 / a) / v;
  else
    t = sqrt(2.0 * l / a);
  printf("%.12lf", t);
  return 0;
}
