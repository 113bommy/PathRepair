#include <bits/stdc++.h>
int main() {
  double s, a, b, c, x;
  while (~scanf("%lf%lf%lf%lf", &s, &a, &b, &c)) {
    if (s < 1 || a + b + c < 1) {
      a = 0;
      b = 0;
      c = 0;
      s = 1;
      x = 1;
    } else
      x = (a + b + c) / s;
    printf("%.10f %.10f %.10f\n", a / x, b / x, c / x);
  }
  return 0;
}
