#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline")
using namespace std;
template <class T>
inline void read(T &x) {
  int ch = 0, f = 0;
  x = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  if (f) x = -x;
}
const int N = 4005, mod = 1e9 + 7;
char str[N];
int dp[N][N][2][2], s[N], n, p, Alpha;
inline void up(int &x, int y) { x = x + y >= mod ? x + y - mod : x + y; }
inline int gao(int x) {
  if (x < 0) return 0;
  int tot = max(min(p, x - (p - 1) + 1), 0), res = 0;
  res = 1ll * tot * p % mod;
  int last = min(x, p - 1);
  if (tot <= last) {
    int k = x - last + x - tot + 2;
    k = 1ll * k * (last - tot + 1) % mod;
    k = 1ll * k * ((mod + 1) / 2) % mod;
    up(res, k);
  }
  return res;
}
inline int calc(int x, int y, int z) {
  return y ? (gao(x + p) - gao(p - 1 - z) + mod) % mod : gao(x);
}
inline int dfs(int x, int y, int a, int b) {
  if (x == n + 1) return y >= Alpha;
  if (~dp[x][y][a][b]) return dp[x][y][a][b];
  int res = 0;
  if (a) {
    if (x < n) {
      int c1 = calc(p - 2, b, 1);
      up(res, 1ll * c1 * dfs(x + 1, y + b, 1, 1) % mod);
    }
    int c2 = calc(p - 1, b, 0);
    up(res, 1ll * c2 * dfs(x + 1, y + b, 1, 0) % mod);
  } else {
    int c1 = calc(s[x] - 2, b, 1);
    if (x < n) up(res, 1ll * c1 * dfs(x + 1, y + b, 1, 1) % mod);
    int c2 = calc(s[x] - 1, b, 0);
    up(res, 1ll * c2 * dfs(x + 1, y + b, 1, 0) % mod);
    if (x < n) {
      int c3 = calc(s[x] - 1, b, 1) - c1 % mod;
      up(res, 1ll * c3 * dfs(x + 1, y + b, 0, 1) % mod);
    }
    int c4 = (calc(s[x], b, 0) - c2 + mod) % mod;
    up(res, 1ll * c4 * dfs(x + 1, y + b, 0, 0) % mod);
  }
  return dp[x][y][a][b] = res;
}
int main() {
  read(p), read(Alpha), scanf("%s", str + 1);
  int m = strlen(str + 1);
  reverse(str + 1, str + m + 1);
  while (m) {
    long long now = 0;
    for (int i = m; i >= 1; i--) {
      now = 10ll * now + str[i] - '0';
      str[i] = now / p + '0';
      now %= p;
    }
    s[++n] = now;
    while (m && str[m] == '0') m--;
  }
  reverse(s + 1, s + n + 1);
  memset(dp, -1, sizeof(dp));
  cout << dfs(1, 0, 0, 0) << endl;
  return 0;
}
