#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
const int maxn = 1010;
int n, vis[10], ans, a[maxn], nex[maxn][maxn], dp[maxn][maxn];
void init() {
  memset(vis, 0, sizeof(vis));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 1; i <= n; i++) {
    int k = 1, j = i;
    nex[i][k++] = i;
    if (vis[a[i]] == 0) {
      ans++;
      vis[a[i]] = 1;
    }
    while (++j <= n) {
      if (a[j] == a[i]) nex[i][k++] = j;
    }
  }
}
int dfs(int pos, int s, int l) {
  if (dp[pos][s] != -1) return dp[pos][s];
  if (s == 0) return dp[pos][s] = 0;
  int nn = -INF;
  if (pos > n) return dp[pos][s] = nn;
  nn = max(nn, dfs(pos + 1, s, l));
  if ((1 << a[pos]) & s) {
    if (nex[pos][l])
      nn = max(nn, dfs(nex[pos][l] + 1, s ^ (1 << a[pos]), l) + l);
    if (nex[pos][l + 1])
      nn = max(nn, dfs(nex[pos][l + 1] + 1, s ^ (1 << a[pos]), l) + l + 1);
  }
  return dp[pos][s] = nn;
}
bool check(int l) {
  memset(dp, -1, sizeof(dp));
  dfs(1, (1 << 8) - 1, l);
  return dp[1][(1 << 8) - 1] > 0;
}
void sov() {
  int left = 0, right = n;
  while (left < right) {
    int mid = (left + right + 1) >> 1;
    if (check(mid)) {
      left = mid;
      ans = max(ans, dp[1][(1 << 8) - 1]);
    } else
      right = mid - 1;
  }
  printf("%d\n", ans);
}
int main() {
  init();
  sov();
}
