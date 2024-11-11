#include <bits/stdc++.h>
using namespace std;
void impgraph(int n, int m);
void dfs(int u, int par);
const int mod = 1e9;
const int N = 3e5 + 1;
vector<int> g[N];
int A[N];
void solve() {
  int n, m, ans = 0, cnt = 0, k;
  int d;
  cin >> n >> d;
  string s;
  cin >> s;
  vector<int> dp(n, mod);
  dp[0] = 0;
  for (int i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1) {
    for (int j = 1; 1 < d + 1 ? j < d + 1 : j > d + 1;
         1 < d + 1 ? j += 1 : j -= 1) {
      if (i + j < n && s[i] == '1' && s[i + j] == '1') {
        dp[i + j] = min(dp[i] + 1, dp[i + j]);
      } else if (i + j > n)
        break;
    }
  }
  if (dp[n - 1] == mod)
    cout << "-1";
  else
    cout << dp[n - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
void impgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (A[v]) {
    }
    dfs(v, 0);
  }
}
