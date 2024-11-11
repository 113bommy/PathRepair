#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long ans = 1, n, a, b, c, d, dp1, dp0;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &d);
    if (d == 2ll) {
      b++;
    } else {
      a++;
    }
  }
  for (long long i = 1; i <= b; i++) ans = ans * (n - i + 1) % mod;
  dp0 = 1, dp1 = 1;
  for (long long i = 2; i <= a; i++) {
    long long now = (dp1 + dp0 * (i - 1)) % mod;
    if (i == a) {
      printf("%lld", now * ans % mod);
      exit(0);
    } else {
      dp0 = dp1;
      dp1 = now;
    }
  }
  cout << ans << "\n";
  return 0;
}
