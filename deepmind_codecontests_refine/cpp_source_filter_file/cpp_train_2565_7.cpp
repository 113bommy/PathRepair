#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
  if (ib == ie) {
    ib = ibuf;
    ie = ibuf + fread(ibuf, 1, BUFF, stdin);
  }
  return ib == ie ? -1 : *ib++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const size_t N = 1 << 18;
const int MOD = 998244353;
int qpow(int base, int e) {
  int ret = 1;
  for (; e; e >>= 1) {
    if (e & 1) {
      ret = (LL)ret * base % MOD;
    }
    base = (LL)base * base % MOD;
  }
  return ret;
}
int fac[N], inv[N];
void prep() {
  fac[0] = 1;
  for (unsigned i = 1; i <= N - 1; ++i) {
    fac[i] = (LL)fac[i - 1] * i % MOD;
  }
  inv[N - 1] = qpow(fac[N - 1], MOD - 2);
  for (unsigned i = N - 1; i >= 1; --i) {
    inv[i - 1] = (LL)inv[i] * i % MOD;
  }
}
void fft(int a[], int lg, int flag) {
  static int rev[N], rev_lg = -1;
  int n = 1 << lg;
  if (rev_lg != lg) {
    for (int i = 0; i < n; ++i) {
      rev[i] = rev[i >> 1] >> 1 | ((i & 1) << lg >> 1);
    }
    rev_lg = lg;
  }
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int m = 1, l = 2, i, j, x, y, *xx, *yy, w, wn; m < n; m <<= 1, l <<= 1) {
    wn = qpow(3, flag ? (MOD - 1) - (MOD - 1) / l : (MOD - 1) / l);
    xx = a;
    yy = a + m;
    for (i = 0; i < n; i += l) {
      w = 1;
      for (j = 0; j < m; ++j, ++xx, ++yy, w = (LL)w * wn % MOD) {
        x = *xx;
        y = (LL)*yy * w % MOD;
        *xx = x + y;
        if (*xx >= MOD) *xx -= MOD;
        *yy = x - y;
        if (*yy < 0) *yy += MOD;
      }
      xx += m;
      yy += m;
    }
  }
  if (flag) {
    int mul = (LL)fac[n - 1] * inv[n] % MOD;
    for (int i = 0; i < n; ++i) {
      a[i] = (LL)a[i] * mul % MOD;
    }
  }
}
using Poly = vector<int>;
Poly operator*(const Poly &p, const Poly &q) {
  static int a[N], b[N];
  int n = p.size() + q.size() - 1, lg = 0;
  for (; (1 << lg) < n; ++lg) {
  }
  memset(a, 0, sizeof(int) << lg);
  memset(b, 0, sizeof(int) << lg);
  copy(p.begin(), p.end(), a);
  fft(a, lg, 0);
  copy(q.begin(), q.end(), b);
  fft(b, lg, 0);
  for (unsigned i = 0, _ = 1 << lg; i < _; ++i) {
    a[i] = (LL)a[i] * b[i] % MOD;
  }
  fft(a, lg, 1);
  Poly ret(n);
  copy(a, a + n, ret.begin());
  return ret;
}
int main() {
  prep();
  int n = read() + 1;
  LL m = read();
  Poly a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = fac[i] * read() % MOD;
  }
  for (int i = 0; i < n; ++i) {
    b[i] = inv[i];
  }
  reverse(b.begin(), b.end());
  Poly c = a * b, d(n);
  for (int i = 0; i < n; ++i) {
    d[i] = (LL)c[i + n - 1] * qpow(i + 1, MOD - 1 - m % (MOD - 1)) % MOD;
    if ((i & 1) && d[i]) d[i] = MOD - d[i];
  }
  Poly e = d * b;
  for (int i = 0; i < n; ++i) {
    int ans = (LL)e[i + n - 1] * inv[i] % MOD;
    if ((i & 1) && ans) ans = MOD - ans;
    printf("%d%c", ans, "\n "[i < n - 1]);
  }
  return 0;
}
