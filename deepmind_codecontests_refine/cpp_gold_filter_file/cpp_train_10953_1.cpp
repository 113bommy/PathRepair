#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
pair<pair<int, int>, int> edge[5002];
pair<int, int> Edge[5002];
int G[5002][5002];
int dep[5002], fa[5002];
vector<int> tree[5002];
void dfs(int cur, int f) {
  fa[cur] = f;
  dep[cur] = dep[f] + 1;
  for (auto it : tree[cur]) {
    if (it == f) continue;
    dfs(it, cur);
  }
}
inline bool go(int f, int t, int v) {
  if (dep[f] < dep[t]) swap(f, t);
  while (dep[f] > dep[t]) {
    int ff = fa[f];
    int val = G[ff][f];
    if (v > val) {
      G[ff][f] = G[f][ff] = v;
    }
    f = ff;
  }
  while (f != t) {
    int ff = fa[f];
    int ft = fa[t];
    if (v > G[ff][f]) {
      G[ff][f] = G[f][ff] = v;
    }
    if (v > G[ft][t]) {
      G[ft][t] = G[t][ft] = v;
    }
    f = ff;
    t = ft;
  }
  return true;
}
inline bool check(int f, int t, int v) {
  if (dep[f] < dep[t]) swap(f, t);
  int cnt = 0;
  while (dep[f] > dep[t]) {
    int ff = fa[f];
    int val = G[ff][f];
    cnt += (val == v);
    f = ff;
  }
  while (f != t) {
    int ff = fa[f];
    int ft = fa[t];
    cnt += (G[ff][f] == v || G[ft][t] == v);
    f = ff;
    t = ft;
  }
  return cnt > 0;
}
inline void print(int n) {
  for (int i = 1; i <= n; ++i) {
    cout << G[Edge[i].first][Edge[i].second] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  dep[0] = 0;
  for (int i = 1; i < n; ++i) {
    int f, t;
    cin >> f >> t;
    G[f][t] = G[t][f] = 1;
    Edge[i] = {f, t};
    tree[f].push_back(t);
    tree[t].push_back(f);
  }
  dfs(1, 0);
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int f, t, v;
    cin >> f >> t >> v;
    edge[i] = {{f, t}, v};
    if (!go(f, t, v)) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!check(edge[i].first.first, edge[i].first.second, edge[i].second)) {
      cout << "-1\n";
      return 0;
    }
  }
  print(n - 1);
  return 0;
}
