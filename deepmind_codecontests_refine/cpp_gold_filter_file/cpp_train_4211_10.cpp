#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
vector<vector<long long> > fact;
int main() {
  int i, j, k, n, l;
  cin >> n >> k;
  memset(dp, 0, sizeof(dp));
  fact.resize(n + 1);
  for (i = 1; i < n + 1; i++)
    for (j = 1; j < i + 1; j++)
      if (i % j == 0) fact[i].push_back(j);
  for (i = 0; i < n + 1; i++) dp[1][i] = 1;
  for (i = 2; i < k + 1; i++) {
    for (j = 1; j < n + 1; j++) {
      for (l = 0; l < (int)fact[j].size(); l++)
        dp[i][j] += dp[i - 1][fact[j][l]];
      dp[i][j] = dp[i][j] % 1000000007LL;
    }
  }
  long long ans = 0;
  for (i = 1; i < n + 1; i++) ans += dp[k][i];
  cout << ans % 1000000007LL << endl;
  return 0;
}
