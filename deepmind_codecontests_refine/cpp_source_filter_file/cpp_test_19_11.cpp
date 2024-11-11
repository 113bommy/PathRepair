#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int INF = 1e9;
const long long mod = 1e9 + 7;
int n, arr[N], dp[N][2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i <= 2000; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2000; j++) {
        dp[i][j] = INF;
      }
      for (int j = 0; j <= 2000; j++) {
        if (j >= arr[i]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - arr[i]]);
        } else if (arr[i] + j <= 2000) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j + arr[i]]);
        }
        dp[i][j] = max(dp[i][j], j);
      }
    }
    int ans = INF;
    for (int i = 0; i <= 2000; i++) {
      ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
  }
}
