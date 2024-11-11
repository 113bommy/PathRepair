#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int n, m;
int dp[1 << 22];
string s[22];
int cost[22][22], mrk[22][22], a[22][22];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int maxn = 0;
      for (int k = 0; k < n; ++k) {
        if (s[i][j] == s[k][j]) {
          mrk[i][j] |= (1 << k);
          cost[i][j] += a[i][j];
          maxn = max(maxn, a[i][j]);
        }
      }
      cost[i][j] -= maxn;
    }
  int s = (1 << n);
  for (int i = 0; i <= s; ++i) dp[i] = 1e7;
  dp[0] = 0;
  int first;
  for (int i = 0; i < s; ++i) {
    for (first = 0; i & (1 << first); first++)
      ;
    for (int j = 0; j < m; ++j) {
      dp[i | (1 << first)] = min(dp[i | (1 << first)], dp[i] + a[first][j]);
      dp[i | mrk[first][j]] =
          min(dp[i | mrk[first][j]], dp[i] + cost[first][j]);
    }
  }
  cout << dp[s - 1] << endl;
  return 0;
}
