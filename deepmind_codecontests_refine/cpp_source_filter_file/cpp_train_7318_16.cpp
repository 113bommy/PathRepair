#include <bits/stdc++.h>
using namespace std;
const double eps = 0.000000000000001;
int sz[110] = {0}, n, m;
int val[110][110] = {0};
int nx[110] = {0};
long long sm[110] = {0};
long long dp[110][10010] = {0};
long long mxit[110][110] = {0};
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", &sz[i]);
    long long s = 0;
    for (j = 1; j <= sz[i]; j++) {
      scanf("%d", &val[i][j]);
      s += val[i][j];
      val[i][j] += val[i][j - 1];
    }
    sm[i] = s;
  }
  for (i = n; i >= 1; i--) {
    nx[i] = nx[i + 1] + sz[i];
  }
  for (i = 1; i <= n; i++) {
    mxit[i][0] = 0;
    for (j = 1; j <= sz[i]; j++) {
      int lo = sz[i] - j, z;
      for (z = 1; z <= sz[i] - lo + 1; z++) {
        mxit[i][j] = max(mxit[i][j], sm[i] - ((long long)val[i][z + lo - 1] -
                                              val[i][z - 1]));
      }
    }
  }
  long long ans = 0;
  int atl, atm;
  for (i = 1; i <= m; i++) dp[n + 1][i] = INT_MIN;
  for (i = n; i >= 1; i--) {
    int jj = min(m, nx[i]);
    for (j = 0; j <= jj; j++) {
      atm = min(j, sz[i]);
      atl = (j > nx[i + 1] ? nx[i + 1] - j : 0);
      if (atl > atm) {
        dp[i][j] = INT_MIN;
        continue;
      }
      int z;
      for (z = atl; z <= atm; z++) {
        dp[i][j] = max(dp[i][j], mxit[i][z] + dp[i + 1][j - z]);
      }
    }
  }
  printf("%lld\n", dp[1][m]);
  return 0;
}
