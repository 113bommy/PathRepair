#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const int mod = 998244353;
long long l, r, k;
long long dp[25][1058][3], dp1[25][1058][3], pows[maxn], digit[maxn];
bool valid(long long x) {
  long long cnt = 0;
  while (x) cnt += x % 2, x /= 2;
  if (cnt <= k)
    return 1;
  else
    return 0;
}
long long cnt(long long x) {
  memset(dp, 0, sizeof(dp));
  memset(dp1, 0, sizeof(dp1));
  long long cnt = 0;
  if (x == 0) return 0;
  while (x != 0) {
    digit[cnt++] = x % 10;
    x /= 10;
  }
  reverse(digit, digit + cnt);
  for (long long i = 1; i <= 9; i++) {
    if (i < digit[0])
      dp[0][1 << i][0] = (pows[cnt - 1] * i) % mod, dp1[0][1 << i][0] = 1;
    else if (i == digit[0])
      dp[0][1 << i][1] = (pows[cnt - 1] * i) % mod, dp1[0][1 << i][1] = 1;
  }
  for (long long i = 0; i < cnt; i++) dp1[i][0][0] = 1;
  for (long long i = 0; i < cnt - 1; i++) {
    for (long long j = 0; j < (1 << 10); j++) {
      if (j == 1) continue;
      for (long long k = 0; k < 10; k++) {
        if (valid(j | (1 << k)) && (j | (1 << k)) != 1) {
          dp[i + 1][(j | (1 << k))][0] =
              (dp[i + 1][(j | (1 << k))][0] + dp[i][j][0]) % mod;
          dp1[i + 1][(j | (1 << k))][0] =
              (dp1[i + 1][(j | (1 << k))][0] + dp1[i][j][0]) % mod;
          dp[i + 1][(j | (1 << k))][0] =
              (dp[i + 1][(j | (1 << k))][0] +
               pows[cnt - i - 2] * k % mod * dp1[i][j][0]) %
              mod;
          if (k == digit[i + 1]) {
            dp[i + 1][(j | (1 << k))][1] =
                (dp[i + 1][(j | (1 << k))][1] + dp[i][j][1]) % mod;
            dp1[i + 1][(j | (1 << k))][1] =
                (dp1[i + 1][(j | (1 << k))][1] + dp1[i][j][1]) % mod;
            dp[i + 1][(j | (1 << k))][1] =
                (dp[i + 1][(j | (1 << k))][1] +
                 pows[cnt - i - 2] * k % mod * dp1[i][j][1]) %
                mod;
          } else if (k < digit[i + 1]) {
            dp[i + 1][(j | (1 << k))][0] =
                (dp[i + 1][(j | (1 << k))][0] + dp[i][j][1]) % mod;
            dp1[i + 1][(j | (1 << k))][0] =
                (dp1[i + 1][(j | (1 << k))][0] + dp1[i][j][1]) % mod;
            dp[i + 1][(j | (1 << k))][0] =
                (dp[i + 1][(j | (1 << k))][0] +
                 pows[cnt - i - 2] * k % mod * dp1[i][j][1]) %
                mod;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (long long j = 2; j < (1 << 10); j++) {
    ans = (ans + dp[cnt - 1][j][0]) % mod;
    ans = (ans + dp[cnt - 1][j][1]) % mod;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pows[0] = 1;
  for (long long i = 1; i <= 20; i++) {
    pows[i] = (pows[i - 1] * 10) % mod;
  }
  cin >> l >> r >> k;
  cout << (cnt(r) + mod - cnt(l - 1)) % mod << endl;
}
