#include <bits/stdc++.h>
using namespace std;
int n;
char s[100];
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
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    num[0][i] = num[0][i - 1];
    num[1][i] = num[1][i - 1];
    num[2][i] = num[2][i - 1];
    if (s[i] == 'V') {
      pos[0][num[0][i]++] = i;
    } else if (s[i] == 'K') {
      pos[1][num[1][i]++] = i;
    } else {
      pos[2][num[2][i]++] = i;
    }
  }
  int a = num[0][n];
  int b = num[1][n];
  int c = num[2][n];
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int z = 0; z <= c; z++) {
        for (int v = 0; v < 2; v++) {
          if (i < a) {
            dp[i + 1][j][z][1] = min(dp[i + 1][j][z][1],
                                     dp[i][j][z][v] + cmd(i, j, z, pos[0][i]));
          }
          if (j < b) {
            dp[i][j + 1][z][0] = min(dp[i][j + 1][z][0],
                                     dp[i][j][z][0] + cmd(i, j, z, pos[1][j]));
          }
          if (z < c) {
            dp[i][j][z + 1][0] = min(dp[i][j][z + 1][0],
                                     dp[i][j][z][v] + cmd(i, j, z, pos[2][z]));
          }
        }
      }
    }
  }
  printf("%d\n", min(dp[a][b][c][0], dp[a][b][c][1]));
  return 0;
}
