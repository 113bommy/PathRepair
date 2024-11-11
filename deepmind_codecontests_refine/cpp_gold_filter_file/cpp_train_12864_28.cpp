#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n;
int t[MAXN];
int dp[MAXN];
int main() {
  cin >> n;
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    dp[i + 1] = dp[i] + 20;
    dp[i + 1] = min(dp[i + 1], dp[upper_bound(t, t + i, t[i] - 90) - t] + 50);
    dp[i + 1] =
        min(dp[i + 1], dp[upper_bound(t, t + i, t[i] - 1440) - t] + 120);
  }
  for (int i = 1; i <= n; i++) cout << dp[i] - dp[i - 1] << endl;
  return 0;
}
