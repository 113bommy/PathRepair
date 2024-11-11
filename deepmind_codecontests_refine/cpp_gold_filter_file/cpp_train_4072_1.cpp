#include <bits/stdc++.h>
using namespace std;
long long ppow(long long a, long long b, long long mod) {
  long long ans = 1 % mod;
  a %= mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const long long maxm = 3e5 + 5;
const long long mod = 1e9 + 7;
long long fac[maxm], inv[maxm];
void init() {
  fac[0] = 1;
  for (long long i = 1; i < maxm; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  inv[maxm - 1] = ppow(fac[maxm - 1], mod - 2, mod);
  for (long long i = maxm - 2; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % mod;
  }
}
long long C(long long n, long long m) {
  if (m < 0 || m > n) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long a[maxm];
long long cnt[maxm];
long long d[10][maxm];
signed main() {
  init();
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (long long i = 1; i < maxm; i++) {
    for (long long j = i + i; j < maxm; j += i) {
      cnt[i] += cnt[j];
    }
  }
  for (long long i = 1; i < 10; i++) {
    for (long long j = maxm - 1; j >= 1; j--) {
      d[i][j] = C(cnt[j], i);
      for (long long k = j + j; k < maxm; k += j) {
        d[i][j] = (d[i][j] - d[i][k] + mod) % mod;
      }
    }
    if (d[i][1]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
