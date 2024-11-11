#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
vector<int> p;
int check(vector<pair<int, int>>& a, int curr, int capa, int count, int mini,
          int sum) {
  if (dp[curr][count][capa] != 1000000000) return dp[curr][count][capa];
  if (curr == a.size() && count == mini && capa >= sum)
    return dp[curr][count][capa] = 0;
  else if (curr == a.size())
    return dp[curr][count][capa] = 1000000000;
  if (count <= mini && curr + mini - count <= a.size() &&
      (capa + p[curr] - p[curr + (mini - count)]) < sum)
    return dp[curr][count][capa] = 1000000000;
  int res = 1000000000;
  res = min(res, check(a, curr + 1, capa, count, mini, sum) + a[curr].second);
  if (count < mini)
    res = min(res,
              check(a, curr + 1, capa + a[curr].first, count + 1, mini, sum));
  return dp[curr][count][capa] = res;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].second;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i].second;
  }
  int orig = sum;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum - a[i].first <= 0) {
      cnt = i + 1;
      break;
    }
    sum -= a[i].first;
  }
  dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(10500, 1000000000)));
  int ans = 1000000000;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= cnt; j++) {
      for (int k = 0; k <= cnt * 101; k++) {
        if (dp[i][j][k] == 1000000000) continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + a[i].second);
        dp[i + 1][j + 1][k + a[i].first] =
            min(dp[i + 1][j + 1][k + a[i].first], dp[i][j][k]);
      }
    }
  }
  for (int i = orig; i <= cnt * 101; i++) {
    ans = min(ans, dp[n][cnt][i]);
  }
  cout << cnt << " " << ans << endl;
  return 0;
}
