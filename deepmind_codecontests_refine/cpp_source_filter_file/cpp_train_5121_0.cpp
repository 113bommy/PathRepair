#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, s;
vector<int> v[N], g[N];
int deg[N];
int w[N], vis[N];
vector<pair<int, int> > req;
int tim = 0;
int tims[N];
int used[N];
long long dfs(int x, int p) {
  vis[x] = 1;
  long long ans = 0;
  for (int child : g[x])
    if (child != p && used[child] && tims[child] > tims[x])
      ans = max(ans, dfs(child, x));
  ans += w[x];
  return ans;
}
int main() {
  int x, y;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  memset(deg, 0, sizeof(deg));
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    deg[x]++;
    deg[y]++;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cin >> s;
  set<pair<int, int> > degs;
  for (int i = 1; i <= n; i++) degs.insert({deg[i], i});
  memset(used, 0, sizeof(used));
  memset(vis, 0, sizeof(vis));
  while (degs.size()) {
    int d = degs.begin()->first;
    int ver = degs.begin()->second;
    degs.erase(degs.begin());
    if (d > 1) break;
    used[ver] = 1;
    req.push_back({tim++, ver});
    tims[ver] = tim;
    if (ver == s) {
      tims[ver] = 1e9;
      continue;
    }
    for (int neigh : g[ver]) {
      if (used[neigh]) continue;
      auto elem = degs.find({deg[neigh], neigh});
      degs.erase(elem);
      deg[neigh]--;
      degs.insert({deg[neigh], neigh});
    }
  }
  sort(req.begin(), req.end());
  long long ans = 0;
  if (used[s]) {
    for (int i = req.size() - 1; i >= 0; i--) {
      int vertex = req[i].second;
      if (vertex != s && vis[vertex] == 0) ans = max(ans, dfs(vertex, 0));
    }
    for (int i = 1; i <= n; i++)
      if (used[i] == 0) {
        ans += w[i];
      }
    ans += w[s];
    ans = max(ans, dfs(s, 0));
    printf("%lld\n", ans);
    return 0;
  }
  for (int i = req.size() - 1; i >= 0; i--) {
    int vertex = req[i].second;
    if (vis[vertex] == 0) ans = max(ans, dfs(vertex, 0));
  }
  for (int i = 1; i <= n; i++)
    if (used[i] == 0) {
      ans += w[i];
    }
  printf("%lld\n", ans);
}
