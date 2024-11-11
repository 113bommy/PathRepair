#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 300012, INF = 1e18;
long long int d[MAX], p[MAX], le[MAX];
long long int n, m, u, w, v, now;
bool flag[MAX];
set<pair<long long int, long long int> > dis;
long long int sum;
vector<pair<long long int, long long int> > g[MAX];
map<pair<long long int, long long int>, long long int> e;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  long long int t1, t2, t3;
  for (long long int i = 1; i <= m; i++) {
    cin >> t1 >> t2 >> t3;
    e[make_pair(min(t1, t2), max(t1, t2))] = i;
    g[t1].push_back(make_pair(t2, t3));
    g[t2].push_back(make_pair(t1, t3));
  }
  cin >> u;
  for (long long int i = 1; i <= n; i++) {
    le[i] = d[i] = INF, p[i] = -1;
  }
  le[u] = d[u] = 0, p[u] = 0;
  dis.insert(make_pair(0, u));
  while (!dis.empty()) {
    now = (*dis.begin()).second;
    flag[now] = 1;
    dis.erase(dis.begin());
    for (long long int i = 0; i < g[now].size(); i++) {
      v = g[now][i].first;
      if (flag[v]) continue;
      w = g[now][i].second;
      if (d[now] + w < d[v]) {
        le[v] = w;
        p[v] = now;
        if (d[v] != INF) dis.erase(make_pair(d[v], v));
        d[v] = d[now] + w;
        dis.insert(make_pair(d[v], v));
      } else if (d[now] + w == d[v] && w < le[v]) {
        p[v] = now;
        le[v] = w;
        if (d[v] != INF) dis.erase(make_pair(d[v], v));
        d[v] = d[now] + w;
        dis.insert(make_pair(d[v], v));
      }
    }
  }
  for (long long int i = 1; i <= n; i++) sum += le[i];
  cout << sum << endl;
  for (long long int i = 1; i <= n; i++)
    if (p[i]) cout << e[make_pair(min(i, p[i]), max(i, p[i]))] << " ";
  cout << endl;
  return 0;
}
