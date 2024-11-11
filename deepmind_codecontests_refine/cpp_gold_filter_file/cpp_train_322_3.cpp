#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <typename T, typename U>
inline void mnze(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void mxze(T &x, U y) {
  if (x < y) x = y;
}
void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
template <typename T>
void _dbg(const char *sdbg, T h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename T, typename... U>
void _dbg(const char *sdbg, T h, U... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
const long long MOD = 998244353;
const int MAXN = 2e5;
long long sq(long long x) { return x * x % MOD; }
long long pot(long long b, long long e) {
  return e ? sq(pot(b, e >> 1)) * (e & 1 ? b : 1) % MOD : 1;
}
long long inv(long long x) { return pot(x, MOD - 2); }
long long fact[MAXN], ifact[MAXN];
long long comb(int n, int k) {
  if (k > n) return 0;
  return fact[n] * ifact[n - k] % MOD * ifact[k] % MOD;
}
long long d(int k, int n) { return comb(n + k - 1, k - 1); }
void pre() {
  fact[0] = 1;
  for (int i = 1; i < (int)MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (int i = 0; i < (int)MAXN; i++) ifact[i] = inv(fact[i]);
}
long long p, r, s;
int main() {
  pre();
  scan(p, s, r);
  long long totalw = d(p, s - r);
  long long P = 0;
  for (int x = r; x < (int)s + 1; x++) {
    for (int k = 0; k < (int)p; k++) {
      long long n = p - 1 - k, y = s - (k + 1) * x;
      long long PP = comb(p - 1, k) * inv(k + 1) % MOD;
      if (n == 0) {
        if (y == 0) {
          P += PP;
          P %= MOD;
        }
      } else {
        long long ret = 0, sig = 1;
        for (int i = 0; i < (int)n + 1; i++) {
          long long r = (sig * comb(n, i) + MOD) % MOD;
          r = r * d(n, y - i * x) % MOD;
          ret = (ret + r) % MOD;
          sig *= -1;
        }
        assert(y >= 0 || ret == 0);
        P += ret * PP % MOD;
        P %= MOD;
      }
    }
  }
  long long PQ = P * inv(totalw);
  printf("%lld\n", (PQ % MOD + MOD) % MOD);
}
