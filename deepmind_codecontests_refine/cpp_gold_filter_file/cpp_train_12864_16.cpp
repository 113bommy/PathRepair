#include <bits/stdc++.h>
using namespace std;
int dp[100001], t[100001];
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 20;
    int p = upper_bound(t, t + n + 1, t[i] - 90) - t;
    dp[i] = min(dp[i], dp[p - 1] + 50);
    int p2 = upper_bound(t, t + n + 1, t[i] - 1440) - t;
    dp[i] = min(dp[i], dp[p2 - 1] + 120);
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] - dp[i - 1] << '\n';
  }
}
