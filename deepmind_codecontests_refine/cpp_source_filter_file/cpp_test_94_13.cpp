#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
const long long mod = 1e9 + 7;
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      long long x = 1;
      while (a[i]--) {
        x *= 10;
      }
      a[i] = x;
    }
    k++;
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++) {
      long long rem = a[i + 1] % a[i];
      if (k > 0) {
        if (rem) {
          ans += a[i] * (min(k, a[i + 1] / a[i]));
          k -= a[i + 1] / a[i];
        } else {
          ans += a[i] * min(k, a[i + 1] / a[i] - 1);
          k -= (a[i + 1] / a[i] - 1);
        }
      }
    }
    if (k > 0) ans += k * a[n - 1];
    cout << ans;
  }
}
