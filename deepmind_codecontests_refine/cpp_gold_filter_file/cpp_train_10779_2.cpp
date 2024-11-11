#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
int read();
int sgn(long double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }
struct P {
  long double x, y;
  P() {}
  P(long double xx, long double yy) : x(xx), y(yy) {}
  void in() { x = read(), y = read(); }
  P operator+(P a) { return P(x + a.x, y + a.y); }
  P operator-(P a) { return P(x - a.x, y - a.y); }
  P operator*(long double a) { return P(x * a, y * a); }
  P operator/(long double a) { return P(x / a, y / a); }
  long double operator*(P a) { return x * a.y - y * a.x; }
  long double an() { return atan2(y, x); }
  long double len() { return sqrt(x * x + y * y); }
  P perp() { return P(-y, x) / len(); }
  void prt() { printf("%.15Lf %.15Lf\n", x, y); }
} a[1003], p[1003], q2[1003], res[2];
struct Line {
  P st, en;
  long double an;
  Line() {}
  Line(P a, P b) : st(a), en(b) { an = (en - st).an(); };
  bool operator<(Line b) {
    return sgn(an - b.an) ? an < b.an : sgn((en - st) * (b.en - st)) < 0;
  }
} b[1003], q1[1003], t;
int n;
bool cmp(int x, int y) { return b[x] < b[y]; }
int cur[1003], pos[1003], mxr[1003], vis[1003];
int hd, tl;
P inter(Line a, Line b) {
  long double s1 = (b.st - a.st) * (a.en - a.st);
  long double s2 = (a.en - a.st) * (b.en - a.st);
  return P(b.st * s2 + b.en * s1) / (s1 + s2);
}
bool solve_half_plane() {
  hd = 1, tl = 0;
  for (int i = 1; i <= (n << 1); ++i) {
    if (!vis[i] || (hd <= tl && !sgn(b[cur[i]].an - q1[tl].an))) continue;
    t = b[cur[i]];
    while (hd < tl && sgn((t.en - t.st) * (q2[tl] - t.st)) <= 0) --tl;
    while (hd < tl && sgn((t.en - t.st) * (q2[hd + 1] - t.st)) <= 0) ++hd;
    q1[++tl] = t, (hd < tl) ? q2[tl] = inter(t, q1[tl - 1]) : P();
  }
  t = q1[hd];
  while (hd < tl && sgn((t.en - t.st) * (q2[tl] - t.st)) <= 0) --tl;
  return tl - hd >= 2;
}
bool check_interval(int l, int r) {
  memset(vis + 1, 0, sizeof(int) * (n << 1));
  for (int i = 1; i <= n; ++i) vis[pos[i]] = 1;
  for (int i = l; i <= r; ++i) vis[pos[(i - 1) % n + n + 1]] = 1;
  return solve_half_plane();
}
bool check(long double R) {
  for (int i = 1; i <= n; ++i) {
    P t = (b[i].en - b[i].st).perp() * R;
    b[i + n] = Line(b[i].en + t, b[i].st + t);
    cur[i] = i, cur[i + n] = i + n;
  }
  sort(cur + 1, cur + (n << 1) + 1, cmp);
  for (int i = 1; i <= (n << 1); ++i) pos[cur[i]] = i;
  for (int l = 1, r = 0; l <= n; ++l) {
    while (r < 2 * n && check_interval(l, r + 1)) ++r;
    check_interval(l, mxr[l] = r), p[l] = q2[tl];
  }
  for (int l = 1; l <= n; ++l)
    for (int r = l + 1; r <= mxr[l] + 1; ++r)
      if (mxr[r] >= n + l - 1) return res[0] = p[l], res[1] = p[r], 1;
  return 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i].in();
  for (int i = 1; i <= n; ++i) b[i] = Line(a[i], a[i % n + 1]);
  long double l = 0, r = 50000, mid;
  while (r - l > 1e-12) (check(mid = (l + r) / 2)) ? r = mid : l = mid;
  check(l + 5e-13);
  printf("%.15Lf\n", l), res[0].prt(), res[1].prt();
  return 0;
}
const int _SIZE = 1 << 22;
char ibuf[_SIZE], *iS = ibuf, *iT = ibuf;
int read() {
  int x = 0, f = 1;
  char c = (iS == iT ? iT = ((iS = ibuf) + fread(ibuf, 1, _SIZE, stdin)),
            (iS == iT ? EOF : *iS++) : *iS++);
  while (!isdigit(c))
    f = (c == '-') ? -1 : f,
    c = (iS == iT ? iT = ((iS = ibuf) + fread(ibuf, 1, _SIZE, stdin)),
         (iS == iT ? EOF : *iS++) : *iS++);
  while (isdigit(c))
    x = x * 10 + c - '0',
    c = (iS == iT ? iT = ((iS = ibuf) + fread(ibuf, 1, _SIZE, stdin)),
         (iS == iT ? EOF : *iS++) : *iS++);
  return x * f;
}
