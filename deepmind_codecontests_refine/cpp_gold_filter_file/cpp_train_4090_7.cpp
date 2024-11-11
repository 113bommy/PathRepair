#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n), d(n);
    long long ans = 0, sum = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    for (long long i = 0; i < n; ++i) {
      cin >> d[i];
    }
    if (k == 0) {
      long long sum = 0;
      for (long long i = n - 1; i >= 0; --i) {
        sum += a[i];
        ans = max(ans, sum - d[i]);
      }
      cout << ans << endl;
      return 0;
    } else if (k >= 2) {
      long long spend = 1e18;
      for (long long i = 0; i < n - 1; ++i) {
        spend = min(spend, d[i]);
        ans += a[i];
      }
      ans += a.back();
      ans = max(0LL, ans - spend);
      ans = max(ans, a.back() - d.back());
    } else {
      long long spend = 1e18;
      long long sumP = 0;
      for (long long i = 0; i < n - 1; ++i) {
        sumP += a[i];
        sum -= a[i];
        spend = min(spend, d[i]);
        ans = max(ans, max(0LL, sumP - spend) + max(0LL, sum - d[i + 1]));
      }
      sum = accumulate(a.begin(), a.end(), 0LL);
      sum -= *min_element(a.begin() + 1, a.end());
      ans = max(ans, sum - d[0]);
    }
    cout << ans << endl;
  }
}
