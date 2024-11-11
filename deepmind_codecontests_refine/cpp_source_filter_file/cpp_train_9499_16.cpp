#include <bits/stdc++.h>
using namespace std;
const long long c = 5002;
long long n, mod = 998244353, dp[c][c], fakt[c], of[c];
long long oszt(long long a) {
  long long ans = 1, p = mod - 2;
  while (p) {
    if (p % 2) ans *= a, ans %= mod;
    a *= a, a %= mod, p /= 2;
  }
  return ans;
}
long long alatt(long long a, long long b) {
  return fakt[a] * of[b] % mod * of[a - b] % mod;
}
int main() {
  cin >> n;
  fakt[0] = 1, of[0] = 1;
  for (int i = 1; i <= n; i++)
    fakt[i] = fakt[i - 1] * i % mod, of[i] = oszt(fakt[i]), dp[i][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      dp[i][j] = ((i - j) * dp[i - 1][j - 1] + (j + 1) * dp[i - 1][j]) % mod;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 1; j <= n; j++)
      sum += dp[j][i] * alatt(n, j) % mod * fakt[n - j] % mod;
    cout << sum << " ";
  }
  return 0;
}
