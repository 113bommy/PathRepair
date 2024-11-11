#include <bits/stdc++.h>
bool a[1005][1005];
int main() {
  int n;
  scanf("%d", &n);
  if (n == 3) {
    return puts("0 1 0\n0 0 1\n1 0 0"), 0;
  } else if (n == 4) {
    return puts("-1"), 0;
  };
  int n1 = n - (~n & 1);
  int i, j;
  for (i = 1; i <= n1; i++) {
    a[i][i % n + 1] = 1;
    for (j = 4; j < n1; j += 2) {
      a[i][(i + j - 2) % n1 + 1] = 1;
    };
  };
  if (~n & 1) {
    a[n][1] = 1;
    for (i = 5; i <= n; i += 2) a[n][i] = 1;
    a[3][n] = 1;
    for (i = 2; i < n; i += 2) a[i][n] = 1;
  };
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      putchar(48 + a[i][j]);
      putchar(32);
    };
    putchar('\n');
  };
}
