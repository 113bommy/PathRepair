#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 6e3 + 10;
const long long INF = 1e12 + 10;
vector<long long> vertex[MAXN];
long long a[MAXN];
long long w[MAXN];
long long dp[MAXN];
long long res[MAXN];
bool check[MAXN];
long long d = 0;
void dfs(long long v) {
  check[v] = true;
  long long u = lower_bound(dp, dp + MAXN, a[v]) - dp;
  w[v] = dp[u];
  dp[u] = a[v];
  res[v] = max(res[v], u);
  for (long long i = 0; i < vertex[v].size(); i++) {
    if (!check[vertex[v][i]]) {
      res[vertex[v][i]] = res[v];
      dfs(vertex[v][i]);
    }
  }
  dp[u] = w[v];
  d = max(d, res[v]);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < (n - 1); i++) {
    long long v, u;
    cin >> v >> u;
    vertex[v].push_back(u);
    vertex[u].push_back(v);
  }
  for (long long i = 1; i <= n; i++) {
    fill(check, check + MAXN, false);
    fill(dp, dp + MAXN, INF);
    dp[0] = 0;
    res[i] = 0;
    dfs(i);
  }
  cout << d;
}
