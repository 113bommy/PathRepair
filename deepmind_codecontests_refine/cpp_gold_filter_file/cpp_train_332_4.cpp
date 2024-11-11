#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 + 5;
const long long inf = 9223372036854775807;
int n, q, mark[maxn], h[maxn], par[maxn][50];
vector<int> adj[maxn];
void dfs(int v) {
  mark[v] = 1;
  for (auto u : adj[v]) {
    if (mark[u] == 0) {
      mark[u] = 1;
      h[u] = h[v] + 1;
      par[u][0] = v;
      for (int i = 1; i <= 31; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
      }
      dfs(u);
    }
  }
}
int lca(int u, int v) {
  if (h[v] < h[u]) {
    swap(u, v);
  }
  for (int i = 31; i >= 0; i--) {
    if (par[v][i] != 0 && h[par[v][i]] >= h[u]) {
      v = par[v][i];
    }
  }
  if (v == u) return v;
  for (int i = 31; i >= 0; i--) {
    if (par[v][i] != par[u][i]) {
      v = par[v][i], u = par[u][i];
    }
  }
  return par[v][0];
}
int lp(int u, int v) {
  int lc = lca(u, v), ans = 0;
  for (int i = 31; i >= 0; i--) {
    if (par[u][i] != 0 && h[par[u][i]] >= h[lc]) {
      ans += pow(2, i);
      u = par[u][i];
    }
    if (par[v][i] != 0 && h[par[v][i]] >= h[lc]) {
      ans += pow(2, i);
      v = par[v][i];
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v, a, b, k;
    cin >> u >> v >> a >> b >> k;
    int x = lp(a, b), y = lp(a, u) + 1 + lp(v, b), z = lp(a, v) + 1 + lp(u, b);
    if (x <= k && x % 2 == k % 2) {
      cout << "YES";
    } else if (y <= k && y % 2 == k % 2) {
      cout << "YES";
    } else if (z <= k && z % 2 == k % 2) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
