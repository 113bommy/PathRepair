#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 5000;
char s[MAXN + 1];
int n;
int dp[MAXN + 1][3];
void run() {
  scanf("%s", s);
  n = strlen(s);
  memset(dp, 0, sizeof(dp));
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j < (3); ++j) {
      if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      if (i < n && s[i] == "aba"[j])
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
    }
  printf("%d\n", dp[n][2]);
}
int main() {
  run();
  return 0;
}
