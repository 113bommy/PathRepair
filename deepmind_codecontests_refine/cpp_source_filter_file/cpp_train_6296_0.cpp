#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
int n, m;
int in[N], edges;
multiset<int> G[N];
vector<int> odd;
vector<int> ans;
void dfs(int u) {
  while (!G[u].empty()) {
    int v = *G[u].begin();
    G[u].erase(G[u].begin());
    G[v].erase(G[v].find(u));
    dfs(v);
  }
  ans.push_back(u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
    in[u]++;
    in[v]++;
    edges++;
  }
  for (int i = 1; i <= n; i++)
    if (in[i] & 1) odd.push_back(i);
  assert((int)odd.size() % 2 == 0);
  for (int i = 0; i < (int)odd.size(); i += 2) {
    G[odd[i]].insert(odd[i + 1]);
    G[odd[i + 1]].insert(odd[i]);
    edges++;
  }
  if (edges & 1) G[1].insert(1), G[1].insert(1);
  dfs(1);
  cout << edges << '\n';
  for (int i = 0; i < (int)ans.size() - 1; i++) {
    if (i & 1)
      cout << ans[i] << ' ' << ans[i + 1] << '\n';
    else
      cout << ans[i + 1] << ' ' << ans[i] << '\n';
  }
  return 0;
}
