#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int dp[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) dp[i] = 1 + dp[i - 1];
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
