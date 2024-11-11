#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 10;
const int maxt = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9;
int a[maxn];
vector<int> G[maxn];
int visited[maxn];
int par[maxn];
bool has_cycle;
int comp_cnt;
vector<long long> coin;
int dp[maxt];
void dfs(int v) {
  visited[v] = comp_cnt;
  for (int u : G[v]) {
    if (!visited[u]) {
      dfs(u);
    } else if (visited[u] == visited[v]) {
      has_cycle = true;
    }
  }
}
int add(int a, int b) {
  int c = a + b;
  if (c >= mod) {
    c -= mod;
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  long long t;
  cin >> n >> q >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(par, -1, sizeof par);
  while (q--) {
    int b, c;
    cin >> b >> c;
    G[--c].push_back(--b);
    par[b] = c;
  }
  for (int v = 0; v < n; v++) {
    if (!visited[v]) {
      comp_cnt++;
      dfs(v);
      if (has_cycle) {
        return cout << 0, 0;
      }
    }
  }
  for (int v = 0; v < n; v++) {
    if (G[v].empty()) {
      long long sum = 0;
      vector<int> path;
      int u = v;
      while (u != -1) {
        path.push_back(u);
        sum += a[u];
        coin.push_back(sum);
        u = par[u];
      }
      reverse(path.begin(), path.end());
      sum = 0;
      for (int i = 0; i < path.size(); i++) {
        sum += 1ll * i * a[path[i]];
      }
      t -= sum;
      if (t < 0) {
        return cout << 0, 0;
      }
    }
  }
  n = coin.size();
  dp[0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= t; j++) {
      if (coin[i] <= j) {
        dp[j] = add(dp[j], dp[j - coin[i]]);
      }
    }
  }
  cout << dp[t] << '\n';
}
