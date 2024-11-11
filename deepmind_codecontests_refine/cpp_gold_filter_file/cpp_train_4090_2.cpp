#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long M = 998244353;
const long double PI = acos(-1);
long long n, k;
long long a[N], d[N], mn[N] = {INT_MAX};
signed main() {
  long long i, s = 0, ans = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> d[i], mn[i] = min(mn[i - 1], d[i]);
  for (i = n; i >= 1; i--) a[i] += a[i + 1];
  if (k == 0) {
    for (i = 1; i <= n; i++) ans = max(ans, a[i] - d[i]);
    cout << ans;
  } else if (k == 1) {
    for (i = 2; i <= n; i++)
      ans = max(ans, max(0ll, a[1] - a[i] - mn[i - 1]) + max(0ll, a[i] - d[i]));
    for (i = 1; i < n; i++)
      ans = max(ans, a[1] - (a[i + 1] - a[i + 2]) - d[1] +
                         max(0ll, a[i + 1] - a[i + 2] - d[i + 1]));
    cout << ans;
  } else
    cout << max({0ll, a[1] - mn[n - 1], a[n] - d[n]});
  return 0;
}
