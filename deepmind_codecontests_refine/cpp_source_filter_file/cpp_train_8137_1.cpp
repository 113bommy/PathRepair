#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, i;
  cin >> n;
  long long int a[n], a1[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    cin >> a1[i];
  }
  long long int dp[n], dp1[n];
  dp[0] = a[0];
  dp1[0] = a1[0];
  for (i = 1; i < n; i++) {
    if (i < 2) {
      dp[i] = (dp1[i - 1] + a[i]);
      dp1[i] = (dp[i - 1] + a1[i]);
    } else {
      dp[i] = max(dp1[i - 1] + a[i], dp1[i - 2] + a[i]);
      dp1[i] = max(dp[i - 1] + a1[i], dp[i - 1] + a1[i]);
    }
  }
  cout << max(dp[n - 1], dp1[n - 1]);
  return 0;
}
