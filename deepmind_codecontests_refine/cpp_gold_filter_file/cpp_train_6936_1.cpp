#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos((long double)-1.0);
const double EPS = 1e-12;
const int MOD = 1e9 + 7;
template <typename T>
void cmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void cmax(T &x, T y) {
  if (y > x) x = y;
}
long long qpow(long long x, long long n, long long mod = MOD) {
  if (n < 0) return 0;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long sq(long long x) { return x * x; }
double sq(double x) { return x * x; }
namespace Solver {
const int MAXN = 1e6 + 5;
int p[MAXN], ptop;
int pm[MAXN], pk[MAXN];
void sieve(int n) {
  pm[1] = 1, pk[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!pm[i]) p[++ptop] = i, pm[i] = i, pk[i] = i;
    for (int j = 1; j <= ptop; ++j) {
      int t = i * p[j];
      if (t > n) break;
      pm[t] = p[j];
      if (i % p[j])
        pk[t] = pk[p[j]];
      else {
        pk[t] = pk[i] * p[j];
        break;
      }
    }
  }
  cerr << "ptop"
          " = "
       << (ptop) << endl;
}
namespace Combinatory {
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
long long inv[MAXN], fac[MAXN], invfac[MAXN];
void init(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  fac[0] = 1, invfac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    invfac[i] = invfac[i - 1] * inv[i] % MOD;
  }
}
long long A(long long n, long long m) {
  if (n < m) return 0;
  return fac[n] * invfac[n - m] % MOD;
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return fac[n] * invfac[n - m] % MOD * invfac[m] % MOD;
}
}  // namespace Combinatory
void InitOnce() {
  int t;
  scanf("%d", &t);
  sieve(1000000);
  Combinatory::init(2000000);
}
int x, y;
void Read() {
  int res = scanf("%d%d", &x, &y);
  if (res == -1) exit(0);
}
void Solve() {
  map<int, int> M;
  while (x > 1) {
    M[pm[x]] += 1;
    x /= pm[x];
  }
  long long ans = 1;
  for (auto i : M) {
    int n = i.second;
    int m = y;
    ans *= Combinatory::C(n + m - 1, n);
    ans %= MOD;
  }
  ans *= qpow(2, y - 1);
  ans %= MOD;
  printf("%lld\n", ans);
}
}  // namespace Solver
int main() {
  Solver::InitOnce();
  while (true) {
    Solver::Read();
    Solver::Solve();
  }
  return 0;
}
