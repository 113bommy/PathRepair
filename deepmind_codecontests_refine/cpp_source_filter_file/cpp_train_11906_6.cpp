#include <bits/stdc++.h>
const int mod = 998244353, N = 505, M = 6e5 + 5, INF = 0x3f3f3f3f;
const double eps = 1e-9, alpha = 0.7;
template <typename T>
inline T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    f = ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
template <typename T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <typename T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <typename T>
inline T abs(const T &x) {
  return x > 0 ? x : -x;
}
inline int Mod(int x) {
  if (x >= mod) {
    return x - mod;
  } else if (x < 0) {
    return x + mod;
  } else {
    return x;
  }
}
template <typename T1, typename T2>
struct pair {
  T1 first;
  T2 second;
  pair(const T1 &x = 0, const T2 &y = 0) {
    first = x;
    second = y;
  }
  friend pair operator+(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return pair(x.first + y.first, x.second + y.second);
  }
  friend pair operator-(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return pair(x.first - y.first, x.second - y.second);
  }
  friend bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first < y.first || (x.first == y.first && x.second < y.second);
  }
  friend bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first < y.first || (x.first == y.first && x.second <= y.second);
  }
  friend bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first > y.first || (x.first == y.first && x.second > y.second);
  }
  friend bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first > y.first || (x.first == y.first && x.second >= y.second);
  }
  friend bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first == y.first && x.second == y.second;
  }
  friend bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y) {
    return x.first != y.first || x.second != y.second;
  }
};
template <typename T1, typename T2>
inline pair<T1, T2> make_pair(const T1 &x, const T2 &y) {
  return pair<T1, T2>(x, y);
}
template <typename T>
struct stack {
  int top;
  T vals[N];
  bool empty() { return !top; }
  void push(T x) { vals[++top] = x; }
  void pop() {
    if (top > 0) {
      --top;
    }
    return;
  }
  void clear() { top = 0; }
  T TOP() { return top ? vals[top] : T(-1); }
};
inline int ksm(int x, int y) {
  int ret = 1;
  for (; y; y /= 2, x = 1LL * x * x % mod) {
    if (y & 1) {
      ret = 1LL * ret * x % mod;
    }
  }
  return ret;
}
inline int ksc(int x, int y) {
  int ret = 0;
  for (; y; y /= 2, x = Mod(x + x)) {
    if (y & 1) {
      ret = Mod(ret + x);
    }
  }
  return ret;
}
struct graph {
  int cnt, h[N];
  pair<int, int> edge[N * 2];
  void add_edge(int x, int y) {
    edge[cnt].first = y;
    edge[cnt].second = h[x];
    h[x] = cnt++;
  }
  void clear() {
    memset(h, -1, sizeof h);
    cnt = 0;
  }
};
inline int ls(int k) { return k << 1; }
inline int rs(int k) { return k << 1 | 1; }
inline int sign(double x) {
  if (abs(x) < eps) {
    return 0;
  } else if (x < 0) {
    return -1;
  } else {
    return 1;
  }
}
template <typename T>
struct BIT {
  int limit;
  T vals[N];
  void resize(int n) { limit = n; }
  void add(int x, T y) {
    for (; x <= limit; x += x & -x) {
      vals[x] += y;
    }
  }
  T sum(int x) {
    T ret = 0;
    for (; x; x -= x & -x) {
      ret = ret + vals[x];
    }
    return ret;
  }
};
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::map;
using std::queue;
using std::set;
using std::vector;
int n, m, ans[M];
char mp[N][N];
std::bitset<N> f[N][N], g[N][N];
struct Query {
  int sx, sy, tx, ty, id;
  Query(int SX = 0, int SY = 0, int TX = 0, int TY = 0, int ID = 0)
      : sx(SX), sy(SY), tx(TX), ty(TY), id(ID) {}
};
void divide(int L, int R, std::vector<Query> &vec) {
  if (!vec.size()) {
    return;
  }
  if (L > R) {
    return;
  }
  int MID = (L + R) / 2;
  for (int i = m; i >= 1; --i) {
    if (mp[MID][i] == '.') {
      f[MID][i] = f[MID][i + 1];
      f[MID][i][i] = 1;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (mp[MID][i] == '.') {
      g[MID][i] = g[MID][i - 1];
      g[MID][i][i] = 1;
    }
  }
  for (int i = MID - 1; i >= L; --i) {
    for (int j = m; j >= 1; --j) {
      if (mp[i][j] == '.') {
        f[i][j] = f[i][j + 1] | f[i + 1][j];
      }
    }
  }
  for (int i = MID + 1; i <= R; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j] == '.') {
        g[i][j] = g[i][j - 1] | g[i - 1][j];
      }
    }
  }
  std::vector<Query> vecl, vecr;
  for (auto &i : vec) {
    if (i.sx > MID) {
      vecr.push_back(i);
    } else if (i.tx < MID) {
      vecl.push_back(i);
    } else {
      if ((f[i.sx][i.sy] & g[i.tx][i.ty]).any()) {
        ans[i.id] = 1;
      }
    }
  }
  divide(L, MID - 1, vecl);
  divide(MID + 1, R, vecr);
  return;
}
int main() {
  n = read<int>();
  m = read<int>();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", mp + 1);
  }
  int q;
  q = read<int>();
  std::vector<Query> vec;
  for (int i = 1, sx, sy, tx, ty; i <= q; ++i) {
    sx = read<int>();
    sy = read<int>();
    tx = read<int>();
    ty = read<int>();
    vec.emplace_back(sx, sy, tx, ty, i);
  }
  divide(1, n, vec);
  for (int i = 1; i <= q; ++i) {
    puts(ans[i] ? "Yes" : "No");
  }
  return 0;
}
