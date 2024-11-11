#include <bits/stdc++.h>
using namespace std;
int T, n;
int t1[10100];
double p[10100];
int p1[10100];
double dp[5001][5002];
double pw[110][5002];
double f() {
  for (int i = 0; i <= 100; i++) {
    pw[i][0] = 1;
    for (int j = 1; j <= 5000; j++) {
      pw[i][j] = pw[i][j - 1] * (1 - (i / 100.0));
    }
  }
  for (int i = n; i >= 0; i--) {
    double r = 0;
    int k = i;
    bool b = 0;
    for (int t = T; t >= i; t--) {
      if (t1[i] > 1) {
        if (t + t1[i] <= T)
          r -= dp[i + 1][t + t1[i]] * p[i] * pw[p1[i]][t1[i] - 2];
        r *= (1 - p[i]);
        r += dp[i + 1][t + 1] * p[i];
      }
      if (i == n) {
        dp[i][t] = n;
        continue;
      }
      if (t == T) {
        dp[i][t] = i;
        continue;
      }
      double r2 = 0;
      if (t + t1[i] <= T)
        r2 = dp[i + 1][t + t1[i]] * pw[p1[i]][t1[i] - 1];
      else {
        r2 = i * pw[p1[i]][T - t];
      }
      dp[i][t] = r;
      dp[i][t] += r2;
    }
  }
  return dp[0][0];
}
int main() {
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p1[i], &t1[i]);
    p[i] = p1[i] / 100.0;
  }
  cout << fixed << setprecision(10) << f() << endl;
  return 0;
}
