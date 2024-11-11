#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  vector<vector<pair<int, int>>> adjp(n);
  vector<pair<pair<int, int>, int>> edges(m);
  for (int i = 0; i < (int)m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].emplace_back(b - 1, c);
    adjp[b - 1].emplace_back(a - 1, c);
    edges[i] = {{a - 1, b - 1}, c};
  }
  vector<bool> temp(n), done(n);
  vector<int> depth(n);
  function<bool(int, int)> dfs = [&](int u, int x) {
    if (done[u]) return 0;
    if (temp[u]) return 1;
    temp[u] = 1;
    depth[u] = 0;
    for (auto& p : adj[u])
      if (p.second > x) {
        if (dfs(p.first, x)) return 1;
        depth[u] = max(depth[u], depth[p.first] + 1);
      }
    temp[u] = 0;
    done[u] = 1;
    return 0;
  };
  function<bool(int)> cando = [&](int x) {
    fill(temp.begin(), temp.end(), 0);
    fill(done.begin(), done.end(), 0);
    fill(depth.begin(), depth.end(), 0);
    for (int i = 0; i < (int)n; i++)
      if (!done[i])
        if (dfs(i, x)) return 0;
    return 1;
  };
  int lo = 0, hi = 1e9 + 17;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (cando(mid))
      hi = mid;
    else
      lo = mid;
  }
  assert(cando(hi));
  vector<int> ans;
  for (int i = 0; i < (int)m; i++) {
    int a = edges[i].first.first, b = edges[i].first.second,
        c = edges[i].second;
    if (c <= hi && (depth[a] < depth[b] || depth[a] == depth[b] && b < a))
      ans.push_back(i);
  }
  cout << hi << " " << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
}
