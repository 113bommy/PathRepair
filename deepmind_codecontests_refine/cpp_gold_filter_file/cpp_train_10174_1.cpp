#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c - '0');
    c = getchar();
  }
  return x * f;
}
int n, m;
double dp[1010][1010];
inline double f(int n, int m) {
  if (!n) return 1.0 / (m + 1.0);
  if (!m) return 1.0;
  if (dp[n][m]) return dp[n][m];
  double A = 1.0 * m / (m + 1.0) * (1.0 - f(m - 1, n)), B = 1.0;
  double C = 1.0 / (m + 1.0) + A, D = 1.0 - f(m, n - 1);
  double P = (D - B) / (A - B - C + D);
  return dp[n][m] = P * A + (1 - P) * B;
}
int main() {
  n = read(), m = read();
  double ans = f(n, m);
  printf("%.10lf %.10lf", ans, 1.0 - ans);
  return 0;
}
