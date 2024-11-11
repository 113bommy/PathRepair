#include <bits/stdc++.h>
using namespace std;
int n, m, x, p, ans = -1;
bool ok = false;
bool vis[222];
vector<int> v[222];
void dfs(int nd) {
  vis[nd] = true;
  for (int i = 0; i < v[nd].size(); ++i) {
    int x = v[nd][i];
    if (!vis[x]) dfs(x);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    if (p != 0) ok = true;
    for (int j = 0; j < p; ++j) {
      cin >> x;
      v[i].push_back(n + x - 1);
      v[n + x - 1].push_back(i);
    }
  }
  if (!ok) return cout << n, 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans;
  return 0;
}
