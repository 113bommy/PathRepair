#include <bits/stdc++.h>
using namespace std;
int n, a[2005][2005];
namespace p1 {
int b[20][20], sz[1 << 6], low[20], dfn[20], tot, cs, fc[10];
void dfs(int x) {
  low[x] = dfn[x] = ++tot;
  for (int i = 1; i <= n; ++i)
    if (b[x][i] && i != x) {
      if (!dfn[i])
        dfs(i), low[x] = min(low[x], low[i]);
      else
        low[x] = min(low[x], dfn[i]);
    }
  if (low[x] == dfn[x]) ++cs;
}
void solve() {
  int len = 1 << n, ans1 = 1e9, ans2 = 0;
  fc[0] = fc[1] = 1;
  for (int i = 2; i <= n; ++i) fc[i] = fc[i - 1] * i;
  for (int i = 0; i < len; ++i) {
    sz[i] = sz[i >> 1] + (i & 1);
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k) b[j][k] = a[j][k];
    for (int j = 0; j < n; ++j)
      if ((1 << j) & i) {
        for (int k = 1; k <= n; ++k) b[j + 1][k] ^= 1, b[k][j + 1] ^= 1;
      }
    for (int j = 1; j <= n; ++j) low[j] = dfn[j] = 0;
    tot = 0;
    cs = 0;
    dfs(1);
    if (cs == 1 && tot == n) {
      if (sz[i] < ans1)
        ans1 = sz[i], ans2 = fc[sz[i]];
      else if (sz[i] == ans1)
        ans2 += fc[sz[i]];
    }
  }
  if (ans2 == 0)
    puts("-1");
  else
    printf("%d %d\n", ans1, ans2);
}
}  // namespace p1
namespace p2 {
int deg[2005], sk[2005];
bool cmp(int x, int y) { return deg[x] < deg[y]; }
bool check() {
  for (int i = 1; i <= n; ++i) sk[i] = i;
  sort(sk + 1, sk + n + 1, cmp);
  for (int i = 1, ans = 0; i < n; ++i) {
    ans += deg[sk[i]];
    if (ans == 1ll * i * (i - 1) / 2) return 0;
  }
  return 1;
}
void solve() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) deg[i] += a[i][j];
  if (check())
    puts("0 1");
  else {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i][j])
          deg[i]--, deg[j]++;
        else
          deg[i]++, deg[j]--;
      }
      ans += check();
      for (int j = 1; j <= n; ++j) {
        if (a[i][j])
          deg[i]++, deg[j]--;
        else
          deg[i]--, deg[j]++;
      }
    }
    printf("1 %d\n", ans);
  }
}
}  // namespace p2
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%1d", &a[i][j]);
  if (n <= 6)
    p1::solve();
  else
    p2::solve();
}
