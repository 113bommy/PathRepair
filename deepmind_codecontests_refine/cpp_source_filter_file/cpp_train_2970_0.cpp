#include <bits/stdc++.h>
int main() {
  double n, r, a, pi, c;
  scanf("%lf %lf", &n, &r);
  pi = 3.14159265359;
  a = sin(pi / n);
  c = 1 + 2 * cos(pi / n);
  printf("%0.12lf\n", n * r * r * a / c);
  return 0;
}
