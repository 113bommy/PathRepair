#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, Inf = 0x7fffffff;
const long long INF = 0x7fffffffffffffff;
const double eps = 1e-8;
unsigned int seed = 19260817;
const unsigned int _RAND_MAX_ = 4294967295u;
__inline__ __attribute__((always_inline)) unsigned int Rand() {
  return seed = seed * 998244353u + 1000000007u;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return (!b) ? a : gcd(b, a % b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp abs(const _Tp &a) {
  return a > 0 ? a : -a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp max(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) _Tp min(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(_Tp &a, const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(_Tp &a, const _Tp &b) {
  (a > b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) bool _cmp(const double &a,
                                                    const double &b) {
  return abs(a - b) <= eps;
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  register char ch(getchar());
  bool f(false);
  while (ch < 48 || ch > 57) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (ch >= 48 && ch <= 57)
    x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
__inline__ __attribute__((always_inline)) int read_str(char *s) {
  register char ch(getchar());
  while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
  register char *tar = s;
  *tar = ch, ch = getchar();
  while (ch != ' ' && ch != '\r' && ch != '\n' && ch != EOF)
    *(++tar) = ch, ch = getchar();
  return tar - s + 1;
}
const int N = 1005;
int l[N][N], r[N][N], u[N][N], d[N][N];
char s[N][N];
int ans[N][N];
bool used[N][N];
int main() {
  int n, m;
  read(n, m);
  for (int i = 1; i <= n; ++i) {
    read_str(s[i] + 1);
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '*') {
        l[i][j] = l[i][j - 1] + 1;
      }
    }
    for (int j = m; j >= 1; --j) {
      if (s[i][j] == '*') {
        r[i][j] = r[i][j + 1] + 1;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (s[j][i] == '*') {
        u[j][i] = u[j - 1][i] + 1;
      }
    }
    for (int j = n; j >= 1; --j) {
      if (s[j][i]) {
        d[j][i] = d[j + 1][i] + 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '*') {
        ans[i][j] = min(l[i][j], min(r[i][j], min(u[i][j], d[i][j]))) - 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int maxx = 0;
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '*') {
        if (ans[i][j]) chmax(maxx, j + ans[i][j]);
        if (maxx >= j) used[i][j] = 1;
      }
    }
    int minn = m + 1;
    for (int j = m; j >= 1; --j) {
      if (s[i][j] == '*') {
        if (ans[i][j]) chmin(minn, j - ans[i][j]);
        if (minn <= j) used[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    int maxx = 0;
    for (int j = 1; j <= n; ++j) {
      if (s[j][i] == '*') {
        if (ans[j][i]) chmax(maxx, j + ans[j][i]);
        if (maxx >= j) used[j][i] = 1;
      }
    }
    int minn = n + 1;
    for (int j = n; j >= 1; --j) {
      if (s[j][i] == '*') {
        if (ans[j][i]) chmin(minn, j - ans[j][i]);
        if (minn <= j) used[j][i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '*' && !used[i][j]) {
        printf("-1\n");
        return 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ans[i][j]) {
        ++cnt;
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (ans[i][j]) {
        printf("%d %d %d\n", i, j, ans[i][j]);
      }
    }
  }
  return 0;
}
