#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 5;
vector<int> adj[N];
int n, u, v;
long long sz[N], ans;
void dfs(int u, int p) {
  sz[u] = 1;
  long long tmp = 0;
  for (auto v : adj[u])
    if (v != p) {
      dfs(v, u);
      tmp += sz[u] * sz[v];
      sz[u] += sz[v];
    }
  ans -= tmp * (tmp + 2 * sz[u] * (n - sz[u]));
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = n * (n - 1) / 2;
  ans *= ans;
  dfs(1, 1);
  cout << ans << '\n';
  return 0;
}
