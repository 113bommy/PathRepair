#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
} p[10001], Q;
struct dpoint {
  long double x, y;
};
point operator+(point a, point b) { return (point){a.x + b.x, a.y + b.y}; }
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
long long cross(point a, point b) { return 1ll * a.x * b.y - 1ll * b.x * a.y; }
long long Abs(long long x) { return x < 0 ? -x : x; }
long long n, lim = 100000000, q;
long long Size[2][10010];
point get(long long x) {
  x = (lim << 2) + 1 - x;
  if (x <= lim) return (point){lim, x - 1};
  if (x <= lim * 3)
    return (point){(lim << 1) + 1 - x, lim};
  else
    return (point){-lim, (lim << 2) + 1 - x};
}
dpoint getpoint(point a1, point a2, point b1, point b2) {
  if (b1.x == b2.x) swap(a1, b1), swap(a2, b2);
  if (a1.x == a2.x) {
    long double y = (long double)(1ll * b2.y * a1.x - 1ll * b1.x * b2.y -
                                  1ll * b1.y * a1.x + 1ll * b2.x * b1.y) /
                    (long double)(b2.x - b1.x);
    return (dpoint){(long double)a1.x, y};
  }
  long double k1 = (long double)(a1.y - a2.y) / (long double)(a1.x - a2.x),
              B1 = (long double)a1.y - (long double)a1.x * k1;
  long double k2 = (long double)(b1.y - b2.y) / (long double)(b1.x - b2.x),
              B2 = (long double)b1.y - (long double)b1.x * k2;
  long double x = (B2 - B1) / (k1 - k2);
  return (dpoint){x, k1 * x + B1};
}
dpoint cast(point a) { return (dpoint){(long double)a.x, (long double)a.y}; }
long double _abs(long double x) { return x < 0. ? -x : x; }
long double getSize(dpoint a, dpoint b, dpoint c) {
  return _abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
long double f(point a, point b) {
  long double ans = 0.;
  long long l = 2, r = n, mid, L = 1, R = 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    bool good =
        (cross(p[mid] - a, p[1] - a) >= 0) &&
        ((cross(b - a, p[1] - a) <= 0) == (cross(b - a, p[mid] - a) <= 0));
    if (good)
      R = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = 2, r = n;
  while (l <= r) {
    mid = (l + r) >> 1;
    bool good =
        (cross(p[mid] - a, p[1] - a) < 0) &&
        ((cross(b - a, p[1] - a) <= 0) == (cross(b - a, p[mid] - a) <= 0));
    if (good)
      L = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  ans += (long double)(Size[0][R] + Size[1][L]);
  dpoint p1 = getpoint(a, b, p[R], p[(R < n) ? R + 1 : 1]),
         p2 = getpoint(a, b, p[L], p[(L > 1) ? L - 1 : n]);
  ans += getSize(cast(p[1]), cast(p[L]), p2);
  ans += getSize(cast(p[1]), cast(p[R]), p1);
  ans += getSize(cast(p[1]), p1, p2);
  ans = (long double)Size[0][n] - (ans * 2.0);
  if ((cross(b - a, p[1] - a) <= 0)) ans = -ans;
  return ans;
}
signed main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
  for (long long i = 1; i <= n; i++) {
    Size[0][i] = Size[0][i - 1];
    if (i > 2) Size[0][i] += Abs(cross(p[i] - p[1], p[i - 1] - p[1]));
  }
  for (long long i = n; i > 1; i--) {
    Size[1][i] = Size[1][i + 1];
    if (i < n) Size[1][i] += Abs(cross(p[i] - p[1], p[i + 1] - p[1]));
  }
  for (long long i = 1; i <= q; i++) {
    scanf("%lld%lld", &Q.x, &Q.y);
    long long l = 1, r = lim << 2, mid;
    long double Left = f(Q, Q + (point){1, 0}), Right = -Left;
    long double ans = atan2(0, 1), Ans = abs(Left);
    while (l <= r) {
      mid = (l + r) >> 1;
      point now = get(mid);
      long double Val = f(Q, Q + now);
      if (Left * Val <= 0.)
        l = mid + 1, Right = Val;
      else
        r = mid - 1, Left = Val;
      if (_abs(Val) < Ans) Ans = _abs(Val), ans = atan2(now.y, now.x);
    }
    printf("%.20Lf\n", ans);
  }
}
