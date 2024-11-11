#include <bits/stdc++.h>
char a[305][305];
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (n == 5) {
    puts(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1");
    return 0;
  } else if (n == 3) {
    puts(">vv\n^<.\n^.<\n1 3");
    return 0;
  };
  int i, j;
  memset(a, '.', sizeof(a));
  int t = n / 3 - 1;
  for (i = 1; i <= n; i++) {
    if (i & 1) {
      for (j = 2; j <= t + 1; j++) {
        a[i][j] = '>';
      };
      for (j = t + 3; j < n; j += 2) {
        a[i][j] = '>';
      };
      a[i][n] = 'v';
    } else {
      for (j = n; j >= n - t + 1; j--) {
        a[i][j] = '<';
      };
      for (j = n - t + 1 - 2; j > 2; j -= 2) {
        a[i][j] = '<';
      };
      a[i][2] = 'v';
    };
  };
  for (i = n; i >= n - t + 1; i--) {
    a[i][1] = '^';
  };
  for (i = n - t + 1 - 2; i > 1; i -= 2) {
    a[i][1] = '^';
  };
  a[1][1] = '>';
  a[n][2] = '<';
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) putchar(a[i][j]);
    putchar('\n');
  };
  puts("1 1");
}
