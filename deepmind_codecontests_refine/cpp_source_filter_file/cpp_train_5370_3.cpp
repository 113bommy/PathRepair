#include <bits/stdc++.h>
using namespace std;
long long n, rd[2010][2010], st, Min = 1e18, dis[2010];
signed main() {
  cin >> n;
  for (long long i = 1; i < n; i++)
    for (long long j = i + 1; j <= n; j++) {
      scanf("%lld", &rd[i][j]);
      rd[j][i] = rd[i][j];
      if (rd[i][j] <= Min) Min = rd[i][j], st = i;
    }
  for (long long i = 1; i < n; i++)
    for (long long j = i + 1; j <= n; j++) rd[i][j] = rd[j][i] = rd[i][j] - Min;
  for (long long i = 1; i <= n; i++) dis[i] = 1e18;
  for (long long i = 1; i <= n; i++) {
    dis[i] = rd[st][i];
    for (long long j = 1; j <= n; j++)
      if (i != j) dis[i] = min(dis[i], rd[i][j] * 2);
  }
  long long vis[2010];
  memset(vis, 0, sizeof(vis));
  vis[st] = 1;
  for (long long i = 1; i < n; i++) {
    long long x, tmp = 1e18;
    for (long long j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < tmp) x = j, tmp = dis[j];
    vis[x] = 1;
    for (long long j = 1; j <= n; j++)
      if (!vis[j]) dis[j] = min(dis[j], dis[i] + rd[i][j]);
  }
  for (long long i = 1; i <= n; i++) printf("%lld\n", dis[i] + (n - 1) * Min);
  return 0;
}
