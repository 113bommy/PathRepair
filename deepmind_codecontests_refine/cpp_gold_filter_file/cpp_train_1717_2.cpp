#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
const long long N = 2 + 2;
long long n, k, l, m, a[N][N], x[N][N], ans[N][N];
void ready() {
  for (long long i = 0; i < 2; i++) {
    for (long long j = 0; j < 2; j++) {
      a[i][j] = 1;
      ans[i][j] = 1;
    }
  }
  a[1][1] = 0;
  ans[0][1] = 0;
  ans[1][0] = 0;
}
long long power(long long a1, long long b1) {
  long long res = 1;
  for (; b1; b1 /= 2) {
    if (b1 % 2) {
      res *= a1;
      res %= m;
    }
    a1 *= a1;
    a1 %= m;
  }
  return res;
}
long long fib(long long b) {
  ready();
  b++;
  for (; b; b /= 2) {
    if (b % 2) {
      for (long long i = 0; i < 2; i++) {
        for (long long j = 0; j < 2; j++) {
          x[i][j] = 0;
          for (long long k = 0; k < 2; k++) {
            x[i][j] += ans[i][k] * a[k][j] % m;
          }
        }
      }
      for (long long i = 0; i < 2; i++) {
        for (long long j = 0; j < 2; j++) {
          ans[i][j] = x[i][j];
        }
      }
    }
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < 2; j++) {
        x[i][j] = 0;
        for (long long k = 0; k < 2; k++) {
          x[i][j] += a[i][k] * a[k][j] % m;
        }
      }
    }
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < 2; j++) {
        a[i][j] = x[i][j];
      }
    }
  }
  return ans[0][0] % m;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> l >> m;
  if (l < 63 && (1LL << l) <= k) {
    cout << 0;
    return 0;
  }
  long long jv = 1;
  for (long long i = 0; i < l; i++) {
    if ((1LL << i) & k) {
      jv *= (power(2, n) - fib(n));
      jv %= m;
    } else {
      jv *= fib(n);
      jv %= m;
    }
  }
  if (jv < 0) {
    jv += m;
  }
  cout << jv % m << '\n';
  return 0;
}
