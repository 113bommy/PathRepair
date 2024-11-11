#include <bits/stdc++.h>
using namespace std;
int dp[6000 + 10][6000 + 10];
char num[6000 + 10][6000 + 10];
char temp[6000 + 10][6000 + 10];
int cmp(const void *_a, const void *_b) {
  int *a = (int *)_a;
  int *b = (int *)_b;
  return *b - *a;
}
int main() {
  int n, m;
  int ans;
  while (scanf("%d %d", &n, &m) > 0) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) scanf("%s", num[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        temp[i][j] = num[j][i];
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!i)
          dp[i][j] = temp[i][j] - '0';
        else if (temp[i][j] - '0')
          dp[i][j] = dp[i - 1][j] + 1;
        else
          dp[i][j] = 0;
      }
    }
    ans = -10000000;
    for (int i = 0; i < m; i++) {
      qsort(dp[i], n, sizeof(int), cmp);
      for (int j = 0; j < m; j++) {
        ans = max(ans, dp[i][j] * (j + 1));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
