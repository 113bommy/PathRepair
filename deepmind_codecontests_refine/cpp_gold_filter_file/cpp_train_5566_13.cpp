#include <bits/stdc++.h>
using namespace std;
const int Maxn = 6000;
const int M = 1000000007;
int n, a, b, k;
int dp[2][Maxn];
int sum[2][Maxn];
void up(int &x, int y) {
  x += y;
  if (x >= M) x -= M;
}
void read() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  int cs = 0;
  dp[0][a] = 1;
  for (int i = a; i <= n; i++) sum[0][i] = 1;
  for (int i = 1; i <= k; i++) {
    memset(dp[cs ^ 1], 0, sizeof(dp[cs ^ 1]));
    for (int j = 1; j <= n; j++) {
      if (j == b) {
        dp[cs ^ 1][j] = 0;
        continue;
      }
      if (j < b) {
        int t = (b + j) / 2;
        while (abs(t - j) >= abs(t - b)) t--;
        up(dp[cs ^ 1][j], sum[cs][t]);
        up(dp[cs ^ 1][j], (M - dp[cs][j]) % M);
        continue;
      }
      if (j > b) {
        int t = (b + j) / 2;
        while (abs(t - j) >= abs(t - b)) t++;
        up(dp[cs ^ 1][j], ((sum[cs][n] - sum[cs][t - 1]) % M + M) % M);
        up(dp[cs ^ 1][j], (M - dp[cs][j]) % M);
      }
    }
    for (int j = 1; j <= n; j++)
      sum[cs ^ 1][j] = (sum[cs ^ 1][j - 1] + dp[cs ^ 1][j]) % M;
    cs ^= 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + dp[cs][i]) % M;
  printf("%d\n", ans);
}
void solve() {}
int main() {
  read();
  solve();
}
