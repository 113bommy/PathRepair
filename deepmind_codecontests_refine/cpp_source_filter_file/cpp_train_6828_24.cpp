#include <bits/stdc++.h>
using namespace std;
int a[100005];
int dp[302][100005];
int main() {
  ios::sync_with_stdio(0);
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> q;
  memset(dp, 0, sizeof(dp));
  for (int k = min(300, n); k >= 1; --k) {
    for (int i = n; i >= 1; --i) {
      if (i + a[i] + k > n)
        dp[k][i] = 1;
      else
        dp[k][i] = 1 + dp[k][i + a[i] + k];
    }
  }
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k <= 300)
      cout << dp[k][p] << endl;
    else {
      int ans = 0;
      while (p < n) {
        p = p + a[p] + k;
        ans++;
      }
      cout << ans << endl;
    }
  }
}
