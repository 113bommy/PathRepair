#include <bits/stdc++.h>
using namespace std;
long long n, dp[100100], a[100100], ans[100100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = 0;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 20;
    int j, k;
    j = lower_bound(a + 1, a + 1 + n, a[i] - 89) - a;
    dp[i] = min(dp[i], dp[j - 1] + 50);
    k = lower_bound(a + 1, a + 1 + n, a[i] - 1439) - a;
    dp[i] = min(dp[i], dp[k - 1] + 120);
    cout << dp[i] - dp[i - 1] << '\n';
  }
  return 0;
};
