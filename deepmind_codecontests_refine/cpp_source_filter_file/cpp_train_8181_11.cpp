#include <bits/stdc++.h>
using namespace std;
long long int dp[1001][1001][3];
int a[1001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    printf("%d\n", a[0]);
    printf("1\n");
    return 0;
  }
  if (n == 2) {
    printf("%d\n", max(a[0], a[1]));
    printf("1 2\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    dp[i][n][0] = a[i];
    dp[i][n][1] = -1;
    dp[i][n - 1][0] = max(a[i], a[n - 1]);
    dp[i][n - 1][1] = -1;
  }
  for (int i = n - 3; i >= 0; i--) {
    for (int j = n - 2; j > i; j--) {
      dp[i][j][0] = dp[i][j + 2][0] + max(a[j], a[j + 1]);
      dp[i][j][1] = j;
      dp[i][j][2] = j + 1;
      long long int val1 = dp[j][j + 2][0] + max(a[i], a[j + 1]);
      long long int val2 = dp[j + 1][j + 2][0] + max(a[i], a[j]);
      if (dp[i][j][0] > val1 && val1 < val2) {
        dp[i][j][0] = val1;
        dp[i][j][1] = i;
        dp[i][j][2] = j + 1;
      } else if (dp[i][j][0] > val2 && val2 < val1) {
        dp[i][j][0] = val2;
        dp[i][j][1] = i;
        dp[i][j][2] = j;
      }
    }
  }
  printf("%lld\n", dp[0][1][0]);
  int s = 0;
  int e = 1;
  while (1) {
    int x = dp[s][e][1];
    int y = dp[s][e][2];
    if (x == -1 || y == -1) {
      if (e == n) {
        printf("%d\n", s + 1);
      } else {
        printf("%d %d\n", s + 1, e + 1);
      }
      break;
    }
    printf("%lld %lld\n", dp[s][e][1] + 1, dp[s][e][2] + 1);
    if (x == s && y == e) {
      s = e + 1;
    } else if (x == s && y == e + 1)
      s = e;
    else
      s = s;
    e = e + 2;
  }
}
