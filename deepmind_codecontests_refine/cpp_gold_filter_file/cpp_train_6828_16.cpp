#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int dp[200005][305];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, 0, sizeof(dp));
  for (int i = n; i >= 0; i--) {
    for (int j = 1; j <= 300; j++) {
      if (i + a[i] + j > n)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i + a[i] + j][j] + 1;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k <= 300)
      cout << dp[p][k];
    else {
      int ans = 0;
      while (p <= n) {
        p += a[p] + k;
        ans++;
      }
      cout << ans;
    }
    cout << endl;
  }
  return 0;
}
