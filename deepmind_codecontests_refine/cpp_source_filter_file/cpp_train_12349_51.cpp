#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, t, A[N], B[N];
double p[N];
double dp[N][5010];
inline bool check(double x) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = t + 1; j < 5000; j++) dp[i + 1][j] = x;
    for (int j = 0; j <= t; j++) {
      dp[i][j] = min(x, p[i] * (A[i] + dp[i + 1][j + A[i]]) +
                            (1.0 - p[i]) * (B[i] + dp[i + 1][j + B[i]]));
    }
  }
  return dp[0][0] < x;
}
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i <= n - 1; i++) {
    int P;
    scanf("%d%d%d", &A[i], &B[i], &P);
    p[i] = 0.01 * P;
  }
  double l = 0, r = 1e10, mid;
  for (int i = 1; i <= 100; i++) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", r);
  return 0;
}
