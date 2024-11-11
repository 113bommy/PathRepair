#include <bits/stdc++.h>
using namespace std;
long long int par[100005];
vector<long long int> adj[100005];
long long int sum[100005];
long long int ans[100005] = {};
bool vis[100005];
void dfs(long long int u, long long int prev) {
  long long int min1 = LLONG_MAX;
  vis[u] = true;
  vector<long long int>::iterator it;
  if (sum[u] != -1)
    ans[u] = sum[u] - prev;
  else {
    for (it = adj[u].begin(); it != adj[u].end(); it++) {
      if (sum[*it] < min1) min1 = sum[*it];
    }
    if (min1 != LLONG_MAX) ans[u] = min1 - prev;
    sum[u] = ans[u] + prev;
  }
  for (it = adj[u].begin(); it != adj[u].end(); it++) {
    if (!vis[*it]) dfs(*it, sum[u]);
  }
}
int main() {
  long long int n, i, x, fin = 0, g = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    vis[i] = false;
    par[i] = i;
  }
  for (i = 2; i <= n; i++) {
    cin >> x;
    par[i] = x;
    adj[x].push_back(i);
  }
  for (i = 1; i <= n; i++) cin >> sum[i];
  ans[1] = sum[1];
  dfs(1, 0);
  for (i = 1; i <= n; i++) {
    if (ans[i] < 0) {
      g = 1;
      cout << -1 << endl;
      break;
    }
    fin += ans[i];
  }
  if (g != 1) cout << fin << endl;
}
