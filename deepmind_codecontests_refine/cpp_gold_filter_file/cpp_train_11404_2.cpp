#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
int n, t;
double dp[maxn][maxn];
int num, vol, ret;
int main() {
  scanf("%d", &n);
  scanf("%d", &t);
  num = (n * (n + 1)) >> 1;
  ret = 0;
  dp[1][1] = t;
  for (int i = (1); i < (n + 1); i++) {
    for (int j = (1); j < (i + 1); j++) {
      if (dp[i][j] >= 1) {
        dp[i + 1][j] += (dp[i][j] - 1) / 2;
        dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
        ret++;
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}
