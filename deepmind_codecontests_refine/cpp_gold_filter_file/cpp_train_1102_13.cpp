#include <bits/stdc++.h>
int main() {
  double a, b;
  double s;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf %lf", &a, &b);
    if (a == 0 && b != 0)
      printf("0.5\n");
    else if (b == 0) {
      printf("1\n");
    } else {
      if (a >= 4 * b) {
        s = 4 * b * 4 * b / 2;
      } else {
        s = a * a / 2 + (4 * b - a) * a;
      }
      printf("%llf\n", (a * 8 * b - s) / (a * 8 * b));
    }
  }
  return 0;
}
