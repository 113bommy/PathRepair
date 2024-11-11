#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MOD = 998244353;
const int PRIMROOT = 3;
int pw(int x, int n) {
  int ret = 1;
  while (true) {
    if (n & 1) ret = (long long)ret * x % MOD;
    if ((n >>= 1) == 0) return ret;
    x = (long long)x * x % MOD;
  }
}
struct NTT {
  void _init(int n, int &nlog, int &g, vector<int> &w) {
    assert((MOD - 1) % n == 0);
    g = pw(PRIMROOT, (MOD - 1) / n);
    nlog = 0;
    while ((1 << nlog) < n) ++nlog;
    if ((1 << nlog) != n) nlog = -1;
    w = vector<int>(n);
    w[0] = 1;
    for (int i = (1); i < (n); ++i) w[i] = (long long)w[i - 1] * g % MOD;
  }
  int fftn, fftnlog;
  int fftg;
  vector<int> fftw;
  void initfft(int n) {
    fftn = n, _init(fftn, fftnlog, fftg, fftw);
    assert(fftnlog != -1);
  }
  void fft(int *a, int n, bool inv) {
    if (n != fftn) initfft(n);
    for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) {
      if (i < j) swap(a[i], a[j]);
      for (k = l; k & j; j ^= k, k >>= 1)
        ;
    }
    int *l, *r, *w;
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
      for (int i = 0; i < n; i += (hlen << 1)) {
        l = a + i, r = l + hlen, w = fftw.data();
        for (int off = (0); off < (hlen); ++off) {
          int v = (long long)(*r) * (*w) % MOD;
          *r = (*l) - v;
          if (*r < 0) *r += MOD;
          *l = (*l) + v;
          if (*l >= MOD) *l -= MOD;
          ++l, ++r, w += step;
        }
      }
    }
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    if (inv) {
      int mlt = pw(n, MOD - 2);
      for (int i = (0); i < (n); ++i) a[i] = (long long)a[i] * mlt % MOD;
    }
  }
  void mult(const int *a, int na, const int *b, int nb, int *c, int nc) {
    int sz = 1;
    while (sz < na + nb - 1) sz *= 2;
    vector<int> A(sz, 0), B(sz, 0);
    for (int i = (0); i < (na); ++i) A[i] = a[i];
    for (int i = (0); i < (nb); ++i) B[i] = b[i];
    fft(A.data(), sz, false);
    fft(B.data(), sz, false);
    for (int i = (0); i < (sz); ++i) A[i] = (long long)A[i] * B[i] % MOD;
    fft(A.data(), sz, true);
    for (int i = (0); i < (nc); ++i) c[i] = i < sz ? A[i] : 0;
  }
};
const int MAXN = 20000;
const int MAXQ = 10;
const int MAXS = 4 * MAXN;
int n, tupsz;
int a[MAXN];
int nq;
int qv[MAXQ], ql[MAXQ], qr[MAXQ], qd[MAXQ], qans[MAXQ];
int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) {
  if (k < 0 || k > n) return 0;
  return (long long)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int b[MAXN];
vector<int> sprod[MAXS];
NTT ntt;
vector<int> mlt(const vector<int> &a, const vector<int> &b) {
  if (((int)(a).size()) == 0 || ((int)(b).size()) == 0) return vector<int>();
  vector<int> ret(((int)(a).size()) + ((int)(b).size()) - 1, 0);
  ntt.mult(a.data(), ((int)(a).size()), b.data(), ((int)(b).size()), ret.data(),
           ((int)(ret).size()));
  return ret;
}
void sinit(int x, int l, int r) {
  if (l == r) {
    sprod[x].clear();
    sprod[x].push_back(1);
    sprod[x].push_back(b[l]);
  } else {
    int m = l + (r - l) / 2;
    sinit(2 * x + 1, l, m);
    sinit(2 * x + 2, m + 1, r);
    sprod[x] = mlt(sprod[2 * x + 1], sprod[2 * x + 2]);
  }
}
void sappend(int x, int l, int r, int L, int R, vector<int> &LST) {
  if (L <= l && r <= R) {
    LST.push_back(x);
  } else {
    int m = l + (r - l) / 2;
    if (L <= m) sappend(2 * x + 1, l, m, L, R, LST);
    if (m + 1 <= R) sappend(2 * x + 2, m + 1, r, L, R, LST);
  }
}
vector<int> add(const vector<int> &a, int b) {
  b = (b % MOD + MOD) % MOD;
  int n = ((int)(a).size()) - 1;
  vector<int> bpw(n + 1);
  bpw[0] = 1;
  for (int i = (1); i <= (n); ++i) bpw[i] = (long long)bpw[i - 1] * b % MOD;
  vector<int> c(n + 1);
  for (int x = (0); x <= (n); ++x) c[x] = (long long)fac[n - x] * a[x] % MOD;
  vector<int> d(n + 1);
  for (int y = (0); y <= (n); ++y) d[y] = (long long)ifac[y] * bpw[y] % MOD;
  vector<int> ret = mlt(c, d);
  ret.resize(n + 1);
  for (int k = (0); k <= (n); ++k)
    ret[k] = (long long)ret[k] * ifac[n - k] % MOD;
  return ret;
}
void solve() {
  inv[1] = 1;
  for (int i = (2); i <= (n); ++i)
    inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
  fac[0] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = (long long)fac[i - 1] * i % MOD;
  ifac[0] = 1;
  for (int i = (1); i <= (n); ++i)
    ifac[i] = (long long)ifac[i - 1] * inv[i] % MOD;
  for (int i = (0); i < (n); ++i) b[i] = (-a[i] % MOD + MOD) % MOD;
  sinit(0, 0, n - 1);
  for (int i = (0); i < (nq); ++i) {
    vector<int> outidx;
    vector<int> inidx;
    if (ql[i] != 0) sappend(0, 0, n - 1, 0, ql[i] - 1, outidx);
    sappend(0, 0, n - 1, ql[i], qr[i], inidx);
    if (qr[i] != n - 1) sappend(0, 0, n - 1, qr[i] + 1, n - 1, outidx);
    sort(outidx.begin(), outidx.end(), [&](const int &x, const int &y) {
      return ((int)(sprod[x]).size()) < ((int)(sprod[y]).size());
    });
    sort(inidx.begin(), inidx.end(), [&](const int &x, const int &y) {
      return ((int)(sprod[x]).size()) < ((int)(sprod[y]).size());
    });
    vector<int> out(1, 1);
    for (int j = (0); j < (((int)(outidx).size())); ++j)
      out = mlt(out, sprod[outidx[j]]);
    vector<int> in(1, 1);
    for (int j = (0); j < (((int)(inidx).size())); ++j)
      in = mlt(in, sprod[inidx[j]]);
    out = add(out, qv[i]);
    in = add(in, qv[i] - qd[i]);
    vector<int> res = mlt(out, in);
    qans[i] = res[tupsz];
  }
}
void run() {
  scanf("%d%d", &n, &tupsz);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  scanf("%d", &nq);
  for (int i = (0); i < (nq); ++i) {
    int kind;
    scanf("%d%d", &kind, &qv[i]);
    if (kind == 1)
      scanf("%d%d", &ql[i], &qd[i]), --ql[i], qr[i] = ql[i], qd[i] -= a[ql[i]];
    if (kind == 2) scanf("%d%d%d", &ql[i], &qr[i], &qd[i]), --ql[i], --qr[i];
  }
  solve();
  for (int i = (0); i < (nq); ++i) printf("%d\n", qans[i]);
}
int main() {
  run();
  return 0;
}
