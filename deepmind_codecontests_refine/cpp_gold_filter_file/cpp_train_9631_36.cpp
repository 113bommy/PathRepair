#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
const int base = 37;
const int _mod = 19260817;
int n, m, ans, res, val[N];
char str[2][N], W[N];
template <typename _Tp>
inline void IN(_Tp& x) {
  char ch;
  bool flag = 0;
  x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = true;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
int power[N];
inline int mul(int x, int y) { return 1ll * x * y % _mod; }
inline int del(int x, int y) {
  x -= y;
  if (x < 0) x += _mod;
  return x;
}
inline int add(int x, int y) {
  x += y;
  if (x >= _mod) x -= _mod;
  return x;
}
inline void inc(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
struct Hash {
  int pre[N], suf[N];
  inline void init(char* S) {
    for (int i = 1; i <= n; ++i)
      pre[i] = add(mul(pre[i - 1], base), S[i] - 'a');
    for (int i = n; i >= 1; --i)
      suf[i] = add(mul(suf[i + 1], base), S[i] - 'a');
  }
  inline int get_pre(int l, int r) {
    return del(pre[r], mul(pre[l - 1], power[r - l + 1]));
  }
  inline int get_suf(int l, int r) {
    return del(suf[l], mul(suf[r + 1], power[r - l + 1]));
  }
} L[2];
inline int merge(int x, int y, int len) { return add(x, mul(y, power[len])); }
int f[2][N][N], g[2][N][N];
inline void solve() {
  memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
  for (int i = 1; i <= m; ++i) val[i] = add(mul(val[i - 1], base), W[i] - 'a');
  for (int i = 0; i <= 1; ++i)
    for (int r = 1; r <= n; ++r)
      for (int l = r; l >= 1; --l) {
        int len = 2 * (r - l + 1);
        if (len > m) continue;
        long long _1 = L[i].get_pre(l, r), _2 = L[i ^ 1].get_suf(l, r);
        if (merge(_1, _2, r - l + 1) == val[len])
          len == m ? ++res : g[i][r][len] = 1;
      }
  for (int i = 0; i <= 1; ++i)
    for (int j = 1; j <= n; ++j)
      if (str[i][j] == W[1]) g[i][j][1] = 1;
  for (int len = 1; len < m; ++len)
    for (int j = 1; j <= n; ++j)
      for (int i = 0; i <= 1; ++i) {
        if (g[i][j][len])
          if (j < n && str[i][j + 1] == W[len + 1])
            inc(f[i][j + 1][len + 1], g[i][j][len]);
        if (f[i][j][len]) {
          if (j < n && str[i][j + 1] == W[len + 1])
            inc(f[i][j + 1][len + 1], f[i][j][len]);
          if (str[i ^ 1][j] == W[len + 1])
            inc(g[i ^ 1][j][len + 1], f[i][j][len]);
        }
      }
  for (int i = m; i >= 1; --i) val[i] = add(mul(val[i + 1], base), W[i] - 'a');
  for (int i = 0; i <= 1; ++i)
    for (int l = 1; l <= n; ++l) {
      if (str[i][l] == W[m])
        inc(ans, (bool)(m == 1)), inc(ans, f[i][l - 1][m - 1]),
            inc(ans, g[i][l - 1][m - 1]);
      for (int r = l; r <= n; ++r) {
        int len = 2 * (r - l + 1);
        if (len > m) continue;
        long long _1 = L[i ^ 1].get_pre(l, r), _2 = L[i].get_suf(l, r);
        if (merge(_2, _1, r - l + 1) == val[m - len + 1])
          if (len == m && m != 2)
            ++res;
          else
            inc(ans, f[i][l - 1][m - len]), inc(ans, g[i][l - 1][m - len]);
      }
    }
}
int main() {
  scanf("%s\n%s\n%s", str[0] + 1, str[1] + 1, W + 1);
  n = strlen(str[0] + 1), m = strlen(W + 1);
  L[0].init(str[0]), L[1].init(str[1]);
  int lim = max(n, m);
  power[0] = 1;
  for (int i = 1; i <= lim; ++i) power[i] = mul(power[i - 1], base);
  solve(), reverse(W + 1, W + 1 + m), solve();
  inc(ans, res >> 1);
  if (m == 1) ans >>= 1;
  printf("%d\n", ans);
  return 0;
}
