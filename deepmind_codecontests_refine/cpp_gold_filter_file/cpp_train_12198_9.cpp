#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 70;
const int maxm = 1e6 + 70;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
int n, m, k;
int f[maxn];
int u[maxm], v[maxm], w[maxm], r[maxm], ans[maxm], rt;
bool vis[maxm];
bool cmp(int x, int y) { return w[x] < w[y]; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
bool Union(int x, int y) {
  int p = find(x), q = find(y);
  if (p != q) {
    f[p] = q;
    return true;
  }
  return false;
}
vector<pair<int, int> > G[maxn];
vector<int> T1[maxn], T2[maxn];
int L[maxn], fa[maxn], fe[maxn], anc[maxn][20], mx[maxn][20];
void dfs(int u) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first;
    if (v != fa[u]) {
      fa[v] = u;
      fe[v] = G[u][i].second;
      mx[v][0] = w[fe[v]];
      L[v] = L[u] + 1;
      dfs(v);
    }
  }
}
void preprocess() {
  for (int i = 1; i <= n; i++) {
    anc[i][0] = fa[i];
    for (int j = 1; (1 << j) < n; j++) anc[i][j] = -1;
  }
  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 1; i <= n; i++) {
      if (anc[i][j - 1] != -1) {
        int a = anc[i][j - 1];
        anc[i][j] = anc[a][j - 1];
        mx[i][j] = max(mx[i][j - 1], mx[a][j - 1]);
      }
    }
  }
}
int lca(int p, int q, int& ans) {
  if (L[p] < L[q]) swap(p, q);
  int log = 0;
  for (; (1 << log) <= L[p]; log++)
    ;
  log--;
  ans = -INF;
  for (int i = log; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) {
      ans = max(ans, mx[p][i]);
      p = anc[p][i];
    }
  }
  if (p == q) {
    return p;
  }
  for (int i = log; i >= 0; i--) {
    if (anc[p][i] != anc[q][i]) {
      ans = max(ans, mx[p][i]);
      ans = max(ans, mx[q][i]);
      p = anc[p][i];
      q = anc[q][i];
    }
  }
  ans = max(ans, mx[p][0]);
  ans = max(ans, mx[q][0]);
  return fa[p];
}
struct Node {
  Node* ch[2];
  int v, r, cnt, sz;
  Node(int v, int c) : v(v), cnt(c), sz(c) {
    ch[0] = ch[1] = NULL;
    r = rand();
  }
  bool operator<(const Node& rhs) const { return r < rhs.r; }
  int cmp(int x) const {
    if (x == v) return -1;
    return x < v ? 0 : 1;
  }
  void maintain() {
    sz = cnt;
    if (ch[0] != NULL) sz += ch[0]->sz;
    if (ch[1] != NULL) sz += ch[1]->sz;
  }
};
void rotate(Node*& o, int d) {
  Node* k = o->ch[d ^ 1];
  o->ch[d ^ 1] = k->ch[d];
  k->ch[d] = o;
  o->maintain();
  k->maintain();
  o = k;
}
void insert(Node*& o, int x, int c) {
  if (o == NULL)
    o = new Node(x, c);
  else {
    int d = o->cmp(x);
    if (d == -1)
      o->cnt += c;
    else {
      insert(o->ch[d], x, c);
      if (o->ch[d] > o) rotate(o, d ^ 1);
    }
    o->maintain();
  }
}
void remove(Node*& o, int x, int c) {
  int d = o->cmp(x);
  if (d == -1) {
    assert(o->cnt >= c);
    if (o->cnt - c > 0)
      o->cnt -= c;
    else {
      if (o->ch[0] != NULL && o->ch[1] != NULL) {
        int d2 = (o->ch[0] > o->ch[1] ? 1 : 0);
        rotate(o, d2);
        remove(o->ch[d2], x, c);
      } else {
        Node* u = o;
        if (o->ch[0] == NULL)
          o = o->ch[1];
        else
          o = o->ch[0];
        delete u;
      }
    }
  } else {
    remove(o->ch[d], x, c);
  }
  if (o != NULL) o->maintain();
}
int getmin(Node* o) {
  if (o == NULL) return 1e9;
  while (o->ch[0] != NULL) o = o->ch[0];
  return o->v;
}
void mergeto(Node*& src, Node*& dest) {
  if (src == NULL) return;
  mergeto(src->ch[0], dest);
  mergeto(src->ch[1], dest);
  insert(dest, src->v, src->cnt);
  delete src;
  src = NULL;
}
void removetree(Node*& o) {
  if (o == NULL) return;
  removetree(o->ch[0]);
  removetree(o->ch[1]);
  delete o;
  o = NULL;
}
Node* root[maxn];
void dfs2(int u) {
  int sz = 0, son = -1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first;
    if (v != fa[u]) {
      dfs2(v);
      if (root[v] != NULL && root[v]->sz > sz) {
        son = v;
        sz = root[v]->sz;
      }
    }
  }
  if (son != -1) {
    root[u] = root[son];
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].first;
      if (v != fa[u] && v != son) {
        mergeto(root[v], root[u]);
        removetree(root[v]);
      }
    }
  }
  for (int i = 0; i < T1[u].size(); i++) remove(root[u], T1[u][i], 1);
  for (int i = 0; i < T2[u].size(); i++) insert(root[u], T2[u][i], 1);
  if (u != rt) ans[fe[u]] = getmin(root[u]);
}
int main() {
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      T1[i].clear();
      T2[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", &u[i], &v[i], &w[i]);
      r[i] = i;
    }
    sort(r + 1, r + m + 1, cmp);
    memset(vis, 0, m + 1);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
      int x = r[i];
      if (Union(u[x], v[x])) {
        vis[x] = 1;
        G[u[x]].push_back(make_pair(v[x], x));
        G[v[x]].push_back(make_pair(u[x], x));
      }
    }
    rt = 1;
    L[rt] = 0;
    fa[rt] = -1;
    dfs(rt);
    preprocess();
    for (int i = 1; i <= m; i++) {
      if (vis[i]) continue;
      int p = lca(u[i], v[i], ans[i]);
      if (p != u[i]) {
        T2[u[i]].push_back(w[i]);
        T1[p].push_back(w[i]);
      }
      if (p != v[i]) {
        T2[v[i]].push_back(w[i]);
        T1[p].push_back(w[i]);
      }
    }
    for (int i = 1; i <= n; i++)
      if (root[i] != NULL) removetree(root[i]);
    dfs2(rt);
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
