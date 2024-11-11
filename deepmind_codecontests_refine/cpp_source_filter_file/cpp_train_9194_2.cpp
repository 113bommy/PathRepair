#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int mod = 1000000000 + 7;
char str[maxn];
long long dp[maxn][maxn * maxn];
int main() {
  for (int i = 0; i < 26; i++) dp[0][i] = 1;
  for (int i = 0; i < maxn - 1; i++) {
    for (int j = 0; j < maxn * maxn; j++) {
      if (dp[i][j] == 0) continue;
      for (int h = 0; h < 26; h++) {
        dp[i + 1][j + h] = (dp[i + 1][j + h] + dp[i][j]) % mod;
      }
    }
  }
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%s", str);
    int len = strlen(str), s = 0;
    for (int i = 0; i < len; i++) s += str[i] - 'a';
    cout << dp[len - 1][s] << endl;
  }
  return 0;
}
