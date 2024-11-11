#include <bits/stdc++.h>
using namespace std;
long long fpm(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class edge>
struct Graph {
  vector<vector<edge>> adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  int deg(int v) { return adj[v].size(); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 330000;
Graph<int> G;
int w[maxn], col[maxn];
set<pair<int, int>> f;
void update(int v) {
  f.erase(make_pair(w[v], v));
  w[v] = 0;
  for (auto &u : G[v]) w[v] += col[v] == col[u] ? -1 : 1;
  f.insert(make_pair(w[v], v));
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  G.resize(n);
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    G.add(a, b);
    G.add(b, a);
  }
  for (int i = 1; i <= n; ++i) {
    f.insert(make_pair(0, i));
    update(i);
  }
  for (;;) {
    auto v = *f.begin();
    if (v.first >= -1) break;
    col[v.second] ^= 1;
    update(v.second);
    for (auto &u : G[v.second]) update(u);
  }
  for (int i = 1; i <= n; ++i) {
    cout << col[i];
  }
  return 0;
}
