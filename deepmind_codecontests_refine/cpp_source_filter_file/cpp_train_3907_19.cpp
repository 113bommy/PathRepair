#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 2e5 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o << "\n";
  return;
}
long long n, sd[MAX], t[MAX], su[MAX], dp[MAXL][MAX], h[MAX];
vector<int> adj[MAX];
void dfs(int v, int p) {
  t[v] = 1;
  h[v] = h[p] + 1;
  dp[0][v] = p;
  for (int i = 1; i <= 20; i++) dp[i][v] = dp[i - 1][dp[i - 1][v]];
  for (int u : adj[v])
    if (u != p) {
      dfs(u, v);
      t[v] += t[u];
      sd[v] += t[u] + sd[u];
    }
}
void dfsu(int v, int p) {
  for (int u : adj[v])
    if (u != p) {
      su[u] = su[v] + sd[v] - sd[u] - t[u] + n - t[u];
      dfsu(u, v);
    }
}
long long g(int v, int x) {
  for (int i = 0; i <= 20; i++)
    if (x & (1 << i)) v = dp[i][v];
  return v;
}
void lca(int v, int u) {
  long long d = 1;
  long double ans = 0.0;
  if (h[v] > h[u]) swap(v, u);
  d += h[u] - h[v];
  long long z = g(u, h[u] - h[v]);
  if (z == v) {
    long long x = g(u, h[u] - h[v] - 1);
    ans = sd[u] * (n - t[x]) + (su[x] - (n - t[x])) * t[u];
    ans = (ans / (t[u] * (n - t[x]))) + d;
    OUT(ans, 7);
    return;
  }
  ans = (sd[v] * t[u]) + (sd[u] * t[v]);
  ans = ans / (t[v] * t[u]);
  u = z;
  d += 2;
  for (int i = 20; i >= 0; i--) {
    if (dp[i][v] != dp[i][u]) {
      v = dp[i][v];
      u = dp[i][u];
      d += 2;
    }
  }
  ans += d;
  OUT(ans, 7);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 1);
  dfsu(1, 1);
  while (m--) {
    long long x, y;
    cin >> x >> y;
    lca(x, y);
  }
  return 0;
}
