#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
using namespace std;
const int INF = 1000000000;
const int MAX = 50007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;
double dp[2][5007];
double P[5007];
int main() {
  dp[0][0] = 1;
  int prev = 0;
  int next = 1;
  int n, T;
  cin >> n >> T;
  double res = 0;
  for (int it = (0); it < (n); ++it) {
    int pp, t;
    cin >> pp >> t;
    double p = 0.01 * pp;
    if (t == 1) {
      dp[next][0] = 0;
      for (int i = (1); i < (T + 1); ++i) {
        dp[next][i] = dp[prev][i - 1];
        res += dp[next][i];
      }
      swap(prev, next);
      continue;
    } else {
      double ss = 0;
      P[0] = p;
      ss += P[0];
      for (int i = (1); i < (t - 1); ++i) {
        P[i] = P[i - 1] * (1 - p);
        ss += P[i];
      }
      P[t - 1] = 1 - ss;
    }
    dp[next][0] = 0;
    for (int i = (1); i < (T + 1); ++i) {
      dp[next][i] = dp[next][i - 1];
      if (i - 1 >= t) {
        dp[next][i] -= dp[prev][i - 1 - t] * P[t - 1];
      }
      if (i >= t) {
        dp[next][i] -= dp[prev][i - t] * P[t - 2];
      }
      dp[next][i] *= (1 - p);
      if (i >= t) {
        dp[next][i] += dp[prev][i - t] * P[t - 1];
      }
      dp[next][i] += dp[prev][i - 1] * p;
      if (dp[next][i] < 1e-12) dp[next][i] = 0;
      res += dp[next][i];
    }
    swap(prev, next);
  }
  printf("%.10f\n", res);
  return 0;
}
