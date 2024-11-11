#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
double dp[MAX][MAX];
int N, K;
double prob[MAX];
long long lho(unsigned long long x) {
  long long res = 0;
  for (unsigned long long t = 1; t <= x; t *= 10) {
    if (t <= x / 10)
      res += t;
    else {
      if (x < 2 * t)
        res += x - t + 1;
      else
        res += t;
    }
  }
  return res;
}
int main() {
  cin >> N;
  for (int i = 1; i <= (int)N; i++) {
    long long L, R;
    cin >> L >> R;
    prob[i] = (lho(R) - lho(L - 1)) / (R - L + 1.0);
  }
  cin >> K;
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++)
    for (int k = 0; k <= N; k++) {
      if (k) dp[i][k] += prob[i] * dp[i - 1][k - 1];
      dp[i][k] += (1 - prob[i]) * dp[i - 1][k];
    }
  double res = 0;
  for (int k = 0; k <= N; k++)
    if (k * 100 >= K * N) res += dp[N][k];
  printf("%.12lf\n", res);
}
