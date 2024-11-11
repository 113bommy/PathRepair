#include <bits/stdc++.h>
using namespace std;
const int MAXC = 1050, MOD = 1e9 + 7;
long long C[MAXC][MAXC];
void calc_comb() {
  for (int i = (0); i < (int)(MAXC); i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1); j < (int)(i); j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
}
int n, m, k;
int main() {
  calc_comb();
  while (scanf("%d %d %d", &n, &m, &k) >= 1) {
    long long ans = C[n - 1][2 * k] * C[m - 1][2 * k] % MOD;
    printf("%lld\n", ans);
  }
  return 0;
}
