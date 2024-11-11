#include <bits/stdc++.h>
int n, k;
int a[1000];
double fn(double d) {
  double q;
  int i;
  q = 0;
  for (i = (0); i < (n); i++) {
    if (a[i] > d)
      q += (a[i] - d) * (1 - (double)k / 100);
    else
      q -= d - a[i];
  }
  return q;
}
double bsearchzero(double t1, double t2) {
  double tm;
  if (fn(t1) > fn(t2)) {
    tm = t1;
    t1 = t2;
    t2 = tm;
  }
  while (fabs(t2 - t1) > 1e-8) {
    tm = (t1 + t2) / 2;
    if (fn(tm) < 0)
      t1 = tm;
    else
      t2 = tm;
  }
  return (t1 + t2) / 2;
}
int main() {
  int i, s;
  scanf("%d %d", &n, &k);
  s = 0;
  for (i = (0); i < (n); i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  printf("%.8lf\n", bsearchzero(0, (double)s / n));
  return 0;
}
