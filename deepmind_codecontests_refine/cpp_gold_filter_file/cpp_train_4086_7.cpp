#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
int T;
vector<pair<int, int>> m;
set<pair<int, int>> check;
vector<int> g[nax];
int val[nax];
void add(int u, int t) {
  if (check.find({u, t}) == check.end()) {
    m.push_back({u, t});
    check.insert({u, t});
  }
}
int dfs(int u, int p, int t, int in = 0) {
  add(u, t);
  int e = g[u].size() - 1 + !p;
  int st = t;
  for (int v : g[u]) {
    if (v == p) continue;
    if (t == T) {
      t = st - e - 1;
      add(u, t);
    }
    e--;
    int x = dfs(v, u, t + 1, t);
    t = x + 1;
    add(u, t);
  }
  if (p && in != t) {
    t = in;
    add(u, in);
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) T = max(T, (int)g[i].size());
  val[1] = 1;
  dfs(1, 0, 0);
  cout << m.size() << '\n';
  for (pair<int, int> i : m) {
    cout << i.first << ' ' << i.second << '\n';
  }
}
