#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long maxx = 1e18;
int n;
long long x[maxn], y[maxn], z[maxn];
inline bool check(long long ls_, long long la_, long long lb_, long long lc_,
                  long long rs_, long long ra_, long long rb_, long long rc_,
                  long long &x, long long &y, long long &z) {
  long long ls, la, lb, lc, rs, ra, rb, rc, t, ta, tb, tc;
  for (t = 0; t <= 1; t++) {
    ls = ls_, la = la_, lb = lb_, lc = lc_, rs = rs_, ra = ra_, rb = rb_,
    rc = rc_;
    if (t) ls += 3, la++, lb++, lc++, rs += 3, ra++, rb++, rc++;
    if (ls % 2) ls++;
    if (la % 2) la++;
    if (lb % 2) lb++;
    if (lc % 2) lc++;
    if (rs % 2) rs--;
    if (ra % 2) ra--;
    if (rb % 2) rb--;
    if (rc % 2) rc--;
    ls >>= 1, la >>= 1, lb >>= 1, lc >>= 1, rs >>= 1, ra >>= 1, rb >>= 1,
        rc >>= 1;
    if (ls > rs || la > ra || lb > rb || lc > rc) continue;
    if (la + lb + lc > rs || ra + rb + rc < ls) continue;
    if (la + lb + lc >= ls) {
      x = lb + lc - t, y = lc + la - t, z = la + lb - t;
      return 1;
    }
    ta = la, tb = lb, tc = ls - ta - tb;
    if (lc <= tc && tc <= rc) {
      x = tb + tc - t, y = tc + ta - t, z = ta + tb - t;
      return 1;
    }
    ta = la, tc = rc, tb = ls - ta - tc;
    if (lb <= tb && tb <= rb) {
      x = tb + tc - t, y = tc + ta - t, z = ta + tb - t;
      return 1;
    }
    tb = rb, tc = rc, ta = ls - tb - tc;
    if (la <= ta && ta <= ra) {
      x = tb + tc - t, y = tc + ta - t, z = ta + tb - t;
      return 1;
    }
  }
  return 0;
}
int main() {
  int T, i;
  long long l, r, mid, tx, ty, tz, mina, maxa, minb, maxb, minc, maxc, mins,
      maxs;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    l = 0, r = maxx * 3;
    while (l < r) {
      mid = (l + r) >> 1;
      mins = mina = minb = minc = -maxx * 6,
      maxs = maxa = maxb = maxc = maxx * 6;
      for (i = 0; i < n; i++) {
        mins = max(mins, x[i] + y[i] + z[i] - mid),
        maxs = min(maxs, x[i] + y[i] + z[i] + mid);
        mina = max(mina, -x[i] + y[i] + z[i] - mid),
        maxa = min(maxa, -x[i] + y[i] + z[i] + mid);
        minb = max(minb, x[i] - y[i] + z[i] - mid),
        maxb = min(maxb, x[i] - y[i] + z[i] + mid);
        minc = max(minc, x[i] + y[i] - z[i] - mid),
        maxc = min(maxc, x[i] + y[i] - z[i] + mid);
      }
      if (check(mins, mina, minb, minc, maxs, maxa, maxb, maxc, tx, ty, tz))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%lld %lld %lld\n", tx, ty, tz);
  }
  return 0;
}
