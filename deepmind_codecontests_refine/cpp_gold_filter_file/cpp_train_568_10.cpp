#include <bits/stdc++.h>
using namespace std;
int dp[1 << 25];
int tick[25][25], value[25][25], cost[25][25];
int n, m;
string s[25];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> value[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int maxi = 0;
      for (int x = 0; x < n; x++)
        if (s[i][j] == s[x][j]) {
          tick[i][j] |= (1 << x);
          maxi = max(maxi, value[x][j]);
          cost[i][j] += value[x][j];
        }
      cost[i][j] -= maxi;
    }
  memset(dp, 1000000005, sizeof(dp));
  dp[0] = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int t;
    for (int pos = 0; pos < n; pos++)
      if ((mask >> pos) & 1) {
        t = pos;
        break;
      }
    for (int pos = 0; pos < m; pos++) {
      dp[mask] = min(dp[mask], dp[mask & (mask ^ tick[t][pos])] + cost[t][pos]);
      dp[mask] = min(dp[mask], dp[mask - (1 << t)] + value[t][pos]);
    }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}
