#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 2e5 + 100;
long long a[N], s[N];
long long before;
long long sum(long long l, long long r) { return s[r] - s[l - 1]; }
long long check(long long x, long long y) {
  if (x == y) return before;
  if (x < y)
    return before - a[x] * x - sum(x + 1, y) + a[x] * y;
  else
    return before - a[x] * x + sum(y, x - 1) + a[x] * y;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> a[i], s[i] = s[i - 1] + a[i], before += a[i] * i;
  long long ans = before;
  for (long long i = 1; i <= n; i++) {
    long long l = 1, r = n;
    while (r - l >= 3) {
      long long m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
      long long res1 = check(i, m1), res2 = check(i, m2);
      ans = max({ans, res1, res2});
      if (res1 > res2)
        r = m2;
      else
        l = m1;
    }
    for (long long j = max(1ll, l - 5); j <= min(n, r + 5); j++)
      ans = max(ans, check(i, j));
  }
  cout << ans;
}
