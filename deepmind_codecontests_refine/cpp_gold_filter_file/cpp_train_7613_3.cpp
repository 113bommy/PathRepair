#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
int n;
char s[N];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) dp[i][i] = 1;
  for (int r = 2; r <= n; ++r) {
    for (int l = 1; l < r; ++l) {
      dp[l][r] = 0x3f3f3f;
      for (int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r - 1] + 1 -
                                     ((s[k] == s[r]) ? 1 : 0));
      }
    }
  }
  printf("%d\n", dp[1][n]);
  return 0;
}
