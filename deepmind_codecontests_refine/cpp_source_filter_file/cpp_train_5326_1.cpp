#include <bits/stdc++.h>
using namespace std;
const int N = 150007;
int n, m, mx, tot;
int f[N], p[N], deg[N], len[N], sum[N], dep[N], cnt[N][27], dp[N][27], ch[N][2];
char c[N];
inline void update(int x, char y, int v) {
  if (y == '?') return;
  y = y - 'a' + 1;
  x = p[x];
  cnt[x][y] += v;
  for (x = p[x]; x; x = p[f[x]]) {
    int vv = max(dp[ch[x][0]][y] + cnt[ch[x][0]][y],
                 dp[ch[x][1]][y] + cnt[ch[x][1]][y]);
    if (dp[x][y] != vv) {
      int lst = sum[x];
      sum[x] -= vv - dp[x][y];
      dp[x][y] = vv;
      if (lst < 0 && sum[x] >= 0)
        --tot;
      else if (lst >= 0 && sum[x] < 0)
        ++tot;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  ++deg[1];
  p[1] = 1;
  for (int i = 2; i <= n; ++i)
    scanf("%d %c", &f[i], &c[i]), ++deg[f[i]], dep[i] = dep[f[i]] + 1,
                                               mx = max(mx, dep[i]);
  sum[1] = len[1] = mx;
  int flag = 1;
  for (int i = 2; i <= n; ++i)
    if (!deg[i] && deg[i] != mx) flag = 0;
  if (!flag) {
    for (int i = 1; i <= m; ++i) puts("Fou");
    return 0;
  }
  for (int i = 2; i <= n; ++i) sum[i] = len[i] = n;
  for (int i = 2; i <= n; ++i)
    p[i] = deg[f[i]] > 1 ? i : p[f[i]],
    sum[p[i]] = len[p[i]] = min(sum[p[i]], mx - dep[i]);
  for (int i = 2; i <= n; ++i)
    if (p[i] == i) ch[p[f[i]]][ch[p[f[i]]][0] ? 1 : 0] = i;
  for (int i = 2; i <= n; ++i) update(i, c[i], 1);
  for (int i = 1; i <= m; ++i) {
    int x;
    char ch, lst;
    scanf("%d %c", &x, &ch);
    lst = c[x];
    c[x] = ch;
    update(x, lst, -1);
    update(x, ch, 1);
    if (tot)
      puts("Fou");
    else {
      printf("Shi ");
      int ans = 0, sum = 0;
      for (int i = 1; i <= 26; ++i) sum += dp[1][i];
      for (int i = 1; i <= 26; ++i) ans += i * (dp[1][i] + mx - sum);
      printf("%d\n", ans);
    }
  }
  return 0;
}
