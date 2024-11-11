#include <bits/stdc++.h>
using namespace std;
long long n, m, st, dis[300005], used[300005], v1[300005], g[300005], null;
vector<pair<long long, pair<long long, long long> > > edge[300005];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    q;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long x, y, d;
    cin >> x >> y >> d;
    edge[x].push_back(make_pair(y, make_pair(d, i + 1)));
    edge[y].push_back(make_pair(x, make_pair(d, i + 1)));
  }
  cin >> st;
  q.push(make_pair(null, st));
  for (int i = 1; i <= n; i++) dis[i] = 300000000000007, g[i] = 300000000000007;
  dis[st] = 0;
  while (!q.empty()) {
    long long v, t;
    v = q.top().second;
    t = q.top().first;
    q.pop();
    for (int i = 0; i < edge[v].size(); i++) {
      long long u = edge[v][i].first, d = edge[v][i].second.first;
      if (dis[u] > dis[v] + d) {
        dis[u] = dis[v] + d;
        q.push(make_pair(dis[u], u));
        g[u] = d;
        v1[u] = edge[v][i].second.second;
      } else if (dis[u] == dis[v] + d)
        if (g[u] > d) g[u] = d, v1[u] = edge[v][i].second.second;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i != st) ans += g[i];
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    if (i != st) cout << v1[i] << " ";
  }
  cout << endl;
  return 0;
}
