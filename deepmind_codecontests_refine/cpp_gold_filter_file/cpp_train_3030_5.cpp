#include <bits/stdc++.h>
template <class T, class U>
bool chmin(T &x, U y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <class T, class U>
bool chmax(T &x, U y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
using namespace std;
int n, m;
vector<int> adj[200005];
map<int, int> mp;
int a[200005], b[200005], vis[200005];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  m = n - 1;
  memset(vis, -1, sizeof(vis));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end(),
         [](int x, int y) { return mp[x] < mp[y]; });
  }
  queue<int> q;
  q.push(a[0]);
  vis[1] = 1;
  int j = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    b[j++] = u;
    for (int v : adj[u]) {
      if (vis[v] == -1) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  bool ok = true;
  for (int k = 0; k < n && ok; k++) {
    if (b[k] != a[k]) ok = false;
  }
  if (ok)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
  return 0;
}
