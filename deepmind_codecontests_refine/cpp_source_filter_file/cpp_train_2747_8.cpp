#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  int num;
};
Point a[200000];
Point u;
int n, m;
bool cmp(Point p, Point q) { return p.x < q.x; }
double dis(Point p, Point q) {
  return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}
double work(int l, int r) {
  return dis(a[r], a[l]) + min(dis(u, a[l]), dis(u, a[r]));
}
double solve(int l, int r) {
  return dis(a[r], a[l]) +
         min(dis(a[r], u) + dis(a[m], a[l]), dis(a[l], u) + dis(a[m], a[r]));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i].x);
    a[i].num = i;
    a[i].y = 0;
  }
  scanf("%lf%lf", &u.x, &u.y);
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++)
    if (a[i].num == m) {
      m = i;
      break;
    }
  double ans = 1e9;
  if (m == n + 1)
    ans = work(1, n);
  else {
    ans = solve(1, n);
    for (int i = 1; i <= n; i++) {
      if (i != 1) ans = min(ans, solve(1, i) + work(i + 1, n));
      if (i != n) ans = min(ans, solve(i, n) + work(1, i - 1));
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
