#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll MOD = 1e9 + 7;
const ll inf = (LLONG_MAX >> 2);
bool dfs1(int node, int pere, vector<vector<int>>& adj, vector<int>& deg,
          int l) {
  for (int i : adj[node]) {
    if (i == pere) continue;
    if (deg[i] == 1) {
      if ((l & 1) == 0) return true;
    } else if (dfs1(i, node, adj, deg, l + 1))
      return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> deg(n + 1);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    ++deg[a];
    ++deg[b];
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      int l = 0;
      if (dfs1(i, -1, adj, deg, l))
        cout << "3 ";
      else
        cout << "1 ";
      break;
    }
  }
  int ans = n - 1;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] > 1) {
      int cnt = 0;
      for (int j : adj[i]) {
        if (deg[j] == 1) ++cnt;
      }
      if (cnt > 1) ans -= (cnt - 1);
    }
  }
  cout << ans;
  return 0;
}
