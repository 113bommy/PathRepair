#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long dp[n];
  dp[0] = 1;
  long long ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
    ans = max(ans, dp[i]);
  }
  cout << ans;
}
