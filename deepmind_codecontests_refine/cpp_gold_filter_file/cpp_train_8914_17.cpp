#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)(1e6) + 500, inf = 1e9, mod = 1e9 + 7;
long long n, a[N];
long long mn[N];
long long ans[N];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  mn[n] = a[n];
  for (long long i = n - 1; i >= 1; --i) {
    mn[i] = min(a[i], mn[i + 1]);
  }
  memset(ans, -1, N);
  for (long long i = 1; i <= n; ++i) {
    long long l = i + 1, r = n, m = 0;
    while (r >= l) {
      m = (r + l) / 2;
      if (mn[m] >= a[i]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    if (r != i) {
      ans[i] = r - i - 1;
    }
  }
  for (long long i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  return false;
}
