#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
double eps = 1e-8, Pi = acos(-1);
long long n, k, cnt, m, t[N], p[N], l[N], r[N];
double a[N], b[N], c[N], L[N], R[N];
bool v[N];
void Change(long long x, long long val) {
  while (x <= cnt) {
    t[x] += val;
    x += (x & -x);
  }
  return;
}
long long Ask(long long x) {
  long long ans = 0;
  while (x) {
    ans += t[x];
    x -= (x & -x);
  }
  return ans;
}
bool cmp(long long x, long long y) { return l[x] < l[y]; }
long long check(double d) {
  cnt = 0;
  m = 0;
  for (long long i = 1; i <= n; i++) v[i] = 0;
  for (long long i = 1; i <= n; i++) {
    double dis = sqrt(a[i] * a[i] + b[i] * b[i]);
    if (dis - d < eps) {
      v[i] = 1;
      continue;
    }
    double ang = atan2(b[i], a[i]), ta = acos(d / dis);
    L[i] = ang - ta;
    R[i] = ang + ta;
    if (L[i] < -Pi) L[i] += 2 * Pi;
    if (R[i] > Pi) R[i] -= 2 * Pi;
    if (L[i] > R[i]) swap(L[i], R[i]);
    c[++cnt] = L[i];
    c[++cnt] = R[i];
  }
  sort(c + 1, c + 1 + cnt);
  for (long long i = 1; i <= n; i++) {
    if (v[i]) continue;
    p[++m] = i;
    l[i] = lower_bound(c + 1, c + 1 + cnt, L[i]) - c;
    r[i] = lower_bound(c + 1, c + 1 + cnt, R[i]) - c;
  }
  memset(t, 0, sizeof(t));
  sort(p + 1, p + 1 + m, cmp);
  long long ans = n * (n - 1) / 2;
  for (long long i = 1; i <= m; i++) {
    long long x = p[i];
    ans -= Ask(r[x]) - Ask(l[x] - 1);
    Change(r[x], 1);
  }
  return ans;
}
signed main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) scanf("%lf%lf", &a[i], &b[i]);
  double l = 0, r = 2000;
  while (r - l >= eps) {
    double mid = (l + r) / 2.0;
    if (check(mid) < k)
      l = mid;
    else
      r = mid;
  }
  printf("%.10lf", l);
  return 0;
}
