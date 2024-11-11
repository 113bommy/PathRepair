#include <bits/stdc++.h>
using namespace std;
double dp[1024][1024];
double solve(double a, double b, double c, double d) {
  ((void)0);
  double l = (d - b) / (a - b - c + d);
  return l * a + (1 - l) * b;
}
double f(int m, int n) {
  if (m == 0) return 1.0 / (n + 1);
  if (n == 0) return 1.0;
  if (dp[m][n]) return dp[m][n];
  double A = (1 - f(n - 1, m)) * m / (m + 1);
  double B = 1.0;
  double C = A + 1.0 / (m + 1);
  double D = 1 - f(n, m - 1);
  return dp[m][n] = solve(A, B, C, D);
}
int main() {
  int m, n;
  scanf("%d%d", &n, &m);
  double ans = f(m, n);
  printf("%.12f %.12f\n", ans, 1.0 - ans);
  return 0;
}
