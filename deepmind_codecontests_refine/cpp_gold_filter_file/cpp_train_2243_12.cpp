#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e6 + 3;
const int N = 1e6 + 5;
long long fac[2 * N];
long long binPow(long long x, long long p) {
  if (p == 0) return 1LL;
  long long r = binPow(x, p / 2LL);
  r = (r * r) % MOD;
  r *= (p % 2LL ? x : 1LL);
  return r % MOD;
}
long long getCnk(int k, int n) {
  return fac[n] * binPow((fac[k] * fac[n - k]) % MOD, MOD - 2LL);
}
int main() {
  int n, c;
  cin >> n >> c;
  fac[0] = 1;
  for (int i = 1; i < n + c; ++i) fac[i] = (fac[i - 1] * (long long)i) % MOD;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans = (ans + getCnk(i, i + c - 1)) % MOD;
  cout << ans;
  return 0;
}
