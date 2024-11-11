#include <bits/stdc++.h>
using namespace std;
char sc[1000];
int le, sum[1000];
long long dp[702][702][3][3];
int pas[1000];
int ar[2][4] = {{2, 2, 1, 0}, {1, 0, 2, 2}};
int rek(int a, int b, int t, int w) {
  if (a >= b) return 1;
  if (dp[a][b][t][w] == -1) {
    dp[a][b][t][w] = 0;
    if (pas[a] == b) {
      int i, j;
      for (int k = 0; k < 4; k++) {
        i = ar[0][k];
        j = ar[1][k];
        if (((t != i) || (i == 2)) && ((w != j) || (j == 2))) {
          dp[a][b][t][w] += rek(a + 1, b - 1, i, j);
          dp[a][b][t][w] %= 1000000007LL;
        }
      }
    } else {
      int i, j;
      for (int k = 0; k < 4; k++) {
        i = ar[0][k];
        j = ar[1][k];
        if ((t != i) || (i == 2)) {
          dp[a][b][t][w] +=
              rek(a + 1, pas[a] - 1, i, j) * rek(pas[a] + 1, b, j, w);
          dp[a][b][t][w] %= 1000000007LL;
        }
      }
    }
  }
  return dp[a][b][t][w];
}
int main() {
  scanf("%s", sc);
  le = strlen(sc);
  memset(sum, 0, sizeof sum);
  int p = 1;
  for (int i = 0; i < le; i++) {
    if (sc[i] == '(') {
      sum[p++] = i;
    } else {
      pas[sum[p - 1]] = i;
      pas[i] = sum[p - 1];
      p--;
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%I64d\n", rek(0, le - 1, 2, 2));
  return 0;
}
