#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 5e5 + 10;
long long a[N], pre[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long q;
  cin >> q;
  long long n = 0;
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x;
      cin >> x;
      a[++n] = x;
      pre[n] = pre[n - 1] + x;
    } else {
      if (n == 1) {
        cout << 0 << "\n";
        continue;
      }
      long long lo = 1;
      long long hi = n - 1;
      while (hi - lo > 1) {
        long long m1 = (2 * lo + hi) / 3;
        long long m2 = (lo + 2 * hi) / 3;
        double k = (double)(pre[m1] + a[n]) / (m1 + 1);
        double k1 = (double)(pre[m2] + a[n]) / (m2 + 1);
        if (k > k1) {
          lo = m2;
        } else {
          hi = m1;
        }
      }
      double mn = 1e18;
      for (long long i = lo; i <= hi; i++) {
        if (mn > (double)(pre[i] + a[n]) / (i + 1)) {
          mn = (double)(pre[i] + a[n]) / (i + 1);
        }
      }
      cout << fixed << setprecision(10) << (double)(a[n] - mn) << "\n";
    }
  }
}
