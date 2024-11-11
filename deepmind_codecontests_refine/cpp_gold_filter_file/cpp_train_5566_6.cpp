#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int INF = 2147483647;
const LL MOD = 1000000007;
LL dp[5005][5005];
LL column[5005];
int main() {
  memset(dp, 0, sizeof(dp));
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  if (a > b) {
    a = n + 1 - a;
    b = n + 1 - b;
  }
  --a;
  --b;
  for (int i = 0; i < int(b); ++i) dp[0][i] = 1;
  for (int i = int(1); i < int(k + 1); ++i) {
    memset(column, 0, sizeof(column));
    column[0] = dp[i - 1][0];
    for (int m = int(1); m < int(b); ++m)
      column[m] = dp[i - 1][m] + column[m - 1];
    for (int m = 0; m < int(b); ++m) {
      int max_dist = b - m - 1;
      int low = max(0, m - max_dist);
      dp[i][m] = column[m + max_dist] - (low == 0 ? 0 : column[low - 1]) -
                 dp[i - 1][m];
      dp[i][m] %= MOD;
    }
  }
  cout << int(dp[k][a] % MOD) << endl;
  return 0;
}
