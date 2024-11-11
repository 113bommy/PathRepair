#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < (n); i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort((a).begin(), (a).end());
    long long ans = 0;
    if (sum > k) {
      ans = sum - k;
      long long tot = 0;
      for (int i = 1; i < n; i++) {
        long long x = k - tot;
        long long y = (long long)floor(x / (1.0 * (n - i + 1)));
        ans = min(ans, abs(a[0] - y) + (n - i));
        tot += a[i];
      }
      for (long long i = 1; i < n; i++) {
        sum -= a[n - i];
        sum += a[0];
        if (sum <= k) ans = min(ans, i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
