#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
vector<pair<int, int> > adj[maxn];
vector<int> ans;
int mark[maxn];
void dfs(int v, int par) {
  mark[v] = 1;
  for (auto u : adj[v]) {
    if (mark[u.first] == 0)
      dfs(u.first, u.second);
    else if (u.second != par && mark[u.first] == 1) {
      cout << "-1\n";
      exit(0);
    }
  }
  mark[v] = 2;
  ans.push_back(v);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int m = 0;
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    adj[0].push_back({v, m++});
  }
  for (int v = 1; v <= n; v++) {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      int u;
      cin >> u;
      adj[v].push_back({u, m++});
    }
  }
  dfs(0, -1);
  cout << ans.size() - 1 << '\n';
  for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
