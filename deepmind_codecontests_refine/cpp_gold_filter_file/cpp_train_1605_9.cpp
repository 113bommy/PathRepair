#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long a[N], pre[N], suf[N], n, ans = 1e18;
long long l, r, ql, qr;
signed main() {
  cin >> n >> l >> r >> ql >> qr;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + a[i];
  }
  for (long long i = n; i; --i) {
    suf[i] = suf[i + 1] + a[i];
  }
  for (long long i = 0; i <= n; ++i) {
    long long res = pre[i] * l + suf[i + 1] * r;
    if (n - i >= i)
      res += max(n - 2 * i - 1, 0LL) * qr;
    else if (n - i < i)
      res += max(2 * i - n - 1, 0LL) * ql;
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}
