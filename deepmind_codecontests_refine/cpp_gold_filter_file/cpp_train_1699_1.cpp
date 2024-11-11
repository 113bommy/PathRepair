#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150000 + 1;
struct data {
  double sum, pref, suff, ans;
};
int x[MAXN];
double w[MAXN];
data t[4 * MAXN];
data MAKE(double val) {
  data res;
  res.sum = val;
  res.pref = res.suff = res.ans = max(0.0, val);
  return res;
}
data COMBINE(data a, data b) {
  data res;
  res.sum = a.sum + b.sum;
  res.pref = max(a.pref, a.sum + b.pref);
  res.suff = max(b.suff, b.sum + a.suff);
  res.ans = max(max(a.ans, b.ans), a.suff + b.pref);
  return res;
}
void BUILD(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = MAKE(w[tl]);
  else {
    int tm = (tl + tr) >> 1;
    BUILD(v << 1, tl, tm);
    BUILD((v << 1) + 1, tm + 1, tr);
    t[v] = COMBINE(t[v << 1], t[(v << 1) + 1]);
  }
}
data QUERY(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  if (r <= tm) return QUERY(v << 1, tl, tm, l, r);
  if (l > tm) return QUERY((v << 1) + 1, tm + 1, tr, l, r);
  return COMBINE(QUERY(v << 1, tl, tm, l, tm),
                 QUERY((v << 1) + 1, tm + 1, tr, tm + 1, r));
}
int main() {
  int n, m, c;
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i + 1 < n; ++i) {
    double v;
    scanf("%lf", &v);
    w[i] = (x[i + 1] - x[i]) / 2.0 - c * v / 100;
  }
  BUILD(1, 0, n - 2);
  double ans = 0;
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    ans += QUERY(1, 0, n - 2, l - 1, r - 2).ans;
  }
  printf("%.10lf", ans);
  return 0;
}
