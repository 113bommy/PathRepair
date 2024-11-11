#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int dp[n + 1][405];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j < 405; j++) dp[i][j] = 1000000;
    for (int j = 0; j < 405; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < 405; j++) {
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(j - arr[i]));
      }
    }
    cout << dp[n][404] << endl;
  }
  return 0;
}
