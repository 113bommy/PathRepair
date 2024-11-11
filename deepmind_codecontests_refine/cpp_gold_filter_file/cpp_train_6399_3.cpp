#include <bits/stdc++.h>
using namespace std;
double x1, x2, yy, y2, x, y, a, b, c, a1, b1, c1;
int n, ans = 0;
int jude() {
  if (x1 < x2) {
    if (x < x1 || x > x2) return 0;
  } else {
    if (x < x2 || x > x1) return 0;
  }
  if (yy < y2) {
    if (y < yy || y > y2) return 0;
  } else {
    if (y < y2 || y > yy) return 0;
  }
  return 1;
}
int xiangjiao() {
  if (a * b1 == b * a1) return 0;
  if (a == 0) {
    y = -c / b;
    x = (-c1 - y * b1) / a1;
  } else if (a1 == 0) {
    y = -c1 / b1;
    x = (-c - y * b) / a;
  } else {
    double u = a1 / a;
    y = (-c1 + u * c) / (b1 - u * b);
    x = (-c1 - y * b1) / a1;
  }
  if (jude()) return 1;
  return 0;
}
int main() {
  scanf("%lf%lf%lf%lf", &x1, &yy, &x2, &y2);
  scanf("%d", &n);
  a1 = yy - y2;
  b1 = -x1 + x2;
  c1 = x1 * y2 - x2 * yy;
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &a, &b, &c);
    if (xiangjiao()) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
