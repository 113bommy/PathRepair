#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
const long long mod = 119 << 23 | 1;
const long long N = 1e5 + 1;
void add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
long long Fac[N], Inv[N];
long long Ckn(long long n, long long k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long res = Inv[k] * Inv[n - k] % mod;
  res = Fac[n] * res % mod;
  return res;
}
long long qpow(long long a, long long exp) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = ans * a % mod;
    a = a * a % mod;
    exp >>= 1;
  }
  return ans;
}
long long rebi(long long mask, long long nbit) {
  for (long long i = 0, j = nbit - 1; i < j; ++i, --j)
    if ((mask >> i & 1) != (mask >> j & 1)) {
      mask ^= (1 << i);
      mask ^= (1 << j);
    }
  return mask;
}
void NTT(long long n, vector<long long> &a, bool inv) {
  if (n == 1) return;
  for (long long i = 0; i < n; ++i) {
    long long j = rebi(i, log2(n));
    if (i < j) swap(a[i], a[j]);
  }
  for (long long k = 1; k < n; k <<= 1) {
    long long exp = (mod - 1) / (k << 1);
    if (inv) exp = mod - 1 - exp;
    long long u = qpow(3, exp);
    for (long long i = 0; i < n; i += 2 * k) {
      long long W = 1;
      for (long long j = 0; j < k; ++j) {
        long long x = a[i + j], y = a[i + j + k] * W % mod;
        a[i + j] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
        W = W * u % mod;
      }
    }
  }
  if (inv) {
    long long m = qpow(n, mod - 2);
    for (long long i = 0; i < n; ++i) a[i] = a[i] * m % mod;
  }
}
vector<long long> vec;
void mul(vector<long long> &P, long long l, long long r) {
  if (l == r) {
    P[0] = 1;
    P[1] = vec[l];
    return;
  }
  long long k = log2(r - l + 1) + 1;
  vector<long long> Q(1 << k);
  long long m = (l + r) / 2;
  mul(P, l, m);
  ++m;
  mul(Q, m, r);
  NTT(1 << k, P, 0);
  NTT(1 << k, Q, 0);
  for (long long i = 0; i < (1 << k); ++i) P[i] = P[i] * Q[i] % mod;
  NTT(1 << k, P, 1);
}
long long nCh[N], f[N];
vector<long long> g[N];
long long n, k, ans = 0;
long long h[N];
void dfs(long long u, long long p) {
  nCh[u] = 1;
  vec.clear();
  for (long long v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    add(ans, f[u] * f[v] % mod);
    add(f[u], f[v]);
    add(nCh[u], nCh[v]);
  }
  vec.clear();
  for (long long v : g[u])
    if (v != p) vec.push_back(nCh[v]);
  if (nCh[u] < 2)
    vec.push_back(1);
  else {
    vector<long long> cur(2 << (long long)log2(vec.size()), 0);
    mul(cur, 0, vec.size() - 1);
    vec = cur;
  }
  vec.resize(g[u].size() + (u == 1));
  for (long long i = 0; i < vec.size(); ++i) {
    long long res = vec[i] * Ckn(k, i) % mod;
    res = Fac[i] * res % mod;
    add(f[u], res);
  }
  for (long long i = vec.size() - 1; i; --i)
    add(vec[i], vec[i - 1] * (n - nCh[u]) % mod);
  for (long long v : g[u])
    if (v != p) {
      if (h[nCh[v]] < 0) {
        h[nCh[v]] = 0;
        for (long long i = 0; i < vec.size(); ++i) {
          if (i) add(vec[i], mod - vec[i - 1] * nCh[v] % mod);
          long long res = vec[i] * Ckn(k, i) % mod;
          res = Fac[i] * res % mod;
          add(h[nCh[v]], res);
        }
        for (long long i = vec.size() - 1; i; --i)
          add(vec[i], vec[i - 1] * nCh[v] % mod);
        add(h[nCh[v]], mod);
      }
      add(ans, h[nCh[v]] * f[v] % mod);
    }
  if (u > 1)
    for (long long v : g[u])
      if (v != p) h[nCh[v]] = -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  if (k == 1) return cout << n * (n - 1) / 2, 0;
  Fac[0] = Inv[0] = 1;
  for (long long i = 1; i < N; ++i) Fac[i] = Fac[i - 1] * i % mod;
  Inv[N - 1] = qpow(Fac[N - 1], mod - 2);
  for (long long i = N - 2; i; --i) Inv[i] = Inv[i + 1] * (i + 1) % mod;
  for (long long i = 1; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  memset(h, -1, sizeof h);
  dfs(1, 0);
  cout << (ans + mod) % mod << endl;
}
