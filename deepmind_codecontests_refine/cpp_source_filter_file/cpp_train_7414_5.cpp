#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n, k;
long long int p;
long long int dp[maxn][2];
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 0, a + n);
    dp[0][0] = dp[0][1] = 0;
    int ans = -1;
    for (int i = 1; i < k; i++) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = a[i] + dp[i - 1][1];
    }
    for (int i = k; i <= n; i++) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = min(dp[i - k + 1][0] + a[i], dp[i - 1][1] + a[i]);
    }
    for (int i = n; i >= 0; i--) {
      if (dp[i][1] <= p) {
        ans = i;
        break;
      }
    }
    if (ans != -1)
      cout << ans << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
