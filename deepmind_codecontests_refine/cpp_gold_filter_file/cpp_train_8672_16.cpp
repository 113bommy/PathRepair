#include <bits/stdc++.h>
using namespace std;
struct node {
  double l, r, tot, max;
} t[700000];
double x[700000], p[700000], s[700000];
int n, m, c;
void build(int p, int l, int r) {
  if (l == r) {
    t[p].l = t[p].r = t[p].max = t[p].tot = s[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  t[p].l = max(t[p * 2].l, t[p * 2].tot + t[p * 2 + 1].l);
  t[p].r = max(t[p * 2 + 1].r, t[p * 2 + 1].tot + t[p * 2].r);
  t[p].tot = t[p * 2].tot + t[p * 2 + 1].tot;
  t[p].max =
      max(max(t[p * 2].max, t[p * 2 + 1].max), t[p * 2].r + t[p * 2 + 1].l);
}
node calc(int p, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) {
    return t[p];
  }
  int mid = (l + r) / 2;
  if (rr <= mid) return calc(p * 2, l, mid, ll, rr);
  if (ll >= mid + 1) return calc(p * 2 + 1, mid + 1, r, ll, rr);
  node ans1 = calc(p * 2, l, mid, ll, rr);
  node ans2 = calc(p * 2 + 1, mid + 1, r, ll, rr);
  node ans;
  ans.l = max(ans1.l, ans1.tot + ans2.l);
  ans.r = max(ans2.r, ans2.tot + ans1.r);
  ans.tot = ans1.tot + ans2.tot;
  ans.max = max(max(ans1.max, ans2.max), ans1.r + ans2.l);
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++) scanf("%lf", &x[i]);
  for (int i = 2; i <= n; i++) scanf("%lf", &p[i]);
  for (int i = 2; i <= n; i++) {
    s[i] = (x[i] - x[i - 1]) / 2 - c * p[i] / 100;
  }
  double ans = 0;
  build(1, 2, n);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a++;
    node o = calc(1, 2, n, a, b);
    ans += max(o.max, 0.0);
  }
  printf("%.8lf\n", ans);
  return 0;
}
