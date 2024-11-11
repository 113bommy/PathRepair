#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int64_t n, m, d[N], c, u, w;
vector<pair<int, int64_t> > v[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c >> u >> w;
    v[u].push_back(make_pair(c, 2 * w));
    v[c].push_back(make_pair(u, 2 * w));
  }
  set<pair<int64_t, int> > q;
  for (int i = 1; i <= n; i++)
    scanf("%I64d", &d[i]), q.insert(make_pair(d[i], i));
  while (q.size()) {
    int sd = q.begin()->first, i = q.begin()->second;
    q.erase(q.begin());
    if (d[i] != sd) continue;
    for (int j = 0; j < v[i].size(); j++)
      if (d[v[i][j].first] > v[i][j].second + sd) {
        d[v[i][j].first] = v[i][j].second + sd;
        q.insert(make_pair(d[v[i][j].first], v[i][j].first));
      }
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", d[i]);
  return 0;
}
