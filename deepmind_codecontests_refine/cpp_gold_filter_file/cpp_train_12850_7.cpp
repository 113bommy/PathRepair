#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, m;
vector<bool> vis(N);
vector<int> comp(N), cost(N);
vector<int> adj[N], radj[N], val[N];
stack<int> incord;
int cnt = 0;
void dfs(int u) {
  vis[u] = true;
  for (int &it : adj[u]) {
    if (!vis[it]) {
      dfs(it);
    }
  }
  incord.push(u);
}
void dfs2(int u, int cmp) {
  comp[u] = cmp;
  val[cmp].push_back(cost[u]);
  for (int &it : radj[u]) {
    if (!comp[it]) {
      dfs2(it, cmp);
    }
  }
}
void sccADDE(int from, int to) {
  adj[from].push_back(to);
  radj[to].push_back(from);
}
void scc() {
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  while (!incord.empty()) {
    if (!comp[incord.top()]) {
      dfs2(incord.top(), incord.top());
      cnt++;
    }
    incord.pop();
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  cin >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    sccADDE(u, v);
  }
  scc();
  int64_t ans1 = 0, ans2 = 1;
  for (int i = 1; i <= n; i++) {
    if (!val[i].size()) {
      continue;
    }
    sort(val[i].begin(), val[i].end());
    int min1 = val[i][0];
    ans1 += min1;
    cnt = 0;
    for (int &it : val[i]) {
      cnt += (it == min1);
    }
    ans2 *= cnt;
    ans2 -= (ans2 / mod) * mod;
  }
  cout << ans1 << " " << ans2;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tkd = 1;
  while (tkd-- > 0) {
    solve();
  }
}
