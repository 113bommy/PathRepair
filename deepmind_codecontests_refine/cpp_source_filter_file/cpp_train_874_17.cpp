#include <bits/stdc++.h>
using namespace std;
struct meteor {
  double x, y, vx, vy;
} p[1500], q;
struct vec {
  double x, y;
} b[1500];
double det(vec &a, vec &b) { return a.x * b.y - a.y * b.x; }
bool cmp(vec &a, vec &b) {
  if (abs(det(a, b)) < 1e-7) {
    if (abs(a.x - b.x) < 1e-7) return a.y < b.y;
    return a.x < b.x;
  }
  return det(a, b) < 0;
}
double a[1500];
int n, i, j, ans, tot, cnt;
int main() {
  cin >> n;
  double x, y, t, tt, xx, yy;
  for (i = 0; i <= n; ++i) {
    cin >> t >> x >> y >> tt >> xx >> yy;
    p[i].vx = (xx - x) / (tt - t);
    p[i].vy = (yy - y) / (tt - t);
    p[i].x = x - p[i].vx * t;
    p[i].y = y - p[i].vy * t;
  }
  for (i = 1; i <= n; ++i) {
    tot = 0;
    for (j = 1; j <= n; ++j) {
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
  cout << ans + 1 << "\n";
  return 0;
}
