#include <bits/stdc++.h>
using namespace std;
struct cell {
  int x, y, cost;
  cell(int i, int j, int k) {
    x = i;
    y = j;
    cost = k;
  }
};
int main() {
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);
  s--;
  int t1, t2, t3;
  vector<vector<pair<int, int> > > g(n);
  vector<int> qq(m), w(m), e(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &t1, &t2, &t3);
    t1--;
    t2--;
    qq[i] = t1;
    w[i] = t2;
    e[i] = t3;
    g[t1].push_back(make_pair(t2, t3));
    g[t2].push_back(make_pair(t1, t3));
  }
  int l;
  scanf("%d", &l);
  vector<int> d(n, 10000000);
  d[s] = 0;
  queue<int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (unsigned int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first, len = g[v][i].second;
      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        q.push(to);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] == l) ans++;
  for (int i = 0; i < m; ++i) {
    int x = qq[i], y = w[i], z = e[i];
    int k1 = l - d[x];
    if (k1 > 0 && k1 != z) {
      int res = min(d[x] + k1, z - k1 + d[y]);
      if (res == l) ans++;
    }
    int k2 = l - d[y];
    if (k2 > 0 && k2 != z - k1 && k2 != z) {
      int res = min(d[y] + k2, z - k2 + d[x]);
      if (res == l) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
