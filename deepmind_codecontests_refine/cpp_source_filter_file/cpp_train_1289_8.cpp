#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 5;
const ll INF = 1e16 + 5;
struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};
struct par {
  int u, v;
  ll w;
} edge[N];
int n, siz[N];
ll s[N], d[N];
vector<Edge> G[N];
void dfs(int u, int fa) {
  d[u] = s[u] = 0;
  siz[u] = 1;
  for (auto e : G[u]) {
    if (e.to == fa) continue;
    dfs(e.to, u);
    s[u] += s[e.to] + siz[e.to] * d[u] + siz[u] * d[e.to] +
            siz[e.to] * siz[u] * e.w;
    d[u] += d[e.to] + siz[e.to] * e.w;
    siz[u] += siz[e.to];
  }
}
void dfs2(int u, int fa, ll &mind) {
  mind = min(mind, d[u]);
  for (auto e : G[u]) {
    if (e.to == fa) continue;
    d[e.to] = d[e.to] + (d[u] - d[e.to] - e.w * siz[e.to]) +
              (siz[u] - siz[e.to]) * e.w;
    siz[e.to] = siz[u];
    dfs2(e.to, u, mind);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int x, y, i = 1; i < n; ++i) {
    ll z;
    cin >> x >> y >> z;
    edge[i] = par{x, y, z};
    G[x].emplace_back(y, z);
    G[y].emplace_back(x, z);
  }
  ll mind, now = 0, ans = INF;
  for (int i = 1; i < n; ++i) {
    dfs(edge[i].u, edge[i].v);
    dfs2(edge[i].u, edge[i].v, mind = INF);
    now = s[edge[i].u] + mind * (n - siz[edge[i].u]);
    dfs(edge[i].v, edge[i].u);
    dfs2(edge[i].v, edge[i].u, mind = INF);
    now += s[edge[i].v] + mind * (n - siz[edge[i].v]);
    now += siz[edge[i].u] * siz[edge[i].v] * edge[i].w;
    ans = min(ans, now);
  }
  cout << ans << '\n';
}
