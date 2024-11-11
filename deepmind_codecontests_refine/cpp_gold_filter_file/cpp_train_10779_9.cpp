#include <bits/stdc++.h>
using namespace std;
const int N = 305;
const double eps = 1e-11;
const double PI = acos(-1.0);
int sgn(double a) { return (a > eps) - (a < -eps); }
struct pnt {
  double x, y;
  pnt(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%.9lf %.9lf\n", x, y); }
  pnt operator+(const pnt &a) { return pnt(x + a.x, y + a.y); }
  pnt operator-(const pnt &a) { return pnt(x - a.x, y - a.y); }
  double operator*(const pnt &a) { return x * a.y - y * a.x; }
  pnt operator*(const double &a) { return pnt(x * a, y * a); }
  double len() { return sqrt(x * x + y * y); }
  pnt rot() { return pnt(-y, x); }
  void norm() {
    double t = len();
    x = x / t;
    y = y / t;
  }
  double ang() { return atan2(y, x); }
};
struct Line {
  pnt a, b;
  double ang;
  int c;
};
int n, m;
pnt a[N << 1];
Line rm[N << 2], t[N << 2];
double R;
int ct;
pnt A, B;
double dis(pnt a, pnt b, pnt c) {
  return fabs((b - a) * (c - a)) / (b - a).len();
}
bool cmp(Line a, Line b) {
  int k = sgn(a.ang - b.ang);
  if (k) return k < 0;
  double t = (b.a - a.a) * (b.b - a.a);
  return sgn(t) > 0;
}
pnt crs(Line a, Line b) {
  double S1 = (b.b - a.a) * (b.a - a.a);
  double S2 = (b.b - a.b) * (b.a - a.b);
  assert(sgn(S1 - S2));
  return a.a + (a.b - a.a) * (S1 / (S1 - S2));
}
bool onr(Line a, Line b, Line c) {
  if (!sgn(a.ang + PI - b.ang)) return false;
  if (!sgn(b.ang + PI - a.ang)) return false;
  pnt x = crs(a, b);
  return sgn((c.b - c.a) * (x - c.a)) < 0;
}
bool work(int typ) {
  if (ct <= 2) {
    if (!typ)
      A = t[1].a;
    else
      B = t[1].a;
    return true;
  }
  static Line q[N << 2];
  int hd = 1, tl = 0;
  int n = 0;
  for (int i = 1; i <= ct; i++)
    if (!n || (sgn(t[i].ang - t[n].ang))) t[++n] = t[i];
  for (int i = 1; i <= n; i++) {
    while (hd < tl && onr(q[tl - 1], q[tl], t[i])) --tl;
    while (hd < tl && onr(q[hd], q[hd + 1], t[i])) ++hd;
    q[++tl] = t[i];
  }
  while (hd < tl && onr(q[tl - 1], q[tl], q[hd])) --tl;
  while (hd < tl && onr(q[hd], q[hd + 1], q[tl])) ++hd;
  if (tl - hd + 1 >= 3) {
    if (!typ)
      A = crs(q[hd], q[hd + 1]);
    else
      B = crs(q[hd], q[hd + 1]);
    return true;
  }
  return false;
}
void pus(int l, int r) {
  for (int i = 1; i <= m; i++)
    if (l <= rm[i].c && rm[i].c < r) t[++ct] = rm[i];
}
bool wrk(int l, int r, int typ) {
  ct = 0;
  pus(l, r);
  return work(typ);
}
bool chk(double mid) {
  m = 0;
  R = mid;
  for (int i = 1; i < n + n; i++) {
    pnt dt = a[i + 1] - a[i];
    dt = dt.rot();
    dt.norm();
    dt = dt * R;
    pnt x = a[i] + dt, y = a[i + 1] + dt;
    rm[++m] = (Line){y, x, (x - y).ang(), i};
    x = a[i];
    y = a[i + 1];
    rm[++m] = (Line){x, y, (y - x).ang(), i};
  }
  sort(rm + 1, rm + m + 1, cmp);
  for (int i = 1, j = 2; i <= n; i++) {
    while (j < n + n && wrk(i, j + 1, 0)) ++j;
    if (j > n && wrk(j - n, i, 1)) return true;
    if (j <= n && wrk(j, n + i, 1)) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i].input();
  for (int i = 1; i <= n; i++) a[i + n] = a[i];
  double l = 0, r = 2e4;
  while (l + eps < r) {
    double mid = (l + r) * 0.5;
    if (chk(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.9lf\n", l + eps);
  chk(l + eps);
  A.output();
  B.output();
  return 0;
}
