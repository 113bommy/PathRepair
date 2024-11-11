#include <bits/stdc++.h>
using namespace std;
int dir1[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, 2, -2, 1, -1, -2, -2, -1};
int dir2[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int dir3[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
bool Isleap(int year) {
  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
  return false;
}
bool isPrime(int x) {
  if (x == 1)
    return false;
  else if (x == 2)
    return true;
  for (int i = 2; i <= sqrt(x * 1.0); ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int sqr(int x) { return x * x; }
double dp[120][120][120];
int main() {
  int r, s, p;
  while (~scanf("%d %d %d", &r, &s, &p)) {
    memset((dp), 0, sizeof(dp));
    dp[r][s][p] = 1.0;
    for (int i = r; i >= 1; --i) {
      for (int j = s; j >= 1; --j) {
        for (int k = p; k >= 1; --k) {
          if (dp[i][j][k] == 0) continue;
          int to = i * j + i * k + j * k;
          double te;
          te = 1.0 * i * j / to;
          dp[i][j - 1][k] += dp[i][j][k] * te;
          te = 1.0 * i * k / to;
          dp[i - 1][j][k] += dp[i][j][k] * te;
          te = 1.0 * k * j / to;
          dp[i][j][k - 1] += dp[i][j][k] * te;
        }
      }
    }
    double ans1 = 0, ans2 = 0;
    for (int i = 1; i <= r; ++i) {
      for (int j = 0; j <= s; ++j) {
        ans1 += dp[i][j][0];
      }
    }
    for (int i = 1; i <= s; ++i) {
      for (int j = 0; j <= p; ++j) {
        ans2 += dp[0][i][j];
      }
    }
    printf("%.10lf %.10lf %.10lf\n", ans1, ans2, (1 - ans1 - ans2));
  }
  return 0;
}
