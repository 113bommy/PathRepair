#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
namespace fft {
int len, last = -1, step = 0, rev[1 << 16];
long long C[1 << 16], D[1 << 16], P[1 << 16], Q[1 << 16];
struct complx {
  long double real, img;
  inline complx() { real = img = 0.0; }
  inline complx conjugate() { return complx(real, -img); }
  inline complx(long double x) { real = x, img = 0.0; }
  inline complx(long double x, long double y) { real = x, img = y; }
  inline complx operator+(complx other) {
    return complx(real + other.real, img + other.img);
  }
  inline complx operator-(complx other) {
    return complx(real - other.real, img - other.img);
  }
  inline complx operator*(complx other) {
    return complx((real * other.real) - (img * other.img),
                  (real * other.img) + (img * other.real));
  }
} u[1 << 16], v[1 << 16], f[1 << 16], g[1 << 16], dp[1 << 16], inv[1 << 16];
inline long long round_half_even(long double x) {
  long long res = abs(x) + 0.5;
  if (x < 0) res = -res;
  return res;
}
void build(int& a, long long* A, int& b, long long* B) {
  while (a > 1 && A[a - 1] == 0) a--;
  while (b > 1 && B[b - 1] == 0) b--;
  len = 1 << (32 - __builtin_clz(a + b) - (__builtin_popcount(a + b) == 1));
  for (int i = a; i < len; i++) A[i] = 0;
  for (int i = b; i < len; i++) B[i] = 0;
  if (!step++) {
    dp[1] = inv[1] = complx(1);
    for (int i = 1; (1 << i) < 1 << 16; i++) {
      double theta = (2.0 * acos(0.0)) / (1 << i);
      complx mul = complx(cos(theta), sin(theta));
      complx inv_mul = complx(cos(-theta), sin(-theta));
      int lim = 1 << i;
      for (int j = lim >> 1; j < lim; j++) {
        dp[2 * j] = dp[j], inv[2 * j] = inv[j];
        inv[2 * j + 1] = inv[j] * inv_mul;
        dp[2 * j + 1] = dp[j] * mul;
      }
    }
  }
  if (last != len) {
    last = len;
    int bit = (32 - __builtin_clz(len) - (__builtin_popcount(len) == 1));
    for (int i = 0; i < len; i++)
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (bit - 1));
  }
}
void transform_unrolled(complx* in, complx* out, complx* ar) {
  for (int i = 0; i < len; i++) out[i] = in[rev[i]];
  for (int k = 1; k < len; k <<= 1) {
    for (int i = 0; i < len; i += (k << 1)) {
      complx z, *a = out + i, *b = out + i + k, *c = ar + k;
      if (k == 1) {
        z = (*b) * (*c);
        *b = *a - z, *a = *a + z;
      }
      for (int j = 0; j < k && k > 1; j += 2, a++, b++, c++) {
        z = (*b) * (*c);
        *b = *a - z, *a = *a + z;
        a++, b++, c++;
        z = (*b) * (*c);
        *b = *a - z, *a = *a + z;
      }
    }
  }
}
bool equals(int a, long long* A, int b, long long* B) {
  if (a != b) return false;
  for (a = 0; a < b && A[a] == B[a]; a++) {
  }
  return (a == b);
}
int mod_multiply(int a, long long* A, int b, long long* B, int mod,
                 long long* tp) {
  build(a, A, b, B);
  int flag = equals(a, A, b, B);
  for (int i = 0; i < len; i++) A[i] %= mod, B[i] %= mod;
  for (int i = 0; i < len; i++) u[i] = complx(A[i] & 32767, A[i] >> 15);
  for (int i = 0; i < len; i++) v[i] = complx(B[i] & 32767, B[i] >> 15);
  transform_unrolled(u, f, dp);
  for (int i = 0; i < len; i++) g[i] = f[i];
  if (!flag) transform_unrolled(v, g, dp);
  for (int i = 0; i < len; i++) {
    int j = (len - 1) & (len - i);
    complx c1 = f[j].conjugate(), c2 = g[j].conjugate();
    complx a1 = (f[i] + c1) * complx(0.5, 0);
    complx a2 = (f[i] - c1) * complx(0, -0.5);
    complx b1 = (g[i] + c2) * complx(0.5 / len, 0);
    complx b2 = (g[i] - c2) * complx(0, -0.5 / len);
    v[j] = a1 * b2 + a2 * b1;
    u[j] = a1 * b1 + a2 * b2 * complx(0, 1);
  }
  transform_unrolled(u, f, dp);
  transform_unrolled(v, g, dp);
  long long x, y, z;
  for (int i = 0; i < len; i++) {
    x = f[i].real + 0.5, y = g[i].real + 0.5, z = f[i].img + 0.5;
    tp[i] = (x + ((y % mod) << 15) + ((z % mod) << 30)) % mod;
  }
  return a + b - 1;
}
}  // namespace fft
pair<long long, long long> extendedEuclid(long long a, long long b) {
  if (b == 0)
    return pair<long long, long long>(1, 0);
  else {
    pair<long long, long long> d = extendedEuclid(b, a % b);
    return pair<long long, long long>(d.second, d.first - d.second * (a / b));
  }
}
long long modularInverse(int a, int n) {
  pair<long long, long long> ret = extendedEuclid(a, n);
  return ((ret.first % n) + n) % n;
}
long long fact[1 << 16], inv[1 << 16];
long long bigmode(int v, long long po) {
  if (po == 1) return v;
  if (po & 1) {
    long long d = bigmode(v, po - 1);
    return (d * v) % mod;
  }
  long long d = bigmode(v, po / 2);
  return (d * d) % mod;
}
vector<int> bs;
long long A[1 << 16], B[1 << 16], tp[1 << 16];
long long nCr(int n, int r) {
  if (n == r) return 1;
  if (r == 1) return n;
  long long ret = (fact[n] * inv[r]) % mod;
  return (ret * inv[n - r]) % mod;
}
int k;
vector<int> dp_func(int n) {
  if (n == 1) {
    return bs;
  }
  vector<int> a, b;
  int rem;
  if (n % 2) {
    a = dp_func(n - 1);
    b = bs;
    rem = 1;
  } else {
    a = dp_func(n / 2);
    b = a;
    rem = n / 2;
  }
  for (int i = 1; i <= k; i++) {
    A[i] = (a[i] * bigmode(2, 1LL * i * rem)) % mod;
    A[i] *= inv[i];
    A[i] %= mod;
    B[i] = (b[i] * inv[i]) % mod;
  }
  fft::mod_multiply(k + 1, A, k + 1, B, mod, tp);
  vector<int> ret;
  for (int i = 0; i <= k; i++) {
    ret.push_back((tp[i] * fact[i]) % mod);
  }
  return ret;
}
int main() {
  int i, j, l, m;
  long long n;
  cin >> n >> k;
  if (n > k) {
    printf("0\n");
    return 0;
  }
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= k; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = modularInverse(fact[i], mod);
  }
  bs.resize(k + 1);
  for (int i = 1; i <= k; i++) {
    bs[i] = 1;
  }
  vector<int> vc = dp_func(n);
  long long sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += (1LL * vc[i] * nCr(k, i)) % mod;
  }
  sum %= mod;
  cout << sum << endl;
}
