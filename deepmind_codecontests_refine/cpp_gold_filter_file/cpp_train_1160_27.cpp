#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, a[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) cin >> a[i], ans += a[i] * (n - a[i] + 1);
  for (long long i = 1; i < n; i++) {
    ans -= min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
  }
  cout << ans << endl;
}
