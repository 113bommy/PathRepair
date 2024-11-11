#include <bits/stdc++.h>
double a, b, c, d, x, y;
int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  x = a / b;
  y = c / d;
  printf("%lf", x / (1.0 - (1.0 - x) * (1.0 - y)));
}
