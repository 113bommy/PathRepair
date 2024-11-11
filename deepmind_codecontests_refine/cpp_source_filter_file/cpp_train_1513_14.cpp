#include <bits/stdc++.h>
int main() {
  double x, t;
  long int n;
  scanf("%ld %lf", &n, &t);
  x = pow(1.000000011, t);
  printf("%.20lf", n * x);
  return 0;
}
