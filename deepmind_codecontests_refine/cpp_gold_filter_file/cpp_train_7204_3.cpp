#include <bits/stdc++.h>
struct MI {
 private:
  char bb[1 << 14];
  FILE *f;
  char *bs, *be;
  char e;
  bool o, l;

 public:
  MI() : f(stdin), bs(0), be(0) {}
  MI(FILE *f) : f(f), bs(0), be(0) {}
  inline operator bool() { return !l; }
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
struct Q<char> {
  inline void operator()(MI &t, char &r) {
    int c;
    for (;;) {
      c = t.get();
      if (c == -1) {
        r = -1;
        return;
      };
      if (!isspace(c)) {
        r = c;
        return;
      };
    }
  }
};
template <class T>
inline MI &MI::operator>(T &t) {
  Q<T>()(*this, t);
  return *this;
}
template <class T>
std::ostream &operator<(std::ostream &out, const T &t) {
  return out << t;
}
using std::cout;
MI cin;
const int $k = 9;
const int $L = 1 << $k;
int k, L, M;
struct mat {
  long long v[$L][$L];
} A;
struct point {
  int x, y;
};
std::vector<point> F;
inline mat mul(const mat &A) {
  mat r;
  memset(r.v, 0, sizeof(r.v));
  for (const auto [x, y] : F)
    for (int __r = ((L)-1), i = (0); i <= __r; ++i)
      for (int __r = ((L)-1), j = (0); j <= __r; ++j)
        r.v[(i + x) & M][(j + y) & M] ^= A.v[i][j];
  return r;
}
inline std::vector<point> sqr() {
  static bool ex[$L][$L];
  for (int __r = ((F.size()) - 1), i = (0); i <= __r; ++i) {
    F[i].x = (F[i].x << 1) & M;
    F[i].y = (F[i].y << 1) & M;
    ex[F[i].x][F[i].y] = 0;
  }
  for (auto [x, y] : F) ex[x][y] ^= 1;
  std::vector<point> r;
  for (auto [x, y] : F)
    if (ex[x][y]) {
      r.push_back({x, y});
      ex[x][y] = 0;
    }
  return r;
}
int main() {
  L = 1 << (k = (cin.read<int>()));
  M = L - 1;
  for (int __r = ((L)-1), i = (0); i <= __r; ++i)
    for (int __r = ((L)-1), j = (0); j <= __r; ++j) cin > A.v[i][j];
  F.resize((cin.read<int>()));
  for (int __r = ((F.size()) - 1), i = (0); i <= __r; ++i)
    F[i].x = (cin.read<int>()) - 1, F[i].y = (cin.read<int>()) - 1;
  for (int i = 0;;) {
    A = mul(A);
    if (++i == k) break;
    F = sqr();
  }
  int r = 0;
  for (int __r = ((L)-1), i = (0); i <= __r; ++i)
    for (int __r = ((L)-1), j = (0); j <= __r; ++j) r += !!A.v[i][j];
  cout < r < ('\n');
}
