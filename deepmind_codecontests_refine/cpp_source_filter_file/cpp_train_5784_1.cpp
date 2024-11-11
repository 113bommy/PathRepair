#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
const int M = 3e4 + 4;
int n, m, s, t, a[M], b[M], c[M], idx[N], dfs, low[N];
int brd, edge, vis[M], vs;
bool br[M];
long long ans = 2e18;
vector<pair<int, int> > adj[N], bg;
vector<int> pth;
pair<int, int> in[M];
int ned, xx, yy, zz;
void DFS(int u, int p) {
  idx[u] = low[u] = ++dfs;
  for (auto e : adj[u]) {
    int v = e.first, id = e.second;
    if (id != edge) {
      if (!idx[v]) {
        in[v] = {u, id};
        DFS(v, id);
        low[u] = min(low[v], low[u]);
        if (low[v] > idx[u]) {
          if (edge == -1)
            br[id] = 1;
          else
            bg.push_back({c[id], id});
        }
      } else if (id != p)
        low[u] = min(low[u], idx[v]);
    }
  }
}
pair<int, int> get() {
  pair<int, int> ret = {-1, -1};
  int x = t;
  vector<int> pt;
  while (in[x].first != -1) {
    pt.push_back(in[x].second);
    x = in[x].first;
  }
  sort(pt.begin(), pt.end());
  sort(bg.begin(), bg.end());
  for (auto i : bg) {
    if (binary_search(pt.begin(), pt.end(), i.second)) {
      ret = {i.second, i.first};
      return ret;
    }
  }
  return ret;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &t);
  --s, --t;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    --a[i], --b[i];
    adj[a[i]].push_back({b[i], i});
    adj[b[i]].push_back({a[i], i});
  }
  memset(in, -1, sizeof in);
  edge = -1;
  DFS(s, -1);
  if (in[t].first == -1) {
    puts("0");
    return 0;
  }
  int x = t;
  while (in[x].first != -1) {
    pth.push_back(in[x].second);
    x = in[x].first;
  }
  for (int k : pth) {
    edge = k;
    brd = 2e9;
    memset(low, 0, sizeof low);
    memset(idx, 0, sizeof idx);
    memset(in, -1, sizeof in);
    bg.clear();
    DFS(s, -1);
    auto pp = get();
    if (in[t].first == -1) {
      if (ans > 1ll * c[edge]) {
        ans = 1ll * c[edge];
        ned = 1;
        xx = edge;
      }
    } else if (ans > 1ll * (pp.second + c[edge]) && pp.first != -1) {
      ans = 1ll * (pp.second + c[edge]);
      ned = 2;
      yy = edge;
      zz = pp.first;
    }
  }
  xx++;
  yy++;
  zz++;
  if (!ned) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", ans);
  if (ned == 1) {
    printf("%d\n%d\n", ned, xx);
  }
  if (ned == 2) {
    printf("%d\n%d %d\n", ned, yy, zz);
  }
}
