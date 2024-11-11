#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y) {
  long long MOD = 1000000007;
  if (y == 1) {
    return x;
  }
  long long z = exp(x, y / 2);
  z = (z * z) % MOD;
  if (y % 2 == 1) {
    z = (z * x) % MOD;
  }
  return z;
}
long long inv(long long x) { return exp(x, 1000000005); }
int main() {
  long long n;
  cin >> n;
  long long MOD = 1000000007;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long b[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      b[i][j] = (a[j] * inv(a[i] + a[j])) % MOD;
    }
  }
  long long m = 1 << n;
  long long c[n][m];
  for (long long i = 0; i < n; i++) {
    c[i][0] = 1;
    for (long long j = 0; j < n; j++) {
      for (long long k = 0; k < (1 << j); k++) {
        c[i][k + (1 << j)] = (c[i][k] * b[i][j]) % MOD;
      }
    }
  }
  long long d[m];
  d[0] = 0;
  for (long long i = 1; i < m; i++) {
    bool e[n];
    long long t = 0;
    for (long long j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        e[j] = false;
      } else {
        e[j] = true;
        t++;
      }
    }
    long long g[t];
    long long temp = 0;
    for (long long j = 0; j < n; j++) {
      if (e[j]) {
        g[temp] = j;
        temp++;
      }
    }
    long long f[1 << t];
    f[0] = 0;
    for (long long j = 0; j < t; j++) {
      for (long long k = 0; k < (1 << j); k++) {
        f[k + (1 << j)] = f[k] + (1 << g[j]);
      }
    }
    long long v = 0;
    for (long long j = 0; j < (1 << t) - 1; j++) {
      long long w = d[f[j]];
      for (long long k = 0; k < n; k++) {
        if (e[k] && ((f[j] & (1 << k)) == 0)) {
          w = (w * c[k][f[j]]) % MOD;
        }
      }
      v = (v + w) % MOD;
    }
    d[i] = (MOD + 1 - v) % MOD;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long w = d[i];
    long long t = 0;
    for (long long k = 0; k < n; k++) {
      if ((i & (1 << k)) == 0) {
        w = (w * c[k][i]) % MOD;
      } else {
        t++;
      }
    }
    ans = (ans + (w * t)) % MOD;
  }
  cout << ans << '\n';
  return 0;
}
