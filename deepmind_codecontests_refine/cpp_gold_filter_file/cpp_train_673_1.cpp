#include <bits/stdc++.h>
const int N = 110000, K = 1100000, M = 1000000007;
struct item {
  int tgt, dir;
  item *next;
  item() {}
  item(int tgt, int dir, item *next) : tgt(tgt), dir(dir), next(next) {}
} * list[N], storage[2 * N];
struct query {
  int tgt, id;
  query *next;
  query() {}
  query(int tgt, int id, query *next) : tgt(tgt), id(id), next(next) {}
} * qlist[N], qstorage[2 * K];
bool vis[K];
int lca[K], ufa[N];
int ufind(int a) {
  if (ufa[a] == a) {
    return a;
  }
  int r = ufind(ufa[a]);
  ufa[a] = r;
  return r;
}
void tarjan(int a, int fa) {
  vis[a] = true;
  for (query *p = qlist[a]; p; p = p->next) {
    if (vis[p->tgt]) {
      lca[p->id] = ufind(p->tgt);
    }
  }
  for (item *p = list[a]; p; p = p->next) {
    if (p->tgt != fa) {
      tarjan(p->tgt, a);
      ufa[p->tgt] = a;
    }
  }
}
int lv[N][2], _2[K];
int dfs(int a, int fa) {
  int r = 0;
  for (item *p = list[a]; p; p = p->next) {
    if (p->tgt != fa) {
      r = (r + dfs(p->tgt, a)) % M;
      if (p->dir >= 0) {
        r = (r + _2[lv[p->tgt][p->dir]]) % M;
      }
      for (int d = 0; d < 2; d++) {
        lv[a][d] += lv[p->tgt][d];
      }
    }
  }
  return r;
}
int qin[K];
int main() {
  int n;
  scanf("%d", &n);
  item *loc = storage;
  memset(list, 0, sizeof(list));
  for (int i = 0; i < n - 1; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    a--;
    b--;
    list[a] = new (loc++) item(b, d ? 0 : -1, list[a]);
    list[b] = new (loc++) item(a, d ? 1 : -1, list[b]);
  }
  int q;
  scanf("%d", &q);
  _2[0] = 0;
  for (int i = 1; i <= q; i++) {
    _2[i] = ((_2[i - 1] << 1) | 1) % M;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", qin + i);
    qin[i]--;
  }
  int prev = 0;
  query *qloc = qstorage;
  memset(qlist, 0, sizeof(qlist));
  for (int i = 0; i < q; i++) {
    qlist[prev] = new (qloc++) query(qin[i], i, qlist[prev]);
    qlist[qin[i]] = new (qloc++) query(prev, i, qlist[qin[i]]);
    prev = qin[i];
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    ufa[i] = i;
  }
  tarjan(0, -1);
  memset(lv, 0, sizeof(lv));
  prev = 0;
  for (int i = 0; i < q; i++) {
    lv[prev][0]++;
    lv[qin[i]][1]++;
    lv[lca[i]][0]--;
    lv[lca[i]][1]--;
    prev = qin[i];
  }
  printf("%d\n", dfs(0, -1));
  return 0;
}
