#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<int> dp(n);
    if (a[0] > 1)
      dp[0] = 0;
    else
      dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > i + 1) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = max(dp[i - 1], 1 + (i - a[i] < 0 ? 0 : dp[i - a[i]]));
      }
    }
    cout << dp[n - 1] << endl;
    a.clear();
  }
  return 0;
}
