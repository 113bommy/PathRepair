#include <bits/stdc++.h>
using namespace std;
void dynamic_program(int n);
int decrease(int i, int height);
const int INF = 0x3f3f3f3f;
const int MAX = 5005;
int a[MAX];
int dp[MAX][MAX][2];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    dynamic_program(n);
    int bound = (n / 2) + (n % 2);
    for (int j = 1; j <= bound; j++) {
      printf("%d", min(dp[n][j][0], dp[n][j][1]));
      printf(j == bound ? "\n" : " ");
    }
  }
  return 0;
}
void dynamic_program(int n) {
  memset(dp, INF, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    dp[i][0][0] = 0;
  }
  dp[1][1][1] = 0;
  int bound = (n / 2) + (n % 2);
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= bound; j++) {
      dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
      dp[i][j][0] =
          min(dp[i][j][0], dp[i - 1][j][1] + decrease(i, a[i - 1] - 1));
      dp[i][j][1] =
          min(dp[i][j][1], dp[i - 1][j - 1][0] + decrease(i - 1, a[i] - 1));
      dp[i][j][1] =
          min(dp[i][j][1], dp[i - 2][j - 1][1] +
                               decrease(i - 1, min(a[i - 2] - 1, a[i] - 1)));
    }
}
inline int decrease(int i, int height) {
  return (a[i] <= height ? 0 : a[i] - height);
}
