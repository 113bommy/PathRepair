#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
struct MODOPS {
  static unsigned long long mult(unsigned long long a, unsigned long long b,
                                 unsigned long long m) {
    return norm((long long)a * b - (long long)((long double)a * b / m) * m, m);
    unsigned long long oa = a, ob = b,
                       test = norm((long long)a * b -
                                       (long long)((long double)a * b / m) * m,
                                   m),
                       ret = 0;
    while (true) {
      if (b & 1) ret = (ret + a) % m;
      if ((b >>= 1) == 0) break;
      a = 2 * a % m;
    }
    if (ret != test) {
      printf("%llu * %llu mod %llu = %llu vs %llu (%llu %llf %llf %llu %llu)\n",
             oa, ob, m, ret, test, oa * ob, (long double)oa * ob,
             (long double)oa * ob / m, (long long)((long double)oa * ob / m),
             (unsigned long long)((long double)oa * ob / m) * m);
      exit(0);
    }
    return ret;
  }
  static unsigned long long add(unsigned long long a, unsigned long long b,
                                unsigned long long m) {
    return a < m - b ? a + b : a - (m - b);
  }
  static unsigned long long sub(unsigned long long a, unsigned long long b,
                                unsigned long long m) {
    return m - a <= m - b ? a - b : a + (m - b);
  }
  static unsigned long long pw(unsigned long long x, unsigned long long n,
                               unsigned long long m) {
    unsigned long long ret = 1 % m;
    while (true) {
      if (n & 1) ret = mult(ret, x, m);
      if ((n >>= 1) == 0) return ret;
      x = mult(x, x, m);
    }
  }
  static unsigned long long norm(long long x, unsigned long long m) {
    return x >= 0 ? x % m : (m - (-x) % m) % m;
  }
};
const static int miller_rabin_p[7] = {2,      325,     9375,      28178,
                                      450775, 9780504, 1795265022};
struct ALG {
  static unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  static bool miller_rabin(unsigned long long p, unsigned long long a) {
    if (p % a == 0) return true;
    int r = 0;
    unsigned long long s = a - 1;
    while ((s & 1) == 0) s >>= 1, ++r;
    unsigned long long x = MODOPS::pw(p, s, a);
    if (x == 1) return true;
    for (int j = (0); j < (r); ++j) {
      if (x == a - 1) return true;
      x = MODOPS::mult(x, x, a);
    }
    return false;
  }
  static bool isprime(unsigned long long a) {
    if (a <= 1) return false;
    for (int i = (0); i < (7); ++i)
      if (!miller_rabin(miller_rabin_p[i], a)) return false;
    return true;
  }
  static unsigned long long pollard_rho(unsigned long long a) {
    for (int c = 1;; ++c) {
      unsigned long long x = 2, y = 2;
      while (true) {
        x = MODOPS::mult(x, x, a), x = MODOPS::add(x, c, a);
        y = MODOPS::mult(y, y, a), y = MODOPS::add(y, c, a);
        y = MODOPS::mult(y, y, a), y = MODOPS::add(y, c, a);
        unsigned long long d = gcd(x < y ? y - x : x - y, a);
        if (d == a)
          break;
        else if (d > 1)
          return d;
      }
    }
  }
  static vector<pair<long long, int> > factorize(unsigned long long x) {
    vector<pair<long long, int> > ret;
    for (int i = 2; i * i < x && i < 10000; ++i)
      if (x % i == 0) {
        int cnt = 0;
        while (x % i == 0) x /= i, ++cnt;
        ret.push_back(make_pair(i, cnt));
        if (x == 1) break;
      }
    if (x == 1) return ret;
    if (isprime(x)) {
      ret.push_back(make_pair(x, 1));
      return ret;
    }
    long long d = pollard_rho(x);
    ret = factorize(d);
    vector<pair<long long, int> > oth = factorize(x / d);
    for (int i = (0); i < (((int)(oth).size())); ++i) ret.push_back(oth[i]);
    sort(ret.begin(), ret.end());
    int nret = 0;
    for (int i = (0); i < (((int)(ret).size())); ++i)
      if (i == 0 || ret[nret - 1].first == ret[i].first)
        ret[nret - 1].second += ret[i].second;
      else
        ret[nret++] = ret[i];
    ret.resize(nret);
    return ret;
  }
  static unsigned long long proot(unsigned long long p) {
    vector<pair<long long, int> > fact = factorize(p - 1);
    for (int g = (2); g < (p); ++g) {
      bool ok = gcd(g, p) == 1;
      if (ok)
        for (int i = (0); i < (((int)(fact).size())); ++i) {
          if (MODOPS::pw(g, (p - 1) / fact[i].first, p) == 1) {
            ok = false;
            break;
          }
        }
      if (ok) return g;
    }
    return -1;
  }
};
struct NTT {
  unsigned long long p, pg;
  void init(unsigned long long _p, unsigned long long _pg) { p = _p, pg = _pg; }
  void _init(int n, int &nlog, unsigned long long &g,
             vector<unsigned long long> &w) {
    assert((p - 1) % n == 0);
    g = MODOPS::pw(pg, (p - 1) / n, p);
    nlog = 0;
    while ((1 << nlog) < n) ++nlog;
    if ((1 << nlog) != n) nlog = -1;
    w = vector<unsigned long long>(n);
    w[0] = 1;
    for (int i = (1); i < (n); ++i) w[i] = MODOPS::mult(w[i - 1], g, p);
  }
  int fftn, fftnlog;
  unsigned long long fftg;
  vector<unsigned long long> fftw;
  void initfft(int n) {
    fftn = n, _init(fftn, fftnlog, fftg, fftw);
    assert(fftnlog != -1);
  }
  void fft(unsigned long long *a, int n, bool inv) {
    if (n != fftn) initfft(n);
    for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) {
      if (i < j) swap(a[i], a[j]);
      for (k = l; k & j; j ^= k, k >>= 1)
        ;
    }
    unsigned long long *l, *r, *w;
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
      for (int i = 0; i < n; i += (hlen << 1)) {
        l = a + i, r = l + hlen, w = fftw.data();
        for (int off = (0); off < (hlen); ++off) {
          unsigned long long v = MODOPS::mult(*r, *w, p);
          *r = MODOPS::sub(*l, v, p);
          *l = MODOPS::add(*l, v, p);
          ++l, ++r, w += step;
        }
      }
    }
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    if (inv) {
      unsigned long long mlt = MODOPS::pw(n, p - 2, p);
      for (int i = (0); i < (n); ++i) a[i] = MODOPS::mult(a[i], mlt, p);
    }
  }
  int bsn, bsnn, bsnlog;
  unsigned long long bsg;
  vector<unsigned long long> bsw, bsa, bsb;
  void initbluestein(int n) {
    bsn = n;
    _init(bsn, bsnlog, bsg, bsw);
    bsnn = 1;
    while (bsnn < 2 * n) bsnn <<= 1;
    bsa = vector<unsigned long long>(bsnn),
    bsb = vector<unsigned long long>(bsnn);
    for (int i = (0); i < (bsnn); ++i) {
      int j = i - n, jj = ((j - (long long)j * j) / 2 % n + n) % n;
      bsa[i] = bsw[jj], bsb[i] = bsw[jj == 0 ? 0 : n - jj];
    }
    fft(bsa.data(), bsnn, false);
    fft(bsb.data(), bsnn, false);
  }
  void bluestein(unsigned long long *a, int n, bool inv) {
    if (n != bsn) initbluestein(n);
    if (inv) reverse(bsw.begin() + 1, bsw.end());
    for (int i = (0); i < (n); ++i)
      a[i] = MODOPS::mult(a[i], bsw[(long long)i * (i + 1) / 2 % n], p);
    for (int i = (n); i < (bsnn); ++i) a[i] = 0;
    fft(a, bsnn, false);
    if (!inv)
      for (int i = (0); i < (bsnn); ++i) a[i] = MODOPS::mult(a[i], bsa[i], p);
    if (inv)
      for (int i = (0); i < (bsnn); ++i) a[i] = MODOPS::mult(a[i], bsb[i], p);
    fft(a, bsnn, true);
    for (int i = (0); i < (n); ++i)
      a[i] = MODOPS::mult(a[i + n], bsw[(long long)i * (i - 1) / 2 % n], p);
    for (int i = (n); i < (bsnn); ++i) a[i] = 0;
    if (inv) reverse(bsw.begin() + 1, bsw.end());
    if (inv) {
      unsigned long long mlt = MODOPS::pw(n, p - 2, p);
      for (int i = (0); i < (n); ++i) a[i] = MODOPS::mult(a[i], mlt, p);
    }
  }
};
NTT ntt;
const int MAXN = 100000;
const int MAXNN = 1 << 18;
int n;
int a[MAXN];
int aa[MAXN];
int b[MAXN];
int bb[MAXN];
int c[MAXN];
int cc[MAXN];
unsigned long long AA[MAXNN];
unsigned long long BB[MAXNN];
unsigned long long CC[MAXNN];
vector<unsigned long long> fftstupid(const vector<unsigned long long> &a,
                                     unsigned long long g, unsigned long long p,
                                     bool inv = false) {
  int n = ((int)(a).size());
  unsigned long long x = 1;
  vector<unsigned long long> ret(n, 0);
  if (inv) g = MODOPS::pw(g, n - 1, p);
  for (int i = (0); i < (n); ++i) {
    unsigned long long y = 1;
    for (int j = (0); j < (n); ++j) {
      ret[i] = MODOPS::add(ret[i], MODOPS::mult(a[j], y, p), p);
      y = MODOPS::mult(y, x, p);
    }
    x = MODOPS::mult(x, g, p);
  }
  if (inv) {
    unsigned long long mlt = MODOPS::pw(n, p - 2, p);
    for (int i = (0); i < (((int)(ret).size())); ++i)
      ret[i] = MODOPS::mult(ret[i], mlt, p);
  }
  return ret;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &b[i]);
  for (int i = (0); i < (n); ++i) scanf("%d", &c[i]);
  for (int i = (1); i < (n); ++i)
    if ((c[i] - c[i - 1]) % 2 != 0) {
      printf("0\n");
      return;
    }
  int nn = 1;
  while (nn < 2 * n) nn <<= 1;
  unsigned long long g = ALG::gcd(n, nn), dv = nn / g * n;
  unsigned long long mn = (unsigned long long)1000 * 10000 * n;
  unsigned long long p = dv + 1;
  while (p < mn || !ALG::isprime(p)) p += dv;
  ntt.init(p, ALG::proot(p));
  for (int i = (0); i < (n); ++i)
    bb[i] = b[(n - i) % n], cc[i] = (c[i] - c[(i + n - 1) % n]) / 2;
  for (int i = (0); i < (n); ++i)
    BB[i] = MODOPS::norm(bb[i], p), CC[i] = MODOPS::norm(cc[i], p);
  ntt.bluestein(BB, n, false);
  ntt.bluestein(CC, n, false);
  for (int i = (0); i < (n); ++i)
    AA[i] = MODOPS::mult(MODOPS::pw(BB[i], p - 2, p), CC[i], p);
  ntt.bluestein(AA, n, true);
  bool ok = true;
  for (int i = (0); i < (n); ++i)
    if (AA[i] < 5000)
      aa[i] = AA[i];
    else if (AA[i] > p - 5000)
      aa[i] = -(int)(p - AA[i]);
    else
      ok = false;
  if (!ok) {
    printf("0\n");
    return;
  }
  a[0] = 0;
  for (int i = (1); i < (n); ++i) a[i] = a[i - 1] - aa[i];
  long long x = 0, y = 0, z = -c[0];
  for (int i = (0); i < (n); ++i) {
    int diff = b[i] - a[i];
    z += diff * diff, y -= 2 * diff, x++;
  }
  long long ww = y * y - 4 * x * z, w = (long long)sqrt(1.0 * abs(ww));
  vector<int> a0;
  if (w * w == ww)
    for (int i = (0); i < (2); ++i) {
      long long num = i == 0 ? -y - w : -y + w, den = 2 * x;
      if (num % den == 0 && (i == 0 || w != 0)) a0.push_back(num / den);
    }
  printf("%d\n", ((int)(a0).size()));
  sort(a0.begin(), a0.end());
  for (int i = (0); i < (((int)(a0).size())); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (j != 0) printf(" ");
      printf("%d", a[j] + a0[i]);
    }
    puts("");
  }
}
int main() {
  run();
  return 0;
}
