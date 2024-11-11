#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, m, c;
int xx[160000];
double p[160000], sum[160000], v[160000];
struct node2 {
  double l, r, v;
} num[160000 * 4];
struct node {
  int a, b;
} s[300005];
bool cmp(node p1, node p2) { return p1.b < p2.b; }
double max(double a, double b) { return a > b ? a : b; }
void build(int t, int l, int r) {
  if (l == r) {
    num[t].v = v[l];
    num[t].l = v[l];
    num[t].r = v[l];
    return;
  }
  int m = (l + r) / 2;
  build((t << 1), l, m);
  build(((t << 1) | 1), m + 1, r);
  num[t].v = max(num[(t << 1)].v, num[((t << 1) | 1)].v);
  num[t].v = max(num[t].v, num[(t << 1)].r + num[((t << 1) | 1)].l);
  num[t].l = max(num[(t << 1)].l, sum[m] - sum[l - 1] + num[((t << 1) | 1)].l);
  num[t].r = max(num[((t << 1) | 1)].r, sum[r] - sum[m] + num[(t << 1)].r);
  num[t].v = max(num[t].v, num[t].l);
  num[t].v = max(num[t].v, num[t].r);
}
node2 x;
int flag;
void query(int ll, int rr, int t, int l, int r) {
  if (ll <= l && r <= rr) {
    if (flag == 0) {
      x = num[t];
      flag = 1;
    } else {
      x.v = max(x.v, num[t].v);
      x.v = max(x.v, x.r + num[t].l);
      x.l = max(x.l, sum[l - 1] - sum[ll - 1] + num[t].l);
      x.r = max(num[t].r, sum[r] - sum[l - 1] + x.r);
      x.v = max(x.v, x.l);
      x.v = max(x.v, x.r);
    }
    return;
  }
  int m = (l + r) / 2;
  if (ll <= m) query(ll, rr, (t << 1), l, m);
  if (rr > m) query(ll, rr, ((t << 1) | 1), m + 1, r);
}
int main() {
  while (scanf("%d%d%d", &n, &m, &c) != EOF) {
    int i;
    for (i = 0; i < n; i++) {
      scanf("%d", &xx[i]);
    }
    sum[0] = 0;
    for (i = 1; i <= n - 1; i++) {
      scanf("%lf", &p[i]);
      double vv = ((double)xx[i] - xx[i - 1]) / 2.0;
      v[i] = vv * (1 - p[i] / 100.0) + p[i] / 100.0 * (vv - c);
      sum[i] = sum[i - 1] + v[i];
    }
    double ans = 0;
    build(1, 1, n - 1);
    flag = 0;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &s[i].a, &s[i].b);
      flag = 0;
      query(s[i].a, s[i].b - 1, 1, 1, n - 1);
      if (x.v > 0) ans += x.v;
    }
    printf("%.9lf\n", ans);
  }
  return 0;
}
