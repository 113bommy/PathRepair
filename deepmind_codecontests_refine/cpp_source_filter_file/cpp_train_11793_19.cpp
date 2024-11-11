#include <bits/stdc++.h>
int n, R, r;
double x;
int main() {
  scanf("%d%d%d", &n, &R, &r);
  if (n == 1)
    printf("%s\n", R >= r ? "YES" : "NO");
  else {
    x = asin(1. * r / (R - r)) * 2;
    printf("%s\n", (n <= asin(1) * 4 / x) ? "YES" : "NO");
  }
  return 0;
}
