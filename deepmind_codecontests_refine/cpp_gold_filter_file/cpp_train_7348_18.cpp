#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
class vec {
 public:
  long double x, y;
  vec() {}
  vec(long double tx, long double ty) { x = tx, y = ty; }
  vec operator+(const vec &t) const { return vec(x + t.x, y + t.y); }
  vec operator-(const vec &t) const { return vec(x - t.x, y - t.y); }
  vec operator*(const long double &t) const { return vec(x * t, y * t); }
  vec operator/(const long double &t) const { return vec(x / t, y / t); }
  long double operator*(const vec &t) const { return x * t.y - y * t.x; }
} v[10010];
inline vec intersect(vec s1, vec d1, vec s2, vec d2) {
  return s1 + d1 * ((s2 - s1) * d2 / (d1 * d2));
}
int n, Q;
long double sum[10010];
vec cet;
inline int query(bool sgn, bool lft, long double ang, vec cet) {
  vec dir(cos(ang), sin(ang));
  int l = 1, r = n - 1, ret = -1;
  while (l <= r) {
    if ((dir * (v[((l + r) / 2)] - cet) <= 0) == sgn) {
      ret = ((l + r) / 2);
      if (lft)
        r = ((l + r) / 2) - 1;
      else
        l = ((l + r) / 2) + 1;
    } else {
      if ((v[0] - cet) * (v[((l + r) / 2)] - cet) > 0)
        l = ((l + r) / 2) + 1;
      else
        r = ((l + r) / 2) - 1;
    }
  }
  return ret;
}
inline long double check(long double ang, vec cet) {
  vec dir(cos(ang), sin(ang));
  int lft, rgt;
  if (dir * (v[0] - cet) > 0) {
    lft = query(1, 1, ang, cet);
    rgt = query(1, 0, ang, cet);
  } else {
    lft = query(0, 1, ang, cet);
    rgt = query(0, 0, ang, cet);
  }
  long double area = sum[rgt] - sum[lft];
  vec x = intersect(cet, dir, v[lft - 1], v[lft] - v[lft - 1]),
      y = intersect(cet, dir, v[rgt], v[rgt + 1] - v[rgt]);
  area += x * v[lft];
  area += v[rgt] * y;
  area += y * x;
  if (dir * (v[0] - cet) > 0) return area * 2 - sum[n];
  return sum[n] - area * 2;
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
  reverse(v, v + n);
  v[n] = v[0];
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + v[i - 1] * v[i];
  while (Q--) {
    cin >> cet.x >> cet.y;
    long double l = 0, r = PI;
    bool sign = (check(l, cet) < check(r, cet));
    while (r - l > 1e-10)
      if ((check(((l + r) / 2), cet) >= 0) == sign)
        r = ((l + r) / 2);
      else
        l = ((l + r) / 2);
    printf("%.15lf\n", (double)l);
  }
}
