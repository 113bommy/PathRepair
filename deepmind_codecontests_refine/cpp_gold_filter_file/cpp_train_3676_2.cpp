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
int dp[21][21][21];
int N, T;
int solve(int n, int t, int h) {
  if (dp[n][t][h] != -1) {
    return dp[n][t][h];
  }
  int ret = 0;
  if (n == N) {
    if (t == T) {
      return 1;
    } else
      return 0;
  }
  if (t & 1) {
    for (int i = h + 1; i <= 4; i++) {
      ret += solve(n + 1, t + 1, i);
    }
    for (int i = 1; i <= h - 1; i++) {
      ret += solve(n + 1, t, i);
    }
  } else {
    for (int i = h + 1; i <= 4; i++) {
      ret += solve(n + 1, t, i);
    }
    for (int i = 1; i <= h - 1; i++) {
      ret += solve(n + 1, t + 1, i);
    }
  }
  return dp[n][t][h] = ret;
}
int main() {
  N = in(), T = in();
  T += T - 1;
  if (N + 2 < T) {
    printf("0\n");
    return 0;
  }
  int ans = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= 4; i++) {
    int tmp = solve(2, 0, i);
    ans += (i - 1) * tmp;
  }
  printf("%d\n", ans);
  return 0;
}
