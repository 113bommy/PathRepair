#include <bits/stdc++.h>
using namespace std;
const int N = 100 * 1000 + 10, second = 250, SS = second + 10;
bool mark[N];
vector<int> graph[N];
vector<pair<int, int> > q[N];
set<pair<int, int> > st1[N];
set<pair<int, int>, greater<pair<int, int> > > st2[N];
vector<int> mp[N];
int a[N], ans[N];
void calc(int v) {
  sort((q[v]).begin(), (q[v]).end(), greater<pair<int, int> >());
  int i = 0, t = 0;
  auto it = st2[v].begin();
  while (i < ((int)(q[v]).size())) {
    int p = q[v][i].first, ind = q[v][i].second;
    if (p < second) break;
    for (; it != st2[v].end(); it++) {
      if (it->first < p) break;
      t++;
    }
    ans[ind] = t;
    i++;
  }
  if (i == ((int)(q[v]).size())) return;
  for (; it != st2[v].end(); it++) {
    if (it->second < second) break;
    t++;
  }
  int last = second;
  while (i < ((int)(q[v]).size())) {
    int p = q[v][i].first, ind = q[v][i].second;
    for (int i = (p); i <= (last - 1); i++) t += mp[v][i];
    ans[ind] = t;
    last = p;
    i++;
  }
}
void merge(int v, int u) {
  if (((int)(st1[v]).size()) < ((int)(st1[u]).size())) {
    st1[v].swap(st1[u]);
    st2[v].swap(st2[u]);
    mp[v].swap(mp[u]);
  }
  for (pair<int, int> x : st1[u]) {
    int tt = 0;
    auto srch = st1[v].lower_bound({x.first, 0});
    if (srch != st1[v].end() && srch->first == x.first) {
      tt = srch->second;
      st1[v].erase({x.first, tt});
      st2[v].erase({tt, x.first});
      if (tt < second) mp[v][tt]--;
    }
    tt += x.second;
    st1[v].insert({x.first, tt});
    st2[v].insert({tt, x.first});
    if (tt < second) mp[v][tt]++;
  }
}
void dfs(int v) {
  mark[v] = true;
  st1[v].insert({a[v], 1});
  st2[v].insert({1, a[v]});
  if (1 < second) mp[v][1]++;
  for (int u : graph[v])
    if (!mark[u]) {
      dfs(u);
      merge(v, u);
    }
  calc(v);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = (0); i <= (n - 1); i++) cin >> a[i];
  for (int i = (0); i <= (n - 2); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = (0); i <= (m - 1); i++) {
    int v, k;
    cin >> v >> k;
    v--;
    q[v].push_back({k, i});
  }
  for (int i = (0); i <= (n - 1); i++) mp[i].resize(SS - 1);
  dfs(0);
  for (int i = (0); i <= (m - 1); i++) cout << ans[i] << '\n';
  return 0;
}
