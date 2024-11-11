#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> arr[3002];
int t;
long long int dp[3002][3002];
long long int INF = 3000000000009;
int solve(int pos, int pre_pos) {
  if (pos > t) return 0;
  int x, y;
  x = (arr[pos].first - arr[pre_pos].first) + solve(pos + 1, pre_pos);
  y = solve(pos + 1, pos) + arr[pos].second;
  return (min(x, y));
}
long long int solve1(int pos, int pre) {
  if (pos > t) return (dp[pos][pre] = 0);
  if (dp[pos][pre] != -INF) return (dp[pos][pre]);
  long long int x = abs(arr[pos].first - arr[pre].first) + solve1(pos + 1, pre);
  long long int y = solve1(pos + 1, pos) + arr[pos].second;
  return (dp[pos][pre] = min(x, y));
}
long long int solve2(int pos, int pre) {
  long long int dp[t + 1][t + 1];
  for (int i = 1; i <= pos; i++) {
    for (int j = 1; j <= pre; j++) {
      if (pre == pos)
        dp[i][j] = arr[pos].second;
      else if (pre > pos)
        dp[i][j] = INF;
    }
  }
  for (int i = pos - 1; i >= 1; i--) {
    for (int j = pre; j >= 1; j--) {
      if (i > j) {
        int x = arr[i].first - arr[j].first + dp[i + 1][j];
        int y = dp[i + 1][i] + arr[i].second;
        dp[i][j] = min(x, y);
      }
    }
  }
  for (int i = 1; i <= pos; i++) cout << dp[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr + 1, arr + t + 1);
  for (int i = 0; i <= 3001; i++)
    for (int j = 0; j <= 3001; j++) dp[i][j] = -INF;
  long long int ans = arr[1].second + solve1(2, 1);
  cout << ans;
}
