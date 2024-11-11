#include <bits/stdc++.h>
using namespace std;
const long long NMAX = 2 * 1000 * 1000;
const long long MOD = 1e9 + 7;
long long fac[NMAX + 2], invf[NMAX + 2];
long long lgput(long long b, long long p) {
  long long R = 1, pp = b;
  while (p) {
    if (p & 1) R = R * pp % MOD;
    p >>= 1;
    pp = pp * pp % MOD;
  }
  return R;
}
void precalc() {
  fac[0] = 1;
  invf[0] = 1;
  for (long long i = 1; i <= NMAX; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  invf[NMAX] = lgput(fac[NMAX], MOD - 2);
  for (long long i = NMAX - 1; i >= 0; --i) {
    invf[i] = invf[i + 1] * (i + 1) % MOD;
  }
}
inline long long CM(long long N, long long K) {
  if (N < 0 || K > N || K < 0) return 0;
  return fac[N] * invf[K] % MOD * invf[N - K] % MOD;
}
long long ciur[NMAX + 2];
void do_ciur() {
  ciur[0] = ciur[1] = 1;
  for (long long i = 2; i <= NMAX; ++i) {
    if (!ciur[i])
      for (long long j = i; j <= NMAX; j += i) ciur[j] = i;
  }
}
void solve() {
  long long P, N;
  cin >> P >> N;
  long long Ans = 1;
  while (P > 1) {
    long long fac = ciur[P];
    long long cnt = 0;
    while (P % fac == 0) {
      P /= fac;
      ++cnt;
    }
    Ans = Ans * CM(N + cnt - 1, N - 1) % MOD;
  }
  Ans = Ans * lgput(2, N - 1) % MOD;
  cout << Ans << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  do_ciur();
  precalc();
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
