#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(vector<T> &a, long long n) {
  T x;
  a.clear();
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
}
template <class T>
void write(vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << endl;
}
const int N = 100005;
const int LOG = 20;
vector<pair<int, int> > g[N];
vector<pair<int, pair<int, int> > > q;
vector<pair<pair<int, int>, pair<int, int> > > e;
int n, m;
int p[N];
int par[N][LOG], mx[N][LOG];
int ans[10 * N];
int t, tin[N], tout[N];
int fnd(int u) {
  if (u == p[u]) return u;
  return p[u] = fnd(p[u]);
}
void un(int a, int b) {
  int u = fnd(a);
  int v = fnd(b);
  if (u != v) {
    if (rand() & 1) swap(u, v);
    p[u] = v;
  }
}
void dfs(int u, int pp = 1, int w = 0) {
  tin[u] = t++;
  par[u][0] = pp;
  mx[u][0] = w;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
  }
  for (int i = 0; i < g[u].size(); i++) {
    if (g[u][i].first == pp) continue;
    dfs(g[u][i].first, u, g[u][i].second);
  }
  tout[u] = t++;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = LOG - 1; i >= 0; i--)
    if (!upper(par[a][i], b)) a = par[a][i];
  return par[a][0];
}
int mx_edge(int a, int b) {
  if (upper(a, b)) return 0;
  int res = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    if (!upper(par[a][i], b)) {
      res = max(res, mx[a][i]);
      a = par[a][i];
    }
  }
  return max(res, mx[a][0]);
}
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < N; i++) p[i] = i;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    e.push_back(make_pair(make_pair(c, i), make_pair(a, b)));
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < e.size(); i++) {
    int w = e[i].first.first;
    int id = e[i].first.second;
    int a = e[i].second.first;
    int b = e[i].second.second;
    if (fnd(a) != fnd(b)) {
      un(a, b);
      g[a].push_back(make_pair(b, w));
      g[b].push_back(make_pair(a, w));
      ans[id] = -1;
    } else
      q.push_back(make_pair(id, make_pair(a, b)));
  }
  dfs(1);
  for (int i = 0; i < q.size(); i++) {
    int id = q[i].first;
    int a = q[i].second.first;
    int b = q[i].second.second;
    ans[id] = max(mx_edge(a, b), mx_edge(b, a));
  }
  for (int i = 0; i < m; i++)
    if (ans[i] != -1) cout << ans[i] << " ";
}
