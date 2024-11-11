#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const long long mod = 1e9 + 7;
vector<vector<int>> adj(MAXN);
vector<vector<int>> radj(MAXN);
vector<bool> vis;
stack<int> order;
vector<int> component;
vector<int> letter(MAXN);
void dfs1(int u) {
  vis[u] = true;
  for (auto &it : adj[u])
    if (!vis[it]) dfs1(it);
  order.push(u);
}
void dfs2(int u) {
  vis[u] = true;
  for (auto &it : radj[u])
    if (!vis[it]) dfs2(it);
  component.push_back(u);
}
int scc(int n) {
  int count = 0;
  vis.resize(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(1);
  fill(vis.begin(), vis.end(), false);
  while (!order.empty()) {
    int x = order.top();
    order.pop();
    if (!vis[x]) {
      dfs2(x);
      ;
      for (auto &it : component) letter[it] = count;
      component.clear();
      ++count;
    }
  }
  return count;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) adj[a[i - 1]].push_back(a[i]), radj[a[i]].push_back(a[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (i > 0) adj[b[i - 1]].push_back(b[i]), radj[b[i]].push_back(b[i - 1]);
  }
  int ans = scc(n);
  ;
  if (ans < k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << (char)('a' + min(letter[i], 25));
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  for (int I = 1; I <= t; I++) {
    solve();
  }
  return 0;
}
