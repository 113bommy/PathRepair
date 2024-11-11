#include <bits/stdc++.h>
using namespace std;
int N, Q, F[100005], Ara[100005], ans[100005];
vector<int> adj[100005], cost[100005];
vector<pair<pair<int, int>, pair<int, int> > > vec;
int par[100005], subSize[100005], lvl[100005];
int Base[100005], pos;
int chainHead[100005], chainID[100005], chainPos[100005], chainNext[100005],
    posInBase[100005], chains;
struct node {
  int pref, suf, sz, mi, val;
  void merge(const node L, const node R) {
    val = L.val + R.val - F[R.pref] - F[L.suf] + F[L.suf + R.pref];
    sz = L.sz + R.sz;
    mi = min(L.mi, R.mi);
    pref = L.pref, suf = R.suf;
    if (L.pref == L.sz) pref += R.pref;
    if (R.suf == R.sz) suf += L.suf;
  }
  void print() {
    printf("val %d sz %d pref %d suf %d mi %d\n", val, sz, pref, suf, mi);
  }
} Tree[4 * 100005], identity;
int dfs(int nd, int l) {
  lvl[nd] = l;
  subSize[nd] = 1;
  for (int i = 0; i < (int)adj[nd].size(); i++) {
    if (adj[nd][i] == par[nd]) continue;
    par[adj[nd][i]] = nd;
    Ara[adj[nd][i]] = cost[nd][i];
    subSize[nd] += dfs(adj[nd][i], l + 1);
  }
  return subSize[nd];
}
void hld(int nd) {
  chainID[nd] = chains;
  Base[pos] = Ara[nd];
  posInBase[nd] = pos++;
  int mx = 0, id = -1;
  for (int i = 0; i < (int)adj[nd].size(); i++) {
    int ch = adj[nd][i];
    if (ch == par[nd]) continue;
    if (subSize[ch] > mx) mx = subSize[ch], id = ch;
  }
  chainNext[nd] = id;
  if (id != -1) {
    chainHead[id] = chainHead[nd];
    chainPos[id] = chainPos[nd] + 1;
    hld(id);
  }
  for (int i = 0; i < (int)adj[nd].size(); i++) {
    int ch = adj[nd][i];
    if (ch == par[nd] || ch == id) continue;
    chains++;
    chainHead[ch] = ch;
    chainPos[ch] = 0;
    hld(ch);
  }
}
int Lca(int u, int v) {
  while (chainID[v] != chainID[u]) {
    if (lvl[chainHead[u]] < lvl[chainHead[v]])
      v = par[chainHead[v]];
    else
      u = par[chainHead[u]];
  }
  return (lvl[u] < lvl[v]) ? u : v;
}
void create(int id, int l, int r) {
  if (l == r) {
    Tree[id].mi = Base[l];
    Tree[id].sz = Tree[id].pref = Tree[id].suf = 1;
    Tree[id].val = F[1];
    return;
  }
  int mid = (l + r) >> 1;
  create(2 * id, l, mid);
  create(2 * id + 1, mid + 1, r);
  Tree[id].merge(Tree[2 * id], Tree[2 * id + 1]);
}
void update(int id, int l, int r, int x) {
  if (Tree[id].mi >= x) return;
  if (l == r) {
    Tree[id].pref = Tree[id].suf = 0;
    Tree[id].val = 0;
    Tree[id].mi = 1000000009;
    return;
  }
  int mid = (l + r) >> 1;
  update(2 * id, l, mid, x);
  update(2 * id + 1, mid + 1, r, x);
  Tree[id].merge(Tree[2 * id], Tree[2 * id + 1]);
}
node query(int id, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return Tree[id];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(2 * id, l, mid, ql, qr);
  if (ql > mid) return query(2 * id + 1, mid + 1, r, ql, qr);
  node ret;
  ret.merge(query(2 * id, l, mid, ql, qr),
            query(2 * id + 1, mid + 1, r, ql, qr));
  return ret;
}
node Query(int lca, int nd) {
  node ret = identity, prev = identity;
  while (lvl[nd] > lvl[lca]) {
    node tmp;
    if (chainID[nd] != chainID[lca])
      tmp = query(1, 0, pos - 1, posInBase[chainHead[nd]], posInBase[nd]);
    else
      tmp = query(1, 0, pos - 1, posInBase[lca] + 1, posInBase[nd]);
    nd = par[chainHead[nd]];
    ret.merge(tmp, ret);
  }
  return ret;
}
int main() {
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < (int)N - 1; i++) scanf("%d", &F[i + 1]);
  for (int i = 0; i < (int)N - 1; i++) {
    int u, v, w;
    scanf("%d%d", &u, &v);
    scanf("%d", &w);
    adj[u].push_back(v);
    adj[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  for (int i = 0; i < (int)Q; i++) {
    int u, v, l;
    scanf("%d%d", &u, &v);
    scanf("%d", &l);
    vec.push_back(make_pair(make_pair(l, i), make_pair(u, v)));
  }
  chainHead[1] = 1;
  identity.sz = identity.val = identity.pref = identity.suf = 0;
  identity.mi = 1000000009;
  dfs(1, 1);
  hld(1);
  create(1, 0, pos - 1);
  sort(vec.begin(), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    update(1, 0, pos - 1, vec[i].first.first);
    int u = vec[i].second.first, v = vec[i].second.second, lca = Lca(u, v);
    node l = Query(lca, u), r = Query(lca, v), ret;
    swap(l.pref, l.suf);
    ret.merge(l, r);
    ans[vec[i].first.second] = ret.val;
  }
  for (int i = 0; i < (int)Q; i++) printf("%d\n", ans[i]);
  return 0;
}
