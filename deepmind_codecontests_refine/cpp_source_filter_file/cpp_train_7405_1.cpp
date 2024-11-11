#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 100010;
string s;
int x, y, q, n, num[60];
long long fac[N], ifac[N], dp[N >> 1], dp1[N >> 1], dp2[N >> 1], cnt[60][60],
    res;
int id(char ch) { return ch < 97 ? ch - 64 : ch - 70; }
long long pw(long long x, long long n) {
  long long res = 1;
  for (; n; n >>= 1, x = x * x % MOD)
    if (n & 1) res = res * x % MOD;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = 1;
  for (int i = (1); i <= (N - 1); ++i) fac[i] = fac[i - 1] * i % MOD;
  ifac[N - 1] = pw(fac[N - 1], MOD - 2);
  for (int i = (N - 2); i >= (0); --i) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
  cin >> s;
  n = s.size();
  for (auto ch : s) ++num[id(ch)];
  long long mul = fac[n / 2] * fac[n / 2] % MOD;
  for (int i = (1); i <= (52); ++i) mul = mul * ifac[num[i]] % MOD;
  memset(dp, 0, sizeof dp);
  memset(cnt, 0, sizeof cnt);
  dp[0] = 1;
  for (int i = (1); i <= (52); ++i)
    if (num[i]) {
      for (int j = (n / 2); j >= (num[i]); --j) dp[j] += dp[j - num[i]];
    }
  for (int i = (1); i <= (52); ++i)
    if (num[i]) {
      memcpy(dp1, dp, sizeof dp1);
      for (int k = (num[i]); k <= (n / 2); ++k) dp1[k] -= dp1[k - num[i]];
      for (int j = (i + 1); j <= (52); ++j)
        if (num[j]) {
          memcpy(dp2, dp1, sizeof dp2);
          for (int k = (num[j]); k <= (n / 2); ++k) dp2[k] -= dp2[k - num[j]];
          cnt[i][j] = cnt[j][i] = 2 * dp2[n / 2] % MOD;
        }
    }
  cin >> q;
  while (q--) {
    cin >> x >> y;
    char c1 = s[x - 1], c2 = s[y - 1];
    res = (c1 == c2) ? dp[n / 2] : cnt[id(c1)][id(c2)];
    cout << res * mul % MOD << endl;
  }
  return 0;
}
