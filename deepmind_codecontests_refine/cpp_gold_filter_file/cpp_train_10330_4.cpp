#include <bits/stdc++.h>
using namespace std;
const int N = int(410);
char s[N], r[N], ss[N], rr[N];
int dp[N][N];
const int INF = 100010;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("\n%s", ss);
    scanf("\n%s", rr);
    int n = strlen(ss);
    int m = strlen(rr);
    for (int i = 1; i <= n; i++) {
      s[i] = ss[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      r[i] = rr[i - 1];
    }
    bool ok = false;
    for (int d = 0; d <= m; d++) {
      for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
          dp[i][j] = -INF;
        }
      }
      dp[0][0] = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= d; j++) {
          dp[i][j] = dp[i - 1][j];
          if (j > 0 && s[i] == r[j]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
          }
          int sz = dp[i - 1][j];
          if (sz >= 0 && d + sz + 1 <= m && s[i] == r[d + sz + 1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
          }
        }
        if (dp[i][d] == m - d) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
