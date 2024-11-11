#include <bits/stdc++.h>
using namespace std;
bool dp[101][101][902];
int dpl[101][101][902];
int a[101][101];
int b[101];
int main() {
  char ch;
  memset(dp, 0, sizeof(dp));
  int n, m, kk;
  scanf("%d%d%d", &n, &m, &kk);
  for (int i = 0; i < n; i++) {
    scanf("%c", &ch);
    for (int j = 0; j < m; j++) {
      scanf("%c", &ch);
      a[i][j] = ch - '0';
    }
  }
  for (int j = 0; j < m; j++) dp[n - 1][j][a[n - 1][j]] = 1;
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 900; k++) {
        if (dp[i][j][k]) {
          if (j != 0) {
            dp[i - 1][j - 1][k + a[i - 1][j - 1]] = 1;
            dpl[i - 1][j - 1][k + a[i - 1][j - 1]] = j;
          }
          if (j != m - 1) {
            dp[i - 1][j + 1][k + a[i - 1][j + 1]] = 1;
            dpl[i - 1][j + 1][k + a[i - 1][j + 1]] = j;
          }
        }
      }
    }
  }
  bool tell = 0;
  for (int k = 900; k >= 0; k--)
    if (k % (kk + 1) == 0) {
      for (int j = 0; j < m; j++) {
        if (dp[0][j][k]) {
          printf("%d\n", k);
          int ll = 0, jj = j, kk = k;
          b[ll] = j;
          while (ll != n - 1) {
            b[ll + 1] = dpl[ll][jj][kk];
            kk -= a[ll][jj];
            jj = b[ll + 1];
            ll++;
          }
          printf("%d\n", jj + 1);
          for (int i = n - 2; i >= 0; i--) {
            if (b[i] > b[i + 1])
              printf("R");
            else
              printf("L");
          }
          printf("\n");
          tell = 1;
          break;
        }
      }
      if (tell) break;
    }
  if (!tell) printf("-1\n");
}
