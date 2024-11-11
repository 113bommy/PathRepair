#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 9;
struct Edge {
  int u, v, w;
  int id;
  int flag = 0;
} edge[maxn];
int fa[maxn];
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
bool cmp(Edge a, Edge b) { return a.w < b.w; }
int n, m;
vector<pair<int, int> > mp[maxn];
int dp[maxn], pa[maxn], sz[maxn];
pair<int, int> son[maxn];
int a[maxn];
void dfs1(int u, int fa) {
  sz[u] = 1;
  pa[u] = fa;
  dp[u] = dp[fa] + 1;
  for (pair<int, int> p : mp[u]) {
    int v = p.first;
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u].first]) son[u].first = v, son[u].second = p.second;
  }
}
int top[maxn], id[maxn], tim = 0;
void dfs2(int u, int fa, int tp, int cst) {
  id[u] = ++tim;
  top[u] = tp;
  a[tim] = cst;
  if (son[u].first) dfs2(son[u].first, u, tp, son[u].second);
  for (pair<int, int> p : mp[u]) {
    int v = p.first;
    if (v == fa || v == son[u].first) continue;
    dfs2(v, u, v, p.second);
  }
}
int sum[maxn << 2];
void build(int le, int ri, int rt) {
  if (le == ri) {
    sum[rt] = a[le];
    return;
  }
  int mid = (le + ri) >> 1;
  build(le, mid, rt << 1);
  build(mid + 1, ri, rt << 1 | 1);
  sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
int query(int L, int R, int le, int ri, int rt) {
  if (le >= L && ri <= R) {
    return sum[rt];
  }
  int res = 0;
  int mid = (le + ri) >> 1;
  if (mid >= L) res = max(res, query(L, R, le, mid, rt << 1));
  if (mid < R) res = max(res, query(L, R, mid + 1, ri, rt << 1 | 1));
  return res;
}
int solve(int u, int v) {
  int res = 0;
  while (top[u] != top[v]) {
    if (dp[top[u]] >= dp[top[v]]) {
      res = max(res, query(id[top[u]], id[u], 1, n, 1));
      u = pa[top[u]];
    } else {
      res = max(res, query(id[top[v]], id[v], 1, n, 1));
      v = pa[top[v]];
    }
  }
  if (id[u] != id[v]) {
    if (id[u] < id[v])
      res = max(res, query(id[u] + 1, id[v], 1, n, 1));
    else
      res = max(res, query(id[v] + 1, id[v], 1, n, 1));
  }
  return res;
}
vector<pair<int, int> > ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    edge[i].id = i;
  }
  sort(edge + 1, edge + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    int fu = find(u);
    int fv = find(v);
    if (fu == fv) continue;
    fa[fu] = fv;
    edge[i].flag = 1;
    mp[u].push_back(pair<int, int>(v, edge[i].w));
    mp[v].push_back(pair<int, int>(u, edge[i].w));
  }
  dfs1(1, 1);
  dfs2(1, 1, 1, 0);
  build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    if (edge[i].flag) continue;
    int u = edge[i].u;
    int v = edge[i].v;
    ans.push_back(pair<int, int>(edge[i].id, solve(u, v)));
  }
  sort(ans.begin(), ans.end());
  for (pair<int, int> a : ans) printf("%d ", a.second);
  puts("");
  return 0;
}
