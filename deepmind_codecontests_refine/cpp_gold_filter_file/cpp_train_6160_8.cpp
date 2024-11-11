#include <bits/stdc++.h>
using namespace std;
int mod;
int power(int x, int y, int mod) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
  }
  return ret;
}
bool isPrime(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
int primitiveRoot(int p) {
  vector<int> divisors;
  for (int i = 1; i < p - 1; ++i) {
    if ((p - 1) % i == 0) divisors.push_back(i);
  }
  for (int g = 2;; ++g) {
    bool okay = true;
    for (int d : divisors) {
      if (power(g, d, p) == 1) {
        okay = false;
        break;
      }
    }
    if (okay) return g;
  }
  return -1;
}
const int MAXN = 1 << 20;
const double PI = acos(-1);
complex<double> w[MAXN];
void init() {
  for (int i = 0; i < MAXN; ++i) {
    w[i] = complex<double>(cos(2 * PI * i / MAXN), sin(2 * PI * i / MAXN));
  }
}
void fft(int n, vector<complex<double> > &a) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    int wlen = MAXN / len;
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len >> 1; j++) {
        complex<double> u = a[i + j];
        complex<double> v = a[i + j + len / 2] * w[wlen * j];
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
      }
    }
  }
}
const int sz = 16, msk = (1 << 16) - 1;
vector<int> multiply(vector<int> a, vector<int> b) {
  int n = 1 << (32 - __builtin_clz(a.size() + b.size()));
  a.resize(n, 0);
  b.resize(n, 0);
  vector<complex<double> > A(n), B(n);
  for (int i = 0; i < n; i++) {
    A[i] = complex<double>(a[i] & msk, a[i] >> sz);
    B[i] = complex<double>(b[i] & msk, b[i] >> sz);
  }
  fft(n, A);
  fft(n, B);
  complex<double> im2 = {0, 2}, im = {0, 1};
  vector<complex<double> > nA(n), nB(n);
  for (int i = 0; i < n; i++) {
    complex<double> lA = (A[i] + conj(A[(n - i) % n])) / 2.;
    complex<double> gA = (A[i] - conj(A[(n - i) % n])) / im2;
    complex<double> lB = (B[i] + conj(B[(n - i) % n])) / 2.;
    complex<double> gB = (B[i] - conj(B[(n - i) % n])) / im2;
    nA[i] = lA * lB + im * gA * gB;
    nB[i] = lA * gB + gA * lB;
  }
  fft(n, nA);
  fft(n, nB);
  reverse(begin(nA) + 1, end(nA));
  reverse(begin(nB) + 1, end(nB));
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    long long a = llround(nA[i].real() / n) % mod;
    long long b = llround(nB[i].real() / n) % mod;
    long long c = llround(nA[i].imag() / n) % mod;
    ans[i] = (a + (b << sz) + (c << 2 * sz)) % mod;
  }
  ans.resize(a.size() + b.size() - 1);
  return ans;
}
vector<int> czt(vector<int> a, int z, int n) {
  int sz = n + a.size() - 1;
  int iz = power(z, mod - 2, mod);
  vector<int> zp(sz, z), izp(sz, iz);
  zp[0] = zp[1] = izp[0] = izp[1] = 1;
  for (int k = 0; k < 2; ++k) {
    for (int i = 2; i < sz; ++i) {
      zp[i] = 1LL * zp[i] * zp[i - 1] % mod;
      izp[i] = 1LL * izp[i] * izp[i - 1] % mod;
    }
  }
  vector<int> A(a.size());
  for (int i = 0; i < a.size(); ++i) {
    A[a.size() - i - 1] = 1LL * a[i] * izp[i] % mod;
  }
  A = multiply(A, zp);
  for (int i = 0; i < n; ++i) {
    A[i] = 1LL * A[i + a.size() - 1] * izp[i] % mod;
  }
  A.resize(n);
  return A;
}
const int N = 100005;
int n, m;
char s[N], t[N];
int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);
  init();
  for (mod = m;; ++mod) {
    if (!isPrime(mod)) continue;
    int g = primitiveRoot(mod);
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
      P[i] = (s[i] - t[i]) % mod;
      if (P[i] < 0) P[i] += mod;
    }
    P = czt(P, g, mod - 1);
    for (int i = 1; i < mod - 1; ++i) {
      if (P[i] == 0) {
        int r = power(g, i, mod);
        if (r == mod - 1) continue;
        return 0 * printf("%d %d\n", mod, r);
      }
    }
  }
  return 0;
}
