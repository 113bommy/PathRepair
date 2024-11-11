#include <bits/stdc++.h>
using namespace std;
int n, m;
bool debug = false;
int k;
char s[105];
int dp[105][105][2], len;
void dd() {
  for (int i = 0; i <= len; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j][k] = 0 - (1 << 30);
      }
    }
  }
}
int main() {
  scanf("%s%d", s + 1, &n);
  int ans = 0;
  int len = (int)strlen(s + 1);
  dd();
  dp[0][0][0] = dp[0][0][1] = 0;
  for (int i = 1; s[i]; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        int pos = dp[i - 1][j][k];
        for (int jj = j; jj <= n; jj++) {
          char ope = (s[i] == 'T' && (jj - j) % 2 == 0) ||
                             (s[i] == 'F' && (jj - j) % 2 == 1)
                         ? 'T'
                         : 'F';
          if (ope == 'T') {
            dp[i][jj][1 - k] = max(dp[i][jj][1 - k], pos);
          } else {
            dp[i][jj][k] = max(dp[i][jj][k], pos + (k == 0 ? 1 : -1));
          }
        }
      }
    }
  }
  for (int k = 0; k < 2; k++) {
    ans = max(ans, dp[len][n][k]);
  }
  printf("%d\n", ans);
  return 0;
}
