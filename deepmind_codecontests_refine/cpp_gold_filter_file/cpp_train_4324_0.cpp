#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[200200];
vector<int> ans[200200];
bool vis[200200];
int k = 0;
void dfs(int curr, int c) {
  vis[curr] = true;
  int x = 0;
  for (auto child : v[curr]) {
    if (!vis[child.first]) {
      if (++x == c) x++;
      ans[x].push_back(child.second);
      dfs(child.first, x);
    }
  }
  k = max(k, x);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].emplace_back(y, i + 1);
    v[y].emplace_back(x, i + 1);
  }
  dfs(1, 0);
  cout << k << "\n";
  for (int i = 1; i <= k; i++) {
    cout << ans[i].size() << " ";
    for (int it : ans[i]) cout << it << " ";
    cout << "\n";
  }
}
