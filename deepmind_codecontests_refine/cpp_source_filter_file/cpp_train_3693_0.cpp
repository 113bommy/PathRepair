#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ '0');
    ch = getchar();
  }
  return f ? x : -x;
}
const int N = 3e2 + 5, mod = 1e4 + 7;
int n, len, m, vis[N][N][N], cnt[N][N][N];
char s[N];
inline void inc(int& x, int y) { x = x + y < mod ? x + y : x + y - mod; }
inline void dec(int& x, int y) { x = x - y >= 0 ? x - y : x - y + mod; }
struct matrix {
  int x[N][N], flg;
  inline matrix(int _flg = 0) : flg(_flg) { memset(x, 0, sizeof x); }
  inline int* operator[](int p) { return x[p]; }
  inline const int* operator[](int p) const { return x[p]; }
  inline matrix operator*(const matrix& o) {
    matrix ans;
    if (!flg)
      for (int i = (1), _ed = (m); i <= _ed; ++i)
        for (int k = (i), _ed = (m); k <= _ed; ++k)
          for (int j = (k), _ed = (m); j <= _ed; ++j)
            inc(ans[i][j], 1ll * x[i][k] * o[k][j] % mod);
    else
      for (int i = (1), _ed = (m); i <= _ed; ++i)
        for (int j = (1), _ed = (m); j <= _ed; ++j)
          inc(ans[1][j], 1ll * x[1][i] * o[i][j] % mod);
    return ans;
  }
  inline void print() {
    for (int i = (1), _ed = (m); i <= _ed; ++i)
      fprintf(stderr, "%d%c", x[i][200], " \n"[i == m]);
    fprintf(stderr, "\n\n");
  }
};
void ksm(matrix& ans, matrix& b, int n) {
  for (; n; n >>= 1, b = b * b)
    if (n & 1) ans = ans * b;
}
inline int dfs(int i, int l, int r) {
  if (i < 0) return 0;
  if (vis[i][l][r]) return cnt[i][l][r];
  vis[i][l][r] = 1;
  if (l == 1 && r == len) return cnt[i][l][r] = !i;
  if (1 < l && r < len && s[l - 1] == s[r + 1])
    inc(cnt[i][l][r], dfs(i, l - 1, r + 1));
  if (1 < l && s[l - 1] != s[r]) inc(cnt[i][l][r], dfs(i - 1, l - 1, r));
  if (r < len && s[l] != s[r + 1]) inc(cnt[i][l][r], dfs(i - 1, l, r + 1));
  return cnt[i][l][r];
}
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1), m = len + (len + 1) / 2;
  n = read();
  matrix f(1), g;
  for (int t = (0), _ed = (len - 1); t <= _ed; ++t) {
    int c = 0;
    for (int i = (1), _ed = (len); i <= _ed; ++i)
      inc(c, dfs(t, i, i)),
          (i < len && s[i] == s[i + 1]) ? inc(c, dfs(t, i, i + 1)) : void();
    if (!t) {
      f[1][1] = 1, f[1][len] = c;
      g[m][m] = 26;
      for (int i = (len), _ed = (m - 1); i <= _ed; ++i)
        g[i][i + 1] = 1, g[i][i] = 25;
    } else {
      g[t][m - (len - t + 1) / 2] = c, g[t][t] = 24;
      if (t < len - 1) g[t][t + 1] = 1;
    }
  }
  ksm(f, g, (n + len + 1) / 2);
  if (~(n + len) & 1) return printf("%d\n", f[1][m]), 0;
  int res = f[1][m];
  f = matrix(1), g = matrix();
  for (int t = (0), _ed = (len - 1); t <= _ed; ++t) {
    int c = 0;
    for (int i = (1), _ed = (len - 1); i <= _ed; ++i)
      if (s[i] == s[i + 1]) inc(c, dfs(t, i, i + 1));
    if (!t) {
      f[1][1] = 1, f[1][len] = c;
      for (int i = (len), _ed = (m - 1); i <= _ed; ++i)
        g[i][i + 1] = 1, g[i][i] = 25;
    } else {
      g[t][m - (len - t + 1) / 2] = c, g[t][t] = 24;
      if (t < len) g[t][t + 1] = 1;
    }
  }
  ksm(f, g, (n + len + 1) / 2);
  dec(res, f[1][m]);
  return printf("%d\n", res), 0;
}
