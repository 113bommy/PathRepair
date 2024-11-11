#include <bits/stdc++.h>
double calculate(int x, int y) {
  if (y > x) return -1;
  if (y == x) return x;
  int n;
  double r1, r2;
  n = (int)(x - y) / (2 * y);
  if (n == 0)
    r1 = 1000000001;
  else
    r1 = (x - y) / (2.0 * n);
  n = (int)(x + y) / (2 * y);
  r2 = (x + y) / (2.0 * n);
  if (r1 < r2)
    return r1;
  else
    return r2;
}
int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  double ret = calculate(x, y);
  if (ret == -1)
    printf("-1");
  else
    printf("%lf", ret);
  return 0;
}
