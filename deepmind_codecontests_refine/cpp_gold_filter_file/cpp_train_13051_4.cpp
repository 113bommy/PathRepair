#include <bits/stdc++.h>
using namespace std;
int p, tot = 0, tp = 0, ans = 0, dp[4000010];
long long l, r, lis[4000010], pri[100];
bool yes[4000010];
void dfs(int k, long long now) {
  lis[++tot] = now;
  for (int i = k; i <= tp; i++) {
    if (pri[i] * now > r) return;
    dfs(i, now * pri[i]);
  }
}
void prepare() {
  for (long long i = 2; i <= p; i++) {
    bool bo = 1;
    for (int j = 2; j <= sqrt(i); j++)
      if (i % j == 0) {
        bo = 0;
        break;
      }
    if (bo) pri[++tp] = i;
  }
  dfs(1, 1);
  sort(lis + 1, lis + tot + 1);
}
int main() {
  memset(dp, 0x3f, sizeof(dp));
  scanf("%I64d%I64d%I64d", &l, &r, &p);
  prepare();
  dp[1] = 0;
  for (int i = 2; i <= p; i++) {
    int k = 1;
    for (int j = 1; j <= tot; j++) {
      while (k <= tot && lis[k] != lis[j] * i) k++;
      if (k > tot) break;
      dp[k] = min(dp[k], dp[j] + 1);
      if (lis[k] >= l && dp[k] + i <= p) yes[k] = 1;
    }
  }
  for (int i = 1; i <= tot; i++)
    if (yes[i]) ans++;
  printf("%d", ans);
  return 0;
}
