#include <bits/stdc++.h>
using namespace std;
struct edge {
  double x, y, ang;
  bool operator<(const edge& p) const { return ang < p.ang; }
} a[100008];
int main() {
  int i, j, k, l, n, m, t, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &a[i].x, &a[i].y);
    if (a[i].x < 0 && a[i].y == 0) {
      a[i].ang = 180.00;
      continue;
    }
    a[i].ang = atan(a[i].y / a[i].x) * 180 / 3.14159265359;
    if (a[i].x < 0 && a[i].y >= 0)
      a[i].ang = 180.00 + a[i].ang;
    else if (a[i].x < 0 && a[i].y < 0)
      a[i].ang = 180.00 + a[i].ang;
    else if (a[i].x >= 0 && a[i].y < 0)
      a[i].ang = 360.00 + a[i].ang;
    if (a[i].ang == 360.00) a[i].ang = 0.00;
  }
  if (n == 1) {
    printf("%lf\n", 0.00);
    return 0;
  }
  if (n == 2) {
    printf("%.10lf\n",
           min(abs(a[0].ang - a[1].ang), 360.00 - abs(a[0].ang - a[1].ang)));
    return 0;
  }
  sort(a, a + n);
  double mi, d;
  mi = 360.00 - abs(a[0].ang - a[n - 1].ang);
  for (i = 0; i < n - 1; i++) {
    d = abs(a[i].ang - a[i + 1].ang);
    if (d > mi) mi = d;
  }
  printf("%.10lf\n", 360.00 - mi);
  return 0;
}
