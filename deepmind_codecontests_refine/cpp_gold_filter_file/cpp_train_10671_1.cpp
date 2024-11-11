#include <bits/stdc++.h>
using namespace std;
const int N = 40 * 1000 + 5;
int par[N], dis[N], mark[N];
vector<int> edj[N], ans;
vector<pair<int, int> > e;
map<pair<int, int>, int> cn;
int n, m, k, x, y, z, u, v;
set<int> cnt[N];
queue<pair<int, int> > q;
set<pair<int, int> > mys;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    edj[x].push_back(y);
    edj[y].push_back(x);
    e.push_back({x, y});
    e.push_back({y, x});
    cn[{x, y}] = i * 2;
    cn[{y, x}] = i * 2 + 1;
  }
  edj[n].push_back(n + 1);
  e.push_back({n, n + 1});
  cn[{n, n + 1}] = 2 * m;
  for (int i = 0; i < k; i++) {
    cin >> x >> y >> z;
    cnt[cn[{x, y}]].insert(z);
  }
  fill(dis, dis + 2 * m + 1, INT_MAX / 2);
  fill(par, par + 2 * m + 1, -1);
  for (auto u : edj[1]) {
    dis[cn[{1, u}]] = 1;
  }
  for (int i = 0; i <= 2 * m; i++) {
    mys.insert({dis[i], i});
  }
  for (int i = 0; i < m * 2 + 1; i++) {
    int have = mys.begin()->second;
    mys.erase(mys.begin());
    mark[have] = true;
    int v = e[have].first, u = e[have].second;
    for (auto z : edj[u]) {
      if (!mark[cn[{u, z}]] and cnt[have].find(z) == cnt[have].end() and
          dis[cn[{u, z}]] > dis[have] + 1) {
        mys.erase({dis[cn[{u, z}]], cn[{u, z}]});
        dis[cn[{u, z}]] = dis[have] + 1;
        mys.insert({dis[cn[{u, z}]], cn[{u, z}]});
        par[cn[{u, z}]] = have;
      }
    }
  }
  if (dis[cn[{n, n + 1}]] == INT_MAX / 2) {
    cout << -1 << "\n";
    return 0;
  }
  cout << dis[cn[{n, n + 1}]] - 1 << "\n";
  u = 2 * m;
  while (u != -1) {
    ans.push_back(e[u].first);
    u = par[u];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
