#include <bits/stdc++.h>
using namespace std;
int n, m, lx, ly, rx, ry;
long double l, ans, r, ma, mid;
struct P {
  int c, x, y;
} a[2005];
struct range {
  int c;
  long double l, r;
  bool operator<(const range &b) const { return l + 1e-13 < b.l; }
} b[4005];
long double max(long double x, long double y) { return (x < y ? y : x); }
long double sqr(long double x) { return x * x; }
bool check(int i, long double x) {
  int tot = 0;
  for (int j = 1; j <= n; j++)
    if (a[i].x == a[j].x && a[i].y == a[j].y) {
      if (a[j].c == 2) continue;
      b[++tot] = (range){1, -acos(-1), acos(-1)};
    } else {
      long double t = atan2((double)a[j].y - a[i].y, a[j].x - a[i].x);
      long double tt = sqr(a[j].x - a[i].x) + sqr(a[j].y - a[i].y);
      if (a[j].c == 1) {
        if (4.0 * x * x - 1e-13 <= tt) {
          if (4.0 * x * x + 1e-13 >= tt) b[++tot] = (range){1, t, t};
          continue;
        }
        tt = acos(sqrt(tt) / 2.0 / x);
        long double ll = t - tt, rr = t + tt;
        if (ll - 1e-13 < -acos(-1)) ll += 2 * acos(-1), rr += 2 * acos(-1);
        if (rr + 1e-13 < acos(-1))
          b[++tot] = (range){1, ll, rr};
        else {
          b[++tot] = (range){1, ll, acos(-1)};
          b[++tot] = (range){1, -acos(-1), rr - 2 * acos(-1)};
        }
      } else {
        if (4.0 * x * x - 1e-13 <= tt) continue;
        tt = acos(sqrt(tt) / 2.0 / x);
        long double ll = t - tt, rr = t + tt;
        if (ll - 1e-13 < -acos(-1)) ll += 2 * acos(-1), rr += 2 * acos(-1);
        if (rr + 1e-13 < acos(-1))
          b[++tot] = (range){2, ll + 1e-13, rr - 1e-13};
        else {
          b[++tot] = (range){2, ll + 1e-13, acos(-1)};
          b[++tot] = (range){2, -acos(-1), rr - 2 * acos(-1) - 1e-13};
        }
      }
    }
  sort(b + 1, b + tot + 1);
  long double r1 = -acos(-1), r2 = -acos(-1);
  for (int j = 1; j <= tot; j++)
    if (b[j].c == 1) {
      if (r2 + 1e-13 < b[j].l) return 1;
      r1 = max(r1, b[j].r);
    } else {
      if (r2 + 1e-13 < b[j].l && r2 + 1e-13 < r1) return 1;
      r2 = max(r2, b[j].r);
    }
  return r2 + 1e-13 < r1;
}
int main() {
  scanf("%d%d", &n, &m);
  lx = ly = 10000, rx = ry = 0;
  for (int i = 1; i <= n + m; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    lx = min(lx, a[i].x);
    ly = min(ly, a[i].y);
    rx = max(rx, a[i].x);
    ry = max(ry, a[i].y);
  }
  for (int i = 1; i <= n + m; i++) a[i].c = (i <= n ? 1 : 2);
  n += m;
  l = 0.0;
  ma = sqr(rx - lx) + sqr(ry - ly);
  for (int i = 1; i <= n; i++)
    if (check(i, ma)) return puts("-1"), 0;
  for (int i = 1; i <= n; i++) {
    l = ans, r = ma;
    if (!check(i, l)) continue;
    for (int j = 1; j <= 50; j++) {
      mid = (l + r) / 2;
      if (check(i, mid))
        l = mid;
      else
        r = mid;
      if (abs(r - l) / max(l, 1.0) <= 1e-8) break;
    }
    ans = max(ans, l);
  }
  printf("%.15lf", (double)ans);
}
