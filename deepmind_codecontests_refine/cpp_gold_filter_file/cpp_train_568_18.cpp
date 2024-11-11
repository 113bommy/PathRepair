#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int cost[MAXN][MAXN];
string s[MAXN];
bool single[MAXN];
int dp[1000 * 1000 * 2];
vector<pair<int, int> > arr;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> cost[i][j];
  }
  for (int j = 0; j < m; j++) {
    for (char c = 'a'; c <= 'z'; c++) {
      int sum = 0, ma = INT_MIN, msk = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][j] == c) {
          msk |= 1 << i;
          ma = max(ma, cost[i][j]);
          sum += cost[i][j];
        }
      }
      if (msk > 0) {
        arr.push_back({msk, sum - ma});
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) arr.push_back({1 << i, cost[i][j]});
  dp[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    dp[i] = INT_MAX / 2;
    for (pair<int, int> cur : arr) {
      dp[i] = min(dp[i], dp[i & (~cur.first)] + cur.second);
    }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}
