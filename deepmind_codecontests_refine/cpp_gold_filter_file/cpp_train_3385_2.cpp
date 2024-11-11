#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 9;
using ll = long long;
const ll INF = 1e18;
int n, m, p[M], q[M], a[M], b[M], d[M], g[M];
char s[M];
map<pair<int, int>, int> c, f;
using ll = long long;
namespace Dinic {
const int N = 105, M = 1005;
int head[N], v[M], nxt[M], ptr, t;
ll w[M];
inline void padd_edge(int uu, int vv, ll ww) {
  v[ptr] = vv;
  w[ptr] = ww;
  nxt[ptr] = head[uu];
  head[uu] = ptr++;
}
int dis[N], cur[N];
bool vis[N];
bool bfs(int s, int t) {
  memset(vis, 0, sizeof(vis));
  memset(dis, -1, sizeof(dis));
  queue<int> q;
  q.push(s);
  dis[s] = 1;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (int i = head[nd]; i != -1; i = nxt[i])
      if (w[i] && dis[v[i]] == -1) {
        dis[v[i]] = dis[nd] + 1;
        q.push(v[i]);
      }
  }
  return dis[t] != -1;
}
ll dfs(int pos, ll flow) {
  if (pos == t) return flow;
  ll tmp = flow;
  for (int &i = cur[pos]; i != -1; i = nxt[i])
    if (w[i] && dis[v[i]] == dis[pos] + 1) {
      ll fl = dfs(v[i], min(flow, w[i]));
      w[i] -= fl;
      w[i ^ 1] += fl;
      flow -= fl;
      if (!flow) break;
    }
  return tmp - flow;
}
void init() {
  memset(head, -1, sizeof(head));
  memset(nxt, -1, sizeof(nxt));
}
inline void add_edge(int uu, int vv, ll ww) {
  padd_edge(uu, vv, ww);
  padd_edge(vv, uu, 0);
}
ll dinic(int s, int t) {
  Dinic::t = t;
  ll ret = 0;
  while (bfs(s, t)) memcpy(cur, head, sizeof(cur)), ret += dfs(s, INF);
  return ret;
}
};  // namespace Dinic
void solve() {
  for (int i = 1; i <= m; i++) d[i] = 0;
  for (int i = 1; i <= m - 2; i++) ++d[a[i]];
  a[m - 1] = m;
  map<pair<int, int>, int> c = ::c;
  vector<pair<int, int>> e;
  for (int i = 1, j = 1; i < m; i++, j++) {
    while (d[j]) ++j;
    e.push_back({j, a[i]});
    while (i < m && !--d[a[i]] && a[i] < j) e.push_back({a[i], a[i + 1]}), ++i;
  }
  for (auto &i : e) {
    if (i.first > i.second) swap(i.first, i.second);
    if (!c[i]--) return;
  }
  int nn = m + m * (m + 1) / 2 + 2, ss = nn - 1, tt = nn;
  Dinic::ptr = 0;
  for (int i = 1; i <= nn; i++) Dinic::head[i] = -1;
  int k = m;
  vector<pair<int, int>> ff(nn);
  for (int i = 1; i <= m; i++) {
    Dinic::add_edge(i, tt, b[i]);
    for (int j = i; j <= m; j++) {
      f[{i, j}] = ++k;
      ff[k] = {i, j};
      Dinic::add_edge(ss, k, c[{i, j}]);
      Dinic::add_edge(k, i, INF);
      Dinic::add_edge(k, j, INF);
    }
  }
  ll val = Dinic::dinic(ss, tt);
  if (val != n - m) return;
  for (auto &i : e) cout << p[i.first] << ' ' << p[i.second] << endl;
  for (int i = 1; i <= m; i++) {
    q[i] = p[i];
    for (int j = Dinic::head[i]; j != -1; j = Dinic::nxt[j]) {
      int v = Dinic::v[j];
      if (v <= m || v >= ss) continue;
      v = ff[v].first == i ? ff[v].second : ff[v].first;
      while (Dinic::w[j]--) cout << ++q[i] << ' ' << p[v] << endl;
    }
  }
  exit(0);
}
void dfs(int x) {
  if (x == m - 1) return solve();
  for (int i = 1; i <= m; i++) a[x] = i, dfs(x + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i *= 10) p[++m] = i;
  for (int i = 1; i < m; i++) b[i] = p[i + 1] - 1 - p[i];
  b[m] = n - p[m];
  for (int i = 1, x, y; i < n; i++) {
    cin >> s;
    x = strlen(s);
    cin >> s;
    y = strlen(s);
    if (x > y) swap(x, y);
    ++c[{x, y}];
  }
  if (m == 1) {
    if (c[{1, 1}] != n - 1) {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 1; i < n; i++) cout << i << ' ' << i + 1 << endl;
    return 0;
  }
  dfs(1);
  cout << -1 << endl;
  return 0;
}
