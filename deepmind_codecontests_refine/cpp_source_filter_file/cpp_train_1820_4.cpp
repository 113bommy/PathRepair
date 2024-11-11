#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 10;
const long long MAX_N = 1e5 + 10;
long long d[MAX_N];
long long dp[MAX_N];
long long b[MAX_N];
struct matrix {
  long long c[105][105], n, m;
  matrix operator*(const matrix &o) const {
    matrix ans;
    ans.n = n;
    ans.m = o.m;
    for (long long i = 1; i <= ans.n; i++)
      for (long long j = 1; j <= ans.m; j++) ans.c[i][j] = 0;
    for (long long i = 1; i <= ans.n; i++)
      for (long long j = 1; j <= ans.m; j++)
        for (long long k = 1; k <= m; k++)
          ans.c[i][j] = (ans.c[i][j] + 1LL * c[i][k] * o.c[k][j]) % mod;
    return ans;
  }
  void output() {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) printf("%lld", c[i][j]);
      printf("\n");
    }
  }
  void init(long long x) {
    if (x == 1) {
      n = 101, m = 101;
      for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= m; j++) c[i][j] = 0;
      for (long long i = 1; i <= n - 2; i++) c[i][i + 1] = 1;
      for (long long i = 1; i <= 100; i++) c[n - 1][i] = b[101 - i];
      for (long long i = 1; i <= 100; i++) c[n][i] = b[101 - i];
      c[n][m] = 1;
    } else if (x == 0) {
      n = 101, m = 1;
      for (long long i = 1; i <= 100; i++) c[i][1] = dp[i];
      long long sum = 0;
      for (long long i = 0; i <= 100; i++) sum = (sum + dp[i]) % mod;
      c[n][1] = sum;
    }
  }
};
matrix quick_pow(long long p) {
  matrix x;
  x.init(1);
  matrix ans;
  ans.init(1);
  while (p) {
    if (p & 1) ans = ans * x;
    x = x * x;
    p >>= 1;
  }
  return ans;
}
signed main() {
  long long n, x;
  scanf("%lld %lld", &n, &x);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &d[i]);
    b[d[i]]++;
  }
  dp[0] = 1;
  for (long long i = 1; i <= 100; i++)
    for (long long j = i - 1; j >= 0; j--)
      dp[i] = (dp[i] + 1LL * dp[j] * b[i - j]) % mod;
  if (x <= 100) {
    long long sum = 0;
    for (long long i = 0; i <= x; i++) sum = (sum + dp[i]) % mod;
    printf("%lld\n", sum);
  } else {
    matrix t;
    t.init(0);
    t = quick_pow(x - 101) * t;
    printf("%lld\n", t.c[101][1]);
  }
  return 0;
}
