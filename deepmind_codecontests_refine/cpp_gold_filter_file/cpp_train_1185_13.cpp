#include <bits/stdc++.h>
int main() {
  double must1, must2, ans;
  double a, b, c, d;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  must1 = a / b;
  must2 = (1 - c / d) * (1 - a / b);
  ans = must1 / (1 - must2);
  printf("%lf\n", ans);
}
