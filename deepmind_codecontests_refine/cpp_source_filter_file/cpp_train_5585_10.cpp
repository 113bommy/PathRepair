#include <bits/stdc++.h>
using namespace std;
const int sz = 1e3 + 10;
const int mod = 998244353;
void solve() {
  long long int n, u, i, j;
  cin >> n >> u;
  long double ans = -1, x, y;
  long long int ar[n];
  for (i = 0; i < n; i++) cin >> ar[i];
  for (i = 0; i < n; i++) {
    j = lower_bound(ar, ar + n, ar[i] + u) - ar;
    if (j < n && (j - i + 1) >= 3 && ar[j] - ar[i] <= u) {
      x = (long double)ar[j] - (long double)ar[i + 1];
      y = (long double)ar[j] - (long double)ar[i];
      ans = max(ans, x / y);
    }
  }
  cout << setprecision(17) << fixed << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
