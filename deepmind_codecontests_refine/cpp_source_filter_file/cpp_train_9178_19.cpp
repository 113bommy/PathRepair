#include <bits/stdc++.h>
int main() {
  long double h, l;
  scanf("%Lf%Lf", &h, &l);
  printf("%.15Lf\n", ((h * h + l * l) * 0.5 / h) - h);
  return 0;
}
