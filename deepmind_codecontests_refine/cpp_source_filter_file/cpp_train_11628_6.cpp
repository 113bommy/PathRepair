#include <bits/stdc++.h>
struct MI {
 private:
  char bb[4096];
  FILE *f;
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
  template <class T>
  inline T read() {
    T r;
    *this > r;
    return r;
  }
  template <class T>
  inline MI &operator>(T &);
};
template <class T>
struct Q {
  const static bool U = T(-1) >= T(0);
  inline void operator()(MI &t, T &r) const {
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
template <class T>
inline MI &MI::operator>(T &t) {
  Q<T>()(*this, t);
  return *this;
}
template <class T>
inline std::ostream &operator<(std::ostream &out, const T &t) {
  return out << t;
}
using std::cout;
MI cin;
const int mod = 998244353;
const int inv2 = 499122177;
inline void upd(int &x) { x += (x >> 31) & mod; }
inline int pro(int x) { return x + ((x >> 31) & mod); }
inline long long ksm(long long x, int p = mod - 2) {
  long long ret = 1;
  while (p) {
    if (p & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    p >>= 1;
  }
  return ret;
}
template <bool rev>
inline void ntt(int *v, int len) {
  static const int rt[] = {
      1,         998244352, 911660635, 372528824, 929031873, 452798380,
      922799308, 781712469, 476477967, 166035806, 258648936, 584193783,
      63912897,  350007156, 666702199, 968855178, 629671588, 24514907,
      996173970, 363395222, 565042129, 733596141, 267099868, 15311432,
      3748461,   79851780,  4782969,   2187,      27,        3};
  static const int irt[] = {
      1,         998244352, 86583718,  509520358, 337190230, 87557064,
      609441965, 135236158, 304459705, 685443576, 381598368, 335559352,
      129292727, 358024708, 814576206, 708402881, 283043518, 3707709,
      121392023, 704923114, 950391366, 428961804, 382752275, 469870224,
      554917253, 783124715, 577281167, 733050037, 480636170, 332748118};
  assert(!(len & (len - 1)));
  for (int i = 0, j = 0; i < len; ++i) {
    if (i > j) std::swap(v[i], v[j]);
    for (int k = len >> 1; (j ^= k) < k; k >>= 1)
      ;
  }
  for (int i = 1, q = 2, c = 1; i < len; i = q, q <<= 1, ++c) {
    const int delta = (rev ? irt : rt)[c];
    for (int j = 0; j < len; j += i << 1)
      for (int k = 0, w = 1; k < i; ++k, w = (long long)w * delta % mod) {
        const int x = v[j | k], y = (long long)v[i | j | k] * w % mod;
        v[j | k] = pro(x + y - mod);
        v[i | j | k] = pro(x - y);
      }
  }
  if (!rev) return;
  for (int i = 0, r = ksm(len); i < len; ++i) v[i] = (long long)v[i] * r % mod;
}
struct poly : public std::vector<int> {
  static inline int round_up(int x) {
    return (x & (x - 1)) ? (1 << (32 - __builtin_clz(x))) : x;
  }
  poly() {}
  poly(const std::initializer_list<int> &list) : std::vector<int>(list) {}
  inline poly &from(const poly &a, int n) {
    resize(n);
    const int len = std::min(n, (int)a.size());
    std::copy(a.begin(), a.begin() + len, begin());
    std::fill(begin() + len, end(), 0);
    return (*this);
  }
  template <bool rev>
  inline poly &ntt(int len) {
    resize(round_up(len), 0);
    ::ntt<rev>(data(), size());
    return (*this);
  }
  inline poly &operator*=(const poly &a) {
    static poly tmp;
    if (empty() || a.empty()) return clear(), (*this);
    const int l = size() + a.size() - 1, len = round_up(l);
    ntt<0>(len);
    (tmp = a).ntt<0>(len);
    for (int i = 0; i < len; ++i)
      (*this)[i] = (long long)(*this)[i] * tmp[i] % mod;
    return ntt<1>(len), resize(l), (*this);
  }
  inline poly &operator*=(int t) {
    for (int &d : (*this)) d = (long long)d * t % mod;
    return *this;
  }
  inline poly operator*(const poly &t) const { return poly((*this)) *= t; }
};
template <>
struct Q<poly> {};
using std::vector;
const int nmax = 100005;
int n, K;
vector<int> outs[nmax];
vector<int> all;
int siz[nmax], fac[nmax], ifac[nmax];
int f[nmax], g[nmax], h[nmax];
inline poly simple_divide(const poly &a, int b) {
  const int inv = ksm(b);
  int nxt = a.back();
  poly ret;
  ret.resize(a.size() - 1);
  for (int i = a.size() - 2; ~i; --i) {
    ret[i] = (long long)inv * nxt % mod;
    nxt = pro(a[i] - ret[i]);
  }
  return ret;
}
inline void simple_mul(poly &a, int b) {
  a.push_back(0);
  for (int i = a.size() - 1; i; --i)
    a[i] = pro(a[i] + (long long)a[i - 1] * b % mod - mod);
}
inline poly divide(int first, int last) {
  if (last - first == 1) return {1, siz[all[first]]};
  const int mid = (first + last) >> 1;
  return divide(first, mid) * divide(mid, last);
}
inline int calc(const poly &t) {
  int ret = 0;
  for (int i = std::min(K, (int)t.size() - 1); ~i; --i)
    upd(ret += (long long)t[i] * ifac[K - i] % mod - mod);
  return (long long)ret * fac[K] % mod;
}
void dfs(int x, int fa) {
  siz[x] = 1;
  for (int v : outs[x]) {
    if (v == fa) continue;
    dfs(v, x);
    siz[x] += siz[v];
    upd(g[x] += g[v] - mod);
  }
  all.clear();
  for (int v : outs[x])
    if (v != fa) all.push_back(v);
  if (all.empty()) {
    f[x] = 1;
    upd(g[x] += 1 - mod);
    return;
  }
  poly p = divide(0, all.size());
  f[x] = calc(p);
  upd(g[x] += f[x] - mod);
  std::sort(all.begin(), all.end(),
            [](int x, int y) { return siz[x] < siz[y]; });
  simple_mul(p, n - siz[x]);
  for (int i = 0, lst = 0; i < (int)all.size(); ++i) {
    const int x = all[i];
    if (siz[x] == siz[lst]) {
      h[x] = h[lst];
      continue;
    }
    lst = x;
    h[x] = calc(simple_divide(p, siz[x]));
  }
}
int ans;
void load(int x, int fa) {
  for (int v : outs[x]) {
    if (v == fa) continue;
    upd(ans += (long long)pro(h[v] - f[x]) * g[v] % mod - mod);
    load(v, x);
  }
}
int main() {
  cin > n > K;
  if (K == 1) {
    cout < ((long long)n * (n - 1) / 2 % mod) < ('\n');
    return 0;
  }
  const int lim = std::max(n, K);
  for (int i = fac[0] = ifac[0] = 1; i <= lim; ++i)
    fac[i] = (long long)fac[i - 1] * i % mod;
  ifac[n] = ksm(fac[lim]);
  for (int i = lim - 1; i; --i)
    ifac[i] = (long long)ifac[i + 1] * (i + 1) % mod;
  for (int i = 1; i < n; ++i) {
    const int x = (cin.read<int>()), y = (cin.read<int>());
    outs[x].push_back(y);
    outs[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) upd(ans += f[i] - mod);
  ans = (long long)ans * ans % mod;
  for (int i = 1; i <= n; ++i) upd(ans -= (long long)f[i] * f[i] % mod);
  ans = (long long)ans * inv2 % mod;
  load(1, 0);
  cout < ans < ('\n');
}
