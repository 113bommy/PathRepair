#include <bits/stdc++.h>
#pragma GCC optimize("O2,Ofast,inline,unroll-all-loops,-ffast-math")
using namespace std;
const int mod = 119 << 23 | 1;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int MOD = 119 << 23 | 1;
int dp[2020][2020];
int P[2020];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    P[i + 1] = P[i];
    P[i + 1] += (s[i] == '?');
  }
  for (int Len = 2; Len < n + 1; Len++) {
    for (int l = 0; l < n - Len + 1; l++) {
      int r = l + Len - 1;
      if (s[l] != '(') {
        (dp[l][r] += dp[l + 1][r]) %= mod;
      }
      if (s[r] != ')') {
        (dp[l][r] += dp[l][r - 1]) %= mod;
      }
      if (s[l] != '(' && s[r] != ')') {
        ((dp[l][r] -= dp[l + 1][r - 1]) += mod) %= mod;
      }
      if (s[l] != ')' && s[r] != '(') {
        (dp[l][r] += dp[l + 1][r - 1]) %= mod;
        (dp[l][r] += powmod(2, P[r] - P[l + 1])) %= mod;
      }
    }
  }
  cout << dp[0][n - 1];
  return 0;
}
