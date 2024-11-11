#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100010;
const double eps = 1e-7, PI = acos(-1);
double read_db() {
  int x;
  scanf("%d", &x);
  return x * 1e-3;
}
struct Line {
  double k, b;
} L[MaxN];
double x, y, dist[MaxN], ang[MaxN];
int n, m;
pair<double, int> h[MaxN];
int range_l[MaxN], range_r[MaxN];
int htot;
class Fenwick_tree {
 public:
  int c[MaxN];
  void insert(int x, int v) {
    for (; x <= htot; x += (x & -x)) c[x] += v;
  }
  int query(int x) {
    int ret = 0;
    for (; x; x -= (x & -x)) ret += c[x];
    return ret;
  }
  void clear() { memset(c, 0, sizeof(c)); }
} Fr, Fl;
int cir[MaxN], ctot;
inline bool cmp(int a, int b) { return range_r[a] < range_r[b]; }
void get_intersect(double r) {
  htot = 0;
  ctot = 0;
  for (int i = 1; i <= n; ++i)
    if (dist[i] < r) {
      double thita = acos(dist[i] / r), alpha;
      alpha = ang[i] - thita;
      if (alpha < -PI) alpha += 2 * PI;
      if (alpha > PI) alpha -= 2 * PI;
      h[++htot] = make_pair(alpha, i);
      alpha = ang[i] + thita;
      if (alpha < -PI) alpha += 2 * PI;
      if (alpha > PI) alpha -= 2 * PI;
      h[++htot] = make_pair(alpha, i);
      cir[++ctot] = i;
    }
  sort(h + 1, h + htot + 1);
  static bool used[MaxN];
  for (int i = 1; i <= htot; ++i) {
    if (used[h[i].second])
      range_r[h[i].second] = i;
    else
      range_l[h[i].second] = i;
    used[h[i].second] ^= 1;
  }
}
long long calc_size(double r) {
  get_intersect(r);
  Fr.clear();
  Fl.clear();
  sort(cir + 1, cir + ctot + 1, cmp);
  long long ret = 0;
  for (int i = 1; i <= ctot; ++i) {
    int u = cir[i];
    int now = Fr.query(htot) - Fr.query(range_l[u]);
    now -= Fl.query(htot) - Fl.query(range_l[u]);
    ret += now;
    Fl.insert(range_l[u], 1);
    Fr.insert(range_r[u], 1);
  }
  return ret;
}
inline bool cmplen(int a, int b) {
  return range_r[a] - range_l[a] < range_r[b] - range_l[b];
}
int uf[MaxN];
int get_f(int x) { return uf[x] == x ? x : uf[x] = get_f(uf[x]); }
inline double sqr(double x) { return x * x; }
double inter(int a, int b) {
  double tx = (L[a].b - L[b].b) / (L[b].k - L[a].k), ty = L[a].k * tx + L[a].b;
  return sqrt(fabs(sqr(x - tx) + sqr(y - ty)));
}
int pos[MaxN];
double calc_sum(double r) {
  get_intersect(r);
  sort(cir + 1, cir + ctot + 1, cmplen);
  double sum = 0;
  for (int i = 1; i <= htot + 1; ++i) uf[i] = i;
  for (int i = 1; i <= ctot; ++i) {
    int u = cir[i];
    for (int j = get_f(range_l[u] + 1); j < range_r[u]; j = get_f(j + 1)) {
      sum += inter(h[j].second, u);
    }
    uf[range_l[u]] = range_l[u] + 1;
    uf[range_r[u]] = range_r[u] + 1;
  }
  return sum;
}
int main() {
  scanf("%d", &n);
  x = read_db(), y = read_db();
  scanf("%d", &m);
  for (int i = 1; i <= n; ++i) {
    L[i].k = read_db();
    L[i].b = read_db();
    dist[i] = fabs(L[i].k * x + L[i].b - y) / sqrt(1 + L[i].k * L[i].k);
    if (L[i].k == 0)
      ang[i] = 0.5 * PI;
    else
      ang[i] = atan(-1.0 / L[i].k);
    if ((y > L[i].k * x + L[i].b) ^ (ang[i] < 0)) {
      ang[i] = ang[i] + PI;
      if (ang[i] > PI) ang[i] -= 2 * PI;
    }
  }
  int cnt = 0;
  double l = 0, r = 1e18;
  while (++cnt <= 100) {
    double mid = (l + r) * 0.5;
    if (calc_size(mid) >= m)
      r = mid;
    else
      l = mid;
  }
  int sz = calc_size(l - eps);
  double ans = calc_sum(l - eps) + (m - sz) * l;
  printf("%.4lf\n", ans);
  return 0;
}
