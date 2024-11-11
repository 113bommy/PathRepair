#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) {
  if (!b) return 1;
  long long k = mul(a, b / 2);
  if (b & 1) return k * k % 998244353 * a % 998244353;
  return k * k % 998244353;
}
int n, k, l;
long long fac[4010], invfac[4010], mul2[4010], dp[4010];
void init(int lim) {
  fac[0] = 1, invfac[0] = 1, mul2[0] = 1;
  for (int i = 1; i <= lim; i++) {
    fac[i] = fac[i - 1] * i % 998244353;
    invfac[i] = mul(fac[i], 998244353 - 2);
    mul2[i] = mul2[i - 1] * 2 % 998244353;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> l;
  init(4000);
  for (int i = n; i >= k; i--) {
    dp[i] = fac[i] * fac[i] % 998244353 * mul2[i] % 998244353 *
            invfac[2 * i + 1] % 998244353;
    dp[i] *=
        fac[n] % 998244353 * invfac[i] % 998244353 * invfac[n - i] % 998244353;
    for (int j = i + 1; j <= n; j++)
      (dp[i] -= dp[j] * fac[j] % 998244353 * invfac[i] % 998244353 *
                invfac[j - i] % 998244353) %= 998244353;
    dp[i] = (dp[i] + 998244353) % 998244353;
  }
  long long ans = 0;
  for (int i = k; i <= n; i++) (ans += dp[i]) %= 998244353;
  cout << (ans * l) % 998244353 << endl;
  return 0;
}
