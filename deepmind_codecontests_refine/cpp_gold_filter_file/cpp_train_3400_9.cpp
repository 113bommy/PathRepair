#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &ret) {
  ret = 0;
  bool ok = 0, u = 0;
  for (;;) {
    int c = getchar();
    if (c >= '0' && c <= '9')
      ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
    else if (c == '-')
      u = 1;
    else if (ok) {
      if (u) ret *= -1;
      return;
    }
  }
}
long long powmod(long long p, long long n, long long mod) {
  long long ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * p % mod;
    p = p * p % mod;
  }
  return ret;
}
template <class T>
bool chmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool chmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const long long mod = 998244353;
const int N = (int)2e5 + 9;
template <int sz>
struct combo {
  const long long mod = ::mod;
  long long *fac, *ifac;
  long long mem_fac[sz + 5], mem_ifac[sz + 5];
  combo(long long *fa = 0, long long *ifa = 0) {
    fac = fa ? fa : mem_fac;
    ifac = ifa ? ifa : mem_ifac;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= sz; ++i) {
      fac[i] = i * fac[i - 1] % mod;
      ifac[i] = powmod(fac[i], mod - 2, mod);
    }
  }
  long long comb(long long n, long long m) {
    if (n < m) return 0;
    return (fac[n] * ifac[m] % mod) * ifac[n - m] % mod;
  }
};
namespace ntt {
const int N = ::N;
const long long mod = ::mod, rt = 3;
long long G[55], iG[55], itwo[55];
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void init() {
  int now = (mod - 1) / 2, len = 1, irt = powmod(rt, mod - 2, mod);
  while (now % 2 == 0) {
    G[len] = powmod(rt, now, mod);
    iG[len] = powmod(irt, now, mod);
    itwo[len] = powmod(1 << len, mod - 2, mod);
    now >>= 1;
    len++;
  }
}
void dft(long long *first, int n, int fg = 1) {
  for (int i = (n >> 1), j = 1, k; j < n; ++j) {
    if (i < j) swap(first[i], first[j]);
    for (k = (n >> 1); k & i; i ^= k, k >>= 1)
      ;
    i ^= k;
  }
  for (int m = 2, now = 1; m <= n; m <<= 1, now++) {
    long long r = fg > 0 ? G[now] : iG[now];
    for (int i = 0, j; i < n; i += m) {
      long long tr = 1, u, v;
      for (j = i; j < i + (m >> 1); ++j) {
        u = first[j];
        v = first[j + (m >> 1)] * tr % mod;
        first[j] = (u + v) % mod;
        first[j + (m >> 1)] = (u + mod - v) % mod;
        tr = tr * r % mod;
      }
    }
  }
}
void brute(long long *a, long long *b, int n, int m) {
  static long long c[N];
  for (int k = 0, t; k < n + m - 1; ++k) {
    t = 0;
    for (int i = max(k - m + 1, 0); i < n && i <= k; ++i) {
      add(t, a[i] * b[k - i] % mod);
    }
    c[k] = t;
  }
  for (int k = 0; k < n + m - 1; ++k) a[k] = c[k];
}
void mul(long long *a, long long *b, int n, int m) {
  int nn = n + m - 1;
  if (n == 0 || m == 0) {
    memset(a, 0, nn * sizeof(a[0]));
    return;
  }
  int L, len;
  for (L = 1, len = 0; L < nn; ++len, L <<= 1)
    ;
  if (n < L) memset(a + n, 0, (L - n) * sizeof(a[0]));
  if (m < L) memset(b + m, 0, (L - m) * sizeof(b[0]));
  dft(a, L, 1);
  dft(b, L, 1);
  for (int i = 0; i < L; ++i) a[i] = a[i] * b[i] % mod;
  dft(a, L, -1);
  for (int i = 0; i < L; ++i) a[i] = a[i] * itwo[len] % mod;
}
}  // namespace ntt
struct oo {
  int l, r;
};
combo<100005> C;
int tot, c[N * 33];
long long a[N], b[N];
oo solve(int n, int s) {
  if (n == 1) {
    c[tot++] = s;
    c[tot++] = 1;
    return (oo){tot - 2, tot};
  }
  int tn = n / 2;
  oo off1 = solve(tn, s), off2 = solve(n - tn, s - tn);
  for (int i = (0); i < (tn + 1); i++) a[i] = c[off1.l + i];
  for (int i = (0); i < (n - tn + 1); i++) b[i] = c[off2.l + i];
  ntt::mul(a, b, tn + 1, n - tn + 1);
  for (int i = (0); i < (n + 1); i++) c[i + tot] = a[i];
  tot += n + 1;
  return (oo){tot - n - 1, tot};
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  --a;
  --b;
  if (a < 0 || b < 0) {
    puts("0");
    return 0;
  }
  if (n == 1) {
    puts(a == 0 && b == 0 ? "1" : "0");
    return 0;
  }
  if (a + b >= n) {
    puts("0");
    return 0;
  }
  ntt::init();
  oo off = solve(n - 1, 0);
  long long t = c[off.l + a + b];
  if ((n - 1 + b + a) & 1) t = mod - t;
  cout << C.comb(a + b, a) * t % mod;
  return 0;
}
