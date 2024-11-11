#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 5;
const double pi = acos(-1);
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 998244353;
int n, up[17][N], tin[N], tout[N], timer, d[N], u[N], v[N];
vector<int> g[N];
map<pair<int, int>, int> ans;
void dfs(int v, int p) {
  tin[v] = ++timer;
  up[0][v] = p;
  for (int i = 1; i <= 16; i++) {
    up[i][v] = up[i - 1][up[i - 1][v]];
  }
  for (int i = 0; i < (int)(g[v]).size(); i++) {
    int to = g[v][i];
    if (to != p) dfs(to, v);
  }
  tout[v] = ++timer;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = 16; i >= 0; i--) {
    if (!upper(up[i][a], b)) {
      a = up[i][a];
    }
  }
  return up[0][a];
}
void calc(int v, int p) {
  for (int i = 0; i < (int)(g[v]).size(); i++) {
    int to = g[v][i];
    if (to != p) {
      calc(to, v);
      d[v] += d[to];
    }
  }
  ans[{v, p}] = ans[{p, v}] = d[v];
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u[i] >> v[i];
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  dfs(1, 0);
  tin[0] = 0;
  tout[0] = inf;
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int a, b;
    cin >> a >> b;
    int l = lca(a, b);
    d[l] -= 2;
    d[a]++;
    d[b]++;
  }
  calc(1, 0);
  for (int i = 1; i < n; i++) {
    cout << ans[{u[i], v[i]}] << " ";
  }
  return 0;
}
