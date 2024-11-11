#include <bits/stdc++.h>
using namespace std;
int p[19] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
             31, 37, 41, 43, 47, 53, 59, 61, 67};
int hs[75], ycl[100005];
long long dp[2][1 << 19];
int main() {
  int n;
  scanf("%d", &n);
  ycl[1] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    hs[x]++;
    ycl[i] = (ycl[i - 1] << 1) % 1000000007;
  }
  dp[0][0] = 1;
  int t = 0;
  for (int i = 1; i <= 70; i++) {
    if (hs[i]) {
      int stat = 0, tt = i;
      for (int j = 0; j < 19; j++) {
        while (tt % p[j] == 0) {
          stat ^= (1 << j);
          tt /= p[j];
        }
      }
      for (int j = 0; j < (1 << 19); j++) {
        dp[t ^ 1][j ^ stat] =
            (dp[t ^ 1][j ^ stat] + dp[t][j] * ycl[hs[i] - 1] % 1000000007) %
            1000000007;
        dp[t ^ 1][j] = (dp[t ^ 1][j] + dp[t][j] * ycl[hs[i] - 1] % 1000000007) %
                       1000000007;
      }
    } else {
      for (int j = 0; j < (1 << 19); j++) {
        dp[t ^ 1][j] = dp[t][j];
      }
    }
    memset(dp[t], 0, sizeof(dp[t]));
    t ^= 1;
  }
  printf("%I64d\n", ((dp[t][0] - 1) % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
