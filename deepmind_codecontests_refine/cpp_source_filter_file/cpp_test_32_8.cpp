#include <bits/stdc++.h>
const int mod = 998244353;
const int maxn = 2e5 + 5;
const long long int INF = 1e18;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> prefix(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i == 0)
        prefix[i] = arr[i];
      else
        prefix[i] = prefix[i - 1] + arr[i];
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    int k = 0;
    while (k * (k + 1) <= 2 * n) k++;
    k--;
    vector<vector<long long> > dp(n + 2, vector<long long>(k + 1, -INF));
    dp[n - 1][1] = arr[n - 1];
    dp[n - 1][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= k; j++) {
        if (j && i + j - 1 < n &&
            prefix[i + j - 1] - (i - 1 >= 0 ? prefix[i - 1] : 0) <
                dp[i + j][j - 1])
          dp[i][j] = max(dp[i][j],
                         prefix[i + j - 1] - (i - 1 >= 0 ? prefix[i - 1] : 0));
        dp[i][j] = max(dp[i][j], dp[i + 1][j]);
      }
    }
    int ans = 0;
    for (int j = 0; j <= k; j++) {
      if (dp[0][j] != -INF)
        ans = j;
      else
        break;
    }
    cout << ans << '\n';
  }
  return 0;
}
