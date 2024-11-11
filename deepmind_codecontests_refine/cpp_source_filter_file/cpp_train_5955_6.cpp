#include <bits/stdc++.h>
using namespace std;
long long n, sz, k;
long long getban(long long id) {
  if (id == 0) return 1ll * k * (k + 1) / 2;
  long long v = getban(id / k), sub = id % k;
  long long vl = (id / k) * sz + sub * k + 1, vr = vl + k;
  return 1ll * (vl + vr) * (vr - vl + 1) / 2 - max(min(vr, v), vl);
}
void solve() {
  scanf("%lld%lld", &n, &k);
  sz = 1ll * k * k + 1;
  long long be = (n - 1) / sz;
  long long ban = getban(be);
  if (ban != n) {
    long long pre = (n - 1) / sz + (ban <= n);
    long long ans = n + (n - pre - 1) / k - pre;
    printf("%lld\n", ans);
  } else {
    long long Ban = getban(be / k), sub = be % k;
    long long vl = (be / k) * sz + sub * k + 1, vr = vl + k;
    long long v = (vr == Ban ? vr - 1 : vr);
    long long pre = (v - 1) / sz + (Ban <= v);
    long long ans = v + (v - pre - 1) / v - pre + 1;
    printf("%lld\n", ans);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
