#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 2;
long long a[N];
signed main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long ans = a[n] - a[1];
  long long l = 1, r = 1;
  while (l + r < n) {
    if (l < r) {
      long long dd = a[l + 1] - a[l], delta = dd * l;
      if (k >= delta)
        k -= delta, l++, ans -= dd;
      else {
        ans -= k / dd;
        break;
      }
    } else {
      long long R = n - r + 1;
      long long dd = a[R] - a[R - 1], delta = dd * r;
      if (k >= delta)
        k -= delta, r++, ans -= dd;
      else {
        ans -= k / dd;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
