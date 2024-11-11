#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000;
const int MAXV = 6 * MAXN;
const int MAXE = 20 * MAXN;
struct Graph {
  struct edge {
    int to;
    edge *nxt;
  } edges[MAXE + 5], *adj[MAXV + 5], *ecnt;
  Graph() { ecnt = edges; }
  void addedge(int u, int v) {
    edge *p = (++ecnt);
    p->to = v, p->nxt = adj[u], adj[u] = p;
  }
} G1, G2;
int n, m, cnt;
struct edge {
  int u, v, c, t, id;
  edge() {}
  edge(int _u, int _v, int _c, int _t, int _id)
      : u(_u), v(_v), c(_c), t(_t), id(_id) {}
} e[MAXN + 5];
bool cmp(const edge &a, const edge &b) { return a.t < b.t; }
int dfn[MAXV + 5], low[MAXV + 5], id[MAXV + 5];
int stk[MAXV + 5], tp, dcnt, tot;
void dfs(int x) {
  dfn[x] = low[x] = (++dcnt), stk[++tp] = x;
  for (Graph::edge *p = G2.adj[x]; p; p = p->nxt) {
    if (dfn[p->to]) {
      if (!id[p->to]) low[x] = min(low[x], dfn[p->to]);
    } else
      dfs(p->to), low[x] = min(low[x], low[p->to]);
  }
  if (low[x] >= dfn[x]) {
    tot++;
    do {
      id[stk[tp]] = tot;
    } while (stk[tp--] != x);
  }
}
bool check(int x) {
  G2 = G1;
  for (int i = x + 1; i < m; i++) G2.addedge(e[i].id << 1 | 1, e[i].id << 1);
  for (int i = 0; i < cnt; i++) dfn[i] = low[i] = id[i] = 0;
  dcnt = tot = 0;
  for (int i = 0; i < cnt; i++)
    if (!dfn[i]) dfs(i);
  for (int i = 0; i < m; i++) {
    if (id[i << 1] == id[i << 1 | 1]) return false;
  }
  return true;
}
vector<int> v1[MAXV + 5];
void dfs2(int x) {
  dfn[x] = low[x] = (++dcnt), stk[++tp] = x;
  for (Graph::edge *p = G2.adj[x]; p; p = p->nxt) {
    if (dfn[p->to]) {
      if (!id[p->to]) low[x] = min(low[x], dfn[p->to]);
    } else
      dfs2(p->to), low[x] = min(low[x], low[p->to]);
  }
  if (low[x] >= dfn[x]) {
    tot++;
    do {
      v1[tot].push_back(stk[tp]);
      id[stk[tp]] = tot;
    } while (stk[tp--] != x);
  }
}
bool tag[MAXV + 5];
vector<int> ans;
void print(int x) {
  G2 = G1;
  for (int i = x + 1; i < m; i++) G2.addedge(e[i].id << 1 | 1, e[i].id << 1);
  for (int i = 0; i < cnt; i++) dfn[i] = low[i] = id[i] = 0;
  dcnt = tot = 0;
  for (int i = 0; i < cnt; i++)
    if (!dfn[i]) dfs2(i);
  for (int i = 1; i <= tot; i++) {
    for (int j = 0; j < (int)v1[i].size(); j++) {
      int x = v1[i][j];
      for (Graph::edge *p = G2.adj[x]; p; p = p->nxt)
        if (tag[id[p->to]]) tag[i] = true;
    }
    if (!tag[i]) {
      for (int j = 0; j < (int)v1[i].size(); j++)
        if (v1[i][j] < 2 * m) tag[id[v1[i][j] ^ 1]] = true;
    }
  }
  for (int i = 0; i < m; i++) {
    if (tag[id[i << 1]]) ans.push_back(i + 1);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
}
map<int, int> mp;
vector<edge> vec[MAXN + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, c, t;
    scanf("%d%d%d%d", &u, &v, &c, &t);
    e[i] = edge(u, v, c, t, i);
    vec[u].push_back(e[i]), vec[v].push_back(e[i]);
  }
  cnt = 2 * m;
  for (int i = 1; i <= n; i++) {
    bool flag = false;
    mp.clear();
    for (int j = 0; j < (int)vec[i].size(); j++) {
      if (mp.count(vec[i][j].c)) {
        if (flag)
          puts("No"), exit(0);
        else
          flag = true;
        int x = vec[i][j].id, y = mp[vec[i][j].c];
        G1.addedge(x << 1, y << 1 | 1), G1.addedge(y << 1, x << 1 | 1);
      } else
        mp[vec[i][j].c] = vec[i][j].id;
    }
    if (vec[i].size() >= 2) {
      int lst = (vec[i][0].id << 1);
      for (int j = 1; j < (int)vec[i].size(); j++) {
        int x = vec[i][j].id;
        G1.addedge(x << 1 | 1, lst);
        if (j + 1 == (int)vec[i].size()) break;
        G1.addedge(cnt, x << 1), G1.addedge(cnt, lst);
        lst = cnt, cnt++;
      }
      lst = (vec[i][vec[i].size() - 1].id << 1);
      for (int j = (int)vec[i].size() - 2; j >= 0; j--) {
        int x = vec[i][j].id;
        G1.addedge(x << 1 | 1, lst);
        if (j == 0) break;
        G1.addedge(cnt, x << 1), G1.addedge(cnt, lst);
        lst = cnt, cnt++;
      }
    }
  }
  sort(e, e + m, cmp);
  if (!check(m - 1))
    puts("No"), exit(0);
  else
    puts("Yes");
  int le = -1, ri = m - 1;
  while (le < ri) {
    int mid = (le + ri) >> 1;
    if (check(mid))
      ri = mid;
    else
      le = mid + 1;
  }
  printf("%d ", le == -1 ? 0 : e[le].t), print(le);
}
