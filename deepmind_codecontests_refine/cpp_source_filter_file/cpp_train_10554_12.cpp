#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &m, const T &v) {
  if (v > m) return m = v, true;
  return false;
}
template <typename T>
bool chmin(T &m, const T &v) {
  if (v < m) return m = v, true;
  return false;
}
template <typename T>
bool chinc(T &v1, T &v2) {
  if (v1 > v2) return swap(v1, v2), true;
  return false;
}
template <typename T>
bool chdec(T &v1, T &v2) {
  if (v1 < v2) return swap(v1, v2), true;
  return false;
}
namespace fio {
static const char eof = '\xff';
struct Cg {
  inline char operator()() {
    char c = (char)getchar();
    if (c == eof) valid = false;
    return c;
  };
  bool valid = true;
};
struct Cp {
  inline void operator()(int x) { putchar(x); }
};
struct Ce {
  inline void operator()(int x) { putc(x, stderr); }
};
inline bool IS(char x) {
  return x == ' ' || x == '\r' || x == '\n' || x == '\t';
}
template <class T>
struct Fr {
  T P;
  inline Fr &operator,(int &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(long &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(long long &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(unsigned &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(unsigned long &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(unsigned long long &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(float &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (c == '.') {
      double u = 0.1;
      for (c = P(); c >= '0' && c <= '9'; c = P(), u *= 0.1) x += u * (c - '0');
    };
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(double &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (c == '.') {
      double u = 0.1;
      for (c = P(); c >= '0' && c <= '9'; c = P(), u *= 0.1) x += u * (c - '0');
    };
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(long double &x) {
    x = 0;
    int c = P();
    while ((c < '0' || c > '9') && c != '-') c = P();
    bool h = false;
    if (c == '-') h = true, c = P();
    for (; c >= '0' && c <= '9'; c = P()) x = x * 10 + c - '0';
    if (c == '.') {
      double u = 0.1;
      for (c = P(); c >= '0' && c <= '9'; c = P(), u *= 0.1) x += u * (c - '0');
    };
    if (h) x = -x;
    return *this;
  }
  inline Fr &operator,(char &x) {
    for (x = P(); IS(x);) x = P();
    return *this;
  }
  inline Fr &operator,(char *s) {
    for (*s = P(); IS(*s) && P.valid;) *s = P();
    for (; !IS(*s) && P.valid;) *++s = P();
    *s = 0;
    return *this;
  }
  inline Fr &operator,(string &s) {
    s.clear();
    char c = P();
    for (; IS(c) && P.valid;) c = P();
    for (; !IS(c) && P.valid;) s.push_back(c), c = P();
    return *this;
  }
  inline operator bool() { return P.valid; }
};
template <class T>
struct Fw {
  T P;
  char B[32];
  inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      int p = 0;
      while (x) B[p++] = x % 10 + '0', x /= 10;
      while (p--) P(B[p]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(float g, int d) {
    if (d) {
      double t = 0.5;
      for (int i = d; i--;) t *= 0.1;
      if (g < 0) P('-'), g = -g;
      g += t;
      *this, (long long)(g);
      P('.');
      g -= floor(g);
      while (d--) {
        g *= 10;
        int i = (int)floor(g);
        P(i + '0');
        g -= i;
      }
    } else
      *this, (g > 0 ? (long long)(g + 0.5) : (long long)(g - 0.5));
    return *this;
  }
  inline Fw &operator()(double g, int d) {
    if (d) {
      double t = 0.5;
      for (int i = d; i--;) t *= 0.1;
      if (g < 0) P('-'), g = -g;
      g += t;
      *this, (long long)(g);
      P('.');
      g -= floor(g);
      while (d--) {
        g *= 10;
        int i = (int)floor(g);
        P(i + '0');
        g -= i;
      }
    } else
      *this, (g > 0 ? (long long)(g + 0.5) : (long long)(g - 0.5));
    return *this;
  }
  inline Fw &operator()(long double g, int d) {
    if (d) {
      double t = 0.5;
      for (int i = d; i--;) t *= 0.1;
      if (g < 0) P('-'), g = -g;
      g += t;
      *this, (long long)(g);
      P('.');
      g -= floor(g);
      while (d--) {
        g *= 10;
        int i = (int)floor(g);
        P(i + '0');
        g -= i;
      }
    } else
      *this, (g > 0 ? (long long)(g + 0.5) : (long long)(g - 0.5));
    return *this;
  }
  inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  typedef basic_ostream<char, char_traits<char> > &OS;
  typedef basic_istream<char, char_traits<char> > &IS;
  inline Fw &operator,(OS &(*func)(OS)) {
    if (func == static_cast<OS &(*)(OS)>(endl<char, char_traits<char> >))
      P('\n');
    return *this;
  }
  inline Fw &operator,(IS &(*func)(IS)) {
    if (func == static_cast<IS &(*)(IS)>(ws<char, char_traits<char> >)) P(' ');
    return *this;
  }
  inline Fw &operator,(const char *s) {
    for (; *s; ++s) P(*s);
    return *this;
  }
  inline Fw &operator,(const string &s) {
    (*this), s.c_str();
    return *this;
  }
  template <class C>
  inline Fw &all(const C &v, char sep = ' ', char nl = '\n') {
    auto it = v.begin();
    for (int i = 0; i < (int)v.size(); ++i, ++it) {
      if (i && sep) P(sep);
      (*this), *it;
    }
    if (nl) P(nl);
    return *this;
  }
  template <class U>
  inline Fw &print(U x) {
    (*this), x;
    P('\n');
    return *this;
  }
  template <class U, class... Us>
  inline Fw &print(U x, Us... args) {
    (*this), x;
    P(' ');
    print(args...);
    return *this;
  }
};
}  // namespace fio
fio::Fr<fio::Cg> fin;
fio::Fw<fio::Cp> fout;
fio::Fw<fio::Ce> ferr;
static const int maxn = 80005;
vector<int> g[maxn];
int n;
int sz[maxn], tot_sz;
int cnt_pass[maxn];
int64_t cnt1, cnt2;
void dfs_sz(int u, int p) {
  sz[u] = 1;
  int64_t choice = 1;
  for (int v : g[u])
    if (v != p) {
      dfs_sz(v, u);
      sz[u] += sz[v];
      cnt_pass[u] += choice * sz[v];
      choice += sz[v];
    }
}
int64_t C2(int64_t n) { return n * (n - 1) / 2; }
void dfs_cnt1(int u, int p) {
  int64_t sum = 0;
  for (int v : g[u])
    if (v != p) {
      dfs_cnt1(v, u);
      cnt1 += sum * C2(sz[v]);
      sum += C2(sz[v]);
    }
}
void dfs_cnt2(int u, int p) {
  cnt2 += cnt_pass[u] * C2(tot_sz - sz[u]);
  for (int v : g[u])
    if (v != p) {
      dfs_cnt2(v, u);
    }
}
int main() {
  fin, n;
  for (int _ = 0, _end = n - 1; _ < _end; _++) {
    int u, v;
    fin, u, v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs_sz(1, -1);
  tot_sz = sz[1];
  dfs_cnt1(1, -1);
  dfs_cnt2(1, -1);
  ;
  fout, (cnt2 - cnt1) * 2, endl;
  return 0;
}
