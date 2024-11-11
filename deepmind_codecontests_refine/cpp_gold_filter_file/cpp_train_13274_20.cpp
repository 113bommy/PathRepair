#include <bits/stdc++.h>
int k, ans[550][550];
int main() {
  scanf("%d", &k);
  ans[1][1] = 1;
  for (int n = 1; n <= k; n++) {
    int tmp = pow(2, n - 1);
    for (int i = 1; i <= tmp; i++)
      for (int j = 1; j <= tmp; j++)
        ans[tmp + i][j] = ans[i][tmp + j] = ans[i][j],
                  ans[tmp + i][tmp + j] = ans[i][j] ^ 1;
  }
  int tmp = pow(2, k);
  for (int i = 1; i <= tmp; i++) {
    for (int j = 1; j <= tmp; j++) putchar(ans[i][j] ? '+' : '*');
    putchar('\n');
  }
  return 0;
}
