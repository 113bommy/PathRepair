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
  template <typename T>
  inline MI &operator>(T &);
};
template <typename T>
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
template <typename T>
inline MI &MI::operator>(T &t) {
  Q<T>()(*this, t);
  return *this;
}
template <typename T>
std::ostream &operator<(std::ostream &out, const T &t) {
  return out << t;
}
using std::cout;
MI cin;
const int nmax = 55;
const int pmax = 7850;
const int mod = 1000000007;
const int MX[] = {-1, 0, 1, 0};
const int MY[] = {0, -1, 0, 1};
int L, T, B, p[4];
int ind[nmax * 2][nmax * 2], col[pmax];
inline int pro(int x) { return x >= mod ? x - mod : x; }
inline int per(int x) { return x < 0 ? x + mod : x; }
inline long long ksm(long long x, int p = mod - 2) {
  long long ret = 1;
  for (; p; p >>= 1, (x *= x) %= mod)
    if (p & 1) (ret *= x) %= mod;
  return ret;
}
inline int &get(int x, int y) {
  static int v[pmax][nmax * 4];
  return v[x][y - x + B];
}
constexpr int &index(int x, int y) { return ind[x + nmax][y + nmax]; }
inline void elimination() {
  for (int i = 0; i < T; ++i) {
    const int rl(std::min(T, i + B)), cl(std::min(T, i + B * 2));
    if (!get(i, i)) {
      for (int j = i + 1; j < rl; ++j)
        if (get(j, i)) {
          for (int k = i; k < cl; ++k) std::swap(get(i, k), get(j, k));
          std::swap(col[i], col[j]);
          break;
        }
      assert(get(i, i));
    }
    const int inv(ksm(get(i, i)));
    for (int j = i + 1; j < rl; ++j) {
      const int scale((long long)get(j, i) * inv % mod);
      for (int k = i; k < cl; ++k)
        get(j, k) = per(get(j, k) - (long long)scale * get(i, k) % mod);
      col[j] = per(col[j] - (long long)scale * col[i] % mod);
    }
  }
  for (int i = T - 1; ~i; --i) {
    const int rl(std::min(T, i + B * 2));
    for (int j = i + 1; j < rl; ++j)
      col[i] = per(col[i] - (long long)get(i, j) * col[j] % mod);
    col[i] = (long long)col[i] * ksm(get(i, i)) % mod;
  }
}
int main() {
  cin > L > p[0] > p[1] > p[2] > p[3];
  B = L * 2 + 1;
  const int sum(ksm(pro(pro(p[0] + p[1]) + pro(p[2] + p[3]))));
  p[0] = (long long)p[0] * sum % mod;
  p[1] = (long long)p[1] * sum % mod;
  p[2] = (long long)p[2] * sum % mod;
  p[3] = (long long)p[3] * sum % mod;
  const int S(L * L);
  for (int x = -L; x <= L; ++x)
    for (int y = -L; y <= L; ++y)
      if (x * x + y * y <= S) index(x, y) = T++;
  for (int x = -L, tot = 0; x <= L; ++x)
    for (int y = -L; y <= L; ++y) {
      if (x * x + y * y > S) continue;
      get(tot, tot) = 1;
      for (int d = 0; d < 4; ++d) {
        const int nx(x + MX[d]), ny(y + MY[d]);
        if (nx * nx + ny * ny > S) continue;
        get(tot, index(nx, ny)) = per(-p[d]);
      }
      ++tot;
    }
  for (int i = 0; i < T; ++i) col[i] = 1;
  elimination();
  cout < col[index(0, 0)] < ('\n');
}
