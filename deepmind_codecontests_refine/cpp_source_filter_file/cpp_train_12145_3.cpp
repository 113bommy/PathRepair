#include <bits/stdc++.h>
using namespace std;
int seq[1000006], sum[1000006], cnt[1000006];
int n, k, p;
bool lis() {
  static int app[1000006];
  memset(app, 0x3f, sizeof(app));
  for (int i = 1; i < n; i++) *upper_bound(app, app + n + 1, sum[i]) = sum[i];
  if (app[k - 1] <= sum[n])
    return true;
  else
    return false;
}
int dp() {
  static int f[202][40004], g[202][202];
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  f[0][0] = 0;
  g[0][0] = 0;
  for (int j = 1; j <= n; j++)
    for (int i = k; i >= 1; i--) {
      for (int t = 0; t < p; t++)
        f[i][j] = min(f[i][j], g[i - 1][t] + (sum[j] - t + p) % p);
      g[i][sum[j]] = min(g[i][sum[j]], f[i][j]);
    }
  return f[k][n];
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &seq[i]);
  for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + seq[i]) % p;
  for (int i = 1; i <= n; i++) cnt[sum[i]]++;
  int max_cnt = 0;
  for (int i = 0; i < p; i++) max_cnt = max(max_cnt, cnt[i]);
  if (lis())
    printf("%d\n", sum[n]);
  else if (max_cnt >= k)
    printf("%d\n", sum[n] + p);
  else
    printf("%d\n", dp());
  return 0;
}
