#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, int> > q;
vector<pair<long long, pair<int, int> > > E;
vector<pair<int, int> > e[120000];
int n, m, x, y, k, z, fa[120000], i, be[120000], flag[120000];
long long dis[120000], ans;
int get(int x) { return fa[x] == x ? x : (fa[x] = get(fa[x])); }
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &k);
    e[x].push_back(make_pair(y, k));
    e[y].push_back(make_pair(x, k));
  }
  memset(dis, 3, sizeof(dis));
  scanf("%d", &k);
  for (i = 1; i <= k; ++i) {
    scanf("%d", &x);
    dis[x] = 0;
    fa[x] = x;
    q.push(make_pair(0, x));
    be[x] = x;
  }
  while (!q.empty()) {
    x = q.top().second;
    q.pop();
    if (flag[x]) continue;
    flag[x] = 1;
    for (i = 0; i < e[x].size(); ++i) {
      y = e[x][i].first;
      z = e[x][i].second;
      if (be[y])
        E.push_back(make_pair(dis[x] + dis[y] + z, make_pair(be[x], be[y])));
      if (dis[x] + z < dis[y]) {
        dis[y] = dis[x] + z;
        be[y] = be[x];
        q.push(make_pair(-dis[y], y));
      }
    }
  }
  sort(E.begin(), E.end());
  for (i = 0; i < E.size(); ++i) {
    x = E[i].second.first;
    y = E[i].second.second;
    if (get(x) != get(y)) {
      ans += E[i].first;
      fa[get(x)] = get(y);
    }
  }
  printf("%I64d\n", ans + dis[1]);
}
