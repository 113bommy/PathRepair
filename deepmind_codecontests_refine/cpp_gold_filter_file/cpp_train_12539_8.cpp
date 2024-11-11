#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005;
int fa[MAXN];
int find(int x) { return (fa[x] == x ? x : fa[x] = find(fa[x])); }
inline void Union(int x, int y) {
  x = find(x), y = find(y);
  fa[y] = x;
}
inline void init(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
struct Road {
  int u, v;
} r[MAXM];
struct Edge {
  int to, next;
} e[MAXM << 1];
int head[MAXN], deg[MAXN], te = 1;
inline void addE(int u, int v) {
  e[++te] = (Edge){v, head[u]}, head[u] = te, ++deg[u];
}
int id[MAXN];
int n, m;
vector<int> res;
void dfs(int u, int anc = 0) {
  id[u] ^= 1;
  res.push_back(u);
  for (int j = head[u]; j != 0; j = e[j].next) {
    if (e[j].to != anc) dfs(e[j].to, u), id[u] ^= 1, res.push_back(u);
  }
  if (id[u] == 1) {
    if (anc != 0)
      res.push_back(anc), id[anc] ^= 1, res.push_back(u), id[u] ^= 1;
    else
      res.push_back(e[head[u]].to), res.push_back(u),
          res.push_back(e[head[u]].to), id[u] ^= 1;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init(n);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &r[i].u, &r[i].v);
    if (find(r[i].u) != find(r[i].v)) {
      addE(r[i].u, r[i].v);
      addE(r[i].v, r[i].u);
      Union(r[i].u, r[i].v);
    }
  }
  for (int i = 1; i <= n; i++) scanf("%d", &id[i]);
  for (int i = 1; i <= n; i++)
    if (id[i] == 1) {
      dfs(i);
      break;
    }
  for (int i = 1; i <= n; i++)
    if (id[i]) {
      printf("-1\n");
      exit(0);
    }
  printf("%d\n", (int)res.size());
  for (auto x : res) printf("%d ", x);
  printf("\n");
  return 0;
}
