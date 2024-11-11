#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 7;
template <class T>
inline bool updmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
struct Edge {
  int to, val;
  Edge(int to = 0, int val = 0) : to(to), val(val) {}
};
vector<Edge> G[MAXN];
set<int> t[MAXN], nxt[MAXN];
ll dis[MAXN];
int get_nxt(int u, int tt) {
  if (!(t[u].count(tt))) return tt;
  return *nxt[u].upper_bound(tt);
}
void dijkstra(int s) {
  using pii = pair<ll, int>;
  memset(dis, 0x3f, sizeof(dis));
  priority_queue<pii, vector<pii>, greater<pii> > q;
  dis[s] = 0;
  q.emplace(0, s);
  while (!q.empty()) {
    pii p = q.top();
    q.pop();
    int u = p.second;
    if (dis[u] < p.first) continue;
    for (Edge& e : G[u]) {
      int v = e.to;
      if (updmin(dis[v], 1LL * get_nxt(u, dis[u]) + e.val)) {
        q.emplace(dis[v], v);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  int k, x;
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> x;
      t[i].insert(x);
    }
    for (int y : t[i]) {
      if (!(t[i].count(y + 1))) {
        nxt[i].insert(y + 1);
      }
    }
  }
  dijkstra(1);
  cout << ((dis[n] > (ll)1e18) ? -1 : dis[n]) << '\n';
  return 0;
}
