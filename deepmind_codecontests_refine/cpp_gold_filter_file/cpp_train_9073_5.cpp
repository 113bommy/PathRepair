#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0), twopi = 2 * acos(-1.0), eps = 1e-15;
const int N = 100010;
struct point {
  double x, y;
} a[N];
struct range {
  double l, r;
  int op;
  range() {}
  range(double l, double r) : l(l), r(r) {}
} q[N << 1];
int n, m, cnt;
int f[30][N << 1], que[N << 1], po[50];
double d[N];
inline bool cmp(const range &x, const range &y) { return x.r < y.r; }
inline int check(double x) {
  cnt = 0;
  for (int k = 1; k <= n; k++) {
    double u = atan2(a[k].y, a[k].x), v = acos(x / d[k]);
    q[++cnt] = range(u - v, u + v), q[cnt].op = 1;
    if (q[cnt].r < 0) {
      q[cnt].l += twopi;
      q[cnt].r += twopi;
    }
    cnt++;
    q[cnt] = range(q[cnt - 1].l + twopi, q[cnt - 1].r + twopi);
    q[cnt].op = 0;
  }
  sort(q + 1, q + 1 + cnt, cmp);
  int l = 1, r = 0;
  for (int k = 1; k <= cnt; k++) {
    que[++r] = k;
    while (q[k].l > q[que[l]].r + eps) {
      f[0][que[l]] = k;
      l++;
    }
  }
  while (l <= r) {
    f[0][que[l]] = cnt + 1;
    l++;
  }
  f[0][cnt + 1] = cnt + 1;
  for (int k = 1; k <= 18; k++)
    for (int i = 1; i <= cnt + 1; i++) f[k][i] = f[k - 1][f[k - 1][i]];
  for (int k = 1; k <= n; k++) {
    int u = k, v = m;
    for (int i = 18; i >= 0; i--) {
      if (po[i] <= v) {
        u = f[i][u];
        v -= po[i];
      }
    }
    if (u - k >= n) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  double l = 0, r = 999999999.0;
  for (int k = 1; k <= n; k++) {
    scanf("%lf%lf", &a[k].x, &a[k].y);
    d[k] = sqrt(a[k].x * a[k].x + a[k].y * a[k].y);
    r = min(r, d[k]);
  }
  if (m >= n) {
    printf("%.10lf\n", r);
    return 0;
  }
  po[0] = 1;
  for (int k = 1; k <= 30; k++) po[k] = po[k - 1] * 2;
  for (int k = 1; k <= 100; k++) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf\n", l);
  return 0;
}
