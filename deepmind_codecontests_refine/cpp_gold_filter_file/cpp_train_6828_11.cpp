#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int dp[105][maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k, p;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int k = 1; k <= 100; k++) {
    for (int p = n; p >= 1; p--) {
      if (a[p] + p + k > n)
        dp[k][p] = 1;
      else
        dp[k][p] = dp[k][p + a[p] + k] + 1;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    long long ans = 0;
    cin >> p >> k;
    if (k > 100) {
      for (int i = p; i <= n; i = i + a[i] + k) ans++;
      cout << ans << endl;
    } else
      cout << dp[k][p] << endl;
  }
  return 0;
}
