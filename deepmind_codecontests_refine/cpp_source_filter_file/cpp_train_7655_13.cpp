#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar(), flag = 0;
  while ((ch > '9' || ch < '0') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
inline void read(int &x, int &y) { read(x), read(y); }
inline void read(int &x, int &y, int &z) { read(x), read(y), read(z); }
int n, ans, dp[100005][20], now, dep[1000005];
inline void rise(int &x, int y) {
  for (int i = 0; i < 20; i++)
    if (y & (1 << i)) x = dp[x][i];
}
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  rise(x, dep[x] - dep[y]);
  if (x == y) return x;
  for (int i = 19; ~i; i--)
    if (dp[x][i] != dp[y][i]) x = dp[x][i], y = dp[y][i];
  return dp[x][0];
}
inline int get(int x, int y) {
  int p = lca(x, y);
  return dep[x] + dep[y] - 2 * dep[p];
}
int main() {
  read(n);
  now = 1;
  for (int i = 2; i <= n; i++) {
    int x;
    read(x);
    dep[i] = dep[x] + 1;
    dp[i][0] = x;
    for (int j = 1; j < 20; j++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
    if (dep[i] > dep[now]) ans++, now = i;
    ans = max(ans, get(i, now));
    printf("%d ", ans);
  }
  return 0;
}
