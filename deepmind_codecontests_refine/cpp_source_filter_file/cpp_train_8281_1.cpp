#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int IT_MAX = 1 << 19;
const int MOD = 100000000;
const int INF = 1034567891;
const long long LL_INF = 1234567890123456789ll;
const double PI = 3.141592653589793238;
const double ERR = 1E-10;
int in[4050];
int sum[4050];
int dp[4050][91][91];
int main() {
  int N, i, j, k, ii, jj;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &in[i]);
  for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= 90; j++) {
      for (k = 0; k <= 90; k++) {
        if ((N - i + k) % 2) continue;
        int s = (N - i - k) >> 1;
        s++;
        int e = s + i - 1;
        if (s < 1 || e > N) continue;
        dp[i][j][k] = -INF;
        if (j > i) {
          dp[i][j][k] = 0;
          continue;
        }
        if (j == i) {
          dp[i][j][k] = sum[s + j - 1] - sum[s - 1];
          continue;
        }
        for (ii = 0; ii <= 1; ii++) {
          int tx = INF;
          int k1 = j + ii;
          if (i - k1 < k1) {
            dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1]);
            continue;
          }
          if (i - k1 == k1) {
            dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1] -
                                               sum[e] + sum[e - k1]);
            continue;
          }
          for (jj = 0; jj <= 1; jj++) {
            int k2 = k1 + jj;
            tx = min(tx, dp[i - k1 - k2][k2][jj] - sum[e] + sum[e - k2]);
          }
          dp[i][j][k] = max(dp[i][j][k], sum[s + k1 - 1] - sum[s - 1] + tx);
        }
      }
    }
  }
  return !printf("%d\n", dp[N][1][0]);
}
