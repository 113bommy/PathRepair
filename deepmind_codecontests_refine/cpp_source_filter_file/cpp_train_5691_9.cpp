#include <bits/stdc++.h>
struct MI {
 private:
  char bb[4096];
  FILE* f;
  char *bs, *be;
  char e;
  bool o, l;

 public:
  MI() : f(stdin) {}
  inline char get() {
    if (o) {
      o = 0;
      return e;
    }
    if (bs == be) be = (bs = bb) + fread(bb, 1, sizeof(bb), f);
    if (bs == be) {
      l = 1;
      return -1;
    };
    return *bs++;
  }
  inline void unget(char c) {
    o = 1;
    e = c;
  }
  template <typename T>
  inline T read() {
    T r;
    *this > r;
    return r;
  }
  template <typename T>
  inline MI& operator>(T&);
};
template <typename T>
struct Q {
  const static bool U = T(-1) >= T(0);
  inline void operator()(MI& t, T& r) const {
    r = 0;
    char c;
    bool y = 0;
    if (U)
      for (;;) {
        c = t.get();
        if (c == -1) goto E;
        if (isdigit(c)) break;
      }
    else
      for (;;) {
        c = t.get();
        if (c == -1) goto E;
        if (c == '-') {
          c = t.get();
          if (isdigit(c)) {
            y = 1;
            break;
          };
        } else if (isdigit(c))
          break;
        ;
      };
    for (;;) {
      if (c == -1) goto E;
      if (isdigit(c))
        r = r * 10 + (c ^ 48);
      else
        break;
      c = t.get();
    }
    t.unget(c);
  E:;
    if (y) r = -r;
  }
};
template <>
struct Q<char> {};
template <typename T>
inline MI& MI::operator>(T& t) {
  Q<T>()(*this, t);
  return *this;
}
template <typename T>
std::ostream& operator<(std::ostream& out, const T& t) {
  return out << t;
}
using std::cout;
MI cin;
const int nmax = 200005;
const int mod = 100000007;
int n, K, fac[nmax], ifac[nmax];
inline long long ksm(long long x, int p = mod - 2) {
  long long ret = 1;
  while (p) {
    if (p & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    p >>= 1;
  }
  return ret;
}
inline int pro(int x) { return x >= mod ? x - mod : x; }
inline int per(int x) { return x < 0 ? x + mod : x; }
inline int n1(int v, int p) { return (p & 1) ? per(-v) : v; }
inline void init(int n) {
  for (int i = fac[0] = ifac[0] = 1; i <= n; ++i)
    fac[i] = (long long)fac[i - 1] * i % mod;
  ifac[n] = ksm(fac[n]);
  for (int i = n; i > 1; --i) ifac[i - 1] = (long long)ifac[i] * i % mod;
}
inline int calc(int n, int m) {
  int ret = 0;
  for (int i = 0; i <= m; ++i)
    ret = pro(ret + (long long)n1((long long)ifac[i] * ifac[m - i] % mod *
                                      ksm(m - i, n) % mod,
                                  i));
  return ret;
}
int main() {
  cin > n > K;
  init(n);
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum = pro(sum + (cin.read<int>()));
  cout < ((long long)sum *
          pro(calc(n, K) + (long long)(n - 1) * calc(n - 1, K) % mod) % mod) <
      ('\n');
}
