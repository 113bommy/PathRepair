#include <bits/stdc++.h>
int main() {
  int ans[200][200];
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      ans[i][j] = 0;
    }
  }
  ans[0][0] = 1;
  ans[1][0] = 0;
  ans[1][1] = 1;
  for (int i = 2; i <= 150; i++) {
    bool jud = true;
    ans[i][0] = ans[i - 2][0];
    for (int j = 1; j <= i; j++) {
      ans[i][j] = ans[i - 1][j - 1] + ans[i - 2][j];
      if (ans[i][j] * ans[i][j] > 1) {
        jud = false;
        break;
      }
    }
    if (!jud) {
      ans[i][0] = -ans[i - 2][0];
      for (int j = 0; j <= i; j++) {
        ans[i][j] = ans[i - 1][j - 1] - ans[i - 2][j];
      }
    }
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", n);
    for (int i = 0; i <= n; i++) {
      printf("%d ", ans[n][i]);
    }
    printf("\n%d\n", n - 1);
    for (int i = 0; i <= n - 1; i++) {
      printf("%d ", ans[n - 1][i]);
    }
    printf("\n");
  }
}
