#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
char s[N], t[N];
int dp[N][N], ls, lt, ans;
int main() {
  scanf("%s%s", s, t);
  ls = strlen(s), lt = strlen(t);
  for (int i = 0; i < ls; i++) {
    for (int j = 0; j < lt; j++)
      dp[i + 1][j + 1] =
          (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1) % mod) % mod;
    ans = (ans + dp[i + 1][lt]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
