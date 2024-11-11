#include <bits/stdc++.h>
using namespace std;
const int N = 2000005, P = 1000000007;
using ll = long long;
int f[N], dep[N], fa[N], head[N], v[N], nxt[N], ptr, fid[N];
bool vis[N];
int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
inline bool merge(int x, int y) {
  x = getf(x);
  y = getf(y);
  if (x == y)
    return 1;
  else {
    f[x] = y;
    return 0;
  }
}
void dfs(int pos) {
  dep[pos] = dep[fa[pos]] + 1;
  for (int i = head[pos]; i != -1; i = nxt[i])
    if (v[i] != fa[pos])
      fa[v[i]] = pos, dfs(v[i]);
    else
      fid[pos] = i;
}
int deg[N], st[N], l[N], r[N], ed[N], fl;
void solve(int x, int y) {
  queue<int> q;
  stack<int> s;
  int xx = x, yy = y;
  while (dep[x] > dep[y]) --deg[x], q.push(fid[x]), x = fa[x];
  while (dep[x] < dep[y]) --deg[y], s.push(fid[y]), y = fa[y];
  while (x != y)
    --deg[x], q.push(fid[x]), x = fa[x], --deg[y], s.push(fid[y]), y = fa[y];
  --deg[x];
  while (!s.empty()) q.push(s.top() ^ 1), s.pop();
  x = xx;
  y = yy;
  int lst = q.front();
  q.pop();
  if (st[x] || l[lst]) fl = 1;
  st[x] = lst;
  l[lst] = -1;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    lst ^= 1;
    if (r[lst] || l[nd] || merge(nd, lst)) fl = 1;
    l[nd] = lst;
    r[lst] = nd;
    lst = nd;
  }
  lst ^= 1;
  if (ed[y] || r[lst]) fl = 1;
  ed[y] = lst;
  r[lst] = -1;
}
int n;
int fac[N];
inline void add_edge(int uu, int vv) {
  v[ptr] = vv;
  nxt[ptr] = head[uu];
  head[uu] = ptr++;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int ans = 1;
  fac[0] = 1;
  memset(head, -1, sizeof(head));
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
  int t1, t2;
  for (int i = 1; i < n; i++)
    cin >> t1 >> t2, add_edge(t1, t2), add_edge(t2, t1), ++deg[t1], ++deg[t2];
  dfs(1);
  for (int i = 0; i <= ptr; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    cin >> t1;
    if (t1) {
      if (vis[t1] || t1 == i) {
        fl = 1;
        break;
      }
      vis[t1] = 1;
      solve(t1, i);
      if (fl) break;
    }
  }
  if (fl) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (st[i] && ed[i] && getf(st[i]) == getf(ed[i]))
      ans *= (deg[i] == -1);
    else
      ans = ans * fac[deg[i]] % P;
  cout << ans << endl;
  return 0;
}
