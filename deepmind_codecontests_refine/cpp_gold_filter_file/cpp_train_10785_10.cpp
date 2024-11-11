#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const int maxn = 2010;
long long pos[maxn], key[maxn];
long long dp[maxn][maxn];
int main() {
  int n, k, p;
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; i++) scanf("%I64d", &pos[i]);
  for (int i = 1; i <= k; i++) scanf("%I64d", &key[i]);
  sort(pos + 1, pos + 1 + n);
  sort(key + 1, key + 1 + k);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= k; j++)
      dp[i][j] = max(dp[i - 1][j - 1], abs(pos[i] - key[j]) + abs(key[j] - p));
  long long ans = inf;
  for (int i = n; i <= k; i++) ans = min(ans, dp[n][i]);
  printf("%I64d\n", ans);
  return 0;
}
