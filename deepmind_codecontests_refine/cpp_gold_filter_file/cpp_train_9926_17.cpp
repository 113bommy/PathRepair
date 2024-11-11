#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
const long long INF = 1e15;
long long dis[N];
int par[N], pard[N], n, m, k;
vector<int> ptl;
vector<pair<int, long long> > adj[N];
vector<pair<pair<int, int>, long long> > yal;
vector<pair<long long, pair<int, int> > > nyal;
void DJK() {
  set<pair<long long, int> > s;
  for (auto u : ptl) {
    dis[u] = 0;
    par[u] = u;
    s.insert(make_pair(0, u));
  }
  while (!s.empty()) {
    auto x = *s.begin();
    s.erase(x);
    int v = x.second;
    for (auto u : adj[v]) {
      if (dis[v] + u.second < dis[u.first]) {
        s.erase(make_pair(dis[u.first], u.first));
        dis[u.first] = dis[v] + u.second;
        par[u.first] = par[v];
        s.insert(make_pair(dis[u.first], u.first));
      }
    }
  }
  return;
}
int find_par(int a) {
  if (pard[a] == a) return a;
  pard[a] = find_par(pard[a]);
  return pard[a];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0, u, v, val; i < m; i++) {
    cin >> u >> v >> val;
    adj[u].push_back(make_pair(v, val));
    adj[v].push_back(make_pair(u, val));
    yal.push_back(make_pair(make_pair(u, v), val));
  }
  cin >> k;
  for (int i = 0, tmp; i < k; i++) {
    cin >> tmp;
    ptl.push_back(tmp);
  }
  for (int i = 0; i < N; i++) dis[i] = INF, pard[i] = i;
  DJK();
  for (int i = 0; i < m; i++) {
    int u = yal[i].first.first, v = yal[i].first.second, val = yal[i].second;
    long long tmp = dis[u] + dis[v] + val;
    if (par[u] == par[v]) continue;
    nyal.push_back(make_pair(tmp, make_pair(par[u], par[v])));
  }
  sort(nyal.begin(), nyal.end());
  long long ans = dis[1];
  for (auto x : nyal) {
    int u = x.second.first, v = x.second.second;
    long long val = x.first;
    int pu = find_par(u), pv = find_par(v);
    if (pu == pv) continue;
    pard[pu] = pv;
    ans += val;
  }
  cout << ans << '\n';
  return 0;
}
