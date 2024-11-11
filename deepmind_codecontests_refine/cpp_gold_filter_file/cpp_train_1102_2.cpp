#include <bits/stdc++.h>
int a, b;
int main() {
  int Test;
  for (scanf("%d", &Test); Test; --Test) {
    scanf("%d%d", &a, &b);
    if (b == 0) {
      printf("%.6lf\n", 1.0);
      continue;
    }
    if (a == 0) {
      printf("%.6lf\n", 0.5);
      continue;
    }
    double s1 = (double)a * ((double)b * 2.0 + (double)a / 4.0) / 2.0;
    if ((double)a / 4.0 > b) {
      s1 -= ((double)a / 4.0 - (double)b) * ((double)a - 4.0 * (double)b) / 2.0;
    }
    double s2 = (double)a * 2.0 * (double)b;
    printf("%.6lf\n", s1 / s2);
  }
  return 0;
}
