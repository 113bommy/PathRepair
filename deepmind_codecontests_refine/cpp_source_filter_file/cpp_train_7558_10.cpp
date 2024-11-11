#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int val[100000 + 10];
vector<int> E[100000 + 10];
int parent[100000 + 10], sparseTable[20 + 2][100000 + 10], level[100000 + 10],
    n, counter, ara[100000 * 2 + 10];
int st[100000 + 10], ed[100000 + 10];
void dfs(int node, int par, int cur) {
  st[node] = ++counter;
  ara[counter] = node;
  parent[node] = par;
  level[node] = cur;
  for (auto v : E[node]) {
    if (v != par) dfs(v, node, cur + 1);
  }
  ed[node] = ++counter;
  ara[counter] = node;
}
void initSparseTable(int Root) {
  dfs(Root, 0, 1);
  for (int i = 1; i <= n; i++) sparseTable[0][i] = parent[i];
  for (int p = 1; p <= 20; p++) {
    for (int u = 1; u <= n; u++)
      sparseTable[p][u] = sparseTable[p - 1][sparseTable[p - 1][u]];
  }
}
int findLCA(int u, int v) {
  if (level[v] > level[u]) swap(u, v);
  for (int i = 20; i >= 0; i--) {
    if ((1 << i) <= level[u] - level[v]) u = sparseTable[i][u];
  }
  if (u == v) return v;
  for (int i = 20; i >= 0; i--) {
    if (sparseTable[i][u] != sparseTable[i][v])
      u = sparseTable[i][u], v = sparseTable[i][v];
  }
  return parent[v];
}
long long int ans, sltn[100000 + 10], on[100000 + 10];
int freq[2][100000 + 10], bucket_size = sqrt(100000);
int sex[100000 + 10], both[100000 + 10];
struct data {
  int st, ed, idx, l_bucket, u, v, lca;
  bool even;
  data(int a, int b, int i, int uu, int vv, int LCA) {
    u = uu, v = vv, lca = LCA;
    st = a, ed = b, idx = i;
    l_bucket = st / bucket_size;
    if (l_bucket & 1)
      even = false;
    else
      even = true;
  }
  data() {}
};
vector<data> Q;
inline bool cmp(data a, data b) {
  if (a.l_bucket == b.l_bucket) {
    if (a.even)
      return a.ed < b.ed;
    else
      return a.ed > b.ed;
  }
  return a.l_bucket < b.l_bucket;
}
inline void add(int node) {
  long long int nw = (long long int)freq[0][val[node]] * freq[1][val[node]];
  ans -= nw;
  freq[sex[node]][val[node]]++;
  nw = (long long int)freq[0][val[node]] * freq[1][val[node]];
  ans += nw;
}
inline void rmv(int node) {
  long long int nw = (long long int)freq[0][val[node]] * freq[1][val[node]];
  ans -= nw;
  freq[sex[node]][val[node]]--;
  nw = (long long int)freq[0][val[node]] * freq[1][val[node]];
  ans += nw;
}
inline void check(int idx) {
  int node = ara[idx];
  if (on[node])
    rmv(node);
  else
    add(node);
  on[node] ^= 1;
}
void Mo() {
  sort(Q.begin(), Q.end(), cmp);
  ans = 0;
  check(1);
  int l = 1, r = 1;
  for (int i = 0; i < Q.size(); i++) {
    while (l < Q[i].st) check(l), l++;
    while (l > Q[i].st) l--, check(l);
    while (r < Q[i].ed) r++, check(r);
    while (r > Q[i].ed) check(r), r--;
    if (Q[i].lca != Q[i].u && Q[i].lca != Q[i].v) check(st[Q[i].lca]);
    sltn[Q[i].idx] = ans;
    if (Q[i].lca != Q[i].u && Q[i].lca != Q[i].v) check(st[Q[i].lca]);
  }
}
map<int, int> M;
void queryAndSolve() {
  initSparseTable(1);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (st[u] > st[v]) swap(u, v);
    int lca = findLCA(u, v);
    if (u == lca)
      Q.push_back(data(st[u], st[v], i, u, v, lca));
    else
      Q.push_back(data(ed[u], st[v], i, u, v, lca));
  }
  Mo();
  for (int i = 1; i <= q; i++) printf("%d\n", sltn[i]);
}
int main() {
  int u, v, m;
  while (scanf("%d", &n) == 1) {
    counter = 0;
    memset((freq), 0, sizeof(freq));
    memset((on), 0, sizeof(on));
    Q.clear();
    M.clear();
    for (int i = 1; i <= n; i++) scanf("%d", &sex[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]), M[val[i]];
    int cnt = 1;
    for (auto &m : M) m.second = cnt++;
    for (int i = 1; i <= n; i++) val[i] = M[val[i]];
    for (int i = 1; i < n; i++)
      scanf("%d %d", &u, &v), E[u].push_back(v), E[v].push_back(u);
    queryAndSolve();
    for (int i = 1; i <= n; i++) E[i].clear();
  }
  return 0;
}
