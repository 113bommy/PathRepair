#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const long long inf = -1000000000000000000ll;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-8;
long long dp[N][4], a[N][4];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int j = 1; j <= 3; j++)
      for (int i = 1; i <= n; i++) scanf("%d", &a[i][j]);
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2] + a[1][1];
    dp[1][3] = a[1][3] + a[1][2] + a[1][1];
    for (int i = 2; i <= n; i++) {
      dp[i][1] = dp[i][2] = dp[i][3] = inf;
      dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i][1]);
      dp[i][1] = max(dp[i][1], dp[i - 1][2] + a[i][2] + a[i][1]);
      dp[i][1] = max(dp[i][1], dp[i - 1][3] + a[i][3] + a[i][2] + a[i][1]);
      if (i - 3 >= 0)
        dp[i][1] = max(dp[i][1], dp[i - 2][3] + a[i][1] + a[i][2] + a[i][3] +
                                     a[i - 1][1] + a[i - 1][2] + a[i - 1][3]);
      dp[i][2] = max(dp[i][2], dp[i - 1][1] + a[i][1] + a[i][2]);
      dp[i][2] = max(dp[i][2], dp[i - 1][2] + a[i][2]);
      dp[i][2] = max(dp[i][2], dp[i - 1][3] + a[i][3] + a[i][2]);
      dp[i][3] = max(dp[i][3], dp[i - 1][1] + a[i][1] + a[i][2] + a[i][3]);
      dp[i][3] = max(dp[i][3], dp[i - 1][2] + a[i][2] + a[i][3]);
      dp[i][3] = max(dp[i][3], dp[i - 1][3] + a[i][3]);
      if (i - 2 >= 0)
        dp[i][3] = max(dp[i][3], dp[i - 2][1] + a[i][1] + a[i][2] + a[i][3] +
                                     a[i - 1][1] + a[i - 1][2] + a[i - 1][3]);
    }
    printf("%lld\n", dp[n][3]);
  }
  return 0;
}
