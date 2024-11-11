#include <bits/stdc++.h>
using namespace std;
bool vs[1048580];
int n;
int a[500010], b[500010];
vector<pair<int, int> > g[1048580];
vector<int> ans;
void dfs(int u) {
  vs[u] = 1;
  for (auto v : g[u])
    if (!vs[v.first]) dfs(v.first);
}
bool check(int x) {
  int mask = (1 << x) - 1;
  for (int i = 0; i <= mask; ++i) {
    g[i].clear();
    vs[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int u = a[i] & mask;
    int v = b[i] & mask;
    g[u].emplace_back(v, 2 * i);
    g[v].emplace_back(u, 2 * i - 1);
  }
  int cnt = 0;
  for (int i = 0; i <= mask; ++i)
    if (g[i].size()) {
      if (g[i].size() & 1) return false;
      if (!vs[i]) {
        dfs(i);
        cnt++;
      }
    }
  return cnt == 1;
}
void go(int u, int id = -1) {
  while (g[u].size()) {
    pair<int, int> v = g[u].back();
    g[u].pop_back();
    if (vs[(v.second + 1) / 2]) continue;
    vs[(v.second + 1) / 2] = 1;
    go(v.first, v.second);
  }
  if (id != -1) {
    ans.push_back(id);
    ans.push_back(id + (id % 2 == 0 ? -1 : 1));
  }
}
void print(int x) {
  for (int i = 1; i <= n; ++i) vs[i] = 0;
  int mask = (1 << x) - 1;
  for (int i = 0; i <= mask; ++i)
    if (g[i].size()) {
      go(i);
      break;
    }
  for (auto v : ans) cout << v << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (int i = 20; i > 0; --i)
    if (check(i)) {
      cout << i << '\n';
      print(i);
      exit(0);
    }
}
