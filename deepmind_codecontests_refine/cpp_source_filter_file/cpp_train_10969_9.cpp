#include <bits/stdc++.h>
using namespace std;
void min(int &a, int b) {
  if (a > b) a = b;
}
int dis[202][202];
int n, m;
vector<pair<int, int> > e[202];
void floyd() {
  int i, j, k;
  for (i = 0; i <= n; i++) dis[i][i] = 0;
  while (true) {
    bool bans = false;
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
        for (k = 0; k <= n; k++) {
          if (dis[i][k] > dis[i][j] + dis[j][k]) {
            dis[i][k] = dis[i][j] + dis[j][k];
            bans = true;
          }
        }
    if (!bans) break;
  }
}
bool ok(int d) {
  vector<pair<int, int> > a;
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < e[i].size(); j++) {
      int u = i, v = e[i][j].first, w = e[i][j].second;
      a.clear();
      for (k = 0; k < n; k++) {
        int d1 = d - dis[u][k];
        int d2 = d - dis[v][k];
        if (d1 >= w || d2 >= w) continue;
        if (d1 < 0 && d2 < 0) break;
        if (d1 + d2 >= w - 1)
          continue;
        else
          a.push_back(make_pair(d1 + 1, w - 1 - d2));
      }
      if (k == n) {
        if (a.empty()) return 1;
        sort(a.begin(), a.end());
        int m = 0;
        for (k = 0; k < a.size(); k++) {
          if (m < a[k].first) return 1;
          if (m < a[k].second + 1) m = a[k].second + 1;
        }
      }
    }
  return 0;
}
int main() {
  int i, j, x, y, z;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) dis[i][j] = 1000000000;
  while (m--) {
    scanf("%d%d%d", &x, &y, &z);
    x--, y--, z <<= 1;
    dis[x][y] = dis[y][x] = z;
    e[x].push_back(make_pair(y, z));
    e[y].push_back(make_pair(x, z));
  }
  floyd();
  int l = 0, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  printf("%.2lf\n", (double)ans / 2.0);
  return 0;
}
