#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long int ans = -(1e18);
    long long int res = a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5];
    ans = max(ans, res);
    res = a[n - 1] * a[n - 2] * a[n - 3] * a[1] * a[0];
    ans = max(ans, res);
    res = a[n - 1] * a[3] * a[2] * a[1] * a[0];
    ans = max(ans, res);
    cout << ans << endl;
  }
}
