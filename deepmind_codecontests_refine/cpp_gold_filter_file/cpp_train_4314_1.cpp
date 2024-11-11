#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 18][110], per = 1, fact[12], cnt[12];
int main() {
  int m, i;
  char str[50];
  scanf("%s%d", str, &m);
  int n = strlen(str);
  for (i = 0; i < n; i++) cnt[str[i] - '0']++;
  dp[0][0] = 1;
  for (int i = 0; i < (1ll << n); i++) {
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j)))
        for (int k = 0; k < m; k++) {
          if (i || (str[j] - '0'))
            dp[(i | (1 << j))][(k * 10 + (str[j] - '0')) % m] += dp[i][k];
        }
    }
  }
  fact[0] = 1;
  for (i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
  for (i = 0; i <= 9; i++) per *= fact[cnt[i]];
  printf("%I64d\n", dp[(1 << n) - 1][0] / per);
}
