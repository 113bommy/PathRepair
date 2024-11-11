#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, z;
    cin >> n >> k >> z;
    long long *a = new long long[n];
    long long *cs = new long long[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (i == 0) {
        cs[i] = a[i];
      } else {
        cs[i] = a[i] + cs[i - 1];
      }
    }
    long long ans = cs[k];
    for (long long i = 1; i <= k; i++) {
      long long fs = i;
      long long curs = cs[i];
      for (long long j = 1; j <= z; j++) {
        if (fs == k) {
          break;
        }
        curs += a[i - 1];
        fs++;
        ans = max(ans, curs + (cs[i + (k - fs)] - cs[i]));
        if (fs == k) {
          break;
        }
        curs += a[i];
        fs++;
        ans = max(ans, curs + (cs[i + (k - fs)] - cs[i]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
