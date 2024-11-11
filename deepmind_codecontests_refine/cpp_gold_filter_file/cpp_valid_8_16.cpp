#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    double a;
    scanf("%lf", &a);
    double s = round(a / 3);
    printf("%.0f %.0f\n", a - (s * 2), s);
  }
  return 0;
}
