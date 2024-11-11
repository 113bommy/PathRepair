#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
char c[maxn][maxn];
int dp[maxn][2], num[maxn][2];
int main() {
  int N, M, X, Y, ans;
  scanf("%d%d%d%d", &N, &M, &X, &Y);
  for (int i = 1; i <= N; i++) scanf("%s", c[i] + 1);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      if (c[i][j] == '#')
        num[j][0]++;
      else
        num[j][1]++;
    }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  for (int i = 1; i <= M; i++)
    num[i][0] += num[i - 1][0], num[i][1] += num[i - 1][1];
  for (int i = 1; i <= M; i++) {
    for (int j = max(i - Y + 1, 1); j <= i - X + 1; j++) {
      dp[i][0] = min(dp[i][0], dp[j - 1][1] + (num[i][1] - num[j - 1][1]));
      dp[i][1] = min(dp[i][1], dp[j - 1][0] + (num[i][0] - num[j - 1][0]));
    }
  }
  printf("%d\n", min(dp[M][0], dp[M][1]));
  return 0;
}
