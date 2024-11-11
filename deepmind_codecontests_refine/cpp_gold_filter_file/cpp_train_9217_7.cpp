#include <bits/stdc++.h>
using namespace std;
int N;
int dp[101][3];
int arr[101];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) dp[i][j] = 200;
    scanf("%d", &arr[i]);
  }
  dp[1][0] = 1;
  if (arr[1] == 1 || arr[1] == 3) {
    dp[1][1] = 0;
  }
  if (arr[1] == 2 || arr[1] == 3) {
    dp[1][2] = 0;
  }
  for (int i = 2; i <= N; i++) {
    int cc = arr[i];
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
    dp[i][0] = min(dp[i][0], dp[i - 1][2]) + 1;
    if (cc == 1 || cc == 3) {
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    }
    if (cc == 2 || cc == 3) {
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
  }
  int ret = min(dp[N][0], dp[N][1]);
  printf("%d", min(ret, dp[N][2]));
}
