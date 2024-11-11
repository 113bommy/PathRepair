#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, TMP = -INF * 2 + 1;
int root = 0, timer = 0;
vector<vector<int> > g;
vector<bitset<61> > tree;
vector<int> a, mark, id, idLast, idRev;
void dfs(int v, int p) {
  id[v] = ++timer;
  idRev[id[v]] = v;
  for (auto to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
  idLast[v] = timer;
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    bitset<61> newBitset;
    newBitset[a[idRev[tl]]] = 1;
    tree[v] = newBitset;
  } else {
    int m = (tl + tr) / 2;
    build(v * 2, tl, m);
    build(v * 2 + 1, m + 1, tr);
    tree[v] = tree[v * 2] | tree[v * 2 + 1];
  }
}
void push(int v) {
  if (!mark[v]) return;
  tree[v * 2] = tree[v];
  mark[v * 2] = 1;
  tree[v * 2 + 1] = tree[v];
  mark[v * 2 + 1] = 1;
  mark[v] = 0;
}
void update(int v, int tl, int tr, int L, int R, int x) {
  push(v);
  if (tl > R || tr < L) {
    return;
  } else if (L <= tl && tr <= R) {
    bitset<61> newBitset;
    newBitset[x] = 1;
    tree[v] = newBitset;
    mark[v] = 1;
  } else {
    int m = (tl + tr) / 2;
    update(v * 2, tl, m, L, R, x);
    update(v * 2 + 1, m + 1, tr, L, R, x);
    tree[v] = tree[v * 2] | tree[v * 2 + 1];
  }
}
bitset<61> get(int v, int tl, int tr, int L, int R) {
  push(v);
  if (tl > R || tr < L) {
    return bitset<61>();
  } else if (L <= tl && tr <= R) {
    return tree[v];
  } else {
    int m = (tl + tr) / 2;
    return get(v * 2, tl, m, L, R) | get(v * 2 + 1, m + 1, tr, L, R);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  a.assign(n, TMP);
  id.assign(n, TMP);
  idLast.assign(n, TMP);
  idRev.assign(n + 1, TMP);
  g.assign(n, vector<int>());
  tree.assign(4 * n, bitset<61>());
  mark.assign(4 * n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(root, -1);
  build(1, 1, n);
  while (m--) {
    int com;
    cin >> com;
    if (com == 1) {
      int v, c;
      cin >> v >> c;
      v--;
      update(1, 1, n, id[v], idLast[v], c);
    } else {
      int v;
      cin >> v;
      v--;
      bitset<61> ans = get(1, 1, n, id[v], idLast[v]);
      cout << ans.count() << '\n';
    }
  }
  return 0;
}
