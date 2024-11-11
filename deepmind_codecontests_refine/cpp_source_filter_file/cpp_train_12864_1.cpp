#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long int> a(n + 1, 0), dp(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0] = 0;
  long long int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 20;
    int idx = lower_bound(a.begin(), a.end(), a[i] + 1 - 90) - a.begin();
    if (a[idx] > a[i] + 1 - 90) idx--;
    idx = max(idx, 0);
    dp[i] = min(dp[i], dp[idx] + 50);
    idx = lower_bound(a.begin(), a.end(), a[i] + 1 - 1440) - a.begin();
    if (a[idx] > a[i] + 1 - 1440) idx--;
    idx = max(idx, 0);
    dp[i] = min(dp[i], dp[idx] + 120);
  }
  sum = 0;
  for (int i = 1; i <= n; i++) {
    cout << dp[i] - sum << endl;
    sum = dp[i];
  }
  cout << endl;
}
