#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e3 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-7;
double dp[2][N];
int ans[N];
int main() {
  int k, q;
  while (~scanf("%d%d", &k, &q)) {
    int t = 0;
    memset(dp, 0, sizeof(dp));
    dp[t][0] = 1;
    int l = 1;
    for (int i = 1;; i++) {
      t ^= 1;
      dp[t][0] = 1;
      for (int j = 1; j <= k; j++)
        dp[t][j] = dp[t ^ 1][j] * j / k + dp[t ^ 1][j - 1] * (k - j + 1) / k;
      double m = dp[t][k] * 2000 + eps;
      while ((l < m) && (l <= 1000)) ans[l++] = i;
      if (l == 1001) break;
    }
    while (q--) {
      int x;
      scanf("%d", &x);
      printf("%d\n", ans[x]);
    }
  }
  return 0;
}
