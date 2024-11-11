#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353, maxN = 2e3 + 10;
long long int n, m, dp[maxN][maxN];
vector<long long int> perm;
signed main() {
  cin >> n >> m;
  perm.resize(n);
  for (long long int i = 0; i < n; i++) cin >> perm[i];
  for (long long int i = 0; i <= n; i++) dp[i][i] = 1;
  long long int minVal, minAt, sl, sr;
  for (long long int len = 1; len <= n; len++) {
    for (long long int i = 0; i + len <= n; i++) {
      minVal = maxN;
      sl = sr = 0;
      for (long long int j = i; j < i + len; j++) {
        if (minVal > perm[j]) {
          minVal = perm[j];
          minAt = j;
        }
      }
      for (long long int j = i; j <= minAt; j++)
        sl = (sl + (dp[i][j] * dp[j][minAt]) % MOD) % MOD;
      for (long long int j = minAt + 1; j <= i + len; j++)
        sr = (sr + (dp[minAt + 1][j] * dp[j][i + len]) % MOD) % MOD;
      dp[i][i + len] = sl * sr % MOD;
    }
  }
  cout << dp[0][n] << endl;
}
