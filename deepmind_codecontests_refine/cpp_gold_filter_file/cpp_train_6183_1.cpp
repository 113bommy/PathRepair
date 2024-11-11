#include <bits/stdc++.h>
int main() {
  int i, j, pl;
  int l, d, v, g, r;
  double re, tm;
  scanf("%d%d%d%d%d", &l, &d, &v, &g, &r);
  re = (double)d / v;
  tm = 0;
  pl = 0;
  while (1) {
    if (pl == 0) {
      if (tm + g > re) break;
      tm += g;
    }
    if (pl == 1) {
      if (tm + r > re) break;
      tm += r;
    }
    pl++;
    pl %= 2;
  }
  if (pl == 0)
    re += (double)(l - d) / v;
  else {
    re = tm + r;
    re += double(l - d) / v;
  }
  printf("%.8lf\n", re);
  return 0;
}
