#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
vector<vector<int> > adj;
vector<int> a;
vector<map<int, int> > dp;
int ans = 0;
void dfs(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (__gcd(a[v], a[u]) != 1) {
      for (auto i : dp[v]) {
        for (auto j : dp[u]) {
          if (__gcd(i.first, j.first) != 1) {
            ans = max(ans, i.second + j.second);
          }
        }
      }
    }
    for (auto it : dp[v]) {
      int gcd = __gcd(a[u], it.first);
      if (gcd != 1) dp[u][gcd] = max(dp[u][gcd], it.second + 1);
    }
  }
}
int main() {
  std ::ios_base ::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  adj.assign(n, vector<int>());
  dp.assign(n, map<int, int>());
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] != 1) {
      ans = max(ans, 1);
      dp[i][a[i]] = 1;
    }
  }
  int x, y;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    for (auto it : dp[i]) {
      ans = max(ans, it.second);
    }
  }
  cout << ans << endl;
}
