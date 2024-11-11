#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> v(100005);
vector<pair<long long int, long long int>> edg;
vector<long long int> tr, ind(100005);
long long int f, w;
vector<long long int> res;
void dfs(long long int i, vector<long long int> &vis) {
  vis[i] = 1;
  for (long long int j = 0; j < v[i].size(); j++)
    if (vis[v[i][j].first] == 0 && v[i][j].second >= w)
      dfs(v[i][j].first, vis);
    else if (vis[v[i][j].first] == 1 && v[i][j].second >= w)
      f = 1;
  vis[i] = 2;
  if (f == 2) res.push_back(i);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  set<long long int> s;
  s.insert(0);
  for (long long int i = 0; i < m; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    edg.push_back({a, b});
    s.insert(c);
  }
  long long int l = 0, r = *prev(s.end(), 1) + 1, mid, k;
  while (l <= r) {
    mid = (l + r) / 2;
    f = 0;
    w = mid;
    vector<long long int> vis(n + 1, 0);
    for (long long int i = 1; i <= n; i++)
      if (!vis[i]) dfs(i, vis);
    if (f == 0) {
      k = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  f = 2;
  w = k;
  vector<long long int> vis(n + 1, 0);
  for (long long int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, vis);
  k = *prev(s.lower_bound(k), 1);
  reverse(res.begin(), res.end());
  for (long long int i = 1; i <= n; i++)
    if (!vis[i]) res.push_back(i);
  for (long long int i = 0; i < n; i++) ind[res[i]] = i;
  for (long long int i = 0; i < m; i++)
    if (ind[edg[i].first] > ind[edg[i].second]) tr.push_back(i + 1);
  cout << k << " " << tr.size() << endl;
  for (long long int i = 0; i < tr.size(); i++) cout << tr[i] << " ";
}
