#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int lowbit(int x) { return x & (-x); }
long long quickmod(long long x, long long y, long long mod) {
  x = x % mod;
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return ans;
}
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
int n, p;
int num[55];
long long dp[55][55][55];
double jie[55];
int main() {
  int total = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    total += num[i];
  }
  scanf("%d", &p);
  if (total <= p) {
    printf("%d\n", n);
    return 0;
  }
  jie[0] = 1.0;
  for (int i = 1; i <= 50; i++) jie[i] = jie[i - 1] * i;
  double ans = 0;
  for (int zu = 1; zu <= n; zu++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= p; k++) {
          if (j <= i - 1) dp[i][j][k] = dp[i - 1][j][k];
          if (j >= 1 && k >= num[i] && i != zu)
            dp[i][j][k] = dp[i][j][k] + dp[i - 1][j - 1][k - num[i]];
        }
      }
    }
    for (int j = 1; j <= n - 1; j++) {
      for (int k = p; k >= max(p - num[zu] + 1, 0); k--)
        ans = ans + jie[j] * j * jie[n - 1 - j] * dp[n][j][k];
    }
  }
  printf("%.10lf\n", ans / jie[n]);
  return 0;
}
