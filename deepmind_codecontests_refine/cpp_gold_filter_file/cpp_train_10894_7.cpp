#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long s[5005][5005], n, k;
long long pow(long long exp) {
  if (exp == 0) return 1;
  long long s = pow(exp / 2);
  s = s * s % mod;
  if (exp % 2 == 0) return s;
  return s * 2 % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  s[0][0] = 1;
  for (long long i = 1; i <= k; ++i)
    for (long long j = 1; j <= i; ++j)
      s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
  long long ans = 0;
  for (long long i = 1; i <= k; ++i) {
    long long res = 1;
    for (long long j = n - i + 1; j <= n; ++j) res = res * j % mod;
    res = res * s[k][i] % mod;
    res = res * pow(n - i) % mod;
    ans = (ans + res) % mod;
  }
  cout << ans;
}
