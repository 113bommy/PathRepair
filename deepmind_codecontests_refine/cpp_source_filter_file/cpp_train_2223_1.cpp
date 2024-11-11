#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n;
const int MAX = 100 + 5;
vector<int> g[MAX];
vector<int> vis(MAX, 0);
void dfs(int v) {
  vis[v] = 1;
  for (auto u : g[v]) {
    if (vis[v]) continue;
    dfs(u);
  }
  return;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i].first == v[j].first || v[i].second == v[i].second) {
        g[i].push_back(j);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans - 1 << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
