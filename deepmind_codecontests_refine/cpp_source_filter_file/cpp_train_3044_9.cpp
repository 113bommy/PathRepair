#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long t, n, a[maxn], b[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    long long s = max(0ll, a[1] - b[n]);
    for (long long i = 1; i < n; ++i) {
      s += max(0ll, a[i + 1] - b[i]);
    }
    long long ans = 1e18;
    for (long long i = 2; i <= n; ++i) {
      ans = min(ans, s + min(b[i - 1], a[i]));
    }
    ans = min(ans, s + min(b[n], a[n]));
    cout << ans << endl;
  }
  return 0;
}
