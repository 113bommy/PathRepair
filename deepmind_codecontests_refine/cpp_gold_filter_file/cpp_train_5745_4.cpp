#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[n];
    long long flag = 0;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1] - k) {
        m += min(a[i], a[i] - a[i + 1] + k);
      } else {
        m -= a[i + 1] - k - a[i];
      }
      if (m < 0) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
