#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
char mat[25][25];
int mask[50][30];
int dp[40][1 << 20];
int n;
int dfs(int level, int m, int take) {
  int& ret = dp[level][m];
  if (ret != -inf) return ret;
  int now = -inf;
  if (level == n * 2 - 2) {
    now = 0;
  } else {
    for (int letter = 0; letter < 26; ++letter) {
      int next = level + 1;
      int f = mask[next][letter] & (m | m << 1);
      if (f) {
        int t = -dfs(next, f, letter);
        cmax(now, t);
      }
    }
  }
  if (level % 2 == 0) {
    if (take == 0)
      --now;
    else if (take == 1)
      ++now;
  } else {
    if (take == 0)
      ++now;
    else if (take == 1)
      --now;
  }
  return ret = now;
}
int main() {
  const int n = Rint();
  ::n = n;
  for (int i = (0); i < (n); ++i) scanf("%s", mat[i]);
  for (int i = 0; i <= n * 2 - 2; ++i)
    for (int letter = 0; letter < 26; ++letter)
      for (int r = 0; r < n; ++r) {
        const int c = i - r;
        if (c >= 0 && c < n && mat[r][c] - 'a' == letter) {
          mask[i][letter] |= 1 << r;
        }
      }
  for (int i = 0; i <= n * 2 - 2; ++i) fill(dp[i], dp[i] + (1 << n), -inf);
  int ans = dfs(0, 1, mat[0][0] - 'a');
  if (ans < 0) puts("FIRST");
  if (ans == 0) puts("DRAW");
  if (ans > 0) puts("SECOND");
  return 0;
}
