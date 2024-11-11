#include <bits/stdc++.h>
using namespace std;
pair<bool, int> dp[600][600];
int dp2[600];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& el : a) cin >> el;
  for (int i = 0; i < n; i++) dp[i][i] = {true, a[i]};
  for (int t = 1; t < n - 1; t++)
    for (int i = 0; i < n - t; i++)
      for (int k = i; k < i + t; k++)
        if (dp[i][k].first && dp[k + 1][i + t].first &&
            dp[i][k].second == dp[k + 1][i + t].second)
          dp[i][i + t] = {true, dp[i][k].second + 1};
  for (int i = 0; i < n; i++) dp2[i] = 1e9;
  for (int i = 0; i < n; i++)
    if (dp[0][i].first) dp2[i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (dp[i + 1][j].first) dp2[j] = min(dp2[j], dp2[i] + 1);
  cout << dp2[n - 1];
  return 0;
}
