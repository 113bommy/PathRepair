#include <bits/stdc++.h>
char c[500010];
int a[500010][2], b[500010][2];
int main() {
  int n, m, i, j, mod = 1000003, ans;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", c);
    for (j = 0; j < m; j++) {
      if (c[j] == '1') {
        a[j][i % 2] = 1;
        b[i][j % 2] = 1;
      } else if (c[j] == '2') {
        a[j][(i + 1) % 2] = 1;
        b[i][j % 2] = 1;
      } else if (c[j] == '3') {
        a[j][(i + 1) % 2] = 1;
        b[i][(j + 1) % 2] = 1;
      } else if (c[j] == '4') {
        a[j][i % 2] = 1;
        b[i][(j + 1) % 2] = 1;
      }
    }
  }
  ans = 1;
  for (i = 0; i < n; i++) {
    ans = (ans * (2 - a[i][0] - a[i][1])) % mod;
  }
  for (i = 0; i < m; i++) {
    ans = (ans * (2 - b[i][0] - b[i][1])) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
