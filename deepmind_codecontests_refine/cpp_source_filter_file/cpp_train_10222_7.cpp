#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long MOD = 998244353;
const long long mod = 998244353;
inline long long mul(long long a, long long b) { return (a * 1ll * b) % mod; }
inline long long add(long long a, long long b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}
inline long long power(long long a, long long b) {
  long long rt = 1;
  while (b > 0) {
    if (b & 1) {
      rt = mul(rt, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return rt;
}
inline long long inv(long long a) { return power(a, mod - 2); }
inline void modadd(long long &a, long long &b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
long long base = 1;
vector<long long> roots = {0, 1};
vector<long long> rev = {0, 1};
const long long max_base = 14;
const long long root = 666702199;
void ensure_base(long long nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (long long i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    long long z = power(root, 1 << (max_base - 1 - base));
    for (long long i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];
      roots[(i << 1) + 1] = mul(roots[i], z);
    }
    base++;
  }
}
void fft(vector<long long> &a) {
  long long n = (long long)a.size();
  long long zeros = __builtin_ctzll(n);
  ensure_base(zeros);
  long long shift = base - zeros;
  for (long long i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (long long k = 1; k < n; k <<= 1) {
    for (long long i = 0; i < n; i += 2 * k) {
      for (long long j = 0; j < k; j++) {
        long long x = a[i + j];
        long long y = mul(a[i + j + k], roots[j + k]);
        a[i + j] = x + y - mod;
        if (a[i + j] < 0) {
          a[i + j] += mod;
        }
        a[i + j + k] = x - y + mod;
        if (a[i + j + k] >= mod) {
          a[i + j + k] -= mod;
        }
      }
    }
  }
}
vector<long long> multiply(vector<long long> a, vector<long long> b,
                           long long eq = 0) {
  long long need = (long long)(a.size() + b.size() - 1);
  long long nbase = 0;
  while ((1 << nbase) < need) {
    nbase++;
  }
  ensure_base(nbase);
  long long sz = 1 << nbase;
  a.resize(sz);
  b.resize(sz);
  fft(a);
  if (eq) {
    b = a;
  } else {
    fft(b);
  }
  long long inv_sz = inv(sz);
  for (long long i = 0; i < sz; i++) {
    a[i] = mul(mul(a[i], b[i]), inv_sz);
  }
  reverse(a.begin() + 1, a.end());
  fft(a);
  a.resize(need);
  return a;
}
long long const MAG = 250;
vector<long long> solve(vector<long long> b) {
  long long sz = (long long)b.size();
  if (sz < MAG) {
    vector<long long> c;
    c.resize(sz + 1);
    for (long long i = 0; i <= sz; i++) {
      c[i] = 0;
    }
    c[0] = 1;
    for (long long i = 0; i < sz; i++) {
      long long x = b[i];
      for (long long j = i; j >= 0; j--) {
        c[j + 1] = (c[j + 1] * x + c[j]) % MOD;
      }
      c[0] = (c[0] * x) % MOD;
    }
    return c;
  }
  vector<long long> b1, b2;
  for (long long i = 0; i < sz; i++) {
    if (i & 1) {
      b1.push_back(b[i]);
    } else {
      b2.push_back(b[i]);
    }
  }
  return multiply(solve(b1), solve(b2), 0);
}
long long const N = 1e5 + 4;
long long a[N];
long long aa[N];
void solve(long long n, long long k) {
  for (long long i = 0; i < n; i++) {
    a[i] = aa[i];
  }
  long long t;
  long long q;
  scanf("%lld%lld", &t, &q);
  if (t == 1) {
    long long p;
    long long d;
    scanf("%lld%lld", &p, &d);
    p--;
    a[p] = d;
  } else {
    long long l, r;
    long long d;
    scanf("%lld%lld%lld", &l, &r, &d);
    l--;
    for (long long i = l; i < r; i++) {
      a[i] += d;
    }
  }
  for (long long i = 0; i < n; i++) {
    a[i] = (q - a[i]) % MOD;
    if (a[i] < 0) {
      a[i] += MOD;
    }
  }
  vector<long long> z;
  z.resize(n);
  for (long long i = 0; i < n; i++) {
    z[i] = a[i];
  }
  z = solve(z);
  printf("%lld\n", z[n - k]);
}
int32_t main() {
  long long n, k, q;
  scanf("%lld%lld", &n, &k);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &aa[i]);
  }
  scanf("%lld", &q);
  while (q--) {
    solve(n, k);
  }
  return 0;
}
