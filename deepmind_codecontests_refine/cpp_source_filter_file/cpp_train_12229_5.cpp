#include <bits/stdc++.h>
using namespace std;
int n, m, mod;
char str[505];
int num[505], a[3];
long long dp[505][505];
int main() {
  scanf("%d %d %d", &n, &m, &mod);
  memset(num, 0, sizeof(num));
  for (int i = 0; i < m; i++) {
    scanf("%s", str);
    for (int j = 0; j < n; j++) num[j] += (str[j] - '0');
  }
  memset(dp, 0, sizeof(dp));
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) a[abs(num[i] - 2)]++;
  dp[a[1]][a[2]] = 1;
  for (int i = (n - m) * 2; i > 0; i -= 2) {
    for (int j = 0; j <= i; j += 2) {
      int k = (i - j) / 2;
      long long res;
      if (j > 500 || k > 250) continue;
      if (j >= 2) {
        res = dp[j][k] * j * (j - 1) / 2 % mod;
        dp[j - 2][k] = (dp[j - 2][k] + res) % mod;
      }
      if (j && k) {
        res = dp[j][k] * j * k % mod;
        dp[j][k - 1] = (dp[j][k - 1] + res) % mod;
      }
      if (k >= 2) {
        res = dp[j][k] * k * (k - 1) / 2 % mod;
        dp[j + 2][k - 2] = (dp[j + 2][k - 2] + res) % mod;
      }
    }
  }
  printf("%I64d\n", dp[0][0]);
  return 0;
}
