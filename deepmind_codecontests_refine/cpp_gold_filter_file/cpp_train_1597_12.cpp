#include <bits/stdc++.h>
const int maxn = 210;
using namespace std;
const double eps = 0.000000001;
double dp[maxn][maxn][maxn];
int N, L, K, p2[maxn], prize[maxn];
double p[maxn];
inline double ffabs(double a) {
  if (a < 0) return -a;
  return a;
}
inline double max(double a, double b) {
  if (a > b) return a;
  return b;
}
int main() {
  scanf("%d %d %d\n", &N, &L, &K);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &p2[i]);
    p[i] = (1.0 * p2[i]) / 100.0;
  }
  for (int i = 0; i < N; ++i) scanf("%d", &prize[i]);
  dp[0][0][min(K, N)] = 1.0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = 0; k <= N; ++k) {
        int v = k + prize[i] + 1;
        dp[i + 1][j + 1][min(v, N)] += dp[i][j][k] * p[i];
        dp[i + 1][j][k] += dp[i][j][k] * (1.0 - p[i]);
      }
  double sol = 0.0;
  for (int j = L; j <= N; ++j) {
    for (int k = 0; k <= N; ++k) {
      if (k >= j) sol += dp[N][j][k];
    }
  }
  printf("%.9lf\n", sol);
  return 0;
}
