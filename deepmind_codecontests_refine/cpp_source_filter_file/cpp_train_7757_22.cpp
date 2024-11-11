#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000000 + 5;
const long long DIFF = 2000;
const long long mod = 100000000 + 7;
long long dp[DIFF + 5][DIFF + 5];
char s[maxn];
int main() {
  dp[0][0] = 1;
  for (int i = 1; i <= DIFF; dp[i][0] = dp[i - 1][1], i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
  long long n, m;
  scanf("%I64d%I64d%s", &n, &m, s);
  long long len = strlen(s), diff = 0, Min = 0, ans = 0;
  for (long long i = 0; i < len; i++) {
    diff += (s[i] == '(' ? 1 : -1);
    Min = min(Min, diff);
  }
  for (long long i = 0; i <= n - m; i++)
    for (long long j = 0; j <= i; j++)
      if (j + Min >= 0 && j + diff >= 0 && j + diff <= n - m)
        ans = (ans + (dp[i][j] * dp[n - m - i][j + diff]) % mod) % mod;
  printf("%I64d\n", ans);
}
