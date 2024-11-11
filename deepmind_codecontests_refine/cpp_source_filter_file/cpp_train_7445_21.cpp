#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, root, a[N], dp[N], sz[N];
vector<int> adj[N];
bool isFull[N];
bool dfs(int x, int u = root, int par = -1) {
  bool ok = false;
  isFull[u] = true, sz[u] = dp[u] = 1;
  if (a[u] < x) {
    isFull[u] = false, dp[u] = 0;
    for (auto v : adj[u])
      if (v != par) ok |= dfs(x, v, u), sz[u] += sz[v];
    return ok;
  }
  int mx1 = 0, mx2 = 0;
  for (auto v : adj[u])
    if (v != par) {
      ok |= dfs(x, v, u), sz[u] += sz[v];
      if (isFull[v])
        dp[u] += sz[v];
      else {
        isFull[v] = false;
        if (dp[v] >= mx1)
          swap(mx1, mx2), mx1 = dp[v];
        else
          mx2 = max(dp[v], mx2);
      }
    }
  return (dp[u] += mx1) + mx2 >= k || ok;
}
void readInput() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
void solve() {
  for (int i = 0; i < n; i++)
    if (a[i] < a[root]) root = i;
  int L = a[root], R = 1e6 + 10;
  while (L + 1 < R) {
    int mid = L + R >> 1;
    dfs(mid) ? L = mid : R = mid;
  }
  cout << L << endl;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  readInput(), solve();
  return 0;
}
