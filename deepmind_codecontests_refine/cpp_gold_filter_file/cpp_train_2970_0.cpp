#include <bits/stdc++.h>
int main() {
  double n, r, a, b, c;
  scanf("%lf %lf", &n, &r);
  b = 3.14159265359;
  a = sin(b / n);
  c = 1 + 2 * cos(b / n);
  printf("%0.12lf\n", n * r * r * a / c);
  return 0;
}
