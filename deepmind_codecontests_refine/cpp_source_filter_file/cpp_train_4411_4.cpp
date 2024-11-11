#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<pair<int, int> > tt[100111];
int qwerty(int c, int val) {
  if (tt[c].size() == 0) return 0;
  vector<pair<int, int> >::iterator it =
      upper_bound(tt[c].begin(), tt[c].end(), make_pair(val, 1 << 30));
  if (it == tt[c].begin()) return 0;
  --it;
  if (val < it->first + it->second) return it->first + it->second - val;
  return 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<pair<int, int> > > g(n);
  int fr, to, wh;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &fr, &to, &wh);
    g[fr - 1].push_back(make_pair(to - 1, wh));
    g[to - 1].push_back(make_pair(fr - 1, wh));
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    int k, val;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &val);
      if (tt[i].size() == 0)
        tt[i].push_back(make_pair(val, 1));
      else if (tt[i].back().first + tt[i].back().second == val)
        ++tt[i].back().second;
    }
  }
  vector<int> d(n, INF);
  d[s] = 0;
  set<pair<int, int> > q;
  q.insert(make_pair(d[s], s));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (size_t j = 0; j < g[v].size(); ++j) {
      int to = g[v][j].first, len = g[v][j].second + qwerty(v, d[v]);
      if (d[v] + len < d[to]) {
        q.erase(make_pair(d[to], to));
        d[to] = d[v] + len;
        q.insert(make_pair(d[to], to));
      }
    }
  }
  if (d[n - 1] == INF) d[n - 1] = -1;
  printf("%d", d[n - 1]);
}
