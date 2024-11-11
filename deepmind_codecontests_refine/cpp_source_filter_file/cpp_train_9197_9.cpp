#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, M = 52, LOG = 63;
const int N = M * 4;
const long long mod = MOD;
const int inv2 = (mod + 1) / 2;
const double pi = acos(-1);
int m;
int inv[N];
int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int dec(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return (long long)a * b % mod; }
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}
void initinv() {
  inv[1] = 1;
  for (int i = 2; i < N; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
}
void rev(complex<double> *a, int n) {
  for (int i = 1, j = n / 2; i < n - 1; ++i) {
    if (i < j) swap(a[i], a[j]);
    int k = n / 2;
    while (j >= k) j -= k, k /= 2;
    if (j < k) j += k;
  }
}
void fft(complex<double> *a, int n, int f) {
  rev(a, n);
  for (int m = 1; m <= n; m <<= 1) {
    complex<double> wm =
        complex<double>(cos(f * 2 * pi / m), sin(f * 2 * pi / m));
    for (int k = 0; k < n; k += m) {
      complex<double> w = complex<double>(1, 0);
      for (int j = 0; j < m / 2; ++j) {
        complex<double> u = a[k + j];
        complex<double> t = w * a[k + j + m / 2];
        a[k + j] = u + t;
        a[k + j + m / 2] = u - t;
        w = w * wm;
      }
    }
  }
}
void conv(int n, long long *x, long long *y, long long *z) {
  static complex<double> p[N], q[N], a[N], b[N], c[N], d[N], w[N];
  static complex<double> r(0.5, 0), h(0, -0.5), o(0, 1);
  for (int i = 0, ed = n; i < ed; ++i) {
    w[i] = complex<double>(cos(2 * pi * i / n), sin(2 * pi * i / n));
    x[i] = (x[i] + mod) % mod, y[i] = (y[i] + mod) % mod;
    p[i] = complex<double>(x[i] >> 15, x[i] & 32767),
    q[i] = complex<double>(y[i] >> 15, y[i] & 32767);
  }
  fft(p, n, 1);
  fft(q, n, 1);
  for (int i = 0, ed = n; i < ed; ++i) {
    int j = i ? (n - i) : 0;
    static complex<double> ka, ba, kb, bb;
    ka = (p[i] + conj(p[j])) * r;
    ba = (p[i] - conj(p[j])) * h;
    kb = (q[i] + conj(q[j])) * r;
    bb = (q[i] - conj(q[j])) * h;
    a[j] = ka * kb;
    b[j] = ka * bb;
    c[j] = kb * ba;
    d[j] = ba * bb;
  }
  for (int i = 0, ed = n; i < ed; ++i) {
    p[i] = a[i] + b[i] * o;
    q[i] = c[i] + d[i] * o;
  }
  fft(p, n, 1);
  fft(q, n, 1);
  for (int i = 0, ed = n; i < ed; ++i) {
    long long a, b, c, d;
    a = (long long)(p[i].real() / n + 0.5) % mod;
    b = (long long)(p[i].imag() / n + 0.5) % mod;
    c = (long long)(q[i].real() / n + 0.5) % mod;
    d = (long long)(q[i].imag() / n + 0.5) % mod;
    z[i] = ((a << 30) + ((b + c) << 15) + d) % mod;
  }
}
void cmult(int *a, int n, int *b, int m, int *c) {
  static long long A[N], B[N], C[N];
  int l;
  for (l = 1; l <= (n + m - 1); l <<= 1)
    ;
  for (int i = 0; i < n; i++) A[i] = a[i];
  for (int i = 0; i < m; i++) B[i] = b[i];
  fill(A + n, A + l, 0);
  fill(B + m, B + l, 0);
  conv(l, A, B, C);
  for (int i = 0; i < l; i++) c[i] = C[i] % mod;
}
void cinv(int *a, int *b, int n) {
  static int C[N];
  if (n == 0) {
    b[0] = qpow(a[0], mod - 2);
    return;
  }
  cinv(a, b, n >> 1);
  cmult(b, n, b, n, C);
  cmult(C, n, a, n, C);
  for (int i = 0; i < n; i++) b[i] = dec(mul(2, b[i]), C[i]);
  fill(b + n, b + 2 * n, 0);
}
void cintegrate(int *f, int *g, int n) {
  for (int i = n; i >= 1; i--) g[i] = mul(f[i - 1], inv[i]);
  g[0] = 0;
}
void cderivation(int *f, int *g, int n) {
  for (int i = 1; i < n; i++) g[i - 1] = mul(f[i], i);
  g[n - 1] = 0;
}
void cln(int *f, int *g, int n) {
  static int D[N], A[N];
  cderivation(f, D, n);
  cinv(f, A, n);
  cmult(A, n, D, n, A);
  cintegrate(A, g, n);
}
void cexp(int *a, int *b, int n) {
  static int D[N];
  if (n == 1) {
    b[0] = 1;
    return;
  }
  cexp(a, b, n >> 1);
  cln(b, D, n);
  for (int i = 0; i < n; i++) D[i] = dec(a[i], D[i]);
  D[0] = add(1, D[0]);
  cmult(D, n, b, n, b);
}
void csqrt(int *a, int *b, int n) {
  static int C[N];
  if (n == 1) {
    b[0] = sqrt(a[0] + 0.5);
    return;
  }
  csqrt(a, b, n >> 1);
  cinv(b, C, n);
  cmult(a, n, C, n, C);
  for (int i = 0; i < n; i++) b[i] = mul(inv2, add(b[i], C[i]));
  fill(b + n, b + 2 * n, 0);
}
void cpow(int *f, int *g, int n, int k) {
  static int C[N];
  cln(f, C, n);
  for (int i = 0; i < n; i++) C[i] = mul(C[i], k);
  cexp(C, g, n);
}
void cdiv(int *a, int n, int *b, int m, int *ret) {
  static int c[N], d[N], e[N], l;
  while (b[m - 1] == 0) m--;
  if (n < m) return;
  for (l = 1; l <= n - m + 1; l <<= 1)
    ;
  reverse_copy(a, a + n, c);
  reverse_copy(b, b + m, d);
  for (int i = m; i < n + m + 1; i++) d[i] = 0;
  memset(e, 0, sizeof(e[0]) * (l * 2));
  cinv(d, e, l);
  cmult(e, n - m + 1, c, n - m + 1, d);
  reverse_copy(d, d + n - m + 1, ret);
}
void cmod(int *a, int n, int *b, int m, int *ret) {
  static int c[N];
  while (b[m - 1] == 0) m--;
  cdiv(a, n, b, m, c);
  cmult(c, n - m + 1, b, m, c);
  for (int i = 0; i < m - 1; i++) ret[i] = add(a[i] - c[i], mod);
}
void cgcd(int *a, int n, int *b, int m, int *c) {
  static int r[N];
  fill(c, c + max(m, n), 0);
  int i;
  while (1) {
    cmod(a, n, b, m, r);
    for (i = m - 2; i >= 0; i--)
      if (r[i]) break;
    i++;
    if (i == 0) break;
    memcpy(a, b, sizeof(b[0]) * m);
    memcpy(b, r, sizeof(r[0]) * i);
    n = m;
    m = i;
  }
  memcpy(c, b, sizeof(b[0]) * m);
  int invc = qpow(c[0], mod - 2);
  for (int i = 0; i < m; i++) c[i] = mul(c[i], invc);
}
int lagrange(int *f, int n, int x) {
  static int C[N], D[N];
  cinv(f, C, n);
  cpow(C, D, n, x);
  return mul(D[x - 1], qpow(x, mod - 2));
}
struct Vector {
  int a[M];
  Vector() { memset(a, 0, sizeof(a)); }
  int &operator[](const int &i) { return a[i]; }
  const int operator[](const int &i) const { return a[i]; }
  int operator*(const Vector &b) {
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      if ((ret += (long long)a[i] * b[i] % MOD) >= MOD) {
        ret -= MOD;
      }
    }
    return ret;
  }
  Vector operator+(const Vector &b) {
    Vector ret;
    for (int i = 0; i < m; ++i) {
      if ((ret[i] = a[i] + b[i]) >= MOD) {
        ret[i] -= MOD;
      }
    }
    return ret;
  }
};
Vector operator*(int k, const Vector &b) {
  Vector ret;
  for (int i = 0; i < m; ++i) {
    ret[i] = (long long)k * b[i] % MOD;
  }
  return ret;
}
struct Matrix {
  int a[M][M];
  int *operator[](const int &i) { return a[i]; }
  const int *operator[](const int &i) const { return a[i]; }
  Vector operator*(const Vector &b) {
    Vector ret;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((ret[i] += (long long)a[i][j] * b[j] % MOD) >= MOD) {
          ret[i] -= MOD;
        }
      }
    }
    return ret;
  }
};
int inverse(int a) {
  return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}
struct Poly {
  vector<int> a;
  Poly() { a.clear(); }
  Poly(vector<int> &a) : a(a) {}
  int length() const { return a.size(); }
  Poly move(int d) {
    vector<int> na(d, 0);
    na.insert(na.end(), a.begin(), a.end());
    return Poly(na);
  }
  int calc(vector<int> &d, int pos) {
    int ret = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      if ((ret += (long long)d[pos - i] * a[i] % MOD) >= MOD) {
        ret -= MOD;
      }
    }
    return ret;
  }
  Poly operator-(const Poly &b) {
    vector<int> na(max(this->length(), b.length()));
    for (int i = 0; i < (int)na.size(); ++i) {
      int aa = i < this->length() ? this->a[i] : 0,
          bb = i < b.length() ? b.a[i] : 0;
      na[i] = (aa + MOD - bb) % MOD;
    }
    return Poly(na);
  }
};
Poly operator*(const int &c, const Poly &p) {
  vector<int> na(p.length());
  for (int i = 0; i < (int)na.size(); ++i) {
    na[i] = (long long)c * p.a[i] % MOD;
  }
  return na;
}
vector<int> Berlekamp(vector<int> a) {
  int n = a.size();
  Poly s, b;
  s.a.push_back(1), b.a.push_back(1);
  for (int i = 1, j = 0, ld = a[0]; i < n; ++i) {
    int d = s.calc(a, i);
    if (d) {
      if ((s.length() - 1) * 2 <= i) {
        Poly ob = b;
        b = s;
        s = s - (long long)d * inverse(ld) % MOD * ob.move(i - j);
        j = i;
        ld = d;
      } else {
        s = s - (long long)d * inverse(ld) % MOD * b.move(i - j);
      }
    }
  }
  return s.a;
}
Vector LinearRec(vector<Vector> &first, vector<int> &trans, long long k) {
  int n = first.size();
  int m;
  static int a[N];
  static int b[N];
  static int c[N];
  static int d[N];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  for (int i = 0; i < n; i++) a[i] = trans[i];
  a[n] = 1;
  reverse(a, a + n);
  for (int i = 0; i < n; i++) a[i] = MOD - a[i];
  for (m = 1; m <= n + 1; m <<= 1)
    ;
  b[1] = 1;
  c[0] = 1;
  for (k--; k; k >>= 1) {
    if (k & 1) {
      memset(d, 0, sizeof(d));
      cmult(c, m, b, m, c);
      cmod(c, 2 * m, a, m, d);
      memcpy(c, d, sizeof(d));
    }
    memset(d, 0, sizeof(d));
    cmult(b, m, b, m, b);
    cmod(b, 2 * m, a, m, d);
    memcpy(b, d, sizeof(d));
  }
  Vector ans;
  for (int i = 0; i < n; i++) ans = ans + c[i] * first[i];
  return ans;
};
Vector solve(Matrix &A, long long k, Vector &b) {
  vector<Vector> vs;
  vs.push_back(A * b);
  for (int i = 1; i < m * 2; ++i) {
    vs.push_back(A * vs.back());
  }
  if (k == 0) {
    return b;
  } else if (k <= m * 2) {
    return vs[k - 1];
  }
  Vector x;
  for (int i = 0; i < m; ++i) {
    x[i] = rand() % MOD;
  }
  vector<int> a(m * 2);
  for (int i = 0; i < m * 2; ++i) {
    a[i] = vs[i] * x;
  }
  vector<int> s = Berlekamp(a);
  s.erase(s.begin());
  for (int i = 0; i < s.size(); ++i) {
    s[i] = (MOD - s[i]) % MOD;
  }
  vector<Vector> vf(vs.begin(), vs.begin() + s.size());
  return LinearRec(vf, s, k);
}
int n;
long long k;
int main() {
  initinv();
  scanf("%lld %d %d", &k, &m, &n);
  Matrix A;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      A[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    char s[3];
    scanf("%s", s);
    int t1 =
        'a' <= s[0] && s[0] <= 'z' ? t1 = s[0] - 'a' : t1 = s[0] - 'A' + 26;
    int t2 =
        'a' <= s[1] && s[1] <= 'z' ? t2 = s[1] - 'a' : t2 = s[1] - 'A' + 26;
    A[t1][t2] = 0;
  }
  Vector b;
  for (int i = 0; i < m; ++i) {
    b[i] = 1;
  }
  int ans = solve(A, k - 1, b) * b;
  printf("%d\n", ans);
  return 0;
}
