#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 9;
long long n, m;
vector<pair<long long, long long>> v[N];
vector<pair<pair<long long, long long>, long long>> e, ans;
set<pair<pair<long long, long long>, long long>> s;
long long dis[N], cost[N];
map<pair<long long, long long>, long long> pth;
void dij() {
  fill(dis, dis + N, 1e8);
  fill(cost, cost + N, 1e8);
  dis[0] = cost[0] = 0;
  s.insert({{0, 0}, 0});
  while (s.size()) {
    auto tp = *s.begin();
    s.erase(tp);
    long long id = tp.second;
    for (auto it : v[id]) {
      if (make_pair(dis[id] + 1, cost[id] + it.second) <
          make_pair(dis[it.first], cost[it.first])) {
        s.erase({{dis[it.first], cost[it.first]}, it.first});
        dis[it.first] = dis[id] + 1;
        cost[it.first] = cost[id] + it.second;
        s.insert({{dis[it.first], cost[it.first]}, it.first});
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < (m); i++) {
    long long u, w, g;
    cin >> u >> w >> g;
    u--;
    w--;
    g ^= 1;
    v[u].push_back({w, g});
    v[w].push_back({u, g});
    e.push_back({{u, w}, g});
  }
  dij();
  long long u = n - 1;
  while (u) {
    for (auto it : v[u])
      if (dis[it.first] == dis[u] - 1 &&
          cost[it.first] == cost[u] - it.second) {
        pth[{u, it.first}] = pth[{it.first, u}] = 1;
        u = it.first;
        break;
      }
  }
  for (auto it : e) {
    if (pth[{it.first.first, it.first.second}]) {
      if (it.second)
        ans.push_back({{it.first.first, it.first.second}, it.second});
    } else {
      if (!it.second)
        ans.push_back({{it.first.first, it.first.second}, it.second});
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans)
    cout << it.first.first + 1 << ' ' << it.first.second + 1 << ' ' << it.second
         << endl;
}
