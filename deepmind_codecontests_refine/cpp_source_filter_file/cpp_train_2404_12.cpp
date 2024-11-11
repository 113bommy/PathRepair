#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k;
long long a[25][25], ans = 0;
map<long long, int> mp[25][25];
void dfs1(int x, int y, long long sum) {
  if (x + y == (m + n + 2) / 2) {
    mp[x][y][sum]++;
    return;
  }
  if (x < n) dfs1(x + 1, y, sum ^ a[x + 1][y]);
  if (y < m) dfs1(x, y + 1, sum ^ a[x][y + 1]);
}
void dfs2(int x, int y, long long sum) {
  if (x + y == (m + n + 2) / 2) {
    ans += mp[x][y][sum ^ k ^ a[x][y]];
    return;
  }
  if (x > 1) dfs2(x - 1, y, sum ^ a[x - 1][y]);
  if (y > 1) dfs2(x, y - 1, sum ^ a[x][y - 1]);
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
  dfs1(1, 1, a[1][1]);
  dfs2(n, m, a[n][m]);
  printf("%d\n", ans);
  return 0;
}
