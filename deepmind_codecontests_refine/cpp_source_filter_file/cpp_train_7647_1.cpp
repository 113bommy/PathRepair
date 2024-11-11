#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 31) - 1;
int n, m;
int a[311], l[311], r[311];
int daan;
vector<pair<int, int> > v;
set<int> primk;
map<int, int> M, tx;
int cnt = 1;
int id(int x) {
  if (M.count(x) == 0) M[x] = cnt++;
  tx[M[x]] = x;
  return M[x];
}
const int Ni = 210;
const int MAX = 1 << 31 - 1;
struct Edge {
  int u, v, c;
  int next;
} edge[20 * Ni];
int edn;
int p[Ni];
int d[Ni];
int sp, tp;
void addedge(int u, int v, int c) {
  edge[edn].u = u;
  edge[edn].v = v;
  edge[edn].c = c;
  edge[edn].next = p[u];
  p[u] = edn++;
  edge[edn].u = v;
  edge[edn].v = u;
  edge[edn].c = 0;
  edge[edn].next = p[v];
  p[v] = edn++;
}
int bfs() {
  queue<int> q;
  memset(d, -1, sizeof(d));
  d[sp] = 0;
  q.push(sp);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = p[cur]; i != -1; i = edge[i].next) {
      int u = edge[i].v;
      if (d[u] == -1 && edge[i].c > 0) {
        d[u] = d[cur] + 1;
        q.push(u);
      }
    }
  }
  return d[tp] != -1;
}
int dfs(int a, int b) {
  int r = 0;
  if (a == tp) return b;
  for (int i = p[a]; i != -1 && r < b; i = edge[i].next) {
    int u = edge[i].v;
    if (edge[i].c > 0 && d[u] == d[a] + 1) {
      int x = min(edge[i].c, b - r);
      x = dfs(u, x);
      r += x;
      edge[i].c -= x;
      edge[i ^ 1].c += x;
    }
  }
  if (!r) d[a] = -2;
  return r;
}
int dinic(int sp, int tp) {
  int total = 0, t;
  while (bfs()) {
    while (t = dfs(sp, MAX)) total += t;
  }
  return total;
}
void sol() {
  for (__typeof((primk).begin()) it = (primk).begin(); it != (primk).end();
       it++) {
    int i, t = *it;
    M.clear();
    tx.clear();
    v.clear();
    cnt = 1;
    for (i = 1; i <= m; i++) {
      if (a[l[i]] % t == 0 && a[r[i]] % t == 0) {
        int ll = id(l[i]);
        int rr = id(r[i]);
        v.push_back(make_pair(ll, rr));
      }
    }
    edn = 0;
    memset(p, -1, sizeof(p));
    sp = 0;
    tp = n = cnt - 1;
    tp++;
    set<int> ss;
    for (i = 0; i < v.size(); i++) {
      int x = a[tx[v[i].first]];
      int y = a[tx[v[i].second]];
      int cntx = 0, cnty = 0;
      while (x % t == 0) {
        cntx++;
        x /= t;
      }
      while (y % t == 0) {
        cnty++;
        y /= t;
      }
      if (!ss.count(v[i].first))
        ss.insert(v[i].first), addedge(sp, v[i].first, cntx);
      if (!ss.count(v[i].second))
        ss.insert(v[i].second), addedge(v[i].second, tp, cnty);
      addedge(v[i].first, v[i].second, min(cntx, cnty));
    }
    daan += dinic(sp, tp);
  }
  printf("%d\n", daan);
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int x = a[i];
    for (j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        primk.insert(j);
        while (x % j == 0) x /= j;
      }
    }
    if (x > 1) primk.insert(j);
  }
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    if (l[i] % 2 == 0) swap(l[i], r[i]);
  }
  sol();
}
