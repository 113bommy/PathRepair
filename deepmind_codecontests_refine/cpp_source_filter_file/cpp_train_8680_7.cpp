#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c;
  while (c = getchar(), (c != '-') && (c < '0' || c > '9'))
    ;
  bool neg = (c == '-');
  int ret = (neg ? 0 : c - 48);
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
  return neg ? -ret : ret;
}
const int MAXN = 55, MOD = 7 + 1e9;
int N, M, K, ans, c[MAXN * 2][MAXN * 2], dp[MAXN][MAXN][MAXN][MAXN * 2];
void init() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i <= N; i++) c[i][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = min(105, c[i - 1][j] + c[i - 1][j - 1]);
}
void work() {
  int n = N / 2;
  for (int i = 1; i <= n; i++) dp[i][i][1][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= min(n, M); k++)
        for (int p = 1; p <= K; p++) {
          int tmp = dp[i][j][k][p];
          if (!tmp) continue;
          ans = ((long long)tmp * (M - k) + ans) % MOD;
          for (int q = 1; q <= N - i; q++) {
            int tv = p * c[j + p - 1][j - 1];
            if (tv <= K) (dp[i + q][q][k + 1][tv] += tmp) %= MOD;
          }
        }
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
