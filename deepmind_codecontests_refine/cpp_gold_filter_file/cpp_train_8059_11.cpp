#include <bits/stdc++.h>
using namespace std;
int sum[100001], dp[100001][20];
int main() {
  int i, j, n, k, q, ans = 0, l, r;
  string str;
  cin >> n >> k >> q;
  cin >> str;
  sum[0] = 0;
  for (i = 0; i < n; i++) {
    if (str[i] == '1')
      sum[i + 1] = sum[i] + 1;
    else
      sum[i + 1] = sum[i];
  }
  for (i = 1; i <= k; i++) {
    for (j = i + k - 1; j <= n; j += k) {
      if (str[j - 1] == '1')
        dp[j][i] = dp[j - k][i] - 1;
      else
        dp[j][i] = dp[j - k][i] + 1;
    }
  }
  while (q--) {
    cin >> l >> r;
    ans = sum[r] - sum[l - 1];
    i = l % k;
    if (!i) i = k;
    ans += dp[r][i] - dp[l - 1][i];
    cout << ans << endl;
  }
  return 0;
}
