#include <bits/stdc++.h>
using namespace std;
const int maxn = 8000 + 10;
const int mod = 1e9 + 7;
const int base = 103;
int pw[maxn], hsh[maxn];
int ans[maxn];
vector<int> dp[maxn];
int get_hash(int L, int R) {
  int len = R - L + 1;
  int ret = hsh[R] - 1ll * hsh[L - 1] * pw[len] % mod;
  if (ret < 0) ret += mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  s = "+" + s;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = 1ll * pw[i - 1] * base % mod;
    hsh[i] = (1ll * hsh[i - 1] * base + (int)(s[i] - 'a' + 1)) % mod;
  }
  memset(ans, 63, sizeof ans);
  ans[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i].resize(i + 1);
    for (int len = 1; len <= i; len++) {
      if (i - len < len)
        dp[i][len] = 1;
      else if (get_hash(i - len + 1, i) == get_hash(i - 2 * len + 1, i - len))
        dp[i][len] = dp[i - len][len] + 1;
      else
        dp[i][len] = 1;
      for (int j = 1; j <= min(9, dp[i][len]); j++)
        ans[i] = min(ans[i], ans[i - j * len] + len + 1);
      for (int j = 10; j <= min(99, dp[i][len]); j++)
        ans[i] = min(ans[i], ans[i - j * len] + len + 2);
      for (int j = 100; j <= min(999, dp[i][len]); j++)
        ans[i] = min(ans[i], ans[i - j * len] + len + 3);
      for (int j = 1000; j <= min(9999, dp[i][len]); j++)
        ans[i] = min(ans[i], ans[i - j * len] + len + 4);
    }
  }
  cout << ans[n] << endl;
}
