#include <bits/stdc++.h>
using namespace std;
int n, red, blue, ans, u, v;
int colors[300010];
vector<int> adj[300010];
pair<int, int> dfs(int actual, int parent = -1) {
  int actualred = (colors[actual] == 1), actualblue = (colors[actual] == 2);
  for (int to : adj[actual]) {
    if (to != parent) {
      auto t = dfs(to, actual);
      ans += (t.first == red && t.second == 0);
      ans += (t.first == 0 && t.second == blue);
      actualred += t.first;
      actualblue += t.second;
    }
  }
  return make_pair(actualred, actualblue);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> colors[i];
    red += (colors[i] == 1);
    blue += (colors[i] == 2);
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cout << ans << '\n';
  return 0;
}
