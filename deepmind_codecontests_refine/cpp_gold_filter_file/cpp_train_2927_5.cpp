#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1505;
struct node {
  int l, r;
} sv[MAXN];
int n, s, m, k;
int Hash[MAXN], tot = 0;
int a[MAXN], b[MAXN], dp[MAXN][MAXN], tail[MAXN], sum[MAXN];
int getid(int x) {
  int pos = lower_bound(Hash + 1, Hash + 1 + tot, x) - Hash;
  return pos;
}
bool judge(int x) {
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (b[i] <= x);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) dp[i][j] = dp[i - 1][j];
    for (int j = 1; j <= n; j++)
      dp[i][tail[j]] =
          max(dp[i][tail[j]], dp[i - 1][j - 1] + sum[tail[j]] - sum[j - 1]);
    for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
  }
  return dp[m][n] >= k;
}
int main() {
  scanf("%d%d%d%d", &n, &s, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= s; i++) {
    scanf("%d%d", &sv[i].l, &sv[i].r);
    for (int j = sv[i].l; j <= sv[i].r; j++) tail[j] = max(tail[j], sv[i].r);
  }
  for (int i = 1; i <= n; i++) Hash[++tot] = a[i];
  sort(Hash + 1, Hash + 1 + n);
  tot = unique(Hash + 1, Hash + 1 + n) - Hash - 1;
  for (int i = 1; i <= n; i++) b[i] = getid(a[i]);
  int l = 1, r = tot, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (judge(mid)) {
      r = mid - 1;
      ans = Hash[mid];
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
