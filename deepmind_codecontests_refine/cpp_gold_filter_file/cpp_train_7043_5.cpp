#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int ans = 1 << 30;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    if (i - k >= 0) ans = min(ans, a[i] - a[i - k]);
  }
  cout << ans << '\n';
  return 0;
}
