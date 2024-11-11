#include <bits/stdc++.h>
int n;
int x[60001], v[60001];
static long double min(long double a, long double b) { return a < b ? a : b; }
long double cost(long double p) {
  long double max = fabsl(p - x[0]) / v[0], t;
  int i;
  for (i = 1; i < n; i++) {
    t = fabsl(p - x[i]) / v[i];
    if (t > max) max = t;
  }
  return max;
}
double bin_search(long double l, long double r) {
  long double c = 0, t, t2, t3;
  while (fabsl(l - r) > 10e-7) {
    t = cost((3 * l + r) / 4);
    t2 = cost((l + r) / 2);
    t3 = cost((l + 3 * r) / 4);
    if (t < t2 && t < t3) {
      r = (l + r) / 2;
      c = t;
    } else if (t3 < t && t3 < t2) {
      l = (l + r) / 2;
      c = t3;
    } else {
      c = t2;
      l = (3 * l + r) / 4;
      r = (l + 3 * r) / 4;
    }
  }
  return c;
}
int main(void) {
  int i, maxx = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", x + i);
    if (x[i] > maxx) maxx = x[i];
  }
  for (i = 0; i < n; i++) scanf("%d", v + i);
  printf("%.16lf\n", bin_search(1, maxx));
  return 0;
}
