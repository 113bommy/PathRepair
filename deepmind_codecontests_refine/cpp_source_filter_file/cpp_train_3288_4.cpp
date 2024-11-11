#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1, *p2;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class T>
inline void rd(T& x) {
  x = 0;
  char ch = nc();
  for (; !isdigit(ch); ch = nc())
    ;
  for (; isdigit(ch); ch = nc()) x = x * 10 - 48 + ch;
}
const int lev = 63;
const int maxn = 510;
const long long inf = (long long)(1e18);
int n, m;
bitset<maxn> dp[lev][2][maxn], pre, g;
long long ans;
int main() {
  int n, m;
  rd(n);
  rd(m);
  for (int i = 0, u, v, t; i < m; i++) {
    rd(u);
    rd(v);
    rd(t);
    dp[0][t][u][v] = 1;
  }
  for (int s = 1; s <= 60; s++)
    for (int j = 0; j < 2; j++)
      for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
          if (dp[s - 1][j][u][v]) dp[s][j][u] |= dp[s - 1][j ^ 1][v];
  for (int i = 1; i <= n; i++)
    if (dp[60][0][1][i]) return !printf("-1");
  int t = 0;
  pre[1] = 1;
  for (int i = 59; i >= 0; i--) {
    g = 0;
    for (int j = 1; j <= n; j++)
      if (pre[j]) g |= dp[i][t][j];
    if (g.count()) {
      pre = g;
      t ^= 1;
      ans += (1ll << i);
      if (ans > inf) return !printf("-1");
    }
  }
  if (ans > inf) return !printf("-1");
  return !printf("%d\n", ans);
}
