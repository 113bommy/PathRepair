#include <bits/stdc++.h>
int n, i, j, k, who, prevx[88], prevk[88], prekx[88], prekv[88], prexv[88],
    prexk[88], cx, ck, cv, dp[88][88][88][3];
char s[111];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (i = 1; i <= n; i++) {
    if (s[i] == 'V') {
      cv++;
      prevx[cv] = cx;
      prevk[cv] = ck;
    } else if (s[i] == 'K') {
      ck++;
      prekx[ck] = cx;
      prekv[ck] = cv;
    } else {
      cx++;
      prexv[cx] = cv;
      prexk[cx] = ck;
    }
  }
  for (i = 0; i <= cv; i++)
    for (j = 0; j <= ck; j++)
      for (k = 0; k <= cx; k++)
        for (who = 0; who <= 2; who++) dp[i][j][k][who] = 1000000000;
  dp[0][0][0][2] = 0;
  for (i = 0; i <= cv; i++)
    for (j = 0; j <= ck; j++)
      for (k = 0; k <= cx; k++) {
        if (i) {
          dp[i][j][k][0] =
              (dp[i][j][k][0] < dp[i - 1][j][k][0] +
                                    (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                                    (0 > prevx[i] - k ? 0 : prevx[i] - k)
                   ? dp[i][j][k][0]
                   : dp[i - 1][j][k][0] +
                         (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                         (0 > prevx[i] - k ? 0 : prevx[i] - k));
          dp[i][j][k][0] =
              (dp[i][j][k][0] < dp[i - 1][j][k][1] +
                                    (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                                    (0 > prevx[i] - k ? 0 : prevx[i] - k)
                   ? dp[i][j][k][0]
                   : dp[i - 1][j][k][1] +
                         (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                         (0 > prevx[i] - k ? 0 : prevx[i] - k));
          dp[i][j][k][0] =
              (dp[i][j][k][0] < dp[i - 1][j][k][2] +
                                    (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                                    (0 > prevx[i] - k ? 0 : prevx[i] - k)
                   ? dp[i][j][k][0]
                   : dp[i - 1][j][k][2] +
                         (0 > prevk[i] - j ? 0 : prevk[i] - j) +
                         (0 > prevx[i] - k ? 0 : prevx[i] - k));
        }
        if (j) {
          dp[i][j][k][1] =
              (dp[i][j][k][1] < dp[i][j - 1][k][1] +
                                    (0 > prekv[j] - i ? 0 : prekv[j] - i) +
                                    (0 > prekx[j] - k ? 0 : prekx[j] - k)
                   ? dp[i][j][k][1]
                   : dp[i][j - 1][k][1] +
                         (0 > prekv[j] - i ? 0 : prekv[j] - i) +
                         (0 > prekx[j] - k ? 0 : prekx[j] - k));
          dp[i][j][k][1] =
              (dp[i][j][k][1] < dp[i][j - 1][k][2] +
                                    (0 > prekv[j] - i ? 0 : prekv[j] - i) +
                                    (0 > prekx[j] - k ? 0 : prekx[j] - k)
                   ? dp[i][j][k][1]
                   : dp[i][j - 1][k][2] +
                         (0 > prekv[j] - i ? 0 : prekv[j] - i) +
                         (0 > prekx[j] - k ? 0 : prekx[j] - k));
        }
        if (k) {
          dp[i][j][k][2] =
              (dp[i][j][k][2] < dp[i][j][k - 1][0] +
                                    (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                                    (0 > prexk[k] - j ? 0 : prexk[k] - j)
                   ? dp[i][j][k][2]
                   : dp[i][j][k - 1][0] +
                         (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                         (0 > prexk[k] - j ? 0 : prexk[k] - j));
          dp[i][j][k][2] =
              (dp[i][j][k][2] < dp[i][j][k - 1][1] +
                                    (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                                    (0 > prexk[k] - j ? 0 : prexk[k] - j)
                   ? dp[i][j][k][2]
                   : dp[i][j][k - 1][1] +
                         (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                         (0 > prexk[k] - j ? 0 : prexk[k] - j));
          dp[i][j][k][2] =
              (dp[i][j][k][2] < dp[i][j][k - 1][2] +
                                    (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                                    (0 > prexk[k] - j ? 0 : prexk[k] - j)
                   ? dp[i][j][k][2]
                   : dp[i][j][k - 1][2] +
                         (0 > prexv[k] - i ? 0 : prexv[k] - i) +
                         (0 > prexk[k] - j ? 0 : prexk[k] - j));
        }
      }
  printf("%d",
         ((dp[cv][ck][cx][0] < dp[cv][ck][cx][1]
               ? dp[cv][ck][cx][0]
               : dp[cv][ck][cx][1]) < dp[cv][ck][cx][2]
              ? (dp[cv][ck][cx][0] < dp[cv][ck][cx][1] ? dp[cv][ck][cx][0]
                                                       : dp[cv][ck][cx][1])
              : dp[cv][ck][cx][2]));
}
