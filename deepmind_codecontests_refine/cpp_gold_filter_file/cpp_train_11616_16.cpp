#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
vector<int> adj[210000];
vector<long long> a(210000), sum(210000), mx(210000);
int n;
long long ans = -inf;
void dfs(int u, int par) {
  vector<long long> tmp;
  sum[u] = a[u];
  mx[u] = -inf;
  for (auto v : adj[u])
    if (v != par) {
      dfs(v, u);
      sum[u] += sum[v], mx[u] = max(mx[u], mx[v]);
      tmp.push_back(mx[v]);
      sort(tmp.begin(), tmp.end(), greater<long long>());
      if (tmp.size() > 2) tmp.pop_back();
    }
  if (tmp.size() >= 2) ans = max(ans, tmp[0] + tmp[1]);
  mx[u] = max(mx[u], sum[u]);
}
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs(0, -1);
  cout << (ans > -inf ? to_string(ans) : "Impossible") << endl;
}
