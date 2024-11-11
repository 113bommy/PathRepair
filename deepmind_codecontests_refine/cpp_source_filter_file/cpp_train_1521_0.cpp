#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
struct Circle {
  double x;
  double y;
  double r;
  double area;
  int cnt;
};
Circle a[1005];
bool Compare(Circle p, Circle q) { return p.area < q.area; }
bool Distance(int i, int j) {
  return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) +
              (a[i].y - a[j].y) * (a[i].y - a[j].y));
}
bool Inside(int i, int j) { return Distance(i, j) <= a[j].r; }
int main() {
  int n, i, j;
  double ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
    a[i].area = pi * a[i].r * a[i].r;
  }
  sort(a + 1, a + n + 1, Compare);
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++) {
      if (Inside(i, j)) a[i].cnt++;
    }
  ans = 0;
  for (i = 1; i <= n; i++) {
    if (a[i].cnt == 0 || a[i].cnt % 2 == 1)
      ans += a[i].area;
    else
      ans -= a[i].area;
  }
  printf("%.10lf\n", ans);
  return 0;
}
