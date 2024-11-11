#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 1;
int a[N], b[N];
vector<int> adj[N];
vector<int> order;
vector<bool> vis;
void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) dfs(v);
  }
  order.push_back(u);
}
void testcase() {
  int n;
  cin >> n;
  for (int i = 1; i <= (n); ++i) cin >> a[i];
  for (int i = 1; i <= (n); ++i) {
    cin >> b[i];
    if (b[i] != -1) {
      adj[i].push_back(b[i]);
    }
  }
  vis = vector<bool>(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  reverse(order.begin(), order.end());
  vector<int> neg, pos;
  ll sum = 0;
  for (int o : order) {
    sum += (ll)(a[o]);
    if (a[o] < 0) {
      neg.push_back(o);
    } else {
      pos.push_back(o);
      if (b[o] >= 1) a[b[o]] += a[o];
    }
  }
  cout << sum << "\n";
  for (int o : pos) {
    cout << o << " ";
  }
  reverse(neg.begin(), neg.end());
  for (int o : neg) {
    cout << o << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  if (0) cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
