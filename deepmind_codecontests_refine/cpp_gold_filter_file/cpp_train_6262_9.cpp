#include <bits/stdc++.h>
using namespace std;
long long n, m, dp[5005][5005], inv[5005], a[5005], f[5005], e[5005],
    mod = 998244353, ans;
int main() {
  cin >> n;
  for (register int(i) = (1); (i) <= (n); (i)++) cin >> a[i];
  stable_sort(a + 1, a + n + 1);
  for (register int(i) = (1); (i) <= (n); (i)++)
    f[i] = (a[i] != a[i - 1] ? i : f[i - 1]);
  for (register int(i) = (n); (i) >= (1); (i)--)
    e[i] = (a[i] != a[i + 1] ? i : e[i + 1]);
  inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (register int(i) = (1); (i) <= (n); (i)++) (dp[1][f[i]] += inv[n]) %= mod;
  for (int i = 2; i <= n; i++) {
    long long shengyuka = n - i + 1;
    for (register int(j) = (1); (j) <= (n); (j)++)
      if (dp[i - 1][j]) {
        long long f = dp[i - 1][j], yin = e[j] - j;
        (ans += f * inv[shengyuka] % mod * yin) %= mod;
        (dp[i][e[j] + 1] += f * inv[shengyuka]) %= mod;
      }
    for (register int(j) = (1); (j) <= (n); (j)++) {
      (dp[i][e[j] + 1] += dp[i][j]) %= mod;
      (dp[i][j] *= (e[j] - j + 1)) %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
