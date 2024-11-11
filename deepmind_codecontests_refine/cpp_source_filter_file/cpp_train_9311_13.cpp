#include <bits/stdc++.h>
using namespace std;
vector<int> a, dp, dpr;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n);
  dp.resize(n);
  dpr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i && a[i] > a[i - 1]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  dpr[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      dpr[i] = dpr[i + 1] + 1;
    } else {
      dpr[i] = 1;
    }
  }
  int ans = min(n, 2);
  ans = max(dpr[1] + 1, ans);
  ans = max(dp[n - 1] + 1, ans);
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, dp[i - 1] + 1);
    ans = max(ans, dpr[i - 1] + 1);
    if (a[i + 1] - a[i - 1] > 1) {
      ans = max(ans, dp[i - 1] + dpr[i + 1] + 1);
    }
  }
  cout << ans;
}
