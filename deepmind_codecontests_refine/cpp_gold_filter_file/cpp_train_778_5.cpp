#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6) + 3;
const int MOD = 7 + int(1e9);
const double PI = 4 * atan(1);
const double eps = 1e-10;
const long long oo = 1e10;
struct adj {
  int head[N], nxt[N], to[N], ecnt, n;
  int ti[N], col[N];
  void addEdge(int a, int b, int color = 0, int t = 0) {
    nxt[ecnt] = head[a];
    head[a] = ecnt;
    ti[ecnt] = t;
    col[ecnt] = color;
    to[ecnt++] = b;
  }
  void init() {
    ecnt = 0;
    memset(head, -1, n * sizeof(head[0]));
  }
} adj, vadj;
int vis[N], vid = 0, nodes[N], ndcnt = 0, comp[N], comps;
int notsrc[N], notsink[N], dfst[N], low[N], curt;
int val[N];
void dfs(int u) {
  vis[u] = vid;
  low[u] = dfst[u] = curt++;
  nodes[ndcnt++] = u;
  comp[u] = -1;
  for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e]) {
    if (vis[v] != vid) {
      dfs(v);
      low[u] = (low[u] < low[v] ? low[u] : low[v]);
    } else {
      if (comp[v] == -1) low[u] = (low[u] < low[v] ? low[u] : low[v]);
    }
  }
  if (low[u] == dfst[u]) {
    do {
      comp[nodes[--ndcnt]] = comps;
    } while (nodes[ndcnt] != u);
    comps++;
  }
}
void tarjan() {
  ndcnt = 0;
  vid++;
  curt = 0;
  comps = 0;
  for (int i = 0; i < adj.n; i++)
    if (vis[i] != vid) dfs(i);
}
int var(int x) { return 2 * x; }
int notvar(int x) { return x ^ 1; }
void addor(int x, int y) {
  adj.addEdge(notvar(x), y);
  adj.addEdge(notvar(y), x);
}
void buildsol(int u, int par = -1) {
  if (vis[u] == vid) return;
  vis[u] = vid;
  for (int e = adj.head[u], v; ~e && (v = adj.to[e], 1); e = adj.nxt[e]) {
    buildsol(v, u);
  }
  if (val[comp[u]] == -1 && (par == -1 || comp[u] != comp[par])) {
    val[comp[u]] = 1;
    val[comp[notvar(u)]] = 0;
  }
}
int n, m;
int va[N];
bool ok(int cur_t) {
  adj.n = 6 * m;
  adj.init();
  vector<int> ve;
  vector<int> vee;
  vector<int> vaa;
  int cn = m;
  for (int u = 0; u < n; u++) {
    ve.clear();
    vee.clear();
    vaa.clear();
    for (int e = vadj.head[u], v; ~e && (v = vadj.to[e], 1); e = vadj.nxt[e]) {
      if (vadj.ti[e] > cur_t) {
        adj.addEdge(var(e / 2), notvar(var(e / 2)));
      }
      if (vadj.col[e] == va[u]) {
        vaa.push_back(e / 2);
      }
      ve.push_back(cn++);
      vee.push_back(e / 2);
    }
    if (vaa.size()) {
      adj.addEdge(notvar(var(vaa[0])), var(vaa[1]));
      adj.addEdge(notvar(var(vaa[1])), var(vaa[0]));
    }
    for (int i = 0; i < ve.size(); i++) {
      adj.addEdge(notvar(var(ve[i])), notvar(var(vee[i])));
      adj.addEdge(var(vee[i]), var(ve[i]));
      if (i > 0) {
        adj.addEdge(notvar(var(ve[i])), notvar(var(ve[i - 1])));
        adj.addEdge(var(ve[i - 1]), var(ve[i]));
      }
      if (i < ve.size() - 1) {
        adj.addEdge(var(ve[i]), notvar(var(vee[i + 1])));
        adj.addEdge(var(vee[i + 1]), notvar(var(ve[i])));
      }
    }
  }
  tarjan();
  for (int i = 0; i < adj.n; i += 2) {
    if (comp[i] == comp[i + 1]) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(va, -1, sizeof(va));
  memset(val, -1, sizeof(val));
  int a, b, t, c;
  cin >> n >> m;
  vadj.n = n;
  vadj.init();
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c >> t;
    a--;
    b--;
    vadj.addEdge(a, b, c, t);
    vadj.addEdge(b, a, c, t);
  }
  for (int u = 0; u < n; u++) {
    map<int, int> maa;
    for (int e = vadj.head[u], v; ~e && (v = vadj.to[e], 1); e = vadj.nxt[e]) {
      maa[vadj.col[e]]++;
    }
    for (auto t : maa) {
      if (t.second >= 3) {
        cout << "No\n";
        return 0;
      }
      if (t.second == 2) {
        if (va[u] == -1)
          va[u] = t.first;
        else {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  int l = 0;
  int r = 1e9 + 5;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l > 1e9) {
    cout << "No\n";
  }
  int ans = r;
  if (ok(l)) {
    ans = l;
  } else {
    ok(r);
  }
  cout << "Yes\n";
  cout << ans << " ";
  int coun = 0;
  vid++;
  for (int i = 0; i < adj.n; i++) {
    if (vis[i] == vid) continue;
    buildsol(i);
  }
  for (int i = 0; i < m; i++) {
    if (val[comp[var(i)]] == 1) {
      coun++;
    }
  }
  cout << coun << endl;
  for (int i = 0; i < m; i++) {
    if (val[comp[var(i)]] == 1) {
      cout << i + 1 << " ";
    }
  }
  return 0;
}
