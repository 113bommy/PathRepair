#include <bits/stdc++.h>
using namespace std;
int ans[102], dp[102][140004], fact[60], a[102], b[102][140004],
    primes[17] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                  29, 31, 37, 41, 43, 47, 53, 59};
void findFactors();
int main() {
  int i, k, s, x, n, j, minimum, minI;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  findFactors();
  for (i = 0; i < (1 << 17); i++) dp[0][i] = 0;
  for (i = 1; i <= n; i++)
    for (j = 0; j < (1 << 17); j++) dp[i][j] = 100000000;
  for (i = 1; i <= n; i++) {
    for (k = 1; k < 60; k++) {
      x = (~fact[k]) & ((1 << 17) - 1);
      for (s = x;; s = (s - 1) & x) {
        if (dp[i][s | fact[k]] > dp[i - 1][s] + abs(a[i] - k)) {
          dp[i][s | fact[k]] = dp[i - 1][s] + abs(a[i] - k);
          b[i][s | fact[k]] = k;
        }
        if (s == 0) break;
      }
    }
  }
  s = (1 << 17) - 1;
  for (i = n; i > 0; i--) {
    ans[i] = b[i][s];
    s = s - fact[b[i][s]];
  }
  for (i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
void findFactors() {
  int i, j;
  for (i = 0; i < 60; i++) fact[i] = 0;
  fact[1] = 0;
  for (i = 2; i < 60; i++)
    for (j = 0; j < 17; j++)
      if (i % primes[j] == 0) fact[i] |= 1 << j;
}
