#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const long long int MOD = 1e9 + 7, INF = 1e18;
long long int dx[8] = {0, -1, 1, 0, 1, -1, 1, -1},
              dy[8] = {1, 0, 0, -1, -1, -1, 1, 1};
struct edge {
  long long int cost;
  long long int u, v;
};
template <typename G>
struct StronglyConnectedComponents {
  const G& g;
  vector<vector<long long int>> gg, rg;
  vector<int> comp, order, used;
  StronglyConnectedComponents(G& g)
      : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for (int i = 0; i < g.size(); i++) {
      for (auto e : g[i]) {
        gg[i].emplace_back((int)e);
        rg[(int)e].emplace_back(i);
      }
    }
  }
  int operator[](int k) { return comp[k]; }
  void dfs(int idx) {
    if (used[idx]) return;
    used[idx] = true;
    for (int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }
  void rdfs(int idx, int cnt) {
    if (comp[idx] != -1) return;
    comp[idx] = cnt;
    for (int to : rg[idx]) rdfs(to, cnt);
  }
  void build(vector<vector<long long int>>& t) {
    for (int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for (int i : order)
      if (comp[i] == -1) rdfs(i, ptr), ptr++;
    t.resize(ptr);
    for (int i = 0; i < g.size(); i++) {
      for (auto& to : g[i]) {
        int x = comp[i], y = comp[to];
        if (x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};
long long int N, M, s, u, v;
int main() {
  cin >> N >> M >> s;
  s--;
  vector<vector<long long int>> to(N, vector<long long int>()), buff;
  for (long long int i = (0), i_end_ = (M); i < i_end_; i++) {
    cin >> u >> v;
    u--;
    v--;
    to[v].push_back(u);
  }
  long long int ans = 0;
  StronglyConnectedComponents<vector<vector<long long int>>> g(to);
  g.build(buff);
  for (long long int i = (0), i_end_ = (((long long int)(buff).size()));
       i < i_end_; i++) {
    if (i == g[s]) continue;
    if (((long long int)(buff[i]).size()) == 0) ans++;
  }
  cout << ans << '\n';
}
