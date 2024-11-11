#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return ~f ? s : -s;
}
const int maxn = 120;
const int mod = 998244353;
int n, m, k;
long long rk[maxn], s[maxn];
inline void insert(long long x) {
  for (int i = (m - 1), _end_ = (0); i >= _end_; i--)
    if (x >> i & 1) {
      if (!s[i]) {
        s[i] = x;
        k++;
        break;
      } else
        x ^= s[i];
    }
}
inline void init() {
  n = read();
  m = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) {
    long long x;
    scanf("%lld", &x);
    insert(x);
  }
}
long long cnt[100], C[maxn][maxn];
long long ans[100], tp;
void dfs(int u, long long s) {
  if (u == tp + 1) return cnt[__builtin_popcountll(s)]++, void();
  dfs(u + 1, s);
  dfs(u + 1, s ^ rk[u]);
}
inline void doing() {
  for (int i = (0), _end_ = (m - 1); i <= _end_; i++)
    if (s[i])
      for (int j = (i + 1), _end_ = (m - 1); j <= _end_; j++)
        if (s[j] >> i & 1) s[j] ^= s[i];
  for (int i = (0), _end_ = (m - 1); i <= _end_; i++)
    if (s[i]) rk[++tp] = s[i];
  if (k <= m / 2) {
    dfs(1, 0);
    long long mult = 1;
    for (int i = (1), _end_ = (n - k); i <= _end_; i++)
      mult = (long long)mult * 2 % mod;
    for (int i = (0), _end_ = (n); i <= _end_; i++)
      printf("%lld ", (long long)cnt[i] * mult % mod);
  } else {
    tp = 0;
    for (int i = (0), _end_ = (m - 1); i <= _end_; i++)
      if (!s[i]) {
        long long x = 1ll << i;
        for (int j = (0), _end_ = (m - 1); j <= _end_; j++)
          if (s[j] & (1ll << i)) x |= 1ll << j;
        rk[++tp] = x;
      }
    dfs(1, 0);
    for (int i = (0), _end_ = (m); i <= _end_; i++) C[i][0] = 1;
    for (int i = (1), _end_ = (m); i <= _end_; i++)
      for (int j = (1), _end_ = (i); j <= _end_; j++)
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    for (int x = (0), _end_ = (m); x <= _end_; x++) {
      for (int y = (0), _end_ = (m); y <= _end_; y++)
        for (int p = (0), _end_ = (min(y, x)); p <= _end_; p++) {
          ans[x] = (ans[x] + (long long)cnt[y] * C[y][p] % mod *
                                 C[m - y][x - p] * (p & 1 ? -1 : 1)) %
                   mod;
        }
      ans[x] = (ans[x] + mod) % mod;
    }
    long long mult = 1;
    for (int i = (1), _end_ = (n); i <= _end_; i++)
      mult = (long long)mult * 2 % mod;
    for (int i = (1), _end_ = (m); i <= _end_; i++)
      mult = (long long)mult * (mod + 1 >> 1) % mod;
    for (int i = (0), _end_ = (n); i <= _end_; i++)
      printf("%lld ", (long long)ans[i] * mult % mod);
  }
}
int main() {
  init();
  doing();
  return 0;
}
