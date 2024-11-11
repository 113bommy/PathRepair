#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, k;
long long f[1005][1005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int t = max(n, m);
  for (int j = 1; j <= t; j++) f[0][j] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= t; j++) {
      f[i][j] = (f[i - 1][j - 2] + f[i][j - 1] * 2 - f[i][j - 2] + MOD) % MOD;
    }
  printf("%d\n", (int)((f[k][n]) * (f[k][m]) % MOD));
  return 0;
}
