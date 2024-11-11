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
const int N = 500005;
struct node {
  int val, opt;
};
std::vector<node> v[N];
std::multiset<int, std::greater<int> > S;
int f[N][22];
int main() {
  int n, m, x, y;
  read(n, m);
  for (int i = 1; i <= n; ++i) {
    read(x, y);
    ++x, ++y;
    v[x].emplace_back((node){y, 1});
    v[y].emplace_back((node){y, 2});
  }
  for (int i = 1; i <= 5e5 + 1; ++i) {
    for (auto it : v[i]) {
      if (it.opt == 1) {
        S.insert(it.val);
      } else {
        S.erase(S.find(it.val));
      }
    }
    if (S.empty()) {
      f[i][0] = -inf;
    } else {
      f[i][0] = *S.begin();
    }
  }
  for (int i = 5e5 + 1; i >= 1; --i) {
    for (int j = 1; j <= 20; ++j) {
      if (f[i][j - 1] > 0) {
        f[i][j] = f[f[i][j - 1]][j - 1];
      } else {
        f[i][j] = -inf;
      }
    }
  }
  while (m--) {
    read(x, y);
    ++x, ++y;
    int ans = 0;
    for (int i = 20; i >= 0 && x > 0; --i) {
      if (f[x][i] < 0) continue;
      if (f[x][i] < y) {
        x = f[x][i];
        ans += 1 << i;
      }
    }
    if (x < 0) {
      printf("-1\n");
      continue;
    }
    if (x < y) x = f[x][0], ++ans;
    if (x >= y) {
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
