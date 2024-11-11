#include <bits/stdc++.h>
using namespace std;
int d[11];
int n;
long long c[110][110];
const int Mod = 1000000007;
long long dp[110][11];
long long get(int num, int dig) {
  if (dp[num][dig] >= 0) return dp[num][dig];
  long long &res = dp[num][dig];
  res = 0;
  if (dig == 9)
    res = (num >= d[9] ? 1 : 0);
  else if (dig > 0) {
    for (int i = d[dig]; i <= num; ++i) {
      res += (get(num - i, dig + 1) * c[num][i]) % Mod;
      res %= Mod;
    }
  } else {
    for (int i = d[0]; i <= num; ++i) {
      res += (get(num - i, 1) * c[num - 1][i]) % Mod;
      res %= Mod;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 10; ++i) scanf("%d", d + i);
  c[0][0] = 1;
  for (int i = 1; i < 110; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      c[i][j] %= Mod;
    }
  }
  memset(dp, -1, sizeof(dp));
  long long sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum = (sum + get(i, 0)) % Mod;
  }
  printf("%I64d\n", sum);
  return 0;
}
