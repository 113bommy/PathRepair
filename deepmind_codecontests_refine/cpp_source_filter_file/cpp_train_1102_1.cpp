#include <bits/stdc++.h>
int main() {
  int i, t;
  while (scanf("%d", &t) != EOF) {
    long a, b;
    for (i = 0; i < t; i++) {
      scanf("%ld%ld", &a, &b);
      if (a == 0 && b == 0)
        printf("0.0\n");
      else if (a == 0 && b != 0)
        printf("0.5\n");
      else if (a != 0 && b == 0)
        printf("1.0\n");
      else {
        double ans;
        if (a >= 4 * b)
          ans = 1 - (double)b / a;
        else
          ans = 0.5 + (double)a / (16 * b);
        printf("%.10lf\n", ans);
      }
    }
  }
  return 0;
}
