#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int INF = 0x3f3f3f3f;
char arr[N];
int s[N];
int dp[N][N];
int rec[N][N];
int main() {
  int cnt;
  scanf("%d", &cnt);
  scanf("%s", arr);
  arr[cnt] = -1;
  int n = 0;
  for (int i = 1; i <= cnt; i++) {
    if (arr[i] != arr[i - 1]) {
      s[n] = arr[i - 1] - 'a';
      n++;
    }
  }
  memset(dp, INF, sizeof(dp));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
    rec[i][i] = 1 << s[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      for (int k = l; k < r; k++) {
        if (rec[k + 1][r] & rec[l][k]) {
          if (dp[l][r] > dp[k + 1][r] + dp[l][k]) {
            dp[l][r] = dp[k + 1][r] + dp[l][k];
            rec[l][r] = rec[k + 1][r] & rec[l][k];
          } else if (dp[l][r] == dp[k + 1][r] + dp[l][k]) {
            rec[l][r] = rec[l][r] | (rec[k + 1][r] & rec[l][k]);
          }
        } else {
          if (dp[l][r] > dp[k + 1][r] + dp[l][k] + 1) {
            dp[l][r] = dp[k + 1][r] + dp[l][k] + 1;
            rec[l][r] = rec[k + 1][r] | rec[l][k];
          } else if (dp[l][r] == dp[k + 1][r] + dp[l][k] + 1) {
            rec[l][r] = rec[l][r] | (rec[k + 1][r] | rec[l][k]);
          }
        }
      }
    }
  }
  printf("%d\n", dp[0][n - 1] + 1);
}
