#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[n];
    for (long long i = 0; i < n; ++i) cin >> a[i];
    bool f = 1;
    for (long long i = 0; i < n - 1; ++i) {
      if (a[i + 1] >= a[i]) {
        long long d = a[i + 1] - a[i];
        if (d - k < 0) {
          m += max(a[i], k - d);
        } else if (m >= d - k) {
          m = m - d + k;
        } else {
          f = 0;
          cout << "NO\n";
          break;
        }
      } else {
        long long d = a[i] - a[i + 1];
        long long x = max(0LL, a[i + 1] - k);
        m = m + max(0LL, a[i] - x);
      }
    }
    if (!f) continue;
    cout << "YES\n";
  }
  return 0;
}
