#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > adj;
int dfs(int s, int p) {
  if (s == 0) return 0;
  int ret = 0;
  for (int i = 0; i < 2; i++) {
    int child = adj[s][i].first;
    int c = adj[s][i].second;
    if (child != p) {
      if (c > 0)
        ret += dfs(child, s);
      else
        ret += dfs(child, s) - c;
    }
  }
  return ret;
}
int main() {
  int a, b, c;
  int n;
  cin >> n;
  adj = vector<vector<pair<int, int> > >(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, -c});
  }
  int s, ans = 1e6;
  for (int i = 0; i < 2; i++) {
    int parent = adj[0][i].first;
    int c = adj[0][i].second;
    if (c > 0)
      s = dfs(parent, 0);
    else
      s = dfs(parent, 0) - c;
    ans = min(ans, s);
  }
  cout << ans;
  return 0;
}
