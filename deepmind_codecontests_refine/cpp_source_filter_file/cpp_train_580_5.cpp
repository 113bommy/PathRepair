#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
struct IO {
  static const int maxn = (1 << 25) + 10;
  char a[maxn], *s, b[maxn], *t;
  void INPUT() {
    s = a;
    t = b;
    a[fread(a, 1, sizeof a, stdin)] = 0;
  }
  void OUTPUT() { fwrite(b, 1, t - b, stdout); }
  operator int() {
    int x = 0;
    while (*s != '-' && (*s < '0' || *s > '9')) {
      ++s;
    }
    bool f = 0;
    if (*s == '-') {
      f = 1;
      ++s;
    }
    while (*s >= '0' && *s <= '9') {
      (x *= 10) += *s - '0';
      ++s;
    }
    if (f) {
      x = -x;
    }
    return x;
  }
  operator long long() {
    long long x = 0;
    while (*s != '-' && (*s < '0' || *s > '9')) {
      ++s;
    }
    bool f = 0;
    if (*s == '-') {
      f = 1;
      ++s;
    }
    while (*s >= '0' && *s <= '9') {
      (x *= 10) += *s - '0';
      ++s;
    }
    if (f) {
      x = -x;
    }
    return x;
  }
  operator char() {
    while (*s <= 32) {
      ++s;
    }
    char ret = *s;
    ++s;
    return ret;
  }
  inline void out(int x) {
    if (!x) {
      *t++ = '0';
      return;
    }
    if (x < 0) {
      *t++ = '-';
      x = -x;
    }
    static char c[20], *i;
    i = c;
    while (x) {
      int y = x / 10;
      *i++ = x - y * 10 + '0';
      x = y;
    }
    while (i != c) {
      *t++ = *--i;
    }
    return;
  }
  inline void out(int x, char C) {
    if (!x) {
      *t++ = '0';
      *t++ = C;
      return;
    }
    if (x < 0) {
      *t++ = '-';
      x = -x;
    }
    static char c[20], *i;
    i = c;
    while (x) {
      int y = x / 10;
      *i++ = x - y * 10 + '0';
      x = y;
    }
    while (i != c) {
      *t++ = *--i;
    }
    *t++ = C;
    return;
  }
  inline void out(long long x) {
    if (!x) {
      *t++ = '0';
      return;
    }
    if (x < 0) {
      *t++ = '-';
      x = -x;
    }
    static char c[20], *i;
    i = c;
    while (x) {
      long long y = x / 10;
      *i++ = x - y * 10 + '0';
      x = y;
    }
    while (i != c) {
      *t++ = *--i;
    }
    return;
  }
  inline void out(long long x, char C) {
    if (!x) {
      *t++ = '0';
      *t++ = C;
      return;
    }
    if (x < 0) {
      *t++ = '-';
      x = -x;
    }
    static char c[20], *i;
    i = c;
    while (x) {
      long long y = x / 10;
      *i++ = x - y * 10 + '0';
      x = y;
    }
    while (i != c) {
      *t++ = *--i;
    }
    *t++ = C;
    return;
  }
  inline void out(char c) {
    *t++ = c;
    return;
  }
  inline void out(char *s) {
    while (*s >= ' ') {
      *t++ = *s++;
    }
    return;
  }
} io;
void Main();
int main(int argc, char *argv[]) {
  io.INPUT();
  Main();
  io.OUTPUT();
  return 0;
}
const int maxn = 2e5 + 100;
long long T, A, d, B;
int n;
long long a[maxn], ans[maxn];
map<long long, vector<int> > M;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve(vector<int> v, long long T) {
  int n = (int)((v).size());
  if (n == 1) {
    ans[v[0]] = T;
    return;
  }
  vector<pair<long long, int> > vp(n), t;
  for (int j = 0, j_end_ = (n); j < j_end_; ++j) {
    int i = v[j];
    vp[j] = make_pair(a[i] * B % T, i);
  }
  sort((vp).begin(), (vp).end());
  for (int i = 0, i_end_ = (n); i < i_end_; ++i) {
    if ((int)((t).size()) && vp[i].first == t.back().first) {
      if (t.back().second > vp[i].second) {
        t.pop_back();
      } else {
        continue;
      }
    }
    t.push_back(vp[i]);
  }
  if ((int)((t).size()) == 1) {
    ans[t[0].second] = T;
    return;
  }
  n = (int)((t).size());
  t.push_back(t[0]);
  for (int i = 0, i_end_ = (n); i < i_end_; ++i) {
    long long l = t[i].first, r = t[i + 1].first + T;
    int x = t[i].second;
    ans[x] = (r - l) % T;
  }
  return;
}
long long mod;
void extgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  extgcd(b, a % b, y, x);
  ((y -= a / b * x) %= mod += mod) %= mod;
  return;
}
long long inv(long long x, long long mod) {
  ::mod = mod;
  x %= mod;
  long long a, b;
  extgcd(x, mod, a, b);
  return (a + mod) % mod;
}
void Main() {
  T = io;
  n = io;
  A = io;
  for (int i = (1), i_end_ = (n - 1); i <= i_end_; ++i) {
    a[i] = io;
    a[i] += a[i - 1];
  }
  A += a[n - 1];
  if (A % T == 0) {
    for (int i = 0, i_end_ = (n); i < i_end_; ++i) {
      io.out(M.find(a[i] % T) == M.end() ? 1 : 0, i == n - 1 ? '\n' : ' ');
      M[a[i] % T];
    }
    return;
  }
  d = gcd(A, T);
  B = inv(A / d, T / d);
  for (int i = 0, i_end_ = (n); i < i_end_; ++i) {
    if (M.find(a[i] % d) == M.end()) {
      M[a[i] % d] = {};
    }
    M[a[i] % d].push_back(i);
    a[i] /= d;
  }
  for (auto it : M) {
    solve(it.second, T / d);
  }
  for (int i = 0, i_end_ = (n); i < i_end_; ++i) {
    io.out(ans[i], i == n - 1 ? '\n' : ' ');
  }
  return;
}
