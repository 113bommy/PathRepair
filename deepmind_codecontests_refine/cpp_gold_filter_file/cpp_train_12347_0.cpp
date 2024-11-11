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
map<int, int> n, m, s;
long long N, M, S, ans;
vector<pair<int, int> > all;
void input(map<int, int> &a, long long &A) {
  a.clear();
  A = 1;
  for (int i = 0, i_end_ = (3); i < i_end_; ++i) {
    int x = io;
    A *= (long long)x;
    for (int y = 2; y * y <= x; ++y) {
      while (x % y == 0) {
        ++a[y];
        x /= y;
      }
    }
    if (x > 1) {
      ++a[x];
    }
  }
  return;
}
void dfs(long long x = 1, int it = 0) {
  if (x > N) {
    return;
  }
  if (it == (int)((all).size())) {
    ans += (x <= N);
    return;
  }
  dfs(x, it + 1);
  for (int i = 0, i_end_ = (all[it].second); i < i_end_; ++i) {
    dfs((x *= (long long)all[it].first), it + 1);
  }
  return;
}
void solve() {
  input(n, N);
  input(m, M);
  input(s, S);
  ++s[2];
  S *= 2;
  ans = 0;
  vector<long long> v;
  for (auto it : n) {
    int x = s.count(it.first) ? s[it.first] + 1 : 1, y = it.first;
    if (x <= it.second) {
      long long z = 1;
      while (x--) {
        z *= (long long)y;
      }
      v.push_back(z);
    }
  }
  for (int i = 0, i_end_ = (1 << (int)((v).size())); i < i_end_; ++i) {
    long long z = 1;
    for (int j = 0, j_end_ = ((int)((v).size())); j < j_end_; ++j) {
      if ((i >> j) & 1) {
        z *= (long long)v[j];
      }
    }
    ans += (__builtin_parity(i) ? -1 : 1) * (M / z);
  }
  all.clear();
  for (auto it : s) {
    all.push_back(make_pair(it.first, it.second));
  }
  dfs();
  io.out(ans, '\n');
  return;
}
void Main() {
  int T = io;
  while (T--) {
    solve();
  }
  return;
}
