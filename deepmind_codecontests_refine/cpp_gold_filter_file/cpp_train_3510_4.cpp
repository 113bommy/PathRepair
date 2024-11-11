#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
int rint();
char rch();
long long rlong();
template <class T>
T extgcd(T a, T b, T& x, T& y) {
  for (T u = y = 1, v = x = 0; a;) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}
template <class T>
T mod_inv(T a, T m) {
  T x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long mod_pow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long p = a % mod;
  while (n) {
    if (n & 1) ret = ret * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return ret;
}
template <long long mod, long long primitive_root>
class NTT {
 public:
  long long get_mod() const { return mod; }
  void _ntt(vector<long long>& a, long long sign) {
    const long long n = ((long long)(a).size());
    const long long g = primitive_root;
    long long h = (long long)mod_pow(g, (mod - 1) / n, mod);
    if (sign == -1) h = (long long)mod_inv(h, mod);
    long long i = 0;
    for (long long j = 1; j < n - 1; ++j) {
      for (long long k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (j < i) swap(a[i], a[j]);
    }
    for (long long m = 1; m < n; m *= 2) {
      const long long m2 = 2 * m;
      const long long base = mod_pow(h, n / m2, mod);
      long long w = 1;
      for (long long x = 0; x < (m); x++) {
        for (long long s = x; s < n; s += m2) {
          long long u = a[s];
          long long d = a[s + m] * w % mod;
          long long as = u + d;
          if (as >= mod) as -= mod;
          a[s] = as;
          long long sm = u - d;
          if (sm < 0) sm += mod;
          a[s + m] = sm;
        }
        w = w * base % mod;
      }
    }
    for (auto& x : a)
      if (x < 0) x += mod;
  }
  void ntt(vector<long long>& input) { _ntt(input, 1); }
  void intt(vector<long long>& input) {
    _ntt(input, -1);
    const long long n_inv = mod_inv(((long long)(input).size()), mod);
    for (auto& x : input) x = x * n_inv % mod;
  }
  vector<long long> convolution(const vector<long long>& a,
                                const vector<long long>& b) {
    long long ntt_size = 1;
    while (ntt_size < ((long long)(a).size()) + ((long long)(b).size()))
      ntt_size *= 2;
    vector<long long> _a = a, _b = b;
    _a.resize(ntt_size);
    _b.resize(ntt_size);
    ntt(_a);
    ntt(_b);
    for (long long i = 0; i < (ntt_size); i++) {
      (_a[i] *= _b[i]) %= mod;
    }
    intt(_a);
    return _a;
  }
  vector<long long> powup(const vector<long long>& a, long long exponent) {
    long long ntt_size = 1;
    while (ntt_size < (((long long)(a).size()) * exponent)) ntt_size *= 2;
    vector<long long> _a = a;
    _a.resize(ntt_size);
    ntt(_a);
    for (long long i = 0; i < (ntt_size); i++) {
      _a[i] = mod_pow(_a[i], exponent, mod);
    }
    intt(_a);
    return _a;
  }
};
vector<long long> mul(vector<long long> a, vector<long long> b, long long mod) {
  for (auto& x : a) x %= mod;
  for (auto& x : b) x %= mod;
  NTT<167772161, 3> ntt1;
  NTT<469762049, 3> ntt2;
  NTT<1224736769, 3> ntt3;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);
  const long long m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
  const long long m1_inv_m2 = mod_inv<long long>(m1, m2);
  const long long m12_inv_m3 = mod_inv<long long>(m1 * m2, m3);
  const long long m12_mod = m1 * m2 % mod;
  vector<long long> ret(((long long)(x).size()));
  for (long long i = 0; i < (((long long)(x).size())); i++) {
    long long v1 = (y[i] - x[i]) * m1_inv_m2 % m2;
    if (v1 < 0) v1 += m2;
    long long v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
    if (v2 < 0) v2 += m3;
    long long constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
    if (constants3 < 0) constants3 += mod;
    ret[i] = constants3;
  }
  return ret;
}
const int mn = 2e5 + 2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long inpsz = rint(), t = rint();
  vector<long long> f;
  {
    int sum = 0;
    for (int i = 0; i < inpsz; i++) {
      int x = rint();
      if (x < t) {
        f.push_back(sum + 1);
        sum = 0;
      } else
        ++sum;
    }
    f.push_back(sum + 1);
  }
  long long fsz = f.size();
  vector<long long> g = f;
  reverse(g.begin(), g.end());
  vector<long long> res = mul(f, g, ((inpsz * (inpsz + 1)) / 2) + 1);
  long long zero = 0;
  for (auto& w : f) zero += (w * (w - 1)) / 2;
  printf("%lld ", zero);
  for (int x = 1; x <= inpsz; x++) {
    long long e = fsz - 1 + x;
    if (e < res.size())
      printf("%lld ", res[e]);
    else
      printf("0 ");
  }
  printf("\n");
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
