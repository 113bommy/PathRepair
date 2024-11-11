#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 20;
const int N5 = 300 * 1000 + 10;
const int N3 = 3000 + 20;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = LLONG_MAX / 10;
long long par[N], dis[N], rnk[N];
vector<pair<long long, long long> > e[N];
vector<pair<long long, pair<long long, long long> > > edj;
set<pair<long long, long long> > mys;
int find_root(int v) {
  if (par[v] == v) {
    return v;
  }
  return par[v] = find_root(par[v]);
}
void _merge(int a, int b) {
  int r_a = find_root(a);
  int r_b = find_root(b);
  if (rnk[r_a] > rnk[r_b]) {
    swap(r_a, r_b);
  }
  par[r_a] = r_b;
  if (rnk[r_a] == rnk[r_b]) {
    rnk[r_b]++;
  }
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    e[x].push_back({y, w});
    e[y].push_back({x, w});
    edj.push_back({w, {x, y}});
  }
  int k;
  cin >> k;
  fill(dis, dis + n + 1, inf);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    par[x] = x;
    dis[x] = 0;
  }
  for (int i = 1; i <= n; i++) {
    mys.insert({dis[i], i});
  }
  for (int i = 0; i < n; i++) {
    int v = mys.begin()->second;
    mys.erase(mys.begin());
    for (auto [u, a] : e[v]) {
      if (dis[v] + a < dis[u]) {
        mys.erase({dis[u], u});
        dis[u] = dis[v] + a;
        mys.insert({dis[u], u});
        par[u] = par[v];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    edj[i].first += dis[edj[i].second.first] + dis[edj[i].second.second];
  }
  long long ans = 0;
  sort(edj.begin(), edj.end());
  for (int i = 0; i < m; i++) {
    if (find_root(edj[i].second.first) != find_root(edj[i].second.second)) {
      _merge(edj[i].second.first, edj[i].second.second);
      ans += edj[i].first;
    }
  }
  cout << ans + dis[1] << "\n";
}
