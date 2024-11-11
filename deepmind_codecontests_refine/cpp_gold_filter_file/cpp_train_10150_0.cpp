#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long inl() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
inline double ind() {
  double x;
  scanf("%lf", &x);
  return x;
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int power(int x, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    int y = power(x, n / 2);
    return y * y;
  } else
    return x * power(x, n - 1);
}
long long dp[2][505][505];
char s[505][505];
int dxl[] = {-1, 0}, dyl[] = {0, -1}, dxr[] = {1, 0}, dyr[] = {0, 1};
int main() {
  int n = in(), m = in();
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  if (s[0][0] != s[n - 1][m - 1]) {
    printf("0\n");
    return 0;
  }
  dp[0][0][n - 1] = 1;
  int tot = (n + m - 2) >> 1, cur = 0;
  int ly, ry, txl, tyl, txr, tyr;
  for (int k = 1; k <= tot; k++, cur ^= 1) {
    memset(dp[cur ^ 1], 0, sizeof(dp[cur ^ 1]));
    for (int i = 0; i <= min(k, n - 1); i++) {
      for (int j = max(0, n - 1 - k); j <= n - 1; j++) {
        ly = k - i;
        ry = n + m - 2 - k - j;
        if (ly < 0 || ry < 0 || ly >= m || ry >= m) continue;
        if (s[i][ly] != s[j][ry])
          dp[cur ^ 1][i][j] = 0;
        else {
          for (int q = 0; q < 2; q++) {
            for (int r = 0; r < 2; r++) {
              txl = i + dxl[q];
              tyl = ly + dyl[q];
              txr = j + dxr[r];
              tyr = ry + dyr[r];
              if (txl >= 0 && txl < n && tyl >= 0 && tyl < m && txr >= 0 &&
                  txr < n && tyr >= 0 && tyr < m) {
                dp[cur ^ 1][i][j] =
                    modAdd(dp[cur ^ 1][i][j], dp[cur][txl][txr]);
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  if (!((n + m) & 1)) {
    for (int i = 0; i < n; i++) ans = modAdd(ans, dp[cur][i][i]);
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i; j <= min(n - 1, i + 1); j++)
        ans = modAdd(ans, dp[cur][i][j]);
    }
  }
  printf("%I64d\n", ans);
}
