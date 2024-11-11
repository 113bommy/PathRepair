#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
const int MOD = 1000000007;
const int MAGIC = 3;
int p[MAX], second[MAX];
long long dp[2][MAX];
int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &second[i]);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < MAX; j++) {
      dp[i][j] = 1000000000000000000;
    }
  }
  long long minx = 1000000000000000000;
  dp[1][0] = p[1];
  dp[1][1] = second[1];
  for (int i = 2; i < n + 1; i++) {
    dp[i % 2][0] = dp[(i - 1) % 2][0] + p[i];
    for (int j = 1; j < i + 1; j++) {
      dp[i % 2][j] = min(dp[(i - 1) % 2][j - 1] + second[i],
                         dp[(i - 1) % 2][j] + p[i] + (long long)j * c);
      dp[(i - 1) % 2][j - 1] = 0;
    }
    if (i == n) {
      for (int j = 0; j < i + 1; j++) {
        minx = min(minx, dp[i % 2][j]);
      }
    }
  }
  printf("%lld\n", minx);
}
