#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long dp[N], a[] = {1, 2, 5};
void solve() {
  long long n;
  scanf("%lld", &n);
  long long ans = 1, f = 0, y = 3;
  for (long long i = 0; i <= n - 1; i++) {
    long long x;
    scanf("%lld", &x);
    if (x == 1 && y == 1)
      ans += 5;
    else if (x == 1)
      ans++;
    else if (x == 0 && y == 0)
      f = 1;
    y = x;
  }
  if (f)
    puts("-1");
  else
    cout << ans << '\n';
}
signed main() {
  long long t = 1;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
  return 0;
}
