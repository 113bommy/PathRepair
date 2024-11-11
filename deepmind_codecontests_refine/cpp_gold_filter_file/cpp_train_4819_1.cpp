#include <bits/stdc++.h>
using namespace std;
const long long maxn = 505;
long long p;
long long po(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) {
    long long u = po(a, b / 2);
    return (u * u) % p;
  } else {
    long long u = po(a, b - 1);
    return (a * u) % p;
  }
}
long long fact[maxn];
long long invf[maxn];
long long c3[maxn][maxn];
long long c(long long n, long long k) { return c3[n][k]; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  cin >> p;
  long long u1 = 1;
  for (long long i = 0; i < maxn; ++i) {
    fact[i] = u1;
    u1 *= (i + 1);
    u1 %= p;
  }
  for (long long i = 0; i < maxn; ++i) {
    for (long long j = 0; j < maxn; ++j) {
      if (j == 0)
        c3[i][j] = 1;
      else if (i == 0)
        c3[i][j] = 0;
      else if (i > j)
        c3[i][j] = c3[i - 1][j - 1] + c3[i - 1][j];
      else if (i == j)
        c3[i][j] = 1;
      c3[i][j] %= p;
    }
  }
  long long dp1[n + 1];
  dp1[0] = 1;
  long long dp2[n + 1];
  dp2[0] = 0;
  for (long long i = 1; i <= n; ++i) {
    dp1[i] = 0;
    dp2[i] = 0;
    for (long long j = 0; j < i; ++j) {
      dp1[i] +=
          (((((dp1[j] * dp1[i - 1 - j]) % p) * (i + 1)) % p) % p) * c(i - 1, j);
      dp2[i] += ((((((dp1[j] * dp2[i - j - 1]) % p) * (i + 1) +
                    ((dp2[j] * dp1[i - j - 1]) % p) * (i + 1) +
                    ((dp1[j] * dp1[i - 1 - j]) % p) *
                        ((((i - 1 - j) * (i - j) + j * (j + 1)) / 2) % p)) %
                   p) %
                  p) %
                 p) *
                c(i - 1, j);
      dp2[i] %= p;
      dp1[i] %= p;
    }
  }
  long long dp3[n + 1][n + 1];
  long long dp4[n + 1][n + 1];
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= n; ++j) {
      dp3[i][j] = 0;
      dp4[i][j] = 0;
    }
  }
  for (long long i = 0; i <= n; ++i) {
    for (long long j = 0; j <= i; ++j) {
      for (long long k = 0; k <= j; ++k) {
        if (k != j)
          dp3[i][j] += ((dp3[i - k - 1][j - k] * dp1[k]) % p) * c(j, k);
        else
          dp3[i][j] += dp1[k];
        dp3[i][j] %= p;
        if (k != j)
          dp4[i][j] += ((dp4[i - k - 1][j - k] * dp1[k] +
                         dp2[k] * dp3[i - k - 1][j - k]) %
                        p) *
                       c(j, k);
        else
          dp4[i][j] += dp2[k];
        dp4[i][j] %= p;
      }
    }
  }
  cout << dp4[n][m];
  return 0;
}
