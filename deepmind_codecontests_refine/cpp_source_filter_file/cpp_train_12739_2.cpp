#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const int maxn = 1e5 + 10;
const int base = 29;
const int mod = 1e9 + 7;
const int INF = 1e9 + 100;
vector<int> g[maxn];
int Root[maxn * 70], L[maxn * 70], R[maxn * 70], st[maxn], en[maxn], cur;
vector<pair<int, int> > query[maxn];
inline void dfs(int node, int fa = -1) {
  st[node] = cur++;
  for (auto u : g[node]) {
    if (u - fa) dfs(u, node);
  }
  en[node] = cur - 1;
}
int n, q;
int lazy[maxn * 70], stree[maxn * 70];
inline int add(int ql, int qr, int p, int l = 0, int r = n - 1) {
  if (l > qr || r < ql) return p;
  int ret = cur++;
  if (l >= ql && r <= qr) {
    L[ret] = L[p], R[ret] = R[p];
    stree[ret] = lazy[ret] = r - l + 1;
    return ret;
  }
  int mid = (l + r) >> 1;
  lazy[ret] = lazy[p];
  L[ret] = add(ql, qr, L[p], l, mid);
  R[ret] = add(ql, qr, R[p], mid + 1, r);
  stree[ret] = lazy[ret] ? r - l + 1 : stree[L[ret]] + stree[R[ret]];
  return ret;
}
int res[maxn];
inline void calc(int node, int fa = 0) {
  Root[node] = Root[fa];
  for (auto q : query[node]) Root[node] = add(q.first, q.second, Root[node]);
  res[node] = max(stree[Root[node]] - 1, 0);
  for (auto u : g[node])
    if (u - fa) calc(u, node);
}
inline void build(int p, int l = 0, int r = n - 1) {
  if (l == r) return;
  L[p] = cur++;
  R[p] = cur++;
  int mid = (l + r) >> 1;
  build(L[p], l, mid), build(R[p], mid + 1, r);
}
int32_t main() {
  n = in(), q = in();
  for (int i = 0; i < n - 1; i++) {
    int v = in(), u = in();
    g[v].push_back(u), g[u].push_back(v);
  }
  dfs(1);
  cur = 1;
  Root[0] = 0;
  build(0, 0, n - 1);
  for (int i = 0; i < q; i++) {
    int a = in(), b = in();
    query[a].push_back({st[b], en[b]});
    query[b].push_back({st[a], en[a]});
  }
  for (int i = 1; i <= n; i++)
    if (query[i].size()) query[i].push_back({st[i], en[i]});
  calc(1);
  for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
