#include <bits/stdc++.h>
const int N = 21;
const long long INF = 0x3f3f3f3fLL;
int n, m;
long long dist[N][N];
int deg[N], on[N], onp = 0;
long long ans = INF, tans = 0;
bool vis[N];
void init() {
  memset(dist, 0x3f, sizeof(dist));
  memset(deg, 0, sizeof(deg));
  memset(vis, 0, sizeof(vis));
}
bool floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  for (int i = 2; i <= n; i++)
    if (deg[i] && dist[1][i] >= INF) return false;
  return true;
}
void solve(int x) {
  if (x > onp) return (void)(ans = std::min(ans, tans));
  if (vis[x]) return (void)(solve(x + 1));
  vis[x] = true;
  for (int i = 1; i <= onp; i++)
    if (i != x && !vis[i]) {
      tans += dist[on[x]][on[i]];
      vis[i] = true;
      solve(x + 1);
      tans -= dist[on[x]][on[i]];
      vis[i] = false;
    }
  vis[x] = false;
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) dist[i][i] = 0;
  long long wsum = 0;
  while (m--) {
    int a, b;
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    if (dist[a][b] > c) dist[a][b] = dist[b][a] = c;
    deg[a]++;
    deg[b]++;
    wsum += c;
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] & 1) on[++onp] = i;
  if (!floyd()) return printf("-1\n"), 0;
  solve(1);
  ans += wsum;
  printf("%lld\n", ans);
  return 0;
}
