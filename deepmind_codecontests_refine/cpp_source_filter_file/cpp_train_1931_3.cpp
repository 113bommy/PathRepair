#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2, K = 11;
int n, m, k, mtc[N][N], dp[N][N][K];
char s[N], t[N];
int main() {
  scanf("%d%d%d%s%s", &n, &m, &k, s, t);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      mtc[i][j] = (s[i] == t[j]) ? mtc[i + 1][j + 1] + 1 : 0;
    }
  }
  for (int l = 1; l <= k; ++l) {
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        int d = mtc[i][j];
        dp[i][j][k] = d + dp[i + d][j + d][k - 1];
        dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k]);
      }
    }
  }
  printf("%d\n", dp[0][0][k]);
  return 0;
}
