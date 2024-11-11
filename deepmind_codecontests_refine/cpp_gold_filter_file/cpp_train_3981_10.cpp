#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int n, m, sq;
vector<vector<int>> g;
vector<int> dep;
vector<bool> marked;
vector<int> s;
void dfs(int v) {
  dep[v] = (int)s.size();
  s.push_back(v);
  for (int u : g[v]) {
    if (dep[u] == -1)
      dfs(u);
    else if (dep[v] - dep[u] >= sq - 1) {
      cout << 2 << endl;
      cout << dep[v] - dep[u] + 1 << endl;
      for (int i = dep[v]; i >= dep[u]; --i) {
        cout << s[i] + 1 << " ";
      }
      cout << endl;
      exit(0);
    }
  }
  if (marked[v]) {
    for (int u : g[v]) {
      marked[u] = 0;
    }
  }
  s.pop_back();
}
void solve() {
  cin >> n >> m;
  sq = 1;
  while (sq * sq < n) ++sq;
  g.assign(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep.assign(n, -1);
  marked.assign(n, 1);
  dfs(0);
  cout << 1 << endl;
  for (int i = 0; i < n; i++) {
    if (sq && marked[i]) {
      sq--;
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
