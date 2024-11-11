#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[105];
int a[105][105];
int n, m;
long long f(int low, int high, int k) {
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int idx = a[i][k];
    if (v[i][idx].first >= low && v[i][idx].second <= high) ans++;
  }
  return ans * ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      v[i].push_back({l, r});
      for (int j = l; j <= r; j++) a[i][j] = v[i].size() - 1;
    }
  }
  vector<vector<long long>> dp(m, vector<long long>(m, 0));
  for (int i = 0; i < m; i++) {
    dp[i][i] = f(i, i, i);
  }
  for (int len = 3; len <= m; len++) {
    for (int i = 0; i < m - len + 1; i++) {
      int j = i + len - 1;
      dp[i][j] = 0;
      for (int k = i; k <= j; k++) {
        long long tmp = f(i, j, k);
        if (i < k) tmp += dp[i][k - 1];
        if (k < j) tmp += dp[k + 1][j];
        dp[i][j] = max(dp[i][j], tmp);
      }
    }
  }
  cout << dp[0][m - 1] << endl;
  return 0;
}
