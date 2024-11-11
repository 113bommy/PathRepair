#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
int dp[2005][2050][2];
void MYADD(int &x, int val) {
  x += val;
  if (x >= 100000007) x -= 100000007;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int TARGET = 1 << k;
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    for (int s = 0; s <= 2050; s++) {
      if (a != 2) {
        int t = min(s + 4, TARGET);
        if (s & 2) {
          if (s >= TARGET)
            MYADD(dp[i][4][1], dp[i - 1][s][0]);
          else
            MYADD(dp[i][4][0], dp[i - 1][s][0]);
          MYADD(dp[i][4][1], dp[i - 1][s][1]);
        } else {
          MYADD(dp[i][t][0], dp[i - 1][s][0]);
          MYADD(dp[i][t][1], dp[i - 1][s][1]);
        }
      }
      if (a != 4) {
        int t = min(s + 2, TARGET);
        MYADD(dp[i][t][0], dp[i - 1][s][0]);
        MYADD(dp[i][t][1], dp[i - 1][s][1]);
      }
    }
  }
  int res = 0;
  for (int s = 0; s <= 2050; s++) {
    MYADD(res, dp[n][s][1]);
    if (s >= TARGET) MYADD(res, dp[n][s][0]);
  }
  printf("%d\n", res);
  return 0;
}
