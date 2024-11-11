#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int N = 205;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int vis[N][N], n;
int dis[N][N], cnt[N];
pair<int, int> q[N * N];
long long T;
int main() {
  scanf("%lld%d", &T, &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x + 100][y + 100] = 1;
  }
  int h = 0, t = 1;
  cnt[1] = 1;
  q[1] = pair<int, int>(100, 100);
  vis[100][100] = 1;
  while (h != t) {
    int x = q[++h].first, y = q[h].second;
    if (dis[x][y] == min(40ll, T)) continue;
    for (int d = (int)(0); d <= (int)(7); d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      dis[nx][ny] = dis[x][y] + 1;
      ++cnt[dis[nx][ny]];
      q[++t] = pair<int, int>(nx, ny);
    }
  }
  int ans = t;
  if (T > 40) {
    int delta = cnt[40] - cnt[39];
    ans = (ans + 1ll * (cnt[40] + cnt[40] + 1ll * (T - 39) % mo * delta) *
                     ((T - 39) % mo) % mo * (mo + 1) / 2 % mo) %
          mo;
  }
  printf("%d\n", ans);
}
