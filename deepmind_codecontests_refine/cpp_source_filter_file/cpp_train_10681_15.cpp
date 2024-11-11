#include <bits/stdc++.h>
int f, h;
int x[55], y[55];
double cacu(int x, int y) {
  if (x == 0 || y == 0) return 0;
  if (x < 0) x = -x, y = -y;
  if (y < 0) return 0;
  if (x > y) x ^= y, y ^= x, x ^= y;
  double t = x * (f + h) / double(f - h);
  if (t <= y) return (x + t) * h;
  return (x + t) * h -
         (t - y) * (t - y) / (t - y + y * (f + h) / double(f - h) - x) * h;
}
int main() {
  int n, i, j;
  double ans = 0;
  scanf("%d%d%d", &n, &h, &f);
  for (y[n] = 0, i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
    ans += 4 * (y[i] - x[i]) * f / double(f - h) * h;
    if (x[i] < 0 && y[i] > 0) {
      x[n] = 0, y[n] = y[i];
      y[i] = 0;
    }
  }
  if (y[n]) n++;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      ans -= cacu(y[i], y[j]) + cacu(x[i], x[j]) - cacu(x[i], y[j]) -
             cacu(x[j], y[i]);
  printf("%.8lf\n", ans);
  return 0;
}
