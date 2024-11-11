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
const int $n = 20;
const int $s = 1 << $n;
template <typename T>
inline bool gmin(T &a, const T &b) {
  return b < a && (a = b, true);
}
template <typename T>
inline bool gmax(T &a, const T &b) {
  return a < b && (a = b, true);
}
int n, L, lim;
long long v[$n], lf[1 << 10], rg[1 << 10], all[$n], f[$s];
void find(int l, int r, long long *t) {
  int tp = 1;
  t[0] = 0;
  for (int __r = (r), i = (l); i <= __r; ++i) {
    const auto x = all[i];
    for (int __r = ((tp)-1), j = (0); j <= __r; ++j) t[tp + j] = t[j] + x;
    for (int __r = ((tp)-1), j = (0); j <= __r; ++j) t[j] -= x;
    std::inplace_merge(t, t + tp, t + (tp << 1));
    tp <<= 1;
  }
}
inline bool ok(int s) {
  assert(s);
  int tp = 0;
  long long sum = 0;
  for (int __r = ((n)-1), i = (0); i <= __r; ++i)
    if ((s >> i) & 1) sum += all[tp++] = v[i];
  if (!((sum ^ tp) & 1)) return 0;
  lim = tp / 2;
  find(0, lim, lf);
  find(lim + 1, tp - 1, rg);
  const auto l1 = 1 << lim, l2 = 1 << (tp - lim);
  int l = l1 - 1, r = l1 - 1, rem = 1 + (std::abs(sum) < tp) * 2;
  for (int __r = ((l2)-1), i = (0); i <= __r; ++i) {
    while (l >= 0 && lf[l] + rg[i] > -tp) --l;
    while (r >= 0 && lf[r] + rg[i] >= tp) --r;
    if ((rem -= std::max(r - l, 0)) <= 0) return 1;
  }
  return 0;
}
int main() {
  for (int __r = ((cin.read<int>())), _ = (1); _ <= __r; ++_)
    n += !!(v[n] = cin.read<long long>());
  L = 1 << n;
  for (int __r = ((L)-1), s = (1); s <= __r; ++s)
    if (!f[s] && ok(s)) {
      int r = s ^ (L - 1);
      f[s] = 1;
      for (int t = r; t; t = (t - 1) & r) gmax(f[s | t], f[t] + 1);
    }
  cout < (n - f[L - 1]) < ('\n');
}
