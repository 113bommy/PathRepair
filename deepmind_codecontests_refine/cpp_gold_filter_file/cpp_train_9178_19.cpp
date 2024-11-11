#include <bits/stdc++.h>
int main() {
  double h, l;
  scanf("%lf%lf", &h, &l);
  printf("%.15lf\n", ((h * h + l * l) * 0.5 / h) - h);
  return 0;
}
