#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > g;
int n, m;
set<pair<int, int> > st;
set<pair<int, int> >::iterator it;
vector<int> dis;
vector<bool> used;
map<pair<int, int>, bool> mp;
int INF;
int main() {
  INF = 2147483646;
  scanf("%d%d", &n, &m);
  g.resize(n + 1);
  dis.resize(n + 1, 0);
  used.resize(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    g[a].push_back(make_pair(b, d));
    g[b].push_back(make_pair(a, d));
  }
  for (int i = 1; i <= n; i++) {
    int A;
    scanf("%d", &A);
    for (int j = 0; j < A; j++) {
      int B;
      scanf("%d", &B);
      mp[make_pair(i, B)] = 1;
    }
  }
  int s = 1;
  int f = n;
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[s] = 0;
  st.insert(make_pair(0, s));
  while (s != f) {
    if (mp[make_pair(s, dis[s])]) dis[s]++;
    used[s] = 1;
    for (int i = 0; i < g[s].size(); i++) {
      if (used[g[s][i].first] || dis[g[s][i].first] <= dis[s] + g[s][i].second)
        continue;
      dis[g[s][i].first] = dis[s] + g[s][i].second;
      st.insert(make_pair(dis[g[s][i].first], g[s][i].first));
    }
    it = st.begin();
    while (used[it->second] && !st.empty()) {
      st.erase(st.begin());
      it = st.begin();
    }
    if (st.empty()) break;
    s = it->second;
  }
  if (dis[f] == INF)
    cout << -1;
  else
    cout << dis[f];
  return 0;
}
