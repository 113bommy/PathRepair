#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFF = 1e17;
const double EPS = 1e-9;
const long long int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int M = 19;
int n, m, par_DS[N], chainNo, ptr, sz[N], par[N], depth[N], chainHead[N],
    chainInd[N], posInBase[N], p[N][M], otherEnd[N];
vector<vector<int> > ind(N);
int tree[4 * N], a[4 * N], lazy[4 * N];
vector<vector<pair<int, int> > > g(N);
vector<pair<pair<int, int>, int> > elist;
bool vis[N];
map<pair<int, int>, pair<int, int> > edges;
void build(int node, int start, int end) {
  if (start == end)
    tree[node] = a[start];
  else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
}
void updateRange(int node, int start, int end, int l, int r, int val) {
  if (lazy[node] != 0) {
    tree[node] = (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    tree[node] = (end - start + 1) * val;
    if (start != end) {
      lazy[node * 2] = val;
      lazy[node * 2 + 1] = val;
    }
    return;
  }
  int mid = (start + end) / 2;
  updateRange(node * 2, start, mid, l, r, val);
  updateRange(node * 2 + 1, mid + 1, end, l, r, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int queryRange(int node, int start, int end, int l, int r) {
  if (start > end || start > r || end < l) return 0;
  if (lazy[node] != 0) {
    tree[node] = (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) / 2;
  int p1 = queryRange(node * 2, start, mid, l, r);
  int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
  return max(p1, p2);
}
void dfs(int v, int prev, int d) {
  vis[v] = 1;
  par[v] = prev;
  depth[v] = d;
  sz[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (!vis[g[v][i].first]) {
      otherEnd[ind[v][i]] = g[v][i].first;
      dfs(g[v][i].first, v, d + 1);
      sz[v] += sz[g[v][i].first];
    }
  }
}
void HLD(int curNode, int cost, int prev) {
  if (chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
  chainInd[curNode] = chainNo;
  posInBase[curNode] = ptr;
  a[ptr++] = cost;
  int sc = 0, node, c;
  for (auto u : g[curNode]) {
    if (u.first != prev && sz[u.first] > sc) {
      sc = sz[u.first];
      node = u.first;
      c = u.second;
    }
  }
  if (sc != 0) HLD(node, c, curNode);
  for (auto u : g[curNode]) {
    if (u.first != prev && u.first != node) {
      chainNo++;
      HLD(u.first, u.second, curNode);
    }
  }
}
int LCA(int a, int b) {
  int logL;
  if (depth[a] < depth[b]) swap(a, b);
  for (logL = 1; (1 << logL) <= depth[a]; logL++)
    ;
  logL--;
  for (int i = logL; i >= 0; i--)
    if (depth[a] - (1 << i) >= depth[b]) a = p[a][i];
  if (a == b) return a;
  for (int i = logL; i >= 0; i--)
    if (p[a][i] != -1 && p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return par[a];
}
int query_up(int u, int v) {
  if (u == v) return 0;
  int uchain, vchain = chainInd[v], ans = -1;
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      if (u == v) break;
      ans = max(ans, queryRange(1, 0, ptr, posInBase[v] + 1, posInBase[u]));
      break;
    }
    ans = max(
        ans, queryRange(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]));
    u = chainHead[uchain];
    u = par[u];
  }
  return ans;
}
int query(int u, int v) {
  int lca = LCA(u, v);
  return max(query_up(u, lca), query_up(v, lca));
}
int root(int v) { return (par_DS[v] < 0 ? v : (par_DS[v] = root(par_DS[v]))); }
int merge(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return 0;
  if (par_DS[y] < par_DS[x]) swap(x, y);
  par_DS[x] += par_DS[y];
  par_DS[y] = x;
  return 1;
}
void path_update(int u, int v, int val) {
  if (u == v) return;
  int uchain, vchain = chainInd[v];
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      if (u == v) break;
      updateRange(1, 0, ptr, posInBase[v] + 1, posInBase[u], val);
      break;
    }
    updateRange(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u], val);
    u = chainHead[uchain];
    u = par[u];
  }
}
void path(int u, int v, int val) {
  int lca = LCA(u, v);
  path_update(u, lca, val);
  path_update(v, lca, val);
}
void process() {
  ptr = 0;
  chainNo = 0;
  for (int i = (0); i < (n); ++i) vis[i] = 0, chainHead[i] = -1;
  dfs(0, -1, 0);
  HLD(0, -1, -1);
  build(1, 0, ptr);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (M); ++j) p[i][j] = -1;
  for (int i = (0); i < (n); ++i) p[i][0] = par[i];
  for (int j = 1; (1 << j) < n; j++)
    for (int i = (0); i < (n); ++i)
      if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (m); ++i) {
    int t1, t2, t3;
    scanf("%d %d %d", &t1, &t2, &t3);
    t1--;
    t2--;
    elist.push_back(make_pair(make_pair(t1, t2), t3));
    edges[make_pair(t1, t2)] = make_pair(i, 0);
  }
  for (int i = (0); i < (n); ++i) par_DS[i] = -1;
  sort(elist.begin(), elist.end(),
       [](const pair<pair<int, int>, int> &lhs,
          const pair<pair<int, int>, int> &rhs) {
         return lhs.second < rhs.second;
       });
  int curr = 0;
  for (auto u : elist)
    if (merge(u.first.first, u.first.second)) {
      g[u.first.first].push_back(make_pair(u.first.second, u.second)),
          g[u.first.second].push_back(make_pair(u.first.first, u.second));
      ind[u.first.first].push_back(curr);
      ind[u.first.second].push_back(curr++);
      int id = edges[make_pair(u.first.first, u.first.second)].first;
      edges.erase(make_pair(u.first.first, u.first.second));
      edges[make_pair(u.first.first, u.first.second)] = make_pair(id, 1);
    }
  sort(elist.begin(), elist.end(),
       [](const pair<pair<int, int>, int> &lhs,
          const pair<pair<int, int>, int> &rhs) {
         return lhs.second > rhs.second;
       });
  int ans[N];
  process();
  for (auto u : elist) {
    if (!edges[make_pair(u.first.first, u.first.second)].second) {
      ans[edges[make_pair(u.first.first, u.first.second)].first] =
          query(u.first.first, u.first.second) - 1;
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = 0; j < g[i].size(); j++) g[i][j].second = INF;
  }
  process();
  for (auto u : elist) {
    if (!edges[make_pair(u.first.first, u.first.second)].second) {
      path(u.first.first, u.first.second, u.second);
    }
  }
  for (auto u : elist) {
    if (edges[make_pair(u.first.first, u.first.second)].second) {
      int ret = query(u.first.first, u.first.second);
      if (ret == INF)
        ans[edges[make_pair(u.first.first, u.first.second)].first] = -1;
      else
        ans[edges[make_pair(u.first.first, u.first.second)].first] = ret - 1;
    }
  }
  for (int i = (0); i < (m); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
