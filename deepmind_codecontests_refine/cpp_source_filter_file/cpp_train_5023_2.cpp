#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 5e5 + 1;
int a[N], b[N];
const int M = (1 << 20);
vector<pair<int, int> > e[M];
vector<bool> vis(M, false);
vector<int> ans;
void dfs(int u) {
  vis[u] = 1;
  for (auto v : e[u])
    if (!vis[v.first]) dfs(v.first);
}
bool check(int l) {
  int L = (1 << l);
  for (int i = 0; i < L; i++) {
    e[i].clear();
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int u = a[i] & (L - 1);
    int v = b[i] & (L - 1);
    e[u].push_back({v, 2 * i - 1});
    e[v].push_back({u, 2 * i - 2});
  }
  int comps = 0;
  bool ev = 1;
  for (int i = 0; i < L; i++) {
    if (e[i].size() & 1) ev = 0;
    if (e[i].size() > 0 && vis[i] == 0) {
      comps++;
      dfs(i);
    }
  }
  if (ev != 1 || comps != 1)
    return false;
  else
    return true;
}
void dfs2(int u, int w = -1) {
  while (e[u].size()) {
    auto x = e[u].back();
    e[u].pop_back();
    if (vis[x.second / 2]) continue;
    vis[x.second / 2] = 1;
    dfs2(x.first, x.second);
  }
  if (w != -1) {
    ans.push_back(w);
    ans.push_back(w ^ 1);
  }
}
void loop(int l) {
  int L = (1 << l);
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 0; i < L; i++) {
    if (e[i].size() > 0) {
      dfs2(i);
      break;
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int l = 20; l >= 0; l--) {
    bool valid = check(l);
    if (valid) {
      cout << l << '\n';
      ans.clear();
      loop(l);
      for (auto j : ans) cout << j + 1 << " ";
      cout << '\n';
      return;
    }
  }
}
int main() {
  int q = 1;
  for (int i = 1; i <= q; i++) {
    solve();
  }
  return 0;
}
