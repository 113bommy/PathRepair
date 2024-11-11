#include <bits/stdc++.h>
using namespace std;
int rdn() {
  int ret = 0;
  bool fx = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') fx = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return fx ? ret : -ret;
}
const int N = (3e4 + 5) * 4;
const long double eps = 1e-9;
int dcmp(long double x) { return (x > -eps) - (x < eps); }
long double Sqr(long double x) { return x * x; }
int n, m, tot, cnt;
long double len[N];
struct Node {
  long double x, y;
  Node(long double x = 0, long double y = 0) : x(x), y(y) {}
  Node operator+(const Node &b) const { return Node(x + b.x, y + b.y); }
  Node operator-(const Node &b) const { return Node(x - b.x, y - b.y); }
  Node operator*(const long double &b) const { return Node(x * b, y * b); }
  Node operator/(const long double &b) const { return Node(x / b, y / b); }
  long double mod() { return Sqr(x) + Sqr(y); }
} a[N], dir[N];
long double dot(Node u, Node v) { return u.x * v.x + u.y * v.y; }
struct Dt {
  long double ql, qr, a, b, c;
  Dt(long double l = 0, long double r = 0, long double a = 0, long double b = 0,
     long double c = 0)
      : ql(l), qr(r), a(a), b(b), c(c) {}
} h[N];
struct F {
  long double p;
  int v;
  F(long double p = 0, int v = 0) : p(p), v(v) {}
  bool operator<(const F &b) const {
    return dcmp(p - b.p) == 0 ? v < b.v : p < b.p;
  }
} tp[N << 2];
long double chk(long double mid) {
  cnt = 0;
  for (int i = 1; i <= tot; i++) {
    long double a = h[i].a, b = h[i].b, c = h[i].c - mid;
    long double ql = h[i].ql, qr = h[i].qr;
    if (a < eps) {
      if (dcmp(b) == 0) {
        if (c < eps) {
          tp[++cnt] = F(ql, 1);
          tp[++cnt] = F(qr, -1);
        }
      } else {
        long double x = -c / b;
        if (b > 0 && x > 0) {
          tp[++cnt] = F(ql, 1);
          tp[++cnt] = F(min(ql + x, qr), -1);
        } else if (b < 0 && ql + x < qr) {
          tp[++cnt] = F(ql + max(x, (long double)0), 1);
          tp[++cnt] = F(qr, -1);
        }
      }
    } else {
      long double dlt = Sqr(b) - 4 * a * c;
      if (dlt < 0) continue;
      dlt = sqrt(dlt);
      long double tmp = 2 * a;
      long double x0 = ql + (-b - dlt) / tmp, x1 = ql + (-b + dlt) / tmp;
      x0 = max(x0, ql);
      x1 = min(x1, qr);
      if (x0 < x1) {
        tp[++cnt] = F(x0, 1);
        tp[++cnt] = F(x1, -1);
      }
    }
  }
  sort(tp + 1, tp + cnt + 1);
  for (int i = 1, lj = 0; i <= cnt; i++) {
    lj += tp[i].v;
    if (lj == m) return true;
  }
  return false;
}
void cz(int &x) {
  x++;
  if (x > n) x = 1;
}
int main() {
  n = rdn();
  m = rdn();
  for (int i = 1; i <= n; i++) a[i].x = rdn(), a[i].y = rdn();
  a[n + 1] = a[1];
  long double sm = 0;
  for (int i = 1; i <= n; i++) {
    len[i] = sqrt((a[i + 1] - a[i]).mod());
    sm += len[i];
    dir[i] = (a[i + 1] - a[i]) / len[i];
  }
  long double ave = sm / m, L = len[1], R = ave, nw = 0;
  int id = 1;
  int pl = 1, pr = 1;
  for (; dcmp(R - len[pr]) >= 0; pr++) R -= len[pr];
  Node st = a[1], en = a[pr] + dir[pr] * R;
  R = len[pr] - R;
  while (dcmp(sm - nw) > 0) {
    long double cr = min(id * ave - nw, min(L, R));
    Node d0 = en - st, d1 = dir[pr] - dir[pl];
    st = st + dir[pl] * cr;
    en = en + dir[pr] * cr;
    h[++tot] = Dt(nw - (id - 1) * ave, nw - (id - 1) * ave + cr, d1.mod(),
                  2 * dot(d0, d1), d0.mod());
    L -= cr;
    if (dcmp(L) == 0) {
      cz(pl);
      st = a[pl];
      L = len[pl];
    }
    R -= cr;
    if (dcmp(R) == 0) {
      cz(pr);
      en = a[pr];
      R = len[pr];
    }
    nw += cr;
    if (dcmp(id * ave - nw) == 0) id++;
  }
  long double l = 0, r = ave;
  while (r - l > eps) {
    long double mid = (l + r) / 2;
    if (chk(Sqr(mid)))
      r = mid;
    else
      l = mid;
  }
  printf("%.10Lf\n", l);
  return 0;
}
