#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n < 5) {
    puts("No solution");
    return 0;
  }
  double alpha = 2 * M_PI / n;
  double sa = sin(alpha), ca = cos(alpha);
  double dx = 0, dy = 1, x = 0, y = 0, r = 500;
  for (int i = 0; i < n - 2; i++) {
    printf("%.20lf %.20lf\n", x, y);
    x = x + r * dx;
    y = y + r * dy;
    r += 0.01;
    double ndx = ca * dx - sa * dy;
    dy = sa * dx + ca * dy;
    dx = ndx;
  }
  printf("%.20lf %.20lf\n", x, y);
  double l = 1;
  r = 1000;
  double sv = cos(M_PI - alpha);
  for (int i = 0; i < 100; i++) {
    double m = (l + r) * 0.5;
    double lsx = x + m * dx, lsy = y + m * dy;
    double b = hypot(lsx, lsy), c = hypot(m * dx, m * dy), a = hypot(x, y);
    double ang = (b * b + c * c - a * a) / (2 * b * c);
    if (ang > sv)
      r = m;
    else
      l = m;
  }
  x += l * dx;
  y += l * dy;
  printf("%.20lf %.20lf\n", x, y);
  return 0;
}
