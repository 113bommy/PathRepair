#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[5005][5005];
int ans(int lo, int hi) {
  if (lo > hi)
    return dp[lo][hi] = 0;
  else if (lo == hi)
    return dp[lo][hi] = 0;
  if (dp[lo][hi] != INT_MAX) return dp[lo][hi];
  if (v[lo] == v[hi])
    return dp[lo][hi] = min(dp[lo][hi], ans(lo + 1, hi - 1));
  else {
    dp[lo][hi] = min(dp[lo][hi], 1 + ans(lo + 1, hi));
    dp[lo][hi] = min(dp[lo][hi], 1 + ans(lo, hi - 1));
    dp[lo][hi] = min(dp[lo][hi], 2 + ans(lo + 1, hi - 1));
    return dp[lo][hi];
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  v.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i - 1] != a[i]) v.push_back(a[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      dp[i][j] = INT_MAX;
    }
  }
  cout << ans(0, v.size() - 1) << endl;
  return 0;
}
