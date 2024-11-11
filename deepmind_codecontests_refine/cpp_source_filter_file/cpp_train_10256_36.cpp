#include <bits/stdc++.h>
int n, q, p;
int a[100010];
int b[100010];
int max;
double ans;
long double f(long double x) {
  int i;
  long double y = 1;
  for (i = 0; i < n; i++) {
    if ((1 - x * a[i]) / b[i] < y) {
      y = (1 - x * a[i]) / b[i];
    }
  }
  return p * x + q * y;
}
int main() {
  int i;
  scanf("%d %d %d", &n, &p, &q);
  max = 0;
  for (i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    if (b[i] > max) max = b[i];
  }
  long double l = 0;
  long double r = 1.0 / max;
  long double tl, tr;
  for (i = 0; i < 200; i++) {
    tl = (2 * l + r) / 3;
    tr = (2 * r + l) / 3;
    if (f(tl) > f(tr)) {
      r = tr;
    } else {
      l = tl;
    }
  }
  printf("%.15f\n", (double)f((l + r) / 2));
  return 0;
}
