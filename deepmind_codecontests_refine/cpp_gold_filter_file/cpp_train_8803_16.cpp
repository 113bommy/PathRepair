#include <bits/stdc++.h>
using namespace std;
long long int const N = 5e3 + 5, mod = 1e9 + 7, inf = 1e17;
long long int a[N], b[N], dp[N][30], ent[N][N], sum[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < N; i++) ent[0][i] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      ent[j][i] = (ent[j][i - 1] + ent[j - 1][i - 1]) % mod;
    }
  }
  long long int n, ans = 0, f;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    f = s[i] - 'a';
    for (int k = n; k >= 1; k--) {
      long long int rf = dp[k][f];
      if (k == 1) {
        if (dp[k][f] <= 0) dp[k][f] = 1;
      } else
        dp[k][f] = sum[k - 1] - dp[k - 1][f] + mod;
      dp[k][f] %= mod;
      sum[k] += dp[k][f] - rf + mod;
      sum[k] %= mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += ent[i - 1][n - 1] * sum[i];
    ans %= mod;
  }
  cout << ans << '\n';
}
