#include <bits/stdc++.h>
int read() {
  static int ch, x;
  int f = 1;
  while ((ch = getchar()) < 48) f = ch ^ 45;
  x = ch ^ 48;
  while ((ch = getchar()) >= 48) x = (((x << 2) + x) << 1) + (ch ^ 48);
  return f ? x : -x;
}
constexpr double EPS = 1e-8;
constexpr int sgn(const double &x) { return (x > EPS) - (x < -EPS); }
struct point {
  double x, y;
  constexpr point() : x(), y() {}
  constexpr point(const double &x, const double &y) : x(x), y(y) {}
  constexpr point operator*(const double &v) { return point(x * v, y * v); }
  constexpr point operator/(const double &v) { return point(x / v, y / v); }
  point &operator/=(const double &t) { return *this = *this / t; }
  friend constexpr point operator+(const point &x, const point &y) {
    return point(x.x + y.x, x.y + y.y);
  }
  friend constexpr point operator-(const point &x, const point &y) {
    return point(x.x - y.x, x.y - y.y);
  }
  point &operator+=(const point &t) { return *this = *this + t; }
  constexpr double norm() { return std::sqrt(x * x + y * y); }
  friend constexpr bool operator==(const point &x, const point &y) {
    return !sgn(x.x - y.x) && !sgn(x.y - y.y);
  }
} s[100010], v[100010], p[100010];
struct func {
  double a, b, c, be, ed;
  constexpr func() : a(), b(), c(), be(), ed() {}
  constexpr func(const double &a, const double &b, const double &c,
                 const double &be, const double &ed)
      : a(a), b(b), c(c), be(be), ed(ed) {}
};
int n, m, tot, ta, tb, top;
int id[100010];
double C, dlt;
double len[100010];
double ti[100010 << 1];
std::vector<func> f[100010];
constexpr int fix(const int &x, const int &n) {
  return x - ((n - x) >> 31 & n);
}
void load(const int &a, const int &b) {
  double be = -(p[a] - s[id[a]]).norm(), rem = dlt - be;
  ti[++tot] = 0;
  for (int i = id[a]; i != id[b]; i = fix(++i, n)) {
    const double ed = be + len[i];
    ti[++tot] = ed;
    be = ed;
    rem -= len[i];
  }
  ti[++tot] = be + rem;
}
struct arr {
  double l, r;
  constexpr arr() : l(), r() {}
  constexpr arr(const double &l, const double &r) : l(l), r(r) {}
} a[100010 << 1], b[100010 << 1], tmp[100010 << 1];
void add(arr *s, int &top, const int id, const double &R) {
  top = 0;
  for (const func &F : f[id]) {
    const double A = F.a, B = F.b, C = F.c - R * R;
    double lf = 0., rg = 0.;
    if (!sgn(A)) {
      if (B < 0) {
        rg = std::min(F.ed, -C / B);
      } else if (!sgn(B)) {
        if (C > 0) continue;
        rg = F.ed;
      } else {
        lf = std::max(0., -C / B);
        rg = F.ed;
      }
    } else {
      double delta = B * B - 4 * A * C;
      if (delta < 0) continue;
      delta = std::sqrt(delta);
      lf = (-B - delta) / (2 * A);
      rg = (-B + delta) / (2 * A);
      if (A < 0) std::swap(lf, rg);
      lf = std::max(lf, 0.);
      rg = std::min(rg, F.ed);
    }
    lf += F.be;
    rg += F.be;
    if (rg < 0) continue;
    if (top && s[top].r >= lf) {
      s[top].r = rg;
    } else {
      s[++top] = arr(lf, rg);
    }
  }
}
bool chk(const double &mid) {
  add(a, ta, 1, mid);
  if (!ta) return false;
  for (int t = 2; t <= m; ++t) {
    add(b, tb, t, mid);
    top = 0;
    for (int i = 1, j = 1; i <= ta && j <= tb;) {
      const double l = std::max(a[i].l, b[j].l), r = std::min(a[i].r, b[j].r);
      if (l < r) tmp[++top] = arr(l, r);
      if (a[i].r < b[j].r) {
        ++i;
      } else {
        ++j;
      }
    }
    memcpy(a + 1, tmp + 1, sizeof(arr) * top);
    ta = top;
    if (!ta) return false;
  }
  return true;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) {
    s[i].x = read();
    s[i].y = read();
  }
  s[n + 1] = s[1];
  for (int i = 1; i <= n; ++i) {
    v[i] = s[i + 1] - s[i];
    len[i] = v[i].norm();
    v[i] /= len[i];
    C += len[i];
  }
  dlt = C / m;
  p[1] = s[1];
  id[1] = 1;
  double rem = 0.;
  for (int i = 2, j = 1; i <= m; ++i) {
    rem += dlt;
    while (len[j] <= rem) rem -= len[j++];
    p[i] = s[j] + v[j] * rem;
    id[i] = j;
  }
  for (int a = 1, b = 2, c = fix(3, m); a <= m;
       ++a, b = fix(++b, m), c = fix(++c, m)) {
    tot = 0;
    load(a, b);
    load(b, c);
    std::sort(ti + 1, ti + tot + 1);
    tot = std::unique(ti + 1, ti + tot + 1) - (ti + 1);
    point A = p[a], B = p[b];
    int ida = id[a], idb = id[b], jda = fix(ida + 1, n), jdb = fix(idb + 1, n);
    for (int i = 1; i < tot; ++i) {
      const double al = A.x - B.x, bt = v[ida].x - v[idb].x;
      const double gm = A.y - B.y, om = v[ida].y - v[idb].y;
      const double d = ti[i + 1] - ti[i];
      f[a].push_back(func(bt * bt + om * om, 2 * (al * bt + gm * om),
                          al * al + gm * gm, ti[i], d));
      A += v[ida] * d;
      B += v[idb] * d;
      if (A == s[jda]) {
        ida = jda;
        jda = fix(ida + 1, n);
      }
      if (B == s[jdb]) {
        idb = jdb;
        jdb = fix(idb + 1, n);
      }
    }
  }
  double l = 0., r = 2829;
  while (l + EPS < r) {
    const double mid = (l + r) * .5;
    if (chk(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.8lf\n", l);
  return 0;
}
