#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  for (; c < 48; c = getchar())
    if (c == '-') f = 0;
  for (; c >= 48; c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
double dp[5005][5005];
int main() {
  int n, T;
  n = read();
  T = read();
  dp[0][0] = 1;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    double pro = read() / 100.0;
    int t = read();
    double e = 1;
    for (int j = 0; j < t - 1; ++j) e = e * (1 - pro);
    double sum = 0;
    for (int j = 1; j <= T; ++j) {
      sum = sum * (1 - pro) + dp[i][j - 1];
      if (j >= t) sum -= e * dp[i][j - t];
      dp[i + 1][j] = sum * pro;
      if (j >= t) dp[i + 1][j] += e * dp[i][j - t];
      ans += dp[i + 1][j];
    }
  }
  printf("%.9f\n", ans);
  return 0;
}
