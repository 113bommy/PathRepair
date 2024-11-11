#include <bits/stdc++.h>
using namespace std;
int solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const int MAXN = (int)2e5 + 10;
int dp[MAXN], DP[MAXN];
int sz[MAXN];
int a[MAXN];
vector<int> g[MAXN];
int n, k;
void dfs(int v, int p, int M) {
  sz[v] = 1;
  for (int to : g[v])
    if (to != p) {
      dfs(to, v, M);
      sz[v] += sz[to];
    }
  if (a[v] < M) return;
  dp[v] = 1;
  int mx = 0;
  for (int to : g[v])
    if (to != p) {
      if (sz[to] == dp[to])
        dp[v] += dp[to];
      else
        mx = max(mx, dp[to]);
    }
  dp[v] += mx;
  return;
}
void change_root(int v, int p, int add, int M) {
  if (add == n - sz[v])
    DP[v] = dp[v] + add;
  else {
    int mx = 0;
    for (int to : g[v])
      if (to != p)
        if (sz[to] != dp[to]) mx = max(mx, dp[to]);
    if (mx < add)
      DP[v] = dp[v] + add - mx;
    else
      DP[v] = dp[v];
  }
  if (a[v] < M) DP[v] = 0;
  vector<int> pref, suff;
  pref.resize((int)g[v].size());
  suff.resize((int)g[v].size());
  int sum = 0;
  for (int i = 0; i < (int)g[v].size(); i++) {
    if (i > 0) pref[i] = pref[i - 1];
    int to = g[v][i];
    if (to != p) {
      if (sz[to] == dp[to])
        sum += dp[to];
      else
        pref[i] = max(pref[i], dp[to]);
    }
  }
  for (int i = (int)g[v].size() - 1; i >= 0; i--) {
    if (i < (int)g[v].size() - 1) suff[i] = suff[i + 1];
    int to = g[v][i];
    if (to != p) {
      if (sz[to] != dp[to]) suff[i] = max(suff[i], dp[to]);
    }
  }
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    int cur = 0;
    if (i > 0) cur = max(cur, pref[i - 1]);
    if (i < (int)g[v].size() - 1) cur = max(cur, suff[i + 1]);
    if (add == n - sz[to])
      cur += add;
    else
      cur = max(cur, add);
    cur += sum;
    if (dp[to] == sz[to]) cur -= dp[to];
    if (a[v] < M)
      cur = 0;
    else
      cur++;
    change_root(to, v, cur, M);
  }
}
bool check(int M) {
  memset(dp, 0, sizeof(dp));
  memset(sz, 0, sizeof(sz));
  memset(DP, 0, sizeof(DP));
  dfs(1, -1, M);
  change_root(1, -1, 0, M);
  for (int i = 1; i <= n; i++)
    if (DP[i] >= k) return 1;
  return 0;
}
int solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int L = 0, R = (int)1e6 + 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    if (check(M))
      L = M;
    else
      R = M;
  }
  cout << L << endl;
  return 0;
}
