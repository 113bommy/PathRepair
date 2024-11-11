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
const int $n = 2005;
int n, m, tp;
struct bitset {
  unsigned long long v[32];
  static inline unsigned long long bit(int i) { return 1ULL << (i & 63); }
  inline bool test(int i) const { return v[i >> 6] & bit(i); }
  inline void set(int i) { v[i >> 6] |= bit(i); }
  inline void operator^=(const bitset &t) {
    for (auto __r = (32 - 1), i = ((decltype(32))0); i <= __r; ++i)
      v[i] ^= t.v[i];
  }
} e[$n];
struct mat {
  bool v[2][2];
} v[$n];
inline mat operator*(const mat &A, const mat &B) {
  mat r;
  r.v[0][0] = (A.v[0][0] & B.v[0][0]) ^ (A.v[0][1] & B.v[1][0]);
  r.v[0][1] = (A.v[0][0] & B.v[0][1]) ^ (A.v[0][1] & B.v[1][1]);
  r.v[1][0] = (A.v[1][0] & B.v[0][0]) ^ (A.v[1][1] & B.v[1][0]);
  r.v[1][1] = (A.v[1][0] & B.v[0][1]) ^ (A.v[1][1] & B.v[1][1]);
  return r;
}
inline void work(const mat &t) {
  for (auto __r = ((cin.read<int>())), _ = ((decltype((cin.read<int>())))1);
       _ <= __r; ++_)
    if (const auto x = (cin.read<int>()); 1) v[x] = v[x] * t;
}
int main() {
  cin > n > m;
  const auto T = n * 2;
  for (auto __r = (n), i = ((decltype(n))1); i <= __r; ++i)
    v[i].v[0][0] = v[i].v[1][1] = 1;
  for (auto __r = (m), _ = ((decltype(m))1); _ <= __r; ++_) {
    switch (cin.read<char>()) {
      case 'm': {
        for (auto __r = ((cin.read<int>())),
                  _ = ((decltype((cin.read<int>())))1);
             _ <= __r; ++_)
          if (const auto x = (cin.read<int>()); 1) {
            const auto b = (x - 1) << 1;
            if (v[x].v[0][0]) e[tp].set(b);
            if (v[x].v[1][0]) e[tp].set(b | 1);
            if (v[x].v[0][1]) e[tp + 1].set(b);
            if (v[x].v[1][1]) e[tp + 1].set(b | 1);
          }
        bool A, B;
        switch (cin.read<char>()) {
          case 'W':
            A = B = 0;
            break;
          case 'R':
            A = 0;
            B = 1;
            break;
          case 'Y':
            A = 1;
            B = 0;
            break;
          case 'B':
            A = B = 1;
            break;
          default:
            assert(0);
        }
        if (A) e[tp].set(T);
        if (B) e[tp + 1].set(T);
        tp += 2;
        break;
      }
      case 'R': {
        if (cin.get() == 'Y')
          work({0, 1, 1, 0});
        else
          work({1, 0, 1, 1});
        break;
      }
      case 'Y': {
        work({1, 1, 0, 1});
        break;
      }
    }
  }
  for (auto __r = (T - 1), i = ((decltype(T))0); i <= __r; ++i) {
    if (!e[i].test(i)) {
      for (auto __r = (std::max(T, tp) - 1), j = ((decltype(std::max(T, tp)))0);
           j <= __r; ++j)
        if ((j > i || !e[j].test(j)) && e[j].test(i)) {
          std::swap(e[i], e[j]);
          break;
        }
      if (!e[i].test(i)) continue;
    }
    for (auto __r = (std::max(T, tp) - 1), j = ((decltype(std::max(T, tp)))0);
         j <= __r; ++j)
      if (i != j && e[j].test(i)) e[j] ^= e[i];
  }
  for (auto __r = (T - 1), i = ((decltype(T))0); i <= __r; ++i)
    if (!e[i].test(i) && e[i].test(T)) return cout < "NO\n", 0;
  for (auto __r = (tp - 1), i = (T + 1); i <= __r; ++i)
    if (e[i].test(T)) cout < "NO\n", 0;
  cout < "YES\n";
  for (auto __r = (n - 1), i = ((decltype(n))0); i <= __r; ++i)
    cout < ".RYB"[(e[i << 1].test(T) << 1) | e[(i << 1) | 1].test(T)];
  cout < ('\n');
}
