#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const double eps = 1e2, oo = 1.5e6;
struct Point {
  double x, y;
  double Len() { return sqrt(x * x + y * y); }
  Point operator+(const Point &rhs) const {
    return (Point){x + rhs.x, y + rhs.y, 0};
  }
  Point operator-(const Point &rhs) const {
    return (Point){x - rhs.x, y - rhs.y, 0};
  }
  int id;
} p[N];
int n, ans[N];
bool cmp(Point a, Point b) { return a.Len() > b.Len(); }
void dfs(int i, Point v) {
  if (i == n) {
    if (v.Len() < oo + eps) {
      for (int j = 0; j < n; j++) printf("%d ", ans[j]);
      exit(0);
    } else
      return;
  }
  Point pos = v + p[i], neg = v - p[i];
  if (pos.Len() - eps < neg.Len()) {
    ans[p[i].id] = 1;
    dfs(i + 1, pos);
  }
  if (neg.Len() - eps < pos.Len()) {
    ans[p[i].id] = -1;
    dfs(i + 1, neg);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y), p[i].id = i;
  sort(p, p + n, cmp);
  dfs(0, (Point){0, 0, 0});
  return 0;
}
