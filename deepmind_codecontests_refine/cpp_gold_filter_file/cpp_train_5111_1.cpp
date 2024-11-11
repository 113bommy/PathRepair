#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
vector<map<int, int> > str(1);
vector<int> G[1000010];
int id[1000010], ans[1000010], dist[1000010];
pair<int, int> gmax(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first)
    return a;
  else if (a.first == b.first and a.second < b.second)
    return a;
  else
    return b;
}
pair<int, int> mx[1000010];
int newset() {
  map<int, int> temp;
  str.emplace_back(temp);
  return str.size() - 1;
}
int merge(int x, int y) {
  if (str[x].size() < str[y].size()) swap(x, y);
  for (auto temp : str[y]) {
    str[x][temp.first] += temp.second;
    mx[x] = gmax(mx[x], {str[x][temp.first], temp.first});
  }
  return x;
}
void dfs(int u, int p) {
  id[u] = newset();
  str[id[u]][dist[u]]++, mx[id[u]] = {1, dist[u]};
  for (auto v : G[u]) {
    if (v != p) {
      dist[v] = dist[u] + 1;
      dfs(v, u);
      id[u] = merge(id[u], id[v]);
    }
  }
  ans[u] = mx[id[u]].second - dist[u];
}
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
}
