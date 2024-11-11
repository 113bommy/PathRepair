#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long z) {
  if (y == 0) return 1 % z;
  long long t = power(x, y / 2, z);
  (t *= t) %= z;
  if (y % 2 != 0) (t *= x) %= z;
  return t;
}
const int LIM = 2e5, K = 2;
const long long MOD = 1e9 + 7;
int n, m, a[LIM + 2];
long long f[LIM + 2], fi[LIM + 2];
long long t[K + 2][LIM];
void prep() {
  f[0] = 1;
  for (long long i = 1; i <= LIM; ++i) f[i] = f[i - 1] * i % MOD;
  fi[LIM] = power(f[LIM], MOD - 2, MOD);
  for (long long i = LIM; i; --i) fi[i - 1] = fi[i] * i % MOD;
}
long long nCr(int n, int r) {
  long long ret = f[n] * fi[r] % MOD * fi[n - r] % MOD;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  prep();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    t[k][l] += 1;
    for (int j = 0; j <= k; ++j)
      (t[j][r + 1] += MOD - nCr(r - l + k - j, k - j)) %= MOD;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = K; j >= 0; --j) (t[j][i] += t[j][i - 1] + t[j + 1][i]) %= MOD;
  for (int i = 1; i <= n; ++i) {
    long long tmp = (t[0][i] + a[i]) % MOD;
    cout << tmp << " ";
  }
  return 0;
}
