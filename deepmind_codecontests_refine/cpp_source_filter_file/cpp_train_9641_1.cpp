#include <bits/stdc++.h>
using namespace std;
char s[255][255];
int n, m;
int borad[255][255];
int dp[255][(1 << 15) + 20][2][2];
inline void upd(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  if (n > m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) borad[i][j] = s[i][j] == '.';
  } else {
    swap(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) borad[i][j] = s[j][i] == '.';
  }
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n * m; i++) {
    int x = i / m, y = i % m;
    for (int msk = 0; msk < (1 << m); msk++) {
      for (int f1 = 0; f1 < 2; f1++) {
        for (int f2 = 0; f2 < 2; f2++) {
          if (dp[i][msk][f1][f2]) {
            if (!borad[x][y])
              upd(dp[i + 1][msk & (~(1 << y))][0][f2], dp[i][msk][f1][f2]);
            else {
              upd(dp[i + 1][msk | (1 << y)][y != m - 1 ? 1 : 0][f2],
                  dp[i][msk][f1][f2]);
              if ((msk >> y & 1) || f1)
                upd(dp[i + 1][msk][y != m - 1 ? f1 : 0][f2],
                    dp[i][msk][f1][f2]);
              else if (f2 == 0)
                upd(dp[i + 1][msk][f1][f2 + 1], dp[i][msk][f1][f2]);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << m); i++)
    for (int j = 0; j < 2; j++) upd(ans, dp[n * m][i][0][j]);
  printf("%I64d\n", ans);
  return 0;
}
