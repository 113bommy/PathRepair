#include <bits/stdc++.h>
long b[2000][2000], sum, i, j, k, l, n, a[2000][2000], t[2000];
int main() {
  scanf("%ld%ld", &n, &k);
  for (i = 1; i <= n; i++) {
    t[i] = 0;
    for (j = 1; j <= i; j++)
      if (i % j == 0) {
        t[i]++;
        a[i][t[i]] = j;
      }
  }
  for (i = 1; i <= n; i++) b[1][i] = 1;
  for (i = 2; i <= k; i++)
    for (j = 1; j <= n; j++)
      for (l = 1; l <= t[j]; l++)
        b[i][j] = (b[i][j] + b[i - 1][a[j][l]]) % 1000000007;
  sum = 0;
  for (i = 1; i <= n; i++) sum = (sum + b[k][i]) % 1000000007;
  printf("%ld", sum);
}
