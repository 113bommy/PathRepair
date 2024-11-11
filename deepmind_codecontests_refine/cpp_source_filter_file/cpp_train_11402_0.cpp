#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200;
const int MAX_K = 1000;
const int MOD = 1000000007;
int as[MAX_N], dp[MAX_N + 1][MAX_N + 1][MAX_K + 1];
inline void addmod(int &a, int b) { a = (a + b) % MOD; }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", as + i);
  sort(as, as + n);
  dp[0][0][0] = 1;
  for (int i = 0, pa = 0; i < n; i++) {
    int da = as[i] - pa;
    pa = as[i];
    for (int j = 0; j <= n; j++)
      for (int l = 0; l <= k; l++)
        if (dp[i][j][l] > 0) {
          int l1 = l + j * da;
          if (l1 <= k) {
            addmod(dp[i + 1][j][l1], dp[i][j][l]);
            if (j < k) addmod(dp[i + 1][j + 1][l1], dp[i][j][l]);
            addmod(dp[i + 1][j][l1], (long long)dp[i][j][l] * j % MOD);
            if (j > 0)
              addmod(dp[i + 1][j - 1][l1], (long long)dp[i][j][l] * j % MOD);
          }
        }
  }
  int sum = 0;
  for (int l = 0; l <= k; l++) addmod(sum, dp[n][0][l]);
  printf("%d\n", sum);
  return 0;
}
