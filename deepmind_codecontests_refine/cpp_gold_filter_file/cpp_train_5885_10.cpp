#include <bits/stdc++.h>
int main() {
  double l3, l4, l5;
  scanf("%lf%lf%lf", &l3, &l4, &l5);
  l3 = (sqrt(2) * (l3 * l3 * l3)) / 12;
  l4 = (sqrt(2) * (l4 * l4 * l4)) / 6;
  l5 = ((5 + sqrt(5)) * (l5 * l5 * l5)) / 24;
  printf("%.10f\n", l3 + l4 + l5);
  return 0;
}
