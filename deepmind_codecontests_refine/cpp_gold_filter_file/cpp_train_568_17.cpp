#include <bits/stdc++.h>
using namespace std;
int n, m;
string str[21];
int dp[1 << 20];
int cost[21][21];
int mask[27], sum[27], maximum[27];
int main() {
  cin >> n >> m;
  for (long long i = 0; i < (long long)n; i++) {
    cin >> str[i];
  }
  for (long long i = 0; i < (long long)n; i++) {
    for (long long j = 0; j < (long long)m; j++) {
      cin >> cost[i][j];
    }
  }
  fill(dp, dp + (1 << n), 0x1f1f1f1f);
  dp[0] = 0;
  for (int col = 0; col < m; ++col) {
    memset(mask, 0, sizeof(mask));
    memset(sum, 0, sizeof(sum));
    memset(maximum, 0, sizeof(maximum));
    for (int row = 0; row < n; ++row) {
      int v = str[row][col] - 'a';
      mask[v] |= (1 << row);
      sum[v] += cost[row][col];
      maximum[v] = max(maximum[v], cost[row][col]);
      for (int old = (1 << n) - 1; old >= 0; --old) {
        if (old & (1 << row)) {
          continue;
        }
        dp[old | (1 << row)] =
            min(dp[old | (1 << row)], dp[old] + cost[row][col]);
      }
    }
    for (int pos = 0; pos < 26; ++pos) {
      if (mask[pos] == 0) {
        continue;
      }
      for (int old = (1 << n) - 1; old >= 0; --old) {
        if ((old | mask[pos]) == old) {
          continue;
        }
        dp[old | mask[pos]] =
            min(dp[old | mask[pos]], dp[old] + sum[pos] - maximum[pos]);
      }
    }
  }
  cout << dp[(1 << n) - 1];
  return 0;
}
