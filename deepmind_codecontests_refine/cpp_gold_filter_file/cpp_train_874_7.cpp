#include <bits/stdc++.h>
using namespace std;
struct ppp {
  double x, y, vx, vy;
  void read() {
    double t1, t2;
    scanf("%lf%lf%lf%lf%lf%lf", &t1, &x, &y, &t2, &vx, &vy);
    vx = (vx - x) / (t2 - t1);
    vy = (vy - y) / (t2 - t1);
    x -= vx * t1;
    y -= vy * t1;
  }
} p[1100], q;
struct vec {
  double x, y;
} b[1100];
double det(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }
bool cmp(const vec &a, const vec &b) {
  if (abs(det(a, b)) < 1e-7) {
    if (abs(a.x - b.x) < 1e-7) return a.y < b.y;
    return a.x < b.x;
  }
  return det(a, b) < 0;
}
double a[1100];
int n, i, j, ans, tot, cnt;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) p[i].read();
  for (i = 1; i <= n; ++i) {
    tot = 0;
    for (j = 1; j <= n; ++j)
      if (i ^ j) {
        q.x = p[j].x - p[i].x;
        q.y = p[j].y - p[i].y;
        q.vx = p[j].vx - p[i].vx;
        q.vy = p[j].vy - p[i].vy;
        double t = q.vx ? q.x / q.vx : q.vy ? q.y / q.vy : 0;
        if (abs(q.x - q.vx * t) < 1e-7 && abs(q.y - q.vy * t) < 1e-7) {
          a[++tot] = t;
          b[tot].x = q.vx;
          b[tot].y = q.vy;
        }
      }
    sort(a + 1, a + tot + 1);
    cnt = 0;
    for (j = 1; j <= tot; ++j) {
      if (abs(a[j] - a[j - 1]) < 1e-7)
        cnt++;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
    cnt = 0;
    sort(b + 1, b + tot + 1, cmp);
    for (j = 1; j <= tot; ++j) {
      if (abs(det(b[j], b[j - 1])) < 1e-7)
        if (abs(b[j].x - b[j - 1].x) > 1e-7 || abs(b[j].y - b[j - 1].y) > 1e-7)
          cnt++;
        else
          ;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans + 1);
}
