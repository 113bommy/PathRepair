#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, inv2 = (MOD + 1) / 2;
double eps = 1e-4;
int INF = 0x7fffffff;
int inf = 1e9;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
long long c[300][300], dp[300][300], mi1[300], mi2[300];
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
int main() {
  c[0][0] = 1;
  for (int i = (int)1; i <= (int)250; i++) {
    c[i][0] = 1;
    for (int j = (int)1; j <= (int)i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
  int n = read(), k = read();
  mi1[0] = 1;
  for (int i = (int)1; i <= (int)n; i++) mi1[i] = mi1[i - 1] * k % MOD;
  mi2[0] = 1;
  for (int i = (int)1; i <= (int)n; i++) mi2[i] = mi2[i - 1] * (k - 1) % MOD;
  dp[0][n] = 1;
  for (int i = (int)1; i <= (int)n; i++)
    for (int j = (int)0; j <= (int)n; j++) {
      dp[i][j] =
          dp[i - 1][j] * mi2[j] % MOD * (mi1[n - j] - mi2[n - j] % MOD) % MOD;
      for (int p = (int)1; p <= (int)n - j; p++)
        dp[i][j] = (dp[i][j] + c[j + p][p] * dp[i - 1][j + p] % MOD *
                                   mi1[n - j - p] % MOD * mi2[j] % MOD) %
                   MOD;
    }
  printf("%I64d\n", dp[n][0]);
  return 0;
}
