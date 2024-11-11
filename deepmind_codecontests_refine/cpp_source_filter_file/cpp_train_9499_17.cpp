#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 3e6;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
long long n, dp[5100][5100], ans;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = 1;
    for (int j = i + 1; j <= n; j++) ans = (ans * j + dp[j][i - 1]) % mod;
    cout << ans << ' ';
  }
  return (0);
}
