#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int Maxn = 2e5;
int f, w, h;
long long inv[Maxn + 5], fac[Maxn + 5], ifac[Maxn + 5];
inline void init() {
  inv[1] = fac[0] = ifac[0] = 1;
  for (int i = 1; i <= Maxn; i++) fac[i] = fac[i - 1] * (long long)i % MOD;
  for (int i = 2; i <= Maxn; i++) inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  for (int i = 1; i <= Maxn; i++) ifac[i] = ifac[i - 1] * inv[i] % MOD;
}
inline long long C(int m, int n) {
  if (n < 0 || m < 0 || m > n) return 0;
  return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
inline long long solve(int r, int b, int k) {
  if (b == 0) return 1;
  long long Ans = 0;
  for (int seg = 1; seg <= r + 1 && (k == 0 || seg <= (b - 1) / k); seg++) {
    Ans += C(seg, r + 1) * C(seg - 1, b - k * seg - 1) % MOD;
    Ans %= MOD;
  }
  return Ans;
}
inline long long powX(long long x, long long t) {
  long long ret = 1;
  while (t) {
    if (t & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    t /= 2;
  }
  return ret;
}
int main() {
  init();
  cin >> f >> w >> h;
  long long up = solve(f, w, h);
  long long down = C(w, w + f);
  cout << up * powX(down, MOD - 2) % MOD << endl;
  return 0;
}
