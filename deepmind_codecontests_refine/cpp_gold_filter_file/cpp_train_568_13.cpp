#include <bits/stdc++.h>
using namespace std;
const int N = 22;
int a[N][N], n, m;
string s[N];
int sv[N][N], cost[N][N];
int dp[1 << N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int mx = 0;
      for (int k = 0; k < n; k++) {
        if (s[i][j] == s[k][j]) {
          sv[i][j] |= (1 << k);
          cost[i][j] += a[k][j];
          mx = max(mx, a[k][j]);
        }
      }
      cost[i][j] -= mx;
    }
  }
  dp[0] = 0;
  for (int msk = 1; msk < (1 << n); msk++) {
    dp[msk] = INT_MAX;
    int last;
    for (int j = 0; j < n; j++)
      if (msk & (1 << j)) {
        last = j;
        break;
      }
    for (int j = 0; j < m; j++) {
      dp[msk] = min(dp[msk], dp[msk & (msk ^ sv[last][j])] + cost[last][j]);
      dp[msk] = min(dp[msk], dp[msk ^ (1 << last)] + a[last][j]);
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
  return 0;
}
