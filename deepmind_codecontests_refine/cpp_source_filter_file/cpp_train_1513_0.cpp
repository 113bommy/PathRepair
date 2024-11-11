#include <bits/stdc++.h>
int main() {
  double x, t;
  long int n;
  scanf("%d %lf", &n, &t);
  x = pow(1.000000011, t);
  printf("%.12lf", n * x);
  return 0;
}
