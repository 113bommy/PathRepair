#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0, n;
  double x1, x2, y1, y2, a, b, c;
  scanf("%lf %lf", &x1, &y1);
  scanf("%lf %lf", &x2, &y2);
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf %lf %lf", &a, &b, &c);
    double d = y2 - y1, e = x1 - x2, f = x2 * y1 - x1 * y2;
    double x = (f * b - c * e) / (a * e - d * b),
           y = (d * c - a * f) / (a * e - d * b);
    if (min(x1, x2) < x && max(x1, x2) > x && min(y1, y2) < y &&
        max(y1, y2) > y)
      ans++;
  }
  printf("%I64d\n", ans);
  return 0;
}
