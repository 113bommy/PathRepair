#include <bits/stdc++.h>
using namespace std;
const int n_max = 100005;
int n, m, i, j, k, x, y, f[n_max];
vector<int> g[n_max];
vector<pair<int, pair<int, int> > > ans;
bool go(int u, int p) {
  f[u] = 1;
  int i, to, h = 0, e, x;
  for (i = 0; i < g[u].size(); i++) {
    to = g[u][i];
    if (to == p || f[to] == 2) continue;
    if (f[to]) {
      if (h)
        ans.push_back(make_pair(x, make_pair(u, to)));
      else
        x = to;
      h ^= 1;
      continue;
    }
    e = go(to, u);
    if (e) {
      if (h)
        ans.push_back(make_pair(x, make_pair(u, to)));
      else
        x = to;
      h ^= 1;
    }
  }
  if (h) {
    ans.push_back(make_pair(x, make_pair(u, p)));
    h = 0;
  } else
    h = 1;
  f[u] = 2;
  return h;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (m & 1) {
    cout << "No solution" << endl;
    return 0;
  }
  if (!go(1, -1)) {
    cout << "No solution" << endl;
    return 0;
  }
  for (i = 0; i < ans.size(); i++)
    printf("%d %d %d\n", ans[i].first, ans[i].second.first,
           ans[i].second.second);
}
