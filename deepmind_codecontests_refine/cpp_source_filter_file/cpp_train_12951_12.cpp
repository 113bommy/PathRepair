#include <bits/stdc++.h>
using namespace std;
char A[105], B[105], S[105];
int fail[105], dp[105][105][105];
int n, m, x, y, z, k, w;
char ANS[105];
struct node {
  int i, j, l;
} pre[105][105][105], cur[105][105][105], tmp, a;
int main() {
  scanf("%s", A);
  scanf("%s", B);
  scanf("%s", S);
  k = strlen(S);
  fail[0] = -1;
  for (int i = (1); i < (k); i++) {
    x = fail[i - 1];
    while (x != -1 && S[x + 1] != S[i]) x = fail[x];
    if (S[x + 1] == S[i])
      fail[i] = x + 1;
    else
      fail[i] = x;
  }
  n = strlen(A);
  m = strlen(B);
  memset(pre, -1, sizeof(pre));
  memset(cur, -1, sizeof(cur));
  for (int i = (0); i <= (max(n, m)); i++) {
    dp[i][0][0] = dp[0][i][0] = 0;
  }
  for (int i = (n); i >= (1); i--) A[i] = A[i - 1];
  for (int i = (m); i >= (1); i--) B[i] = B[i - 1];
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      for (int l = (0); l < (k); l++) {
        if (dp[i - 1][j][l] > dp[i][j][l]) {
          dp[i][j][l] = dp[i - 1][j][l];
          pre[i][j][l] = cur[i - 1][j][l];
          cur[i][j][l] = cur[i - 1][j][l];
        }
        if (dp[i][j - 1][l] > dp[i][j][l]) {
          dp[i][j][l] = dp[i][j - 1][l];
          pre[i][j][l] = cur[i][j - 1][l];
          cur[i][j][l] = cur[i][j - 1][l];
        }
      }
      if (A[i] != B[j]) continue;
      for (int l = (0); l < (k); l++) {
        if (dp[i - 1][j - 1][l] == -1) continue;
        x = l - 1;
        while (x != -1 && A[i] != S[x + 1]) x = fail[x];
        if (S[x + 1] == A[i] && dp[i - 1][j - 1][l] + 1 > dp[i][j][x + 2]) {
          dp[i][j][x + 2] = dp[i - 1][j - 1][l] + 1;
          pre[i][j][x + 2] = cur[i - 1][j - 1][l];
          cur[i][j][x + 2].i = i;
          cur[i][j][x + 2].j = j;
          cur[i][j][x + 2].l = l;
        } else if (S[x + 1] != A[i] &&
                   dp[i - 1][j - 1][l] + 1 > dp[i][j][x + 1]) {
          dp[i][j][x + 1] = dp[i - 1][j - 1][l] + 1;
          pre[i][j][x + 1] = cur[i - 1][j - 1][l];
          cur[i][j][x + 1].i = i;
          cur[i][j][x + 1].j = j;
          cur[i][j][x + 1].l = l;
        }
      }
    }
  x = -2;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      for (int l = (0); l < (k); l++) {
        if (dp[i][j][l] > x) {
          x = dp[i][j][l];
          tmp.i = i;
          tmp.j = j;
          tmp.l = l;
        }
      }
  if (x == 0) {
    printf("0\n");
    return 0;
  }
  w = 0;
  while (tmp.i != -1) {
    ANS[w++] = A[tmp.i];
    a = tmp;
    tmp = pre[a.i][a.j][a.l];
  }
  for (int i = (w - 1); i >= (0); i--) printf("%c", ANS[i]);
  printf("\n");
  return 0;
}
