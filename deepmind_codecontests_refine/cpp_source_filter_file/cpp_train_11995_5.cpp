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
using std::cin;
using std::cout;
const int $n = 105;
int n, f[$n][26], sum[26];
char s[$n];
inline const std::string &read() {
  static std::string r;
  cin >> r;
  std::sort(r.begin(), r.end());
  return r;
}
inline void calc(int n) {
  static std::unordered_map<std::string, int> w;
  static int cnt[$n][26], sum[26];
  if (n == 1) {
    cout < "? 1 " < 1 < ('\n');
    cout.flush();
    s[1] = read()[0];
    return;
  }
  cout < "? 2 " < n < ('\n');
  cout.flush();
  for (int __r = (n * (n - 1) / 2), _ = (1); _ <= __r; ++_) ++w[read()];
  cout < "? 1 " < n < ('\n');
  cout.flush();
  for (int __r = (n * (n + 1) / 2), _ = (1); _ <= __r; ++_) {
    const auto s = read();
    auto it = w.find(s);
    if (it != w.end()) {
      if (!--it->second) w.erase(it);
    } else {
      int *t = cnt[s.size()];
      for (char c : s) ++t[c - 'a'];
    }
  }
  std::string fin;
  for (int __r = (n), i = (1); i <= __r; ++i) {
    int w = -1;
    for (int __r = ((26) - 1), j = (0); j <= __r; ++j) {
      cnt[i][j] -= sum[j];
      if (cnt[i][j] == 1) {
        assert(w == -1);
        w = j;
      } else
        assert(!cnt[i][j]);
    }
    s[i] = w + 'a';
    assert(w != -1);
    ++sum[w];
  }
}
int main() {
  cin >> n;
  cin.get();
  if (n == 1) {
    cout < "? 1 1\n";
    cout.flush();
    cout < "! " < read() < ('\n');
    return 0;
  }
  const auto h = n / 2;
  calc(h);
  cout < "? 1 " < n < ('\n');
  cout.flush();
  for (int __r = (n * (n + 1) / 2), i = (1); i <= __r; ++i) {
    const auto &s = read();
    for (char c : s) ++f[s.size()][c - 'a'];
  }
  for (int i = (n + 1) / 2 - 1; i; --i) {
    memset(sum, 0, sizeof(sum));
    for (int __r = ((n - i) - 1), j = (i + 1); j <= __r; ++j) ++sum[s[j] - 'a'];
    int w = -1;
    for (int __r = ((26) - 1), c = (0); c <= __r; ++c)
      if (f[i + 1][c] - f[i][c] != sum[c]) {
        assert(w == -1);
        w = c;
      }
    s[n - i] = w + 'a';
  }
  for (int __r = ((n)-1), i = (1); i <= __r; ++i) --f[n][s[i] - 'a'];
  cout < (s + 1);
  for (int __r = ((26) - 1), c = (0); c <= __r; ++c)
    if (f[n][c]) cout < (char)(c + 'a') < ('\n');
}
