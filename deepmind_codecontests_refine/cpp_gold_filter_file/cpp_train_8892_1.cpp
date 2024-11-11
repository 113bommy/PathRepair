#include <bits/stdc++.h>
int main() {
  double a, d;
  int n;
  scanf("%lf %lf %d", &a, &d, &n);
  long long m, i;
  for (i = 1; i <= n; ++i) {
    double x = d * i;
    m = (x / a);
    if (m % 4 == 0)
      printf("%.10lf %.10lf\n", x - m * a, 0.0);
    else if (m % 4 == 1)
      printf("%.10lf %.10lf\n", a, x - m * a);
    else if (m % 4 == 2)
      printf("%.10lf %.10lf\n", a - (x - m * a), a);
    else
      printf("%.10lf %.10lf\n", 0.0, a - (x - m * a));
  }
  return 0;
}
