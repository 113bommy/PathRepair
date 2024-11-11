#include <bits/stdc++.h>
using namespace std;
int N;
char S[100];
int dp[100][100][100][2];
int pos[3][100], num[3][100];
inline int cmd(int i, int j, int k, int p) {
  return max(0, num[0][p] - i) + max(0, num[1][p] - j) + max(0, num[2][p] - k) -
         1;
}
void init() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      for (int z = 0; z < 100; z++) {
        for (int x = 0; x < 2; x++) {
          dp[i][j][z][x] = 10000;
        }
      }
    }
  }
  dp[0][0][0][0] = 0;
}
int main() {
  init();
  scanf("%d%s", &N, S + 1);
  for (int i = 1; i <= N; i++) {
    num[0][i] = num[0][i - 1];
    num[1][i] = num[1][i - 1];
    num[2][i] = num[2][i - 1];
    if (S[i] == 'V') {
      pos[0][num[0][i]++] = i;
    } else if (S[i] == 'K') {
      pos[1][num[1][i]++] = i;
    } else {
      pos[2][num[2][i]++] = i;
    }
  }
  for (int i = 0; i <= num[0][N]; i++)
    for (int j = 0; j <= num[1][N]; j++)
      for (int k = 0; k <= num[2][N]; k++)
        for (int is_v = 0; is_v < 2; is_v++) {
          if (i < num[0][N])
            dp[i + 1][j][k][1] =
                min(dp[i + 1][j][k][1],
                    dp[i][j][k][is_v] + cmd(i, j, k, pos[0][i]));
          if (j < num[1][N] && !is_v)
            dp[i][j + 1][k][0] =
                min(dp[i][j + 1][k][0],
                    dp[i][j][k][is_v] + cmd(i, j, k, pos[1][j]));
          if (k < num[2][N])
            dp[i][j][k + 1][0] =
                min(dp[i][j][k + 1][0],
                    dp[i][j][k][is_v] + cmd(i, j, k, pos[2][k]));
        }
  printf("%d\n", min(dp[num[0][N]][num[1][N]][num[2][N]][0],
                     dp[num[0][N]][num[1][N]][num[2][N]][1]));
  return 0;
}
