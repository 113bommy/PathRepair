#include <bits/stdc++.h>
using namespace std;
long long n;
void solve() {
  cin >> n;
  long long ans = 1e9;
  if (n <= 3) {
    cout << n - 1 << "\n";
    return;
  }
  for (long long x = 2; x * x <= n; ++x) {
    if (n % x == 0)
      ans = min(ans, n / x + x - 1);
    else
      ans = min(ans, n / x + x);
  }
  cout << ans - 1 << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
