#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
bitset<maxn> dp;
int to[maxn], vis[maxn], cnt, m, num[maxn], tot[maxn], mini, maxi, n, ji;
int is[maxn];
void dfs(int p, int fa) {
  int x = to[p];
  if (x == fa)
    return;
  else {
    vis[x] = 1;
    num[cnt]++;
    dfs(x, fa);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &to[i]);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      cnt++;
      num[cnt] = 1;
      vis[i] = 1;
      dfs(i, i);
    }
  int k = 0;
  for (int i = 1; i <= cnt; i++) {
    k += num[i] / 2;
    if (num[i] & 1) ji++;
  }
  if (k >= m)
    maxi = m * 2;
  else
    maxi = k * 2 + min(ji, m - k);
  dp[0] = 1;
  for (int i = 1; i <= cnt; i++)
    if (num[i] >= 100)
      dp |= dp << num[i];
    else
      tot[num[i]]++;
  for (int i = 2; i < 3; i++) {
    for (int j = 0; j < i; j++) is[j] = -100;
    for (int j = 0; j <= m; j++) {
      int h = j % i;
      if (dp[j]) is[h] = j;
      if (!dp[j] && is[h] >= 0 && (j - is[h]) / i <= tot[i]) dp[j] = 1;
    }
  }
  if (dp[m])
    mini = m;
  else
    mini = m + 1;
  printf("%d %d\n", mini, maxi);
  return 0;
}
