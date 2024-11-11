#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dc[2009][1009], fact[1000009], d[1009];
long long mod(long long a) { return (a % MOD + MOD) % MOD; }
long long n, m, k;
long long power(long long a, long long b) {
  long long res = 1, cur = a;
  while (b > 0) {
    if (b % 2) {
      res *= cur;
      res = mod(res);
    }
    b /= 2;
    cur *= cur;
    cur = mod(cur);
  }
  return res;
}
void init() {
  for (long long i = 0; i < 2009; i++) {
    for (long long j = 0; j < 1009; j++) {
      dc[i][j] = -1;
    }
  }
  fact[0] = 1;
  for (long long i = 1; i < 1000009; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] = mod(fact[i]);
  }
}
long long inv(long long a) { return power(a, MOD - 2); }
long long c(long long n, long long k) {
  if (dc[n][k] == -1) {
    if (n == k || k == 0) return dc[n][k] = 1;
    return dc[n][k] = mod(c(n - 1, k - 1) + c(n - 1, k));
  }
  return dc[n][k];
}
int main() {
  cin >> n >> m >> k;
  long long ans = 0, t, p;
  init();
  for (long long i = 1; i < 1009; i++) {
    d[i] = power(i, n);
    for (long long j = 1; j < i; j++) {
      d[i] -= mod(d[j] * c(i, j));
      d[i] = mod(d[i]);
    }
  }
  if (m == 1) {
    cout << power(k, n);
    return 0;
  }
  for (long long x = 0; x <= n; x++) {
    for (long long y = 0; 2 * x + y <= k; y++) {
      if (x + y > n) break;
      if (x == 0 && y == 0) continue;
      t = c(2 * x + y, y) * c(2 * x, x);
      t = mod(t);
      t *= fact[k];
      t = mod(t);
      p = mod(fact[2 * x + y] * fact[k - 2 * x - y]);
      t *= inv(p);
      t = mod(t);
      t *= power(y, n * (m - 2));
      t = mod(t);
      t *= mod(d[x + y] * d[x + y]);
      t = mod(t);
      ans += t;
      ans = mod(ans);
    }
  }
  cout << mod(ans);
  return 0;
}
