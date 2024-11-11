#include <bits/stdc++.h>
int main() {
  int s;
  int a, b, c;
  double x, y, z, p;
  while (scanf("%d", &s) != EOF) {
    scanf("%d %d %d", &a, &b, &c);
    p = 1.0 * (a + b + c) / s;
    if (a + b + c == 0) {
      x = 0, y = 0, z = 0;
      printf("%.10lf %.10lf %.10lf\n", x, y, z);
      continue;
    }
    x = a / p;
    y = b / p;
    z = c / p;
    printf("%.10lf %.10lf %.10lf\n", x, y, z);
  }
  return 0;
}
