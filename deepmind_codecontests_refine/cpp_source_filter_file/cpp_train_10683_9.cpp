#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, change[N];
bool vis[N];
vector<int> adj[N], v[N];
void dfs(int node) {
  vis[node] = change[node] = 1;
  for (auto ch : adj[node]) {
    if (!vis[ch]) dfs(ch);
  }
}
bool tmam() {
  for (int i = 1; i < n; i++) {
    int sz = min((int)v[i].size(), (int)v[i + 1].size());
    for (int j = 0; j < sz; j++) {
      pair<int, int> pr = {1, v[i][j]}, pr2 = {1, v[i + 1][j]};
      if (change[pr.second]) pr.first = 0;
      if (change[pr2.second]) pr2.first = 0;
      if (pr < pr2) break;
      if (pr > pr2) return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int len;
    cin >> len;
    for (int j = 1; j <= len; j++) {
      int x;
      cin >> x;
      v[i].push_back(x);
    }
  }
  vector<int> nodes;
  for (int i = 1; i < n; i++) {
    int sz = min((int)v[i].size(), (int)v[i + 1].size());
    for (int j = 0; j < sz; j++) {
      if (v[i][j] != v[i + 1][j]) {
        if (v[i][j] > v[i + 1][j]) {
          nodes.push_back(v[i][j]);
        } else {
          adj[v[i + 1][j]].push_back(v[i][j]);
        }
        break;
      }
      if (j == sz - 1) {
        if (v[i].size() > v[i + 1].size()) return cout << "No\n", 0;
      }
    }
  }
  for (auto it : nodes) dfs(it);
  if (!tmam())
    cout << "No\n";
  else {
    cout << "Yes\n";
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (change[i]) ans.push_back(i);
    }
    cout << (int)ans.size() << '\n';
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
  }
  return 0;
}
