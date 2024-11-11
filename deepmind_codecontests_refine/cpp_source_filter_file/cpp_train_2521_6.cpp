#include <bits/stdc++.h>
int main() {
  int n, m, k, i, j, la;
  scanf("%d%d%d", &n, &m, &k);
  if (2 * k > m - 1 || 2 * k > n - 1) {
    printf("0");
    return 0;
  }
  int64_t ans = 0;
  if (n > m)
    la = n;
  else
    la = m;
  int mat[la + 1][la + 1];
  for (i = 0; i <= la; i++)
    for (j = 0; j <= la; j++) mat[i][j] = 0;
  for (i = 1; i <= la; i++) mat[i][i] = 1;
  for (i = 1; i <= la; i++) mat[i][1] = i;
  for (i = 2; i <= la; i++)
    for (j = 2; j < i; j++) {
      mat[i][j] = mat[i - 1][j - 1] % 1000000007 + mat[i - 1][j] % 1000000007;
    }
  ans = (mat[n - 1][2 * k] * mat[m - 1][2 * k]) % 1000000007;
  printf("%I64d ", ans);
  return 0;
}
