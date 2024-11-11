#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const int MAXN = 3e5 + 20;
vector<pair<int, int> > edge[MAXN];
bool path[MAXN];
int sz[MAXN], n, m;
long long dist[MAXN], disn[MAXN], Hash[MAXN];
inline void dfs(int u, int p) {
  for (auto x : edge[u]) {
    int v = x.first;
    if (v != p) {
      dist[v] = dist[u] + x.second;
      dfs(v, u);
      path[u] |= path[v];
    }
  }
}
inline void dfsn(int u, int p) {
  for (auto x : edge[u]) {
    int v = x.first;
    int w = x.second;
    if (v != p) {
      disn[v] = disn[u] + w;
      dfsn(v, u);
    }
  }
}
inline void dfs2(int u, int p) {
  sz[u] = 1;
  for (auto x : edge[u]) {
    int v = x.first;
    if (v != p && !path[v]) {
      dfs2(v, u);
      sz[u] += sz[v];
    }
  }
}
vector<int> vec;
inline void findp(int u, int p) {
  vec.push_back(u);
  for (auto x : edge[u]) {
    int v = x.first;
    if (v != p && path[v]) {
      findp(v, u);
      return;
    }
  }
}
int que[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (register int i = (2); i <= (n); ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].push_back(pair<int, int>(v, w));
    edge[v].push_back(pair<int, int>(u, w));
  }
  path[n] = 1;
  dfs(1, 1);
  bool flag = false;
  for (register int i = (1); i <= (n); ++i) {
    if (path[i]) {
      dfs2(i, i);
      flag |= sz[i] > 2;
    }
  }
  if (flag) {
    for (register int i = (1); i <= (m); ++i) {
      int xi;
      cin >> xi;
      cout << dist[n] << '\n';
    }
    return 0;
  }
  dfsn(n, n);
  long long res = 0;
  int mx1 = 0, mx2 = 0;
  findp(1, 1);
  dist[0] = -1;
  for (register int i = (0); i <= ((int((vec).size())) - 1); ++i) {
    int ll = 0, rr = 0;
    que[rr++] = vec[i];
    while (ll < rr) {
      int u = que[ll++];
      Hash[u] = 1;
      for (auto x : edge[u]) {
        int v = x.first;
        if (!path[v] && !Hash[v]) {
          que[rr++] = v;
        }
      }
      if (u == vec[i]) {
        int gt = mx1;
        if (i && gt == vec[i - 1]) {
          gt = mx2;
        }
        if (gt == 0) continue;
        res = max(res, dist[gt] + disn[u]);
      } else if (mx1) {
        res = max(res, dist[mx1] + disn[u]);
      }
    }
    for (register int j = (0); j <= (rr - 1); ++j) {
      if (dist[que[j]] > dist[mx2]) {
        mx2 = que[j];
      }
      if (dist[mx1] < dist[mx2]) {
        swap(mx1, mx2);
      }
    }
  }
  for (register int i = (1); i <= (m); ++i) {
    int xi;
    cin >> xi;
    cout << min(dist[n], res + xi) << '\n';
  }
  return 0;
}
