#include <bits/stdc++.h>
using namespace std;
inline void err(istringstream *iss) {}
template <typename T, typename... Args>
void err(istringstream *iss, const T &$val, const Args &...args) {
  string $name;
  *iss >> $name;
  if ($name.back() == ',') $name.pop_back();
  cout << $name << " = " << $val << "; ", err(iss, args...);
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int n, m, K, T, Q, cn;
struct EdgeUnwt {
  int u, v;
} edges[100005 << 1 | 1];
int cntEdge, cnt[100005 << 1 | 1], linkPar[100005];
list<int> adj[100005];
void addEdgeBiUnwt(int u, int v) {
  edges[cntEdge] = {u, v}, adj[u].push_back(cntEdge++);
  edges[cntEdge] = {v, u}, adj[v].push_back(cntEdge++);
}
int lvl[100005], parent[100005][26];
int dfs(const int &u, const int &par) {
  lvl[u] = lvl[par] + 1, parent[u][0] = par;
  int ret = 1;
  for (auto &i : adj[u])
    if (edges[i].v != par) {
      int v = edges[i].v;
      linkPar[v] = i;
      cnt[i] = dfs(v, u), ret += cnt[i], cnt[i ^ 1] = n - cnt[i];
    }
  return ret;
}
void precalcSparseMatrix(int mnNode, int mxNode) {
  for (int i = 1; i < 26; i++) {
    for (int node = mnNode; node <= mxNode; node++) {
      if (parent[node][i - 1] != -1)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
  }
}
int lca(int u, int v) {
  if (lvl[v] < lvl[u]) swap(u, v);
  int diff = lvl[v] - lvl[u];
  for (int i = 0; i < 26; i++)
    if ((diff >> i) & 1) v = parent[v][i];
  if (u == v) return u;
  for (int i = 26 - 1; i >= 0; i--)
    if (parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
  return parent[u][0];
}
int xthPar(int u, int x) {
  for (int i = 0; i < 26; i++) {
    if (x & (1 >> i)) u = parent[u][i];
  }
  return u;
}
int main() {
  cin.tie(NULL);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdgeBiUnwt(u, v);
  }
  lvl[0] = -1, dfs(1, 0), precalcSparseMatrix(1, n);
  for (int i = 0; i < (n - 1) << 1; i++) {
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int l = lca(u, v), x = lvl[u] - lvl[l] + lvl[v] - lvl[l] - 1;
    if (!(x & 1)) {
      printf("0\n");
      continue;
    }
    if (lvl[u] == lvl[v]) {
      if (u == v) {
        printf("%d\n", n);
        continue;
      }
      int pu = xthPar(u, x >> 1), pv = xthPar(v, x >> 1);
      printf("%d\n", n - cnt[linkPar[pu]] - cnt[linkPar[pv]]);
    } else {
      if (lvl[u] < lvl[v]) swap(u, v);
      int pu = xthPar(u, x >> 1);
      printf("%d\n", n - cnt[linkPar[pu]] - cnt[linkPar[parent[pu][0]] ^ 1]);
    }
  }
  return 0;
}
