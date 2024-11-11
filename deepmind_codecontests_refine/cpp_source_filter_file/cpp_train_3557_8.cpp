#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
struct edge {
  int u, v, w;
} ed[N];
vector<edge> vec;
int n;
pair<int, int> dfs(int u, int par) {
  pair<int, int> vv = {u, u};
  for (auto x : adj[u])
    if (x ^ par) {
      int s = dfs(ed[x].u ^ ed[x].v ^ u, x).first;
      if (vv.first == u)
        vv.first = s;
      else
        vv.second = s;
    }
  return vv;
}
inline void read_input() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back(i);
    adj[--v].push_back(i);
    ed[i] = {u, v, w / 2};
  }
}
inline void solve() {
  for (int u = 0; u < n; u++)
    if (adj[u].size() == 2) {
      cout << "NO";
      return;
    }
  for (int i = 0; i < n - 1; i++) {
    pair<int, int> x = dfs(ed[i].u, i);
    pair<int, int> y = dfs(ed[i].v, i);
    vec.push_back({x.first, y.second, ed[i].w});
    vec.push_back({x.second, y.first, ed[i].w});
    if (x.first ^ x.second) vec.push_back({x.first, x.second, -ed[i].w});
    if (y.first ^ y.second) vec.push_back({y.first, y.second, -ed[i].w});
  }
}
inline void write_output() {
  cout << "YES\n";
  cout << vec.size() << endl;
  for (auto e : vec) {
    cout << ++e.u << ' ';
    cout << ++e.v << ' ';
    cout << e.w << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
