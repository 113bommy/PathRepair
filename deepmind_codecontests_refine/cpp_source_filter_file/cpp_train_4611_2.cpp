#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> G[maxn];
int a[maxn];
void add(int x, int y) { G[x].push_back(y); }
int dp[maxn], siz[maxn], sum[maxn];
void dfs(int u) {
  siz[u] = 1;
  sum[u] = a[u];
  for (int i = 0; i < G[u].size(); i++) {
    if (i == 0) siz[u]--;
    int v = G[u][i];
    dfs(v);
    dp[u] = max(dp[u], dp[v]);
    siz[u] += siz[v];
    sum[u] += sum[v];
  }
  dp[u] = max(dp[u], (sum[u] + siz[u] - 1) / siz[u]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    add(x, i);
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  dfs(1);
  cout << dp[1] << endl;
  return 0;
}
