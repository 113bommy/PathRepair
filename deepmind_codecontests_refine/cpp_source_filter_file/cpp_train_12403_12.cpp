#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const double PI = acos(-1.0);
const double EPS = 1e-6;
int dp[41][7];
int n, m;
int main() {
  dp[0][1] = dp[1][1] = 0, dp[2][1] = 1;
  for (int i = 3; i < 41; i++) dp[i][1] = dp[i - 3][1] + 2;
  dp[2][2] = 2;
  for (int i = 3; i < 21; i++) dp[i][2] = dp[i - 1][2] + ((i & 1) > 0 ? 2 : 1);
  dp[3][3] = 6, dp[4][3] = 8, dp[5][3] = 11, dp[6][3] = 13, dp[7][3] = 15;
  for (int i = 8; i < 14; i++) {
    dp[i][3] = dp[i - 5][3] + 11;
    if (i % 4 == 1) dp[i][3]++;
  }
  dp[4][4] = 12, dp[5][4] = 14, dp[6][4] = 17, dp[7][4] = 21;
  dp[8][4] = 24, dp[9][4] = 26, dp[10][4] = 30;
  dp[5][5] = 18, dp[6][5] = 23, dp[7][5] = 26, dp[8][5] = 29;
  dp[6][6] = 26;
  scanf("%d%d", &n, &m);
  if (m > n) swap(n, m);
  switch (m) {
    case 1:
      printf("%d\n", dp[n][1]);
      break;
    case 2:
      printf("%d\n", dp[n][2]);
      break;
    case 3:
      printf("%d\n", dp[n][3]);
      break;
    case 4:
      printf("%d\n", dp[n][4]);
      break;
    case 5:
      printf("%d\n", dp[n][5]);
      break;
    case 6:
      printf("%d\n", dp[6][6]);
      break;
  }
  return 0;
}
