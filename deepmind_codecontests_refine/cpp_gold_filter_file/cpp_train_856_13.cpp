#include <bits/stdc++.h>
using namespace std;
const int maxn = 2050;
int n, p[maxn], pos, b[maxn];
int r[maxn], cnt, r1[maxn];
int vis[maxn][maxn];
int a[maxn] = {0, 5, 1, 3, 4, 2, 0};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int query(int x, int y) {
  int ret;
  if (vis[x][y] != -1) return vis[x][y];
  if (vis[y][x] != -1) return vis[y][x];
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &ret);
  if (ret == -1) exit(0);
  vis[x][y] = vis[y][x] = ret;
  return ret;
}
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) r[i] = i;
  cnt = n;
  memset(vis, -1, sizeof(vis));
  while (true) {
    shuffle(r + 1, r + 1 + cnt, rnd);
    for (int i = 1; i <= cnt; i++) r1[i] = r[i];
    int tmp = (1 << 30) - 1;
    for (int i = 2; i <= min(cnt, 5); i++) tmp = tmp & query(r1[1], r1[i]);
    if (__builtin_popcount(tmp) > 5) continue;
    vector<pair<int, int> > v;
    for (int i = 2; i <= cnt; i++) {
      int q = query(r1[1], r1[i]);
      v.push_back({q, r1[i]});
    }
    int cnt1 = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      if (i == 0)
        r[++cnt1] = v[i].second;
      else if (v[i].first == v[i - 1].first)
        r[++cnt1] = v[i].second;
      else
        break;
    }
    r[++cnt1] = r1[1];
    cnt = cnt1;
    if (cnt == 1) {
      pos = r[1];
      break;
    }
    if (cnt == 2) {
      for (int i = 1; i <= n; i++) b[i] = i;
      shuffle(b + 1, b + 1 + n, rnd);
      int num = (1 << 30) - 1;
      for (int i = 1; i <= min(n, 10); i++) {
        if (r[1] == b[i]) continue;
        int q = query(r[1], b[i]);
        num = num & q;
      }
      if (num == 0)
        pos = r[1];
      else
        pos = r[2];
      break;
    }
  }
  p[pos] = 0;
  for (int i = 1; i <= n; i++) {
    if (i == pos) continue;
    p[i] = query(i, pos);
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", p[i]);
  fflush(stdout);
}
