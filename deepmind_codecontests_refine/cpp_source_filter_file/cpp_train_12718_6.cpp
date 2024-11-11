#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rm(int l, int r) {
  uniform_int_distribution<int> dis(l, r);
  return dis(rng);
}
using ulli = unsigned long long;
using lli = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
const int N = 2e5 + 5;
int n;
vector<int> graph[N];
lli mem[N], ans[N], tot[N];
bool done[N];
int dfs(int u, int pr = -1) {
  tot[u] = 1;
  for (int v : graph[u])
    if (v != pr) tot[u] += dfs(v, u);
  return tot[u];
}
int dp(int u, int pr = -1) {
  lli &ans = mem[u];
  if (done[u]) return ans;
  done[u] = true;
  ans = tot[u];
  for (int v : graph[u])
    if (v != pr) ans += dp(v, u);
  return ans;
}
void solve(int u, int pr = -1) {
  ans[u] = mem[u];
  ;
  for (int v : graph[u])
    if (v != pr) {
      tot[u] -= tot[v];
      mem[u] -= tot[v];
      mem[u] -= mem[v];
      tot[v] += tot[u];
      mem[v] += tot[u];
      mem[v] += mem[u];
      solve(v, u);
      mem[v] -= mem[u];
      mem[v] -= tot[u];
      tot[v] -= tot[u];
      mem[u] += mem[v];
      mem[u] += tot[v];
      tot[u] += tot[v];
    }
}
int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  cin >> n;
  for (auto i = (0) - ((0) > (n - 1)); i != n - 1 - ((0) > (n - 1));
       i += 1 - 2 * ((0) > (n - 1))) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1);
  dp(1);
  solve(1);
  cout << *max_element(ans + 1, ans + n + 1) << '\n';
  return 0;
}
