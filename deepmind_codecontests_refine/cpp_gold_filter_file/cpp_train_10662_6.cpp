#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int a[N];
int n, q;
int f[N];
void add(int id, int val) {
  for (; id < N; id += (id & -id)) f[id] += val;
}
int sum(int x) {
  int res = 0;
  for (; x > 0; x -= (x & -x)) res += f[x];
  return res;
}
int tin[N];
int tout[N];
bool h[N];
int timer = 1;
void dfs(int node, int par = -1, int dep = 0) {
  h[node] = dep;
  tin[node] = tout[node] = timer++;
  for (auto x : g[node])
    if (x != par) dfs(x, node, dep ^ 1), tout[node] = tout[x];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i + 1];
  int u, v, x;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  for (int i = 0; i < q; i++) {
    cin >> x >> u;
    if (x == 1) {
      cin >> v;
      if (h[u]) v *= -1;
      add(tin[u], v);
      add(tout[u] + 1, -v);
    } else {
      int res = sum(tin[u]);
      if (h[u]) res = -res;
      res += a[u];
      cout << res << '\n';
    }
  }
}
