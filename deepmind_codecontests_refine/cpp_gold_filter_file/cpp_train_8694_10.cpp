#include <bits/stdc++.h>
int main() {
  int a, b, c;
  double p, q;
  scanf("%d %d %d", &a, &b, &c);
  p = (double)(-b + sqrt(b * b - 4 * a * c)) / (double)(2 * a);
  q = (double)(-b - sqrt(b * b - 4 * a * c)) / (double)(2 * a);
  if (p > q)
    printf("%lf\n%lf", p, q);
  else
    printf("%lf\n%lf", q, p);
  return 0;
}
