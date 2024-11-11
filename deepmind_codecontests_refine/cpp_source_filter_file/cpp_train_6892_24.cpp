#include <bits/stdc++.h>
int main() {
  int t1, t2, x1, x2, t0;
  int y1, ans1, ans2;
  double m;
  double sofar;
  scanf("%d%d%d%d%d", &t1, &t2, &x1, &x2, &t0);
  if (t0 == t2) {
    if (t0 == t1)
      printf("%d %d\n", x1, x2);
    else
      printf("0 %d\n", x2);
    return 0;
  }
  m = -(((double)t0) - ((double)t1)) / (((double)t0) - ((double)t2));
  ans1 = ans2 = -1;
  sofar = 1.0e+100;
  for (y1 = 0; y1 <= x1; y1++) {
    double opt = m * y1;
    int y2 = (int)opt;
    double t;
    double q;
    if (opt > (double)y2) y2++;
    if (y2 > x2) break;
    t = (((double)t1) * ((double)y1)) + (((double)t2) * ((double)y2));
    t /= (double)(y1 + y2);
    q = t - ((double)t0);
    if (q <= sofar) {
      sofar = q;
      ans1 = y1;
      ans2 = y2;
    }
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
