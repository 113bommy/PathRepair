#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template <typename T>
inline bool isLeap(T y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T EGCD(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T x1, y1;
  T d = EGCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M = MOD) {
  A %= M;
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = MOD) {
  return BigMod(A, M - 2, M);
}
template <typename T>
void Compress(T *in, int n, int f = 0) {
  vector<T> vv;
  for (int i = f; i < n + f; i++) vv.push_back(in[i]);
  sort(vv.begin(), vv.end()), vv.erase(unique(vv.begin(), vv.end()), vv.end());
  for (int i = f; i < n + f; i++)
    in[i] = lower_bound(vv.begin(), vv.end(), in[i]) - vv.begin();
}
template <typename T>
T scani(T &n) {
  n = 0;
  bool negative = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return n;
}
template <typename T>
void write(T n, int type = true) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (!n) {
    putchar('0');
    if (type == 32)
      putchar(' ');
    else if (type)
      putchar('\n');
    return;
  }
  char buff[22];
  int len = 0;
  while (n) buff[len++] = n % 10 + 48, n /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buff[i]);
  if (type == 32)
    putchar(' ');
  else if (type)
    putchar('\n');
}
int scans(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
const int pSz = 2000006;
bool np[pSz + 10];
vector<int> prime;
int prime_size;
void sieve() {
  np[0] = np[1] = 1;
  prime.push_back(2);
  for (long long i = 4; i <= pSz; i += 2) np[i] = 1;
  for (long long i = 3; i <= pSz; i += 2) {
    if (!np[i]) {
      prime.push_back(i);
      for (long long j = i * i; j <= pSz; j += (i << 1)) np[j] = 1;
    }
  }
  prime_size = prime.size();
}
template <typename T>
inline T SqrDis(T x1, T y1, T x2, T y2) {
  return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
template <typename T>
inline T Area2(T Ax, T Ay, T Bx, T By, T Cx, T Cy) {
  T ret = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);
  if (ret < 0) return ret = -ret;
  return ret;
}
const int N = 200005;
const int M = 200005;
const unsigned long long hs = 3797;
struct complx {
  long double real, img;
  inline complx() { real = img = 0.0; }
  inline complx(long double x) { real = x, img = 0.0; }
  inline complx(long double x, long double y) { real = x, img = y; }
  inline void operator+=(complx &other) {
    real += other.real, img += other.img;
  }
  inline void operator-=(complx &other) {
    real -= other.real, img -= other.img;
  }
  inline complx operator+(complx &other) {
    return complx(real + other.real, img + other.img);
  }
  inline complx operator-(complx &other) {
    return complx(real - other.real, img - other.img);
  }
  inline complx operator*(complx &other) {
    return complx((real * other.real) - (img * other.img),
                  (real * other.img) + (img * other.real));
  }
};
;
void FFT(vector<complx> &ar, int n, int inv) {
  int i, j, l, len, len2;
  const long double p = 4.0 * inv * acos(0.0);
  for (i = 1, j = 0; i < n; i++) {
    for (l = n >> 1; j >= l; l >>= 1) j -= l;
    j += l;
    if (i < j) swap(ar[i], ar[j]);
  }
  for (len = 2; len <= n; len <<= 1) {
    long double ang = 2 * acos(-1.0) / len * inv;
    complx wlen(cos(ang), sin(ang));
    for (i = 0; i < n; i += len) {
      complx w(1);
      for (j = 0; j < len / 2; j++) {
        complx u = ar[i + j];
        complx v = ar[i + j + len / 2] * w;
        ar[i + j] = u + v;
        ar[i + j + len / 2] = u - v;
        w = w * wlen;
      }
    }
  }
  if (inv == -1) {
    long double tmp = 1.0 / n;
    for (i = 0; i < n; i++) ar[i].real *= tmp;
  }
}
vector<complx> Mul(const vector<complx> &x, const vector<complx> &y) {
  int n = 1;
  while (n <= x.size() + y.size()) n = n * 2;
  vector<complx> A(n), B(n);
  for (int i = (0); i < (x.size()); ++i) A[i] = x[i];
  for (int i = (0); i < (y.size()); ++i) B[i] = y[i];
  FFT(A, n, 1);
  FFT(B, n, 1);
  for (int i = (0); i < (n); ++i) A[i] = A[i] * B[i];
  FFT(A, n, -1);
  return A;
}
int in[N];
long long res[N];
string num;
vector<long long> numBs;
long long maxPower3, base;
vector<long long> bruteForceMul(vector<long long> &A, vector<long long> &B,
                                long long bs = 10) {
  vector<long long> a = A, b = B;
  if (a.size() > b.size()) swap(a, b);
  vector<long long> r;
  long long carry = 0;
  long long m = a[0];
  for (int i = b.size() - 1, j = 0; i >= 0; i--) {
    long long cur = (carry + b[i] * m);
    r.push_back(cur % bs);
    carry = cur / bs;
  }
  if (carry) r.push_back(carry);
  reverse(r.begin(), r.end());
  return r;
}
vector<long long> bigNumMul(vector<long long> &a, vector<long long> &b,
                            long long bs = 10) {
  if (min(b.size(), a.size()) == 1) return bruteForceMul(a, b, bs);
  string r;
  int na = a.size();
  int nb = b.size();
  vector<complx> A(na), B(nb);
  for (int i = 0; i < na; i++) A[i] = complx(a[na - i - 1]);
  for (int i = 0; i < nb; i++) B[i] = complx(b[nb - i - 1]);
  int n = na + nb - 1;
  vector<complx> R = Mul(A, B);
  vector<long long> rs(n + 1, 0);
  for (int i = 0; i < n; i++) rs[i] = round(R[i].real);
  for (int i = 0; i < n; i++) {
    rs[i + 1] += rs[i] / bs;
    rs[i] %= bs;
  }
  while (n > 0 && rs[n] == 0) n--;
  n++;
  rs.resize(n);
  reverse(rs.begin(), rs.end());
  return rs;
}
char bigNumCompare(vector<long long> &a, vector<long long> &b) {
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < b[i]) return '<';
      if (a[i] > b[i]) return '>';
    }
    return '=';
  }
  return (a.size() < b.size()) ? '<' : '>';
}
vector<long long> bigPow(vector<long long> R, vector<long long> a, int b) {
  while (b) {
    if (b & 1) R = bigNumMul(R, a, base);
    a = bigNumMul(a, a, base);
    b = b / 2;
  }
  return R;
}
int ans_me() {
  int L = numBs.size();
  int P = (num.size() - 1) * log(10) / log(3);
  P = max(0, P - 1);
  int sum = 3 * P;
  int ret = 0x3f3f3f3f;
  vector<long long> temp;
  vector<long long> b = vector<long long>{3};
  vector<long long> b2 = vector<long long>{2};
  vector<long long> b4 = vector<long long>{4};
  vector<long long> threePowP = bigPow(vector<long long>{1}, b, P);
  while (bigNumCompare(threePowP, numBs) == '<') {
    if (bigNumCompare(temp = bigNumMul(threePowP, b2, base), numBs) != '<')
      ret = min(ret, sum + 2);
    if (bigNumCompare(temp = bigNumMul(threePowP, b4, base), numBs) != '<')
      ret = min(ret, sum + 4);
    threePowP = bigNumMul(threePowP, b, base);
    sum += 3;
  }
  ret = min(ret, sum);
  return ret;
}
vector<long long> convertBase(string nc, long long bs) {
  long long pw = 0, sv = bs;
  vector<long long> ret;
  while (sv % 10 == 0) pw++, sv /= 10;
  long long r = nc.size() % pw;
  r = (pw - r) % pw;
  while (r--) nc = '0' + nc;
  for (int i = 0; i < nc.size() / pw; i++) {
    int c = 0;
    for (int j = 0; j < pw; j++) c = c * 10 + nc[i * pw + j] - '0';
    ret.push_back(c);
  }
  return ret;
}
int main() {
  base = 1000;
  maxPower3 = 1500000 * log(10) / log(3);
  maxPower3++;
  cerr << maxPower3 << "\n";
  cin >> num;
  numBs = convertBase(num, base);
  int res = ans_me();
  res = max(res, 1);
  cout << res << "\n";
  return 0;
}
