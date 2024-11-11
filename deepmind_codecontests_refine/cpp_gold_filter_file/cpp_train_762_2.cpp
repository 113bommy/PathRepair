#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long po1w(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, (x *= x) %= mod)
    if (y & 1) (ans *= x) %= mod;
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int last = 0;
  str = " " + str;
  vector<long long> dp(n + 2), notb(n + 2), notw(n + 3), num(n + 2);
  num[n + 1] = notb[0] = 1;
  for (int i = n; i >= 1; i--) {
    if (str[i] == 'X')
      num[i] = num[i + 1] * 2 % mod;
    else
      num[i] = num[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    last = str[i] == 'W' ? 0 : last + 1;
    dp[i] = dp[i - 1];
    notb[i] = str[i] == 'X' ? notb[i - 1] * 2 % mod : notb[i - 1];
    if (last >= k && str[i - k] != 'B') {
      int now = i == k ? 1 : notb[i - k - 1];
      (dp[i] += 1ll * now * num[i + 1]) %= mod;
      (notb[i] += mod - now) %= mod;
    }
  }
  long long ans = 0;
  notw[n + 1] = notw[n + 2] = 1;
  last = 0;
  for (int i = n; i >= 1; i--) {
    last = str[i] == 'B' ? 0 : last + 1;
    notw[i] = str[i] == 'X' ? notw[i + 1] * 2 % mod : notw[i + 1];
    if (last >= k && str[i + k] != 'W') {
      int now = notw[i + k + 1];
      (ans += dp[i - 1] * now % mod * po1w(num[i], mod - 2)) %= mod;
      (notw[i] += mod - now) %= mod;
    }
  }
  cout << ans << endl;
}
