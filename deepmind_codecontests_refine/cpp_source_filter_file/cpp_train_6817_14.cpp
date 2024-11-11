#include <bits/stdc++.h>
using namespace std;
const int kMaxn = 1e2 + 10;
double ans[3];
double dp[kMaxn][kMaxn][kMaxn];
int main() {
  int r, s, p;
  scanf("%d%d%d", &r, &s, &p);
  dp[r][s][p] = 1.0f;
  for (int i = r; i >= 0; --i) {
    for (int j = s; j >= 0; --j) {
      for (int k = p; k >= 0; --k) {
        int tot = i * j + i * k + j * k;
        if (i && j) {
          dp[i][j - 1][k] += dp[i][j][k] * i * j / tot;
        }
        if (i && k) {
          dp[i - 1][j][k] += dp[i][j][k] * i * k / tot;
        }
        if (j && k) {
          dp[i][j][k - 1] += dp[i][j][k] * j * k / tot;
        }
      }
    }
  }
  for (int i = 1; i <= r; ++i) {
    ans[0] += dp[i][0][0];
  }
  for (int i = 1; i <= s; ++i) {
    ans[1] += dp[0][i][0];
  }
  for (int i = 1; i <= p; ++i) {
    ans[2] += dp[0][0][i];
  }
  int tot = ans[0] + ans[1] + ans[2];
  printf("%.10lf %.10lf %.10lf\n", ans[0] / tot, ans[1] / tot, ans[2] / tot);
  return 0;
}
