#include <bits/stdc++.h>
using namespace std;
struct DOT {
  long double x, y;
  DOT(long double _x = 0, long double _y = 0) { x = _x, y = _y; }
};
long double dtime(DOT a, DOT b) { return a.x * b.x + a.y * b.y; }
long double ctime(DOT a, DOT b) { return a.x * b.y - a.y * b.x; }
DOT operator+(DOT a, DOT b) { return DOT(a.x + b.x, a.y + b.y); }
DOT operator-(DOT a, DOT b) { return DOT(a.x - b.x, a.y - b.y); }
DOT operator*(DOT a, long double k) { return DOT(a.x * k, a.y * k); }
long double len(DOT a) { return sqrt(dtime(a, a)); }
long double len2(DOT a) { return dtime(a, a); }
DOT perpend(DOT a) { return DOT(-a.y, a.x); }
DOT adjust(DOT a, long double k) { return a * (k / len(a)); }
int dcmp(long double a) {
  if (fabs(a) <= 1e-8) return 0;
  return a < 0 ? -1 : 1;
}
struct per {
  long double l, r;
} a[100100];
bool cmp(per a, per b) { return dcmp(a.l - b.l) < 0; }
long double sqr(long double a) { return a * a; }
int n;
int main() {
  DOT u, v, del, w, px = DOT(1, 0);
  cin >> u.x >> u.y >> v.x >> v.y;
  cin >> n;
  for (int i = 1, _E_ = n; i <= _E_; ++i) {
    DOT o;
    long double r, sg = 1;
    cin >> o.x >> o.y >> r;
    if (dcmp(ctime(o - u, v - u)) < 0) sg = -1;
    long double h, t, m, res;
    h = 1e-8, t = 3e10, res = 0;
    while (dcmp(t - h) >= 0) {
      m = (h + t) * 0.5;
      long double R = (m + len2(u - v) / 4 / m) * 0.5;
      DOT O = (u + v) * 0.5 + adjust(perpend(u - v), (m - R) * sg);
      if (dcmp(len(O - o) - R - r) >= 0)
        res = m, h = m + 1e-8;
      else
        t = m - 1e-8;
    }
    a[i].l = (res - len2(u - v) / 4 / res) * 0.5 * sg;
    h = 1e-8, t = 3e10, res = t;
    while (dcmp(t - h) >= 0) {
      m = (h + t) * 0.5;
      long double R = (m + len2(u - v) / 4 / m) * 0.5;
      DOT O = (u + v) * 0.5 + adjust(perpend(u - v), (m - R) * sg);
      if (dcmp(len(O - o) - R + r) <= 0)
        t = m - 1e-8, res = m;
      else
        h = m + 1e-8;
    }
    a[i].r = (res - len2(u - v) / 4 / res) * 0.5 * sg;
    if (dcmp(a[i].l - a[i].r) > 0) swap(a[i].l, a[i].r);
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1, _E_ = n; i <= _E_; ++i)
    if (i == 1)
      n = 1;
    else if (dcmp(a[n].r - a[i].l) >= 0) {
      a[n].r = max(a[n].r, a[i].r);
    } else
      a[++n] = a[i];
  long double ans = 1e12;
  int p = 1;
  for (int i = 1, _E_ = n; i <= _E_; ++i) {
    if (dcmp(a[i].l) <= 0 && dcmp(a[i].r) >= 0) p = 0;
    DOT O = (u + v) * 0.5 + adjust(perpend(u - v), a[i].l);
    ans = min(ans, len(O - u));
    O = (u + v) * 0.5 + adjust(perpend(u - v), a[i].r);
    ans = min(ans, len(O - u));
  }
  if (p) ans = len(u - v) / 2;
  cout << setprecision(16) << ans;
  return 0;
}
