#include <bits/stdc++.h>
using namespace std;
vector<int> g[100009];
vector<pair<int, int> > edges;
int deg[100009], n, m;
bool topoSort(int k) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    deg[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    pair<int, int> e = edges[i];
    g[e.first].push_back(e.second);
    deg[e.second]++;
  }
  int ans = 0;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) q.push(i), ++ans;
  while (!q.empty()) {
    if (q.size() > 1) return false;
    int u = q.front();
    q.pop();
    ans = 0;
    for (auto& v : g[u])
      if (--deg[v] == 0) q.push(v), ans++;
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back(pair<int, int>(a, b));
  }
  int l = 1, r = m;
  while (l <= r) {
    int mid = (l + r) / 2;
    int d = topoSort(mid);
    if (d)
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (l > m) l = -1;
  cout << l << endl;
}
