#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
struct hh {
  double x, y;
} sk[100005];
double eps = 1e-8;
double dis(hh s) { return sqrt(s.x * s.x + s.y * s.y); }
int ac[100005], sum[100005 << 1], cnt;
double ls[100005 << 1], l[100005], r[100005];
bool cmp(int a, int b) { return l[a] < l[b]; }
int query(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += sum[x];
  return ans;
}
void update(int x, int w) {
  for (; x <= cnt; x += x & -x) sum[x] += w;
}
long long check(double x) {
  long long ans = 0;
  int tot = 0;
  memset(sum, 0, sizeof(sum));
  cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (dis(sk[i]) > x) {
      double k = -sk[i].x / sk[i].y, b = x * x / sk[i].y;
      double A = k * k + 1, B = 2 * b * k, C = b * b - x * x,
             D = sqrt(B * B - 4 * A * C);
      double x1 = (-B - D) / 2 / A, x2 = (-B + D) / 2 / A, y1 = k * x1 + b,
             y2 = k * x2 + b;
      ac[++tot] = i;
      l[i] = atan2(y1, x1), r[i] = atan2(y2, x2);
      ls[++cnt] = l[i], ls[++cnt] = r[i];
    }
  sort(ls + 1, ls + cnt + 1);
  for (int i = 1; i <= tot; ++i) {
    l[ac[i]] = lower_bound(ls + 1, ls + cnt + 1, l[ac[i]]) - ls,
    r[ac[i]] = lower_bound(ls + 1, ls + cnt + 1, r[ac[i]]) - ls;
    if (l[ac[i]] > r[ac[i]]) swap(l[ac[i]], r[ac[i]]);
  }
  ans += 1ll * (n - tot - 1) * (n - tot) / 2;
  ans += 1ll * tot * (n - tot);
  sort(ac + 1, ac + tot + 1, cmp);
  for (int i = 1; i <= tot; ++i) {
    int x = ac[i];
    if (l[x] == r[x])
      ans += i - 1;
    else
      ans += i - 1 - (query(r[x] - 1) - query(l[x]));
    update(r[x], 1);
  }
  return ans;
}
double p1 = sin(2.5), p2 = cos(2.5);
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    sk[i].x = x * p1 - y * p2;
    sk[i].y = x * p1 + y * p2;
  }
  double l = 0, r = 1e6, ans = 0;
  while (l + eps <= r) {
    double mid = (l + r) / 2;
    if (check(mid) >= k)
      r = mid, ans = mid;
    else
      l = mid;
  }
  printf("%.10lf", ans);
}
