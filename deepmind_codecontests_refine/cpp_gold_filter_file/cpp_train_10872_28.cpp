#include <bits/stdc++.h>
int table[101];
int ans[101][101];
bool find[101];
int main() {
  ans[1][0] = ans[1][1] = 1;
  ans[2][0] = 5;
  ans[2][1] = 3;
  ans[2][2] = 4;
  ans[3][0] = 2;
  ans[3][1] = 1;
  ans[3][2] = 2;
  ans[3][3] = 2;
  find[2] = find[3] = find[1] = 1;
  for (int i = 4; i <= 100; i++) {
    if (i % 2 == 0) {
      ans[i][1] = i / 2 - 1;
      for (int j = 2; j <= i; j++) ans[i][j] = 1;
    } else {
      ans[i][1] = 2;
      ans[i][2] = (i + 1) / 2;
      for (int j = 3; j <= i; j++) ans[i][j] = 1;
    }
  }
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%d", ans[n][i] * ans[m][j]);
        if (j != m)
          printf(" ");
        else
          printf("\n");
      }
    }
  }
}
