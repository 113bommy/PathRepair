#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 3e5 + 1;
int q, n, A[N], B[N];
long long dp[N][3];
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &A[i], &B[i]);
    }
    dp[1][0] = 0;
    dp[1][1] = (long long)B[1];
    dp[1][2] = (long long)2 * dp[1][1];
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= 2; j++) {
        dp[i][j] = INF;
      }
      for (int j = 0; j <= 2; j++) {
        for (int s = 0; s <= 2; s++) {
          if (A[i] + j != A[i - 1] + s) {
            dp[i][j] =
                min(dp[i][j], dp[i - 1][s] + (long long)j * (long long)B[i]);
          }
        }
      }
    }
    long long sol = min(dp[n][1], dp[n][0]);
    sol = min(sol, dp[n][2]);
    printf("%I64d\n", sol);
  }
  return 0;
}
