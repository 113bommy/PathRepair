#include <bits/stdc++.h>
int main() {
  double x, y;
  scanf("%lf %lf", &x, &y);
  if (y > x) {
    printf("-1");
    return 0;
  }
  double h, h1, H, H1;
  h = (x + y) / 2;
  h1 = (x + y) / (2 * y);
  h1 = floor(h1);
  h = h / h1;
  printf("%lf", h);
  return 0;
}
