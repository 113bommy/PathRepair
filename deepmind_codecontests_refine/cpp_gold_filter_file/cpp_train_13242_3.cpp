#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;
const int MOD = 998244353;
long long dp[MAXN][MAXN];
int prefix[MAXN];
long long fpow(long long x, long long n, const long long &mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
int main() {
  string str;
  cin >> str;
  int N = str.size();
  prefix[0] = int(str[0] == '?');
  for (int i = 1; i < N; ++i) prefix[i] = prefix[i - 1] + int(str[i] == '?');
  for (int len = 2; len <= N; ++len)
    for (int l = 0; l + len - 1 < N; ++l) {
      int r = l + len - 1;
      if (str[l] != '(') (dp[l][r] += dp[l + 1][r]) %= MOD;
      if (str[r] != ')') (dp[l][r] += dp[l][r - 1]) %= MOD;
      if (str[l] != '(' and str[r] != ')')
        ((dp[l][r] -= dp[l + 1][r - 1]) += MOD) %= MOD;
      if (str[l] != ')' and str[r] != '(') {
        (dp[l][r] += dp[l + 1][r - 1]) %= MOD;
        (dp[l][r] += fpow(2, prefix[r - 1] - prefix[l], MOD)) %= MOD;
      }
    }
  cout << dp[0][N - 1] << endl;
  return 0;
}
