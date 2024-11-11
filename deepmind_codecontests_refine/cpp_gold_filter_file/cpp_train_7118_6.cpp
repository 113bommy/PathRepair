#include <bits/stdc++.h>
int m, n;
double h, w, x, y, z, a, b, c, ans;
void swap(double *p, double *q) {
  double s = *p;
  *p = *q;
  *q = s;
}
int main() {
  int i, j, k;
  scanf("%lf%lf%lf", &w, &h, &a);
  if (a > 90) a = 180 - a;
  if (h > w) swap(&w, &h);
  a = a * 2 * acos(-1) / 360;
  if (2 * atan(h / w) > a) {
    x = (h - w) / (sin(a) - cos(a) - 1);
    y = (w + h) / (cos(a) + sin(a) + 1);
    b = (x + y) / 2;
    c = (y - x) / 2;
    ans = h * w - b * b * cos(a) * sin(a) - c * c * cos(a) * sin(a);
  } else {
    ans = h * h / sin(a);
  }
  printf("%.8lf\n", ans);
  getchar();
  getchar();
}
