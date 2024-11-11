#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
const double eps = 1e-15;
struct P {
  double x, y;
  P() {}
  P(double x, double y) : x(x), y(y) {}
};
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
struct State {
  int t;
  double lux, hux, a, b;
  State() {}
  State(int t, double lux, double hux, double a, double b)
      : t(t), lux(lux), hux(hux), a(a), b(b) {}
};
int np, w, h;
int sux, svx;
int pt[MAXN], px[MAXN], py[MAXN];
State e[MAXN + 1];
int ne;
bool intersect(vector<P> &hull, double a, double b, double &l, double &h) {
  bool ret = false;
  for (int i = (0); i < (((int)(hull).size())); ++i) {
    P c = hull[i], d = hull[(i + 1) % ((int)(hull).size())], e = d - c;
    double s, t;
    if (fabs(e.x) == 0 && fabs(e.y) == 0) {
      if (fabs(a * c.x + b - c.y) > eps) continue;
      s = c.x, t = 0;
    } else if (fabs(e.x) == 0) {
      s = c.x, t = (a * c.x + b - c.y) / e.y;
    } else {
      double num = (c.y - b) * e.x - c.x * e.y, den = a * e.x - e.y;
      if (fabs(den) < eps) continue;
      s = num / den, t = (s - c.x) / e.x;
    }
    if (t < 0 || t > 1) continue;
    if (!ret)
      ret = true, l = h = s;
    else
      l = min(l, s), h = max(h, s);
  }
  return ret;
}
bool proceed(State &cur, const State &dst, double v) {
  int dt = dst.t - cur.t;
  double dx = v * dt;
  vector<P> hull;
  hull.push_back(P(cur.lux + dx, cur.a * cur.lux + cur.b + dx));
  hull.push_back(P(cur.lux - dx, cur.a * cur.lux + cur.b + dx));
  if (fabs(cur.lux - cur.hux) > eps)
    hull.push_back(P(cur.lux - dx, cur.a * cur.lux + cur.b - dx));
  hull.push_back(P(cur.hux - dx, cur.a * cur.hux + cur.b - dx));
  hull.push_back(P(cur.hux + dx, cur.a * cur.hux + cur.b - dx));
  if (fabs(cur.lux - cur.hux) > eps)
    hull.push_back(P(cur.hux + dx, cur.a * cur.hux + cur.b + dx));
  double l, h;
  if (!intersect(hull, dst.a, dst.b, l, h)) return false;
  l = max(l, dst.lux), h = min(h, dst.hux);
  if (l > h + eps) return false;
  cur = State(dst.t, l, h, dst.a, dst.b);
  return true;
}
bool can(double v) {
  State cur = e[0];
  for (int i = (1); i < (ne); ++i)
    if (!proceed(cur, e[i], v)) return false;
  return true;
}
double solve() {
  ne = 0;
  e[ne++] = State(0, sux, sux, 0, svx);
  for (int l = 0, r = l; l < np; l = r) {
    while (r < np && pt[l] == pt[r]) ++r;
    int a = -1, b = -1;
    for (int i = (l); i < (r); ++i) {
      if (a == -1) a = i;
      if (px[a] == px[i] && py[a] == py[i]) continue;
      if (b == -1) b = i;
      int dx1 = px[b] - px[a], dy1 = py[b] - py[a], dx2 = px[i] - px[a],
          dy2 = py[i] - py[a];
      if ((long long)dx1 * dy2 - (long long)dy1 * dx2 != 0) return -1;
    }
    if (b == -1) {
      int den = h - py[a], luxnum = max(0, h * px[a] - w * py[a]),
          huxnum = min(w * den, px[a] * h);
      if (luxnum > huxnum) return -1;
      e[ne++] = State(pt[a], 1.0 * luxnum / den, 1.0 * huxnum / den,
                      1 - 1.0 * h / py[a], 1.0 * h * px[a] / py[a]);
    } else {
      int dx = px[b] - px[a], dy = py[b] - py[a];
      if (dy == 0) return -1;
      int den = dy, uxnum = px[a] * dy - py[a] * dx,
          vxnum = px[a] * dy + (h - py[a]) * dx;
      if (den < 0) den = -den, uxnum = -uxnum, vxnum = -vxnum;
      if (uxnum < 0 || uxnum > w * den || vxnum < 0 || vxnum > w * den)
        return -1;
      e[ne++] = State(pt[a], 1.0 * uxnum / den, 1.0 * uxnum / den, 0,
                      1.0 * vxnum / den);
    }
  }
  double l = 0, h = w;
  for (int rep = (0); rep < (100); ++rep) {
    double m = l + (h - l) / 2;
    if (can(m))
      h = m;
    else
      l = m;
  }
  return h;
}
void run() {
  scanf("%d%d%d", &np, &w, &h);
  scanf("%d%d", &sux, &svx);
  for (int i = (0); i < (np); ++i) scanf("%d%d%d", &pt[i], &px[i], &py[i]);
  double ans = solve();
  if (ans < 0) {
    printf("-1\n");
    return;
  }
  printf("%.15lf\n", ans);
}
int main() {
  run();
  return 0;
}
