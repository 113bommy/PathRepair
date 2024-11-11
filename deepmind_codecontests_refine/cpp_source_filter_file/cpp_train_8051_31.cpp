#include <bits/stdc++.h>
int main() {
  int n, i, c = 0, p;
  double a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p);
    c = c + p;
  }
  a = (c * 1.0) / n;
  printf("%.6lf", a);
  return 0;
}
