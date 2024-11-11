#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
void read(int &x) {
  char ch = getchar();
  x = 0;
  for (; ch == ' ' || ch == '\n'; ch = getchar())
    ;
  for (; ch != ' ' && ch != '\n'; x = x * 10 + ch - '0', ch = getchar())
    ;
}
void outputno() {
  puts("0.0000");
  exit(0);
}
int n, m, K, lo, hi, cur, nxt = 1;
double dp[2][100012];
int main() {
  read(n), read(m), read(K);
  dp[0][K] = 1.0, lo = hi = K;
  if (n + K < m) outputno();
  for (int i = 0; i < n + m; i++) {
    for (int j = max(0, lo - 1); j <= hi + 1; j++) dp[nxt][j] = 0.0;
    double q = 0.5 / (double)(n + m - i), p = (double)(2 * m - K - i) * q;
    for (int j = lo; j <= hi; j++)
      if (dp[cur][j] > EPS) {
        double t = p + j * q;
        if (j != 0) dp[nxt][j - 1] += dp[cur][j] * t;
        dp[nxt][j + 1] += dp[cur][j] * (1.0 - t);
      }
    if (lo != 0) lo--;
    while (lo < hi && dp[nxt][lo] < EPS) lo++;
    hi++;
    while (hi > lo && dp[nxt][hi] < EPS) hi--;
    swap(cur, nxt);
  }
  printf("%.4lf", dp[cur][n + K - m]);
}
