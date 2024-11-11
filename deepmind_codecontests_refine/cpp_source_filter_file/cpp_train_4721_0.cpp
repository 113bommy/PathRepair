#include <bits/stdc++.h>
using namespace std;
const int A = 1e5 + 2, G = 20;
const int mod = 998244353;
int n, ans[A], loG[4 * A];
pair<int, int> sp[4 * A][G];
vector<int> v[A], ask[A], euler;
int level[A], first[A], freq[A];
map<pair<int, int>, int> id;
void pre_dfs(int node, int par, int lvl) {
  level[node] = lvl;
  first[node] = euler.size();
  euler.push_back(node);
  for (auto to : v[node]) {
    if (to == par) continue;
    pre_dfs(to, node, lvl + 1);
    euler.push_back(node);
  }
}
void sparse() {
  for (int i = 0; i < euler.size(); i++) {
    sp[i][0] = {level[euler[i]], euler[i]};
  }
  for (int j = 1; j <= G; j++) {
    for (int i = 0; i + (1 << j) <= euler.size(); i++) {
      if (sp[i][j - 1].first < sp[i + (1 << (j - 1))][j - 1].first)
        sp[i][j] = sp[i][j - 1];
      else
        sp[i][j] = sp[i + (1 << (j - 1))][j - 1];
    }
  }
}
int lca(int u, int v) {
  int l = first[u], r = first[v];
  if (l > r) swap(l, r);
  int j = loG[r - l + 1];
  if (sp[l][j].first < sp[r - (1 << j) + 1][j].first)
    return sp[l][j].second;
  else
    return sp[r - (1 << j) + 1][j].second;
}
int DFS(int node, int par) {
  int ret = 0;
  for (auto to : v[node]) {
    if (to == par) continue;
    int val = DFS(to, node);
    ret += val;
    ans[id[{min(node, to), max(node, to)}]] += val;
  }
  for (auto i : ask[node]) {
    int x = lca(node, i);
    if (x == node) continue;
    ret++, freq[x]++;
  }
  return ret - freq[node];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  loG[1] = 0;
  for (int i = 2; i < A; i++) {
    loG[i] = loG[i / 2] + 1;
  }
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
    id[{min(x, y), max(x, y)}] = i;
  }
  pre_dfs(1, 1, 0);
  sparse();
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    ask[x].push_back(y), ask[y].push_back(x);
  }
  int rkm = DFS(1, 1);
  for (int i = 1; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
