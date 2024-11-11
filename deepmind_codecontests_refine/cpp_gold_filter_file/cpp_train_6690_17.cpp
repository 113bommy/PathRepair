#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1000005;
vector<int> g[maxn];
int pa[maxn];
int dep[maxn];
vector<int> v[maxn];
void dfs(int now) {
  v[dep[now]].push_back(now);
  for (auto &i : g[now]) {
    if (dep[i]) {
      continue;
    }
    pa[i] = now;
    dep[i] = dep[now] + 1;
    dfs(i);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    g[i].clear();
    dep[i] = 0;
    pa[i] = 0;
    v[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 1;
  dfs(1);
  int tar = (n + 1) / 2;
  for (int i = 1; i < n + 1; i++) {
    if (dep[i] >= tar) {
      vector<int> ans{i};
      while (ans.back() != 1) {
        ans.push_back(pa[ans.back()]);
      }
      cout << "PATH\n";
      cout << ans.size() << '\n';
      for (auto &i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "PAIRING\n";
  vector<pair<int, int>> ans;
  for (int i = 1; i < tar + 1; i++) {
    for (int j = 0; j + 1 < v[i].size(); j += 2) {
      ans.push_back({v[i][j], v[i][j + 1]});
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 1;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    solve();
  }
}
