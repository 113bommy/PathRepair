#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 3e5 + 5;
const int T = 500;
const int oo = 1e9;
vector<int> adj[N];
int mx[N][22];
int dp[N][22];
int deg[N];
int h[N];
int n;
void dfs(int u, int p = -1) {
  h[u] = 1;
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u);
      maxi(h[u], h[v] + 1);
    }
  dp[u][1] = n;
  for (int i = 2; i <= 20; i++) {
    vector<int> best;
    for (int v : adj[u])
      if (v != p) best.push_back(dp[v][i - 1]);
    sort(best.begin(), best.end(), greater<int>());
    for (int j = 0; j < deg[u]; j++)
      if (best[j] >= j + 1) dp[u][i] = j + 1;
  }
  for (int i = 1; i <= 20; i++) {
    mx[u][i] = dp[u][i];
    for (int v : adj[u])
      if (v != p) maxi(mx[u][i], mx[v][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 2; i <= n; i++) deg[i]--;
  h[1] = 1;
  dfs(1);
  long long ans = accumulate(h + 1, h + n + 1, 0LL);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 21; j++) maxi(mx[i][j], 1);
    for (int j = 1; j <= 20; j++) {
      if (mx[i][j] == 1) break;
      ans += (mx[i][j] - mx[i][j + 1]) * j;
    }
  }
  cout << ans;
  return 0;
}
