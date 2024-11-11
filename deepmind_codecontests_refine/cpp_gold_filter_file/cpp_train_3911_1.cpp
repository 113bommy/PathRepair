#include <bits/stdc++.h>
const int MAXN = 200100, MAXM = 400100;
int n, m, s, t, ds, dt, belong[MAXN], cnt, degs, degt, edgeid[MAXN][2];
bool inst[MAXM], connectedst;
struct undiredge {
  int u, v;
} edges[MAXM];
struct diredge {
  int to, next, id;
};
struct graph {
  int ecnt, head[MAXM];
  diredge edges[MAXM << 1];
  inline void addedge(int u, int v, int id) {
    edges[++ecnt].to = v;
    edges[ecnt].id = id;
    edges[ecnt].next = head[u];
    head[u] = ecnt;
  }
} g;
struct tools {
  static inline void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
  }
};
struct unionsetnode {
  int fa, size;
};
struct unionset {
  unionsetnode nodes[MAXN];
  int find(int x) {
    if (nodes[x].fa == x) return x;
    return nodes[x].fa = find(nodes[x].fa);
  }
  inline void merge(int x, int y) {
    x = find(x), y = find(y);
    if (nodes[x].size < nodes[y].size) tools::swap(x, y);
    nodes[x].size += nodes[y].size;
    nodes[y].fa = x;
  }
  inline bool same(int x, int y) { return find(x) == find(y); }
  inline void init() {
    for (int i = 1; i <= n; i++) nodes[i].fa = i, nodes[i].size = 1;
  }
} uset;
void dfs(int x) {
  belong[x] = cnt;
  for (int i = g.head[x]; i; i = g.edges[i].next) {
    int &to = g.edges[i].to;
    if (to == s || to == t) continue;
    if (!belong[to]) dfs(to);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[i].u = u, edges[i].v = v;
    g.addedge(u, v, i), g.addedge(v, u, i);
  }
  scanf("%d%d%d%d", &s, &t, &ds, &dt);
  for (int i = 1; i <= n; i++)
    if (!belong[i] && i ^ s && i ^ t) cnt++, dfs(i);
  uset.init();
  for (int i = 1; i <= m; i++) {
    int u = edges[i].u, v = edges[i].v;
    if (u == s || u == t || v == s || v == t) continue;
    if (!uset.same(u, v)) {
      uset.merge(u, v);
      inst[i] = true;
    }
  }
  for (int i = g.head[s]; i; i = g.edges[i].next)
    edgeid[belong[g.edges[i].to]][0] = g.edges[i].id;
  for (int i = g.head[t]; i; i = g.edges[i].next)
    edgeid[belong[g.edges[i].to]][1] = g.edges[i].id;
  for (int i = 1; i <= cnt; i++) {
    if (!(edgeid[i][0] && edgeid[i][1])) {
      if (edgeid[i][0])
        inst[edgeid[i][0]] = true, degs++;
      else
        inst[edgeid[i][1]] = true, degt++;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (edgeid[i][0] && edgeid[i][1]) {
      if (!connectedst) {
        inst[edgeid[i][0]] = inst[edgeid[i][1]] = true;
        degs++, degt++;
        connectedst = true;
      } else {
        if (ds - degs >= dt - degt)
          inst[edgeid[i][0]] = true, degs++;
        else
          inst[edgeid[i][1]] = true, degt++;
      }
    }
  }
  if (!connectedst) degs++, degt++;
  if (degs <= ds && degt <= dt) {
    printf("Yes\n");
    for (int i = 1; i <= m; i++)
      if (inst[i]) printf("%d %d\n", edges[i].u, edges[i].v);
    if (!connectedst) printf("%d %d\n", s, t);
  } else
    printf("No\n");
  return 0;
}
