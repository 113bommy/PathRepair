#include <bits/stdc++.h>
using namespace std;
const long long N = 400005;
int m, k, top;
long long n, a[N];
pair<long long, long long> q[N];
void solve() {
  top = 0;
  scanf("%lld%d%d", &n, &m, &k);
  for (int i = (int)(1); i <= (int)(m); i++) scanf("%lld", &a[i]);
  a[0] = 0;
  a[++m] = n;
  for (int i = (int)(m); i >= (int)(1); i--) a[i] -= a[i - 1];
  long long l, r, vl, vr;
  l = 1;
  r = n + 1;
  vl = n + 1;
  while (l <= r) {
    long long mid = (l + r) / 2, s = 0;
    for (int i = (int)(1); i <= (int)(m); i++) s += a[i] / mid;
    if (s >= m + k)
      vl = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  l = 1;
  r = n + 1;
  vr = n + 1;
  while (l <= r) {
    long long mid = (l + r) / 2, s = 0;
    for (int i = (int)(1); i <= (int)(m); i++) s += (a[i] + mid - 1) / mid;
    if (s <= m + k)
      vr = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  for (int i = (int)(1); i <= (int)(m); i++) {
    long long tl = a[i] / vl, tr = (a[i] + vr - 1) / vr;
    if (tl >= tr) continue;
    long long pl = 1ll << 60, pr = a[i] / tr;
    if (tl) pl = (a[i] + tl - 1) / tl;
    q[++top] = pair<long long, long long>(pr, pl);
  }
  sort(q + 1, q + top + 1);
  long long mx = vr, ans = n + 1;
  for (int i = (int)(1); i <= (int)(top); i++) {
    ans = min(ans, mx - q[i].first);
    mx = max(mx, q[i].second);
  }
  ans = min(ans, mx - vl);
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
