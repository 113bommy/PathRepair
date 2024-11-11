#include <bits/stdc++.h>
template <class T>
class _Fenwick {
 private:
  std::vector<T> sum;
  int _size;

 public:
  _Fenwick() { _size = 0; }
  void reset(int n) {
    _size = n;
    sum.clear();
    sum.resize(n + 1);
  }
  void add(int x, T y) {
    while (x <= _size) {
      sum[x] += y;
      x += x & -x;
    }
  }
  T query(int x, T y) {
    T ans = y;
    while (x) {
      ans += sum[x];
      x -= x & -x;
    };
    return ans;
  }
  void build(T *a, int n) {
    reset(n);
    for (int i = 1; i <= n; ++i) add(i, a[i]);
  }
};
template <typename T>
void read(T &x);
template <typename T>
void read(T &x, T &y);
template <typename T>
void read(T &x, T &y, T &z);
template <typename T>
void write(T x);
template <typename T>
void writeC(T x);
template <typename T>
void writeN(T x);
template <typename T>
void _binary(T x, int len);
void init_factorial(int *fac, int *ifac, int n, int mod);
long long _qpow(long long a, long long b, long long M);
long long _inv(long long x, long long M);
const int mod = 1e9 + 7;
int qpow(int a, int b) { return _qpow(a, b, mod); }
int inv2 = (mod + 1) / 2;
int inv4 = (long long)inv2 * inv2 % mod;
int inv8 = (long long)inv4 * inv2 % mod;
int inv16 = (long long)inv4 * inv4 % mod;
int vis[500005], instk[500005], fa[500005], u[500005], v[500005], d[500005],
    a[500005], b[500005], sumD[500005], n, m, tl, s;
std::vector<int> ch[500005], in[500005];
void dfs(int u, int f) {
  vis[u] = 1;
  instk[u] = 1;
  fa[u] = f;
  for (int v : ch[u]) {
    if (v == f) continue;
    if (!vis[v])
      dfs(v, u);
    else {
      if (!instk[v]) continue;
      ++tl;
      int p = u;
      sumD[tl] += d[u];
      a[tl]++;
      in[u].push_back(tl);
      while (1) {
        p = fa[p];
        sumD[tl] += d[p];
        a[tl]++;
        in[p].push_back(tl);
        if (p == v) break;
      }
    }
  }
  instk[u] = 0;
}
signed main() {
  read(n, m);
  for (int i = (1); i <= (m); ++i) {
    read(u[i], v[i]);
    ch[u[i]].push_back(v[i]);
    ch[v[i]].push_back(u[i]);
    d[u[i]]++;
    d[v[i]]++;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int p : in[i]) sum = (sum + qpow(inv2, a[p])) % mod;
    for (int p : in[i])
      b[p] = ((b[p] + sum) % mod - qpow(inv2, a[p]) + mod) % mod;
  }
  int E = ((long long)n * inv2 % mod - (long long)m * inv4 % mod + mod) % mod;
  for (int i = 1; i <= tl; ++i) {
    s = (s + qpow(inv2, a[i])) % mod;
  }
  E = (E + s) % mod;
  int A = 0;
  A = (A + (long long)n * (n - 1) % mod * inv4 % mod) % mod;
  A = (A + (long long)n * inv2 % mod) % mod;
  for (int i = 1; i <= m; ++i) {
    int self = 1;
    int related = d[u[i]] - 1 + d[v[i]] - 1;
    int non_related = m - self - related;
    A = (A + (long long)self * inv4 % mod) % mod;
    A = (A + (long long)related * inv8 % mod) % mod;
    A = (A + (long long)non_related * inv16 % mod) % mod;
  }
  for (int i = 1; i <= tl; ++i) {
    int self = (long long)qpow(inv2, a[i]);
    int related = b[i];
    int non_related = ((s - self + mod) % mod - related + mod) % mod;
    A = ((A + self) % mod + (long long)qpow(inv2, a[i] - 1) * related % mod) %
        mod;
    A = (A + (long long)self * non_related % mod) % mod;
  }
  int P = 0;
  for (int i = 1; i <= m; ++i) {
    int related = 2;
    int non_related = n - related;
    P = (P + (long long)inv8 * non_related % mod) % mod;
    P = (P + (long long)inv4 * related % mod) % mod;
  }
  A = (A - (long long)P * 2 % mod + mod) % mod;
  P = 0;
  for (int i = 1; i <= tl; ++i) {
    int related = a[i];
    int non_related = n - a[i];
    P = (P + (long long)related * qpow(inv2, a[i]) % mod) % mod;
    P = (P + (long long)non_related * qpow(inv2, a[i] + 1) % mod) % mod;
  }
  A = (A + (long long)2 * P % mod) % mod;
  P = 0;
  for (int i = 1; i <= tl; ++i) {
    int full_related = a[i];
    int partial_related = sumD[i] - 2 * (a[i]);
    int non_related = m - full_related - partial_related;
    P = (P + (long long)full_related * qpow(inv2, a[i]) % mod) % mod;
    P = (P + (long long)partial_related * qpow(inv2, a[i] + 1) % mod) % mod;
    P = (P + (long long)non_related * qpow(inv2, a[i] + 2) % mod) % mod;
  }
  A = (A - (long long)2 * P + mod) % mod;
  A = (A + (long long)(mod - 1) * E % mod * E % mod) % mod;
  write(A);
  return 0;
}
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T flag = 1;
  while (c < '0' || c > '9') {
    if (c == '-') flag = -flag;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= flag;
}
template <typename T>
void read(T &x, T &y) {
  read(x);
  read(y);
}
template <typename T>
void read(T &x, T &y, T &z) {
  read(x);
  read(y);
  read(z);
}
template <typename T>
void writeC(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) writeC(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void write(T x) {
  writeC(x);
  putchar(' ');
}
template <typename T>
void writeN(T x) {
  writeC(x);
  puts("");
}
template <typename T>
void _binary(T x, int len) {
  for (int i = len - 1; i >= 0; --i) writeC((x >> i) & 1);
}
long long _inv(long long x, long long M) {
  assert(x != 0);
  return x == 1 ? 1 : (M - M / x) * _inv(M % x, M) % M;
}
long long _qpow(long long a, long long b, long long M) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res;
}
void init_factorial(int *fac, int *ifac, int n, int mod) {
  fac[0] = ifac[0] = ifac[1] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 2; i <= n; ++i)
    ifac[i] = (long long)(mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 2; i <= n; ++i) ifac[i] = (long long)ifac[i - 1] * ifac[i] % mod;
}
