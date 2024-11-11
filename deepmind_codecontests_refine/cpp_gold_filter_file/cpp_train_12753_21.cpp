#include <bits/stdc++.h>
int main() {
  int n, a, b;
  double x, y;
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);
  y = (double)n / (a + b);
  x = y * (double)a;
  printf("%.12lf", x);
  return 0;
}
