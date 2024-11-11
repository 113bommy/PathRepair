#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
struct edge {
  int u, v, t, c, id;
} e[N];
int n, m;
vector<edge> s[N];
bool cmp(edge a, edge b) { return a.c < b.c; }
struct TwoSat {
  static const int N = ::N << 1;
  int dfn[N], low[N], id[N], st[N], _st, _, cc;
  vector<int> g[N];
  int mark[N], n;
  void init(int _n) {
    for (int i = ((n = _n << 1)) - 1; i >= (0); --i) g[i].clear();
  }
  int new_node() {
    for (int i = (0); i < (2); i++) g[n++].clear();
    return n / 2 - 1;
  }
  void addedge(int a, int va, int b, int vb) {
    a = a << 1 | va;
    b = b << 1 | vb;
    g[a].push_back(b);
    g[b ^ 1].push_back(a ^ 1);
  }
  void add_set(int a, int va) {
    a = a << 1 | va;
    g[a ^ 1].push_back(a);
  }
  void add_then(int a, int va, int b, int vb) { addedge(a, va, b, vb ^ 1); }
  void add_or(int a, int va, int b, int vb) { addedge(a, va ^ 1, b, vb); }
  void add_xor(int a, int va, int b, int vb) {
    addedge(a, va, b, vb);
    addedge(b, vb, a, va);
  }
  void dfs(int c, vector<int> g[]) {
    dfn[c] = low[c] = ++cc;
    st[_st++] = c;
    for (auto t : g[c])
      if (!dfn[t])
        dfs(t, g), low[c] = min(low[c], low[t]);
      else if (!id[t])
        low[c] = min(low[c], dfn[t]);
    if (low[c] == dfn[c]) {
      ++_;
      do {
        id[st[--_st]] = _;
      } while (st[_st] != c);
    }
  }
  void find() {
    fill_n(dfn, n, cc = 0);
    fill_n(low, n, _st = 0);
    fill_n(id, n, _ = 0);
    for (int i = (0); i < (n); i++)
      if (!dfn[i]) dfs(i, g);
    for (int i = (0); i < (n); i++) --id[i];
    return;
  }
  bool solve() {
    find();
    for (int i = 0; i < n; i += 2) {
      if (id[i] == id[i + 1]) return 0;
      mark[i >> 1] = (id[i] > id[i + 1]);
    }
    return 1;
  }
} ts;
int p = 0;
void solve(int u) {
  sort(s[u].begin(), s[u].end(), cmp);
  for (int i = 0, j; i < (int)s[u].size();) {
    j = i;
    while (j < (int)s[u].size() && s[u][j].c == s[u][i].c) j++;
    if (j - i >= 3) {
      cout << "No\n";
      exit(0);
    }
    if (j - i == 2) {
      int x = s[u][i].id, y = s[u][i + 1].id;
      ts.add_or(x, 0, y, 0);
    }
    i = j;
  }
  for (int i = (0); i < ((int)s[u].size() - 1); i++) {
    ts.addedge(p + i + 1, 0, p + i, 0);
  }
  for (int i = (0); i < ((int)s[u].size()); i++) {
    int x = s[u][i].id;
    ts.addedge(x, 0, p + i, 0);
    if (i != (int)s[u].size() - 1) ts.addedge(x, 0, p + i + 1, 1);
  }
}
void link() {
  p = m;
  for (int i = (1); i < (n + 1); i++) {
    solve(i);
    p += (int)s[i].size();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  int L = 0, R = 0;
  for (int i = (1); i < (m + 1); i++) {
    cin >> e[i].u >> e[i].v >> e[i].c >> e[i].t;
    e[i].id = i - 1;
    R = max(R, e[i].t);
    s[e[i].u].push_back(e[i]);
    s[e[i].v].push_back(e[i]);
  }
  int ans = -1;
  while (L <= R) {
    int mid = (L + R) / 2;
    ts.init(3 * m);
    link();
    for (int i = (1); i < (m + 1); i++)
      if (e[i].t > mid) {
        ts.add_set(e[i].id, 1);
      }
    if (ts.solve()) {
      ans = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  if (ans == -1)
    cout << "No";
  else {
    ts.init(3 * m);
    link();
    for (int i = (1); i < (m + 1); i++)
      if (e[i].t >= ans) ts.add_set(e[i].id, 1);
    ts.solve();
    cout << "Yes\n";
    vector<int> task;
    for (int i = 0; i < m; ++i)
      if (!ts.mark[i]) task.push_back(i + 1);
    cout << ans << " " << (int)task.size() << "\n";
    for (auto v : task) cout << v << " ";
  }
  return 0;
}
