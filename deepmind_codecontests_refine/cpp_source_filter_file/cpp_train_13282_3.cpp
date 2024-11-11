#include <bits/stdc++.h>
using namespace std;
const int mxN = 3 * 100 * 1000 + 5;
vector<int> g[mxN];
int vis[mxN];
void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  queue<pair<int, int>> q;
  for (int i = 0; i < k; i++) {
    int p;
    cin >> p;
    p--;
    if (!vis[p]) {
      vis[p] = 1;
      q.push({p, d});
    }
  }
  map<pair<int, int>, int> mp;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    mp[{min(u, v), max(u, v)}] = i;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  set<int> ans;
  vector<int> par(n);
  while ((int)q.size()) {
    int sz = q.size();
    while (sz--) {
      int cur, depth;
      tie(cur, depth) = q.front();
      q.pop();
      depth--;
      for (auto to : g[cur]) {
        if (vis[to]) {
          if (to != par[cur]) ans.insert(mp[{min(cur, to), max(cur, to)}]);
        } else {
          par[to] = cur;
          vis[to] = 1;
          if (depth) {
            q.push({to, depth});
          }
        }
      }
    }
  }
  cout << (int)ans.size() << endl;
  for (auto edge : ans) {
    cout << edge << " ";
  }
  cout << endl;
}
int query = 0;
int main() {
  int q = 1;
  if (query) cin >> q;
  while (q--) {
    solve();
  }
}
