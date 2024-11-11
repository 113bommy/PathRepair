#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100005];
double dfs(long long v, long long p) {
  long long ans = 0;
  for (auto &x : adj[v]) {
    if (x == p) continue;
    ans += dfs(x, v) + 1;
  }
  return ans ? ans / double(adj[v].size() - (v != 1)) : 0;
}
int main() {
  long long n, i, u, v;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  printf("%.10lf\n", dfs(1, -1));
  return 0;
}
