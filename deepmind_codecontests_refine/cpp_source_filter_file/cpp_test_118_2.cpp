#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 3e5 + 7;
const long long MOD = 998244353;
long long n;
long long deg[MAX_N], fac[MAX_N];
long long f_pow(long long base, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * base % mod;
    base = base * base % mod;
    b >>= 1;
  }
  return res;
}
namespace NTT {
const long long MAX_N = 3e6 + 7;
const long long MOD = 998244353;
const long long G = 3;
long long rev[MAX_N];
long long f[MAX_N], g[MAX_N];
long long n, m;
vector<vector<long long>> p;
struct Poly {
  long long n;
  vector<long long> p;
  Poly(vector<long long> _p = {}, long long _n = 0) : n(_n) {
    n = _p.size();
    p.resize(n);
    for (long long i = 0; i < n; ++i) p[i] = _p[i];
  }
  bool operator<(const Poly &a) const { return n > a.n; }
};
void ntt(long long *a, long long n, long long dft) {
  for (long long i = 0; i < n; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (long long i = 1; i < n; i <<= 1) {
    long long wn = f_pow(G, (MOD - 1) / (i << 1), MOD);
    if (dft < 0) wn = f_pow(wn, MOD - 2, MOD);
    for (long long j = 0; j < n; j += (i << 1)) {
      long long wnk = 1;
      for (long long k = j; k < j + i; k++) {
        long long a1 = wnk * a[k], a2 = wnk * a[k + i];
        a[k] = (a1 + a2 % MOD) % MOD;
        a[k + i] = (a1 - a2 % MOD) % MOD;
        wnk = wnk * wn % MOD;
      }
    }
  }
  if (dft == -1) {
    long long inv = f_pow(n, MOD - 2, MOD);
    for (long long i = 0; i < n; i++) a[i] = a[i] * inv % MOD;
  }
}
vector<long long> merge(const vector<long long> &F,
                        const vector<long long> &G) {
  n = F.size() - 1, m = G.size() - 1;
  long long N = 1, p = 0;
  while (N < (m + n + 1)) N <<= 1, ++p;
  for (long long i = 0; i < N; ++i) rev[i] = f[i] = g[i] = 0;
  for (long long i = 0; i < N; ++i)
    rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (p - 1)));
  for (long long i = 0; i <= n; ++i) f[i] = F[i];
  for (long long i = 0; i <= m; ++i) g[i] = G[i];
  ntt(f, N, 1), ntt(g, N, 1);
  for (long long i = 0; i < N; ++i) f[i] = f[i] * g[i] % MOD;
  ntt(f, N, -1);
  vector<long long> res(m + n + 1);
  for (long long i = 0; i <= n + m; ++i) res[i] = (f[i] + MOD) % MOD;
  return res;
}
vector<long long> div_ntt(long long l, long long r) {
  if (l == r) return p[l];
  long long mid = (l + r) >> 1;
  vector<long long> F = div_ntt(l, mid), G = div_ntt(mid + 1, r);
  return merge(F, G);
}
vector<long long> solve() {
  priority_queue<Poly> q;
  for (long long i = 0; i < p.size(); ++i) q.push(Poly(p[i]));
  while (q.size() > 1) {
    vector<long long> F = q.top().p;
    q.pop();
    vector<long long> G = q.top().p;
    q.pop();
    q.push(Poly(merge(F, G)));
  }
  return q.top().p;
}
vector<long long> solve(long long l, long long r) { return div_ntt(l, r); }
}  // namespace NTT
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i < n; ++i) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    ++deg[x], ++deg[y];
  }
  for (long long i = 2; i <= n; ++i) --deg[i];
  for (long long i = 1; i <= n; ++i) {
    vector<long long> t;
    t.push_back(1ll);
    if (deg[i]) t.push_back(deg[i]);
    NTT::p.push_back(t);
  }
  vector<long long> F = NTT::solve();
  long long ans = 0, flag = 1;
  fac[0] = 1;
  for (long long i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
  for (long long i = 0; i < n && i < F.size(); ++i) {
    ans = (ans + flag * F[i] * fac[n - i] % MOD) % MOD;
    flag = -flag;
  }
  printf("%lld\n", (ans + MOD) % MOD);
  return 0;
}
