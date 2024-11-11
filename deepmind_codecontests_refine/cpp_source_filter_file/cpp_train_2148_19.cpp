#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 5;
long long a[maxn], n, m, t, ans, k;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> m;
    a[m] = i;
    if (k < m) k = m;
  }
  t = maxn;
  for (long long i = 1; i <= k; i++) {
    if (a[i] <= t && a[i]) t = a[i], ans = i;
  }
  cout << ans << endl;
  return 0;
}
