#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 2005;
char s[MAXN];
int dp[MAXN][MAXN];
int t[MAXN][MAXN];
int D[MAXN][MAXN];
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  dp[n + 1][0] = 1;
  D[n + 1][0] = s[n - 1] - 'a';
  for (int i = n; i >= 1; i--) {
    for (int j = n - i + 1; j <= k; j++) {
      t[i][j] = add(t[i][j], (long long)dp[i + 1][j - (n - i + 1)] *
                                 (25 - (s[i - 1] - 'a')) % MOD);
      dp[i][j] = add(dp[i][j], t[i][j]);
    }
    for (int j = 0; j <= k; j++) dp[i][j] = add(dp[i][j], D[i + 1][j]);
    dp[i][0] = add(dp[i][0], 1);
    int flag = i;
    for (int j = i + 1; j <= n; j++) {
      int mx = (j - i) * (n - j + 1);
      if (mx > k) break;
      flag = j;
      for (int z = mx; z <= k; z++) {
        dp[i][z] = add(dp[i][z], t[j][z - (j - i) * (n - j + 1)]);
      }
    }
    for (int j = n; j > flag; j--) {
      int mx = (j - i) * (n - j + 1);
      if (mx > k) break;
      for (int z = mx; z <= k; z++) {
        dp[i][z] = add(dp[i][z], t[j][z - (j - i) * (n - j + 1)]);
      }
    }
    for (int j = 0; j <= k; j++)
      if (i > 1) {
        D[i][j] = D[i + 1][j];
        D[i][j] = add(D[i][j], (long long)dp[i][j] * (s[i - 2] - 'a') % MOD);
      }
  }
  printf("%d\n", dp[1][k]);
  return 0;
}
