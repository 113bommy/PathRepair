#include <bits/stdc++.h>
double solve(double x, double n) {
  double a = atan(1) * 4 / n;
  double h = sqrt(3 * tan(a) * tan(a) - 1) / tan(a);
  double s = n / tan(a);
  return pow(x / 2, 3) * h * s / 3;
}
int main() {
  double ans = 0;
  for (int i = 3; i <= 5; i++) {
    double x;
    scanf("%lf", &x);
    ans += solve(x, i);
  }
  printf("%.10f\n", ans);
}
