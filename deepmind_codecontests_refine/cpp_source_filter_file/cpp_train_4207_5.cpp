#include <bits/stdc++.h>
const int N = 1010;
int n, i, j, a[N][N];
void c(int n) {
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n / 2; j++) a[i][(i + j - 1) % n + 1] = 1;
}
int main() {
  scanf("%d", &n);
  if (n == 4) {
    printf("-1\n");
    return 0;
  }
  if (n & 1)
    c(n);
  else {
    c(n - 1);
    for (i = 1; i <= n; i++)
      if (i & 1)
        a[n][i] = 1;
      else
        a[i][n] = 1;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (j > 1) printf(" ");
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  scanf("\n");
  return 0;
}
