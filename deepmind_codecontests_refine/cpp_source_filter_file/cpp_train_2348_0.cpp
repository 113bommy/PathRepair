#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200020;
int n, m, v[N][2], d[N], vis[N];
struct node {
  int to, tar, nxt;
  node() {}
  node(int x, int y, int z) { to = x, tar = y, nxt = z; }
} tab[N << 1];
int head[N], tot = 2;
inline void add(int x, int y, int z) {
  ++d[x], ++d[y];
  tab[tot] = node(y, z, head[x]), head[x] = tot++;
  tab[tot] = node(x, z, head[y]), head[y] = tot++;
}
map<int, int> S[N][2];
int dp[N][2][2], Ans[2][N], top[2], ans[2][N];
int sol(int x, int tp = 0) {
  vis[x] = true;
  for (int i = head[x]; i; i = tab[i].nxt) {
    int t = tab[i].to, e = tab[i].tar;
    if (vis[t]) continue;
    memset(dp[t], 0, sizeof dp[t]);
    for (int sx = 0; sx < 2; sx++)
      for (int st = 0; st < 2; st++)
        for (int j = 0; j < 2; j++) {
          (dp[t][st][j ^ v[t][st] ^ (S[x][sx][e] || S[t][st][e])] +=
           dp[x][sx][j]) %= mod;
        }
    int ret = sol(t, tp);
    if (tp) vis[x] = false;
    return ret;
  }
  if (tp) vis[x] = false;
  return x;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d", &x);
    if (x == 1)
      scanf("%d", &x), x > 0 ? v[x][1] ^= 1 : v[-x][0] ^= 1;
    else {
      scanf("%d%d", &x, &y);
      int sx = x > 0, sy = y > 0;
      x = max(x, -x), y = max(y, -y);
      if (x == y)
        vis[x] = true, sx == sy ? Ans[0][top[0]++] = Ans[1][top[1]++] = 1
                                : (Ans[0][top[0]++] = 0, Ans[1][top[1]++] = 2);
      else
        add(x, y, i), S[x][sx][i] = 1, S[y][sy][i] = 1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i] && d[i] <= 1) {
      ++dp[i][0][v[i][0]], ++dp[i][1][v[i][1]];
      int x = sol(i);
      Ans[0][top[0]++] = (dp[x][0][0] + dp[x][1][0]) % mod,
      Ans[1][top[1]++] = (dp[x][0][1] + dp[x][1][1]) % mod;
    }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vis[i] = true;
      for (int si = 0; si < 2; si++) {
        int c = 0, x = tab[head[i]].to;
        for (int j = head[i]; j; j = tab[j].nxt) {
          int t = tab[j].to, e = tab[j].tar;
          c ^= S[i][si][e];
          if (!S[i][si][e]) v[t][S[t][1][e]] ^= 1;
        }
        dp[x][0][0] = dp[x][0][1] = dp[x][1][0] = dp[x][1][1] = 0;
        ++dp[x][0][v[x][0]], ++dp[x][1][v[x][1]];
        int y = sol(x, si ^ 1);
        Ans[c][top[c]] += (dp[y][0][0] + dp[y][1][0]) % mod, top[c] += si,
            Ans[1 ^ c][top[1 ^ c]] += (dp[y][0][1] + dp[y][1][1]) % mod,
            top[c ^ 1] += si;
        for (int j = head[i]; j; j = tab[j].nxt) {
          int t = tab[j].to, e = tab[j].tar;
          if (!S[i][si][e]) v[t][S[t][1][e]] ^= 1;
        }
      }
    }
  ans[0][0] = Ans[0][0], ans[1][0] = Ans[1][0];
  for (int i = 1; i < top[0]; i++)
    ans[0][i] =
        (1ll * ans[0][i - 1] * Ans[0][i] + 1ll * ans[1][i - 1] * Ans[1][i]) %
        mod,
    ans[1][i] =
        (1ll * ans[1][i - 1] * Ans[0][i] + 1ll * ans[0][i - 1] * Ans[1][i]) %
        mod;
  printf("%d\n", ans[1][top[0] - 1]);
}
