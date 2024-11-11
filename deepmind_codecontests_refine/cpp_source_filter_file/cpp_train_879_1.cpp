#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> v[N];
int n, m, f[N], deg[N], fa[N];
int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
inline void merge(int x, int y) {
  x = getf(x);
  y = getf(y);
  if (x != y) f[x] = y;
}
bool vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    v[t1].push_back(t2);
    merge(t1, t2);
    ++deg[t2];
  }
  int ans = n;
  for (int i = 1; i <= n; i++) {
    fa[i] = getf(fa[i]);
    if (!vis[fa[i]]) --ans, vis[fa[i]] = 1;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (auto &i : v[nd])
      if (!--deg[i]) q.push(i);
  }
  for (int i = 1; i <= n; i++)
    if (deg[i]) ans += vis[fa[i]], vis[fa[i]] = 0;
  cout << ans << endl;
  return 0;
}
