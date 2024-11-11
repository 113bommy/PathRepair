#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXE = 1000005;
const int mod = 998244353;
const long long seed = 9493101;
const long long M = 1e9 + 9;
struct Edge {
  int v, n;
  Edge() {}
  Edge(int v, int n) : v(v), n(n) {}
};
int cnt;
vector<int> G[MAXN];
vector<pair<int, int> > H[MAXN];
int h[MAXN], p[MAXN], siz[MAXN];
int n;
int X, X2;
int ans;
int dist;
void predfs(int u, int f, int dis) {
  if (dis > dist) {
    dist = dis;
    X = u;
  }
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == f) continue;
    p[v] = u;
    predfs(v, u, dis + 1);
  }
}
void dfs1(int u, int f) {
  H[u].clear();
  siz[u] = 1;
  h[u] = 1;
  int leaf = 1;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == f) continue;
    leaf = 0;
    dfs1(v, u);
    siz[u] += siz[v];
    H[u].push_back(make_pair(h[v], v));
  }
  if (!leaf) {
    sort(H[u].begin(), H[u].end());
    int cnt = 1;
    h[u] = (1LL * h[u] * H[u][0].first) % mod;
    for (int i = 1; i < H[u].size(); ++i) {
      h[u] = (1LL * h[u] * H[u][i].first) % mod;
    }
  }
  h[u] = (1LL * h[u] + siz[u]) % M;
  h[u] = (1LL * h[u] * h[u]) % mod;
}
void dfs(int u, int f, int num) {
  int t = H[u].size();
  if (num + t < 4) ++ans;
  for (int i = 0; i < t; ++i) {
    if (!i || H[u][i].first != H[u][i - 1].first) dfs(H[u][i].second, u, 1);
  }
}
void solve() {
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dist = -1;
  predfs(1, 0, 0);
  dist = -1;
  predfs(X, 0, 0);
  int f = dist & 1;
  dist >>= 1;
  while (dist--) X = p[X];
  X2 = X;
  if (f) X = p[X];
  dfs1(X, X2);
  if (X != X2) dfs1(X2, X);
  ans = 0;
  if (X == X2) {
    dfs(X, X2, 0);
  } else if (h[X] == h[X2]) {
    dfs(X, X2, 1);
  } else {
    dfs(X, X2, 1);
    dfs(X2, X, 1);
  }
  printf("%d\n", ans);
}
int main() {
  while (~scanf("%d", &n)) solve();
  return 0;
}
