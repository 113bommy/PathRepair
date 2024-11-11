#include <bits/stdc++.h>
using namespace std;
const int INFint = 2147483647;
const long long INF = 9223372036854775807ll;
const long long MOD = 1000000009ll;
const long double EPS = 1e-9;
vector<vector<pair<pair<int, int>, int> > > g;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  vector<long long> cc(m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    cc[i] = c;
    g[a].push_back(make_pair(make_pair(b, c), i));
    g[b].push_back(make_pair(make_pair(a, c), i));
  }
  int res = 0;
  vector<int> ans(n, -1);
  int u;
  cin >> u;
  u--;
  vector<long long> d(n, INF);
  d[u] = 0;
  priority_queue<pair<long long, int> > q;
  q.push(make_pair(0, u));
  while (!q.empty()) {
    long long dist = -q.top().first;
    int v = q.top().second;
    q.pop();
    if (dist != d[v]) continue;
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i].first.first;
      int w = g[v][i].first.second;
      int num = g[v][i].second;
      if (d[to] > d[v] + w || (d[to] == d[v] + w && cc[ans[to]] > w)) {
        ans[to] = num;
        d[to] = d[v] + w;
        q.push(make_pair(-d[to], to));
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (ans[i] != -1) res += cc[ans[i]];
  cout << res << endl;
  for (int i = 0; i < n; i++)
    if (ans[i] != -1) cout << ans[i] + 1 << ' ';
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  return 0;
}
