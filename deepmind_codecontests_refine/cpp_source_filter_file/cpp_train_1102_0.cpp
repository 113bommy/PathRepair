#include <bits/stdc++.h>
int main() {
  int t, i;
  double a, b;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%lf%lf", &a, &b);
    if (a)
      if (a / 4 > b)
        printf("%.6lf\n", (a - b) / a);
      else
        printf("%.6lf\n", (a / 4 + b) / (4 * b) + 0.25);
    else if (b)
      printf("1");
    else
      printf("0.5");
  }
  return 0;
}
