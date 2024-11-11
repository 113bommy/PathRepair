#include <bits/stdc++.h>
using namespace std;
double dp[2][5010], pw[5010];
void read() {
  int n, T;
  cin >> n >> T;
  int cur = 0;
  static int x[5010], y[5010];
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) {
    double p = x[i] / 100.0, sum = 0, P = 1;
    cur ^= 1;
    for (int j = 1; j < y[i]; ++j) P *= 1 - p;
    for (int j = 1; j <= T; ++j) {
      sum *= 1 - p;
      sum += (dp[cur ^ 1][j - 1] + 1) * p;
      if (j >= y[i]) sum += (dp[cur ^ 1][j - y[i]] + 1) * P * (1 - p);
      if (j > y[i]) sum -= (dp[cur ^ 1][j - y[i] - 1] + 1) * P * (1 - p);
      dp[cur][j] = sum;
    }
  }
  printf("%.10f\n", dp[cur][T]);
}
int main() {
  read();
  return 0;
}
