#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-11;
inline long long rd() {
  long long x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
double a[N], b[N], p[N], ma;
struct matx {
  double a[4][4];
  matx() { memset(a, 0, sizeof(a)); }
  inline void init() { memset(a, 0, sizeof(a)); }
  matx operator*(const matx &bb) const {
    matx an;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) an.a[i][j] += a[i][k] * bb.a[k][j];
    return an;
  }
} aa, bb[40], cc;
struct line {
  double k, b;
  line() {}
  line(const double &nk, const double &nb) { k = nk, b = nb; }
  bool operator<(const line &bb) const {
    return fabs(k - bb.k) > eps ? k < bb.k : b < bb.b;
  }
} li[N];
inline double X(line a, line b) { return (a.b - b.b) / (b.k - a.k); }
int n, nn, st[N], tp;
long long t;
int main() {
  n = rd(), t = rd();
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf%lf", &a[i], &b[i], &p[i]);
    li[i] = line(p[i], p[i] * a[i]);
    ma = max(ma, b[i] * p[i]);
  }
  sort(li + 1, li + n + 1);
  li[0].k = -1;
  for (int i = 1; i <= n; ++i)
    if (fabs(li[i].k - li[i - 1].k) > eps) li[++nn] = li[i];
  li[0].k = 0;
  st[++tp] = 1;
  for (int i = 2; i <= nn; ++i) {
    while (tp > 1 &&
           X(li[st[tp]], li[st[tp - 1]]) - X(li[i], li[st[tp - 1]]) > -eps)
      --tp;
    st[++tp] = i;
  }
  long long nt = 0;
  for (int i = 1; i <= tp && nt < t; ++i) {
    double nx = nt * ma - aa.a[0][0];
    while (i < tp && X(li[st[i]], li[st[i + 1]]) <= nx) ++i;
    int ii = st[i];
    nx = X(li[st[i]], li[st[i + 1]]);
    bb[0].init();
    bb[0].a[0][0] = 1 - li[ii].k, bb[0].a[1][0] = li[ii].k,
    bb[0].a[2][0] = bb[0].a[1][1] = bb[0].a[3][1] = bb[0].a[2][2] =
        bb[0].a[3][3] = 1;
    aa.a[0][2] = li[ii].b, aa.a[0][3] = ma;
    for (int j = 1; j <= 33; ++j) bb[j] = bb[j - 1] * bb[j - 1];
    for (int j = 33; ~j; --j)
      if (t - nt > (1ll << j)) {
        cc = aa * bb[j];
        if (i == tp ||
            ((double)(nt + (1ll << j)) * ma - cc.a[0][0] - nx) < -eps)
          aa = cc, nt += 1ll << j;
      }
    ++nt, aa = aa * bb[0];
  }
  printf("%.13lf\n", aa.a[0][0]);
  return 0;
}
