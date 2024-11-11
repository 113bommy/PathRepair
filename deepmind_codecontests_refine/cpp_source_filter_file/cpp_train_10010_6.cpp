#include <bits/stdc++.h>
using namespace std;
using db = double;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
template <class T>
void cmax(T& x, const T& y) {
  if (x < y) x = y;
}
template <class T>
void cmin(T& x, const T& y) {
  if (x > y) x = y;
}
template <class T>
void sort(vector<T>& v) {
  sort(v.begin(), v.end());
}
template <class T>
void reverse(vector<T>& v) {
  reverse(v.begin(), v.end());
}
template <class T>
void unique(vector<T>& v) {
  sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
}
void reverse(string& s) { reverse(s.begin(), s.end()); }
const int io_size = 1 << 23 | 233;
const int io_limit = 1 << 22;
struct io_in {
  char ch;
  char getchar() {
    static char buf[io_size], *p1 = buf, *p2 = buf;
    return (p1 == p2) &&
                   (p2 = (p1 = buf) + fread(buf, 1, io_size, stdin), p1 == p2)
               ? EOF
               : *p1++;
  }
  io_in& operator>>(char& c) {
    for (c = getchar(); isspace(c); c = getchar())
      ;
    return *this;
  }
  io_in& operator>>(string& s) {
    for (s.clear(); isspace(ch = getchar());)
      ;
    if (!~ch) return *this;
    for (s = ch; !isspace(ch = getchar()) && ~ch; s += ch)
      ;
    return *this;
  }
  io_in& operator>>(char* str) {
    char* cur = str;
    while (*cur) *cur++ = 0;
    for (cur = str; isspace(ch = getchar());)
      ;
    if (!~ch) return *this;
    for (*cur = ch; !isspace(ch = getchar()) && ~ch; *++cur = ch)
      ;
    return *++cur = 0, *this;
  }
  template <class T>
  void read(T& x) {
    bool f = 0;
    while ((ch = getchar()) < 48 && ~ch) f ^= (ch == 45);
    x = ~ch ? (ch ^ 48) : 0;
    while ((ch = getchar()) > 47) x = x * 10 + (ch ^ 48);
    x = f ? -x : x;
  }
  io_in& operator>>(int& x) { return read(x), *this; }
  io_in& operator>>(ll& x) { return read(x), *this; }
  io_in& operator>>(uint& x) { return read(x), *this; }
  io_in& operator>>(ull& x) { return read(x), *this; }
  io_in& operator>>(db& x) {
    read(x);
    bool f = x < 0;
    x = f ? -x : x;
    if (ch ^ '.') return *this;
    double d = 0.1;
    while ((ch = getchar()) > 47) x += d * (ch ^ 48), d *= .1;
    return x = f ? -x : x, *this;
  }
} in;
struct io_out {
  char buf[io_size], *s = buf;
  int pw[233], st[233];
  io_out() {
    set(7);
    for (register int i = (pw[0] = 1); i <= (9); ++i) pw[i] = pw[i - 1] * 10;
  }
  ~io_out() { flush(); }
  void io_chk() {
    if (s - buf > io_limit) flush();
  }
  void flush() { fwrite(buf, 1, s - buf, stdout), fflush(stdout), s = buf; }
  io_out& operator<<(char c) { return *s++ = c, *this; }
  io_out& operator<<(string str) {
    for (char c : str) *s++ = c;
    return io_chk(), *this;
  }
  io_out& operator<<(char* str) {
    char* cur = str;
    while (*cur) *s++ = *cur++;
    return io_chk(), *this;
  }
  template <class T>
  void write(T x) {
    if (x < 0) *s++ = '-', x = -x;
    do {
      st[++st[0]] = x % 10, x /= 10;
    } while (x);
    while (st[0]) *s++ = st[st[0]--] ^ 48;
  }
  io_out& operator<<(int x) { return write(x), io_chk(), *this; }
  io_out& operator<<(ll x) { return write(x), io_chk(), *this; }
  io_out& operator<<(uint x) { return write(x), io_chk(), *this; }
  io_out& operator<<(ull x) { return write(x), io_chk(), *this; }
  int len, lft, rig;
  void set(int _length) { len = _length; }
  io_out& operator<<(db x) {
    bool f = x < 0;
    x = f ? -x : x, lft = x, rig = 1. * (x - lft) * pw[len];
    return write(f ? -lft : lft), *s++ = '.', write(rig), io_chk(), *this;
  }
} out;
template <long long sz, long long mod>
struct math_t {
  math_t() {
    fac.resize(sz + 1), ifac.resize(sz + 1);
    for (register long long i = (fac[0] = 1); i <= (sz); ++i)
      fac[i] = fac[i - 1] * i % mod;
    ifac[sz] = inv(fac[sz]);
    for (register long long i = (sz - 1); i >= (0); --i)
      ifac[i] = ifac[i + 1] * (i + 1) % mod;
  }
  vector<long long> fac, ifac;
  long long qpow(long long x, long long y) {
    long long ans = 1;
    for (; y; y >>= 1, x = x * x % mod)
      if (y & 1) ans = ans * x % mod;
    return ans;
  }
  long long inv(long long x) { return qpow(x, mod - 2); }
  long long C(long long n, long long m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  }
};
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
long long n;
const long long maxn = 1e5 + 51;
long long a[maxn];
set<long long> s;
long long ans = 0;
void solve(long long l, long long r) {
  if (l == r) return;
  long long mid = l + r >> 1;
  long long L, R, mxl, mxr;
  L = R = mid + 1;
  mxl = mxr = 0;
  s.clear();
  while (R <= r) {
    cmax(mxr, a[R]);
    while (L > l && a[L - 1] < mxr) s.insert(a[--L]);
    if (s.count(mxr - a[R])) ++ans;
    ++R;
  }
  L = R = mid;
  mxl = mxr = 0;
  s.clear();
  while (L >= l) {
    cmax(mxl, a[L]);
    while (R < r && a[R + 1] < mxl) s.insert(a[++R]);
    if (s.count(mxl - a[L])) ++ans;
    --L;
  }
  solve(l, mid), solve(mid + 1, r);
}
signed main() {
  in >> n;
  for (register long long i = (1); i <= (n); ++i) in >> a[i];
  solve(1, n);
  out << ans << '\n';
  return 0;
}
