#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MOD = 51123987;
char str[MAXN];
char s[MAXN];
int dp[200][50][50][50];
int nex[200][3];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof(dp));
    scanf("%s", str);
    int k = 0;
    s[k++] = str[0];
    for (int i = 1; i < n; i++) {
      if (str[i] != str[i - 1]) s[k++] = str[i];
    }
    memset(nex, -1, sizeof(nex));
    for (int i = 0; i < k; i++) {
      for (int j = i; j < k; j++) {
        if (s[j] == 'a' && nex[i][0] == -1) nex[i][0] = j;
        if (s[j] == 'b' && nex[i][1] == -1) nex[i][1] = j;
        if (s[j] == 'c' && nex[i][2] == -1) nex[i][2] = j;
      }
    }
    int tn = n / 3 + 1;
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int A = 0; A <= tn; A++) {
        for (int B = 0; B <= tn; B++) {
          for (int C = 0; C <= tn; C++) {
            if (dp[i - 1][A][B][C] == 0) continue;
            int dex = nex[i - 1][0];
            if (dex != -1) {
              dp[dex][A + 1][B][C] += dp[i - 1][A][B][C];
              dp[dex][A + 1][B][C] %= MOD;
            }
            dex = nex[i - 1][1];
            if (dex != -1) {
              dp[dex][A][B + 1][C] += dp[i - 1][A][B][C];
              dp[dex][A][B + 1][C] %= MOD;
            }
            dex = nex[i - 1][2];
            if (dex != -1) {
              dp[dex][A][B][C + 1] += dp[i - 1][A][B][C];
              dp[dex][A][B][C + 1] %= MOD;
            }
          }
        }
      }
    }
    int res = 0;
    if (n % 3 == 0) {
      for (int i = 0; i < k; i++) {
        res += dp[i][n / 3][n / 3][n / 3];
        res %= MOD;
      }
    } else if (n % 3 == 1) {
      for (int i = 0; i < k; i++) {
        res += dp[i][n / 3 + 1][n / 3][n / 3];
        res %= MOD;
        res += dp[i][n / 3][n / 3 + 1][n / 3];
        res %= MOD;
        res += dp[i][n / 3][n / 3][n / 3 + 1];
        res %= MOD;
      }
    } else {
      for (int i = 0; i < k; i++) {
        res += dp[i][n / 3 + 1][n / 3 + 1][n / 3];
        res %= MOD;
        res += dp[i][n / 3 + 1][n / 3][n / 3 + 1];
        res %= MOD;
        res += dp[i][n / 3][n / 3 + 1][n / 3 + 1];
        res %= MOD;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
