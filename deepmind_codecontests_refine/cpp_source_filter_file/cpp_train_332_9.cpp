#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int lg = 30;
int n, m;
int h[maxn];
bool mark[maxn];
int f[lg][maxn];
string ans[maxn];
vector<int> adj[maxn];
void in();
void dfs(int u);
void solve();
int dis(int u, int v);
void out();
int main() {
  in();
  solve();
  out();
}
void in() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> m;
}
void dfs(int u) {
  for (int i = 1; i < lg; i++)
    if (f[i - 1][u] != -1) f[i][u] = f[i - 1][f[i - 1][u]];
  mark[u] = 1;
  for (auto v : adj[u]) {
    if (!mark[v]) {
      h[v] = h[u] + 1;
      f[0][v] = u;
      dfs(v);
    }
  }
}
void solve() {
  for (int i = 0; i < lg; i++) fill(f[i], f[i] + n, -1);
  dfs(0);
  for (int t = 0; t < m; t++) {
    int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    x--;
    y--;
    a--;
    b--;
    ans[t] = "NO\n";
    int ab = dis(a, b);
    int xy = dis(x, y);
    int ax = dis(a, x);
    int ay = dis(a, y);
    int bx = dis(b, x);
    int by = dis(b, y);
    if (ab <= k && (k - ab) % 2 == 0) ans[t] = "YES\n";
    ab = ax + 1 + by;
    if (ab <= k && (k - ab) % 2 == 0) ans[t] = "YES\n";
    ab = ay + 1 + bx;
    if (ab <= k && (k - ab) % 2 == 0) ans[t] = "YES\n";
  }
}
int dis(int u, int v) {
  int tmp = h[u] + h[v];
  if (h[u] > h[v]) swap(u, v);
  for (int i = lg - 1; i >= 0; i--)
    if (f[i][v] != -1 && h[f[i][v]] >= h[u]) v = f[i][v];
  if (u == v) return tmp - 2 * h[u];
  for (int i = lg - 1; i >= 0; i--) {
    if (f[i][v] != f[i][u]) {
      v = f[i][v];
      u = f[i][u];
    }
  }
  u = f[0][u];
  return tmp - 2 * h[u];
}
void out() {
  for (int i = 0; i < n; i++) cout << ans[i];
}
