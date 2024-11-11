#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXK = 30000;
const int N = 1 << 16;
const int MOD = 1000000007;
const double MYPI = acos(-1);
typedef struct Pol {
  int x[MAXK + 1];
} Pol;
int inv[MAXK + 1];
int fact[MAXK + 1];
int ifact[MAXK + 1];
int ipow(int x, int n) {
  int ret = 1;
  while (true) {
    if (n & 1) ret = (long long)ret * x % MOD;
    if ((n >>= 1) == 0) return ret;
    x = (long long)x * x % MOD;
  }
}
void fft(complex<double> a[N]) {
  for (int i = 0, j = 0; i < N - 1; ++i) {
    if (i < j) swap(a[i], a[j]);
    int m = N / 2;
    j ^= m;
    while ((j & m) == 0) m /= 2, j ^= m;
  }
  for (int len = 1; len < N; len <<= 1) {
    for (int off = (0); off < (len); ++off) {
      double t = MYPI * off / len;
      complex<double> w(cos(t), sin(t));
      for (int i = off; i < N; i += 2 * len) {
        complex<double> u = a[i], v = w * a[i + len];
        a[i] = u + v;
        a[i + len] = u - v;
      }
    }
  }
}
int K;
void pmult(Pol &c, Pol &a, Pol &b) {
  static complex<double> A[N], B[N], C[N], D[N];
  for (int i = (0); i <= (K); ++i)
    A[i] = complex<double>(a.x[i] & ((1 << 15) - 1), a.x[i] >> 15);
  for (int i = (0); i <= (K); ++i)
    B[i] = complex<double>(b.x[i] & ((1 << 15) - 1), b.x[i] >> 15);
  for (int i = (K + 1); i < (N); ++i) A[i] = B[i] = complex<double>(0, 0);
  fft(A);
  fft(B);
  for (int i = (0); i < (N); ++i) {
    int j = (N - i) & (N - 1);
    complex<double> w = (A[i] + conj(A[j])) * complex<double>(.5, 0);
    complex<double> x = (A[i] - conj(A[j])) * complex<double>(0, -.5);
    complex<double> y = (B[i] + conj(B[j])) * complex<double>(.5, 0);
    complex<double> z = (B[i] - conj(B[j])) * complex<double>(0, -.5);
    C[j] = w * y + w * z * complex<double>(0, 1);
    D[j] = x * y + x * z * complex<double>(0, 1);
  }
  fft(C);
  fft(D);
  for (int i = (0); i <= (K); ++i) {
    int w = (long long)(real(C[i]) / N + .5) % MOD;
    int x = (long long)(imag(C[i]) / N + .5) % MOD;
    int y = (long long)(real(D[i]) / N + .5) % MOD;
    int z = (long long)(imag(D[i]) / N + .5) % MOD;
    c.x[i] = (w + ((long long)(x + y) << 15) + ((long long)z << 30)) % MOD;
  }
}
void pmult(Pol &a, int n2, Pol &b) {
  static Pol c;
  int step = ipow(2, n2), mlt = 1;
  for (int i = (0); i <= (K); ++i)
    c.x[i] = (long long)a.x[i] * mlt % MOD, mlt = (long long)mlt * step % MOD;
  pmult(a, c, b);
}
void ppow(Pol &a, Pol &b, int n) {
  for (int i = (0); i <= (K); ++i) a.x[i] = i == 0 ? 1 : 0;
  static Pol c;
  for (int i = (0); i <= (K); ++i) c.x[i] = b.x[i];
  int cn = 1;
  while (true) {
    if (n & 1) pmult(a, cn, c);
    if ((n >>= 1) == 0) break;
    pmult(c, cn, c), cn += cn;
  }
}
long long n;
Pol h1;
Pol hn;
void run() {
  fact[0] = 1;
  for (int i = (1); i <= (MAXK); ++i)
    fact[i] = (long long)fact[i - 1] * i % MOD;
  inv[1] = 1;
  for (int i = (2); i <= (MAXK); ++i)
    inv[i] = (MOD - (long long)(MOD / i) * inv[MOD % i] % MOD) % MOD;
  ifact[0] = 1;
  for (int i = (1); i <= (MAXK); ++i)
    ifact[i] = (long long)ifact[i - 1] * inv[i] % MOD;
  scanf("%I64d%d", &n, &K);
  if (n > K) {
    printf("0\n");
    return;
  }
  h1.x[0] = 0;
  for (int i = (1); i <= (K); ++i) h1.x[i] = ifact[i];
  ppow(hn, h1, n);
  int ret = 0;
  for (int i = (0); i <= (K); ++i) {
    int cur = (long long)hn.x[i] * fact[K] % MOD * ifact[K - i] % MOD;
    if ((ret += cur) >= MOD) ret -= MOD;
  }
  printf("%d\n", ret);
}
int main() {
  run();
  return 0;
}
