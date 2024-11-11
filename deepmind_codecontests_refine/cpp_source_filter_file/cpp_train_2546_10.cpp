#include <bits/stdc++.h>
using namespace std;
int n, v, m, f[10005];
double a[10005], t, vx, vy, jd;
bool cmp(int b, int c) { return a[b] < a[c]; }
struct node {
  double x, y;
  bool operator<(const node& b) const { return x != b.x ? x < b.x : y < b.y; }
} p[100005], ans[10005];
int main() {
  scanf("%d%d", &n, &v);
  for (int i = 0; i < n; ++i) f[i] = i, scanf("%lf", a + i);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  sort(f, f + n, cmp);
  sort(p, p + m);
  for (int i = 0, pt = 0; i < n; ++i) {
    vx = v * cos(a[f[i]]), vy = v * sin(a[f[i]]);
    for (; pt <= m; ++pt) {
      t = p[pt].x / vx;
      jd = vy * t - 9.8 * t * t / 2;
      if (jd > p[pt].y)
        continue;
      else if (jd >= 0) {
        ans[f[i]] = node{p[pt].x, jd};
        break;
      } else {
        ans[f[i]] = node{vx * vy / 4.9, 0};
        break;
      }
    }
    if (pt > m) ans[f[i]] = node{vx * vy / 4.9, 0};
  }
  for (int i = 0; i < n; ++i) printf("%.9lf %.9lf\n", ans[i].x, ans[i].y);
  return 0;
}
