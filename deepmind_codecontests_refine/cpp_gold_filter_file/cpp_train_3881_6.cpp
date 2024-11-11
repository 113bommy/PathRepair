#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const double eps = 1e-8;
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  inline void read() { scanf("%lf%lf", &x, &y); }
  inline bool operator<(const Point &p) const {
    return x < p.x || fabs(x - p.x) <= eps && y < p.y;
  }
  inline bool operator==(const Point &p) const {
    return fabs(x - p.x) <= eps && fabs(y - p.y) <= eps;
  }
} a[N];
int n, k, sum = 0;
vector<Point> ans;
Point Mid_point(Point u, Point v) {
  return Point((u.x + v.x) / 2, (u.y + v.y) / 2);
}
void solve(Point u, Point v) {
  Point mid = Mid_point(u, v);
  int i = 1, j = n, cnt = 0;
  while (i <= j) {
    Point tmp = Mid_point(a[i], a[j]);
    if (tmp == mid)
      i++, j--;
    else {
      cnt++;
      if (tmp < mid)
        i++;
      else
        j--;
    }
  }
  if (cnt <= k) ans.push_back(mid);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) a[i].read();
  if (n <= k) {
    printf("-1");
    return 0;
  }
  sort(a + 1, a + 1 + n);
  int l = max(1, (1 + n) / 2 - (k + 1)), r = min(n, (1 + n) / 2 + (k + 1));
  for (int i = l; i <= r; ++i)
    for (int j = i; j <= r; ++j) solve(a[i], a[j]);
  sort(ans.begin(), ans.end());
  int num = unique(ans.begin(), ans.end()) - ans.begin();
  printf("%d\n", num);
  for (int i = 0; i < num; ++i) printf("%.2f %.2f\n", ans[i].x, ans[i].y);
  return 0;
}
