#include <bits/stdc++.h>
using namespace std;
int MAXN = 5000001;
const int mod = 1000000007;
const int INF = INT_MAX;
inline int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
inline int pow(int a, int n, int mod) {
  if (n == 0) return 1;
  int p = pow(a, n / 2, mod);
  p = (p % mod * p % mod) % mod;
  if (n % 2)
    return (p % mod * a % mod) % mod;
  else
    return p;
}
vector<int> adj[200006];
vector<int> wt[200006];
vector<int> sz(200006, 1);
vector<int> vis(200006, 0);
void dfs(int s, int p) {
  for (int i = 0; i < adj[s].size(); i++) {
    int child = adj[s][i];
    if (child != p) {
      dfs(child, s);
      sz[s] += sz[child];
    }
  }
}
vector<int> dp(200006, 0);
int val[100006];
void dfs1(int s, int p) {
  for (int i = 0; i < adj[s].size(); i++) {
    int child = adj[s][i];
    if (child != p) {
      dp[child] = max((int)0, dp[p] + wt[s][i]);
      dfs1(child, s);
      if (val[child] < dp[child]) vis[child] = 1;
    }
  }
}
int ans = 0;
void dfs2(int s, int p) {
  if (vis[s]) {
    ans += sz[s];
    return;
  }
  for (int i = 0; i < adj[s].size(); i++) {
    int child = adj[s][i];
    if (child != p) {
      dfs2(child, s);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> val[i];
  int k = 2;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(k);
    adj[k].push_back(a);
    wt[a].push_back(b);
    wt[k].push_back(b);
    k++;
  }
  dfs(1, 0);
  dfs1(1, 0);
  dfs2(1, 0);
  cout << ans << "\n";
  return 0;
}
