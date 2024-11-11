#include <bits/stdc++.h>
const int MAX_N = (int)2e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;
using namespace std;
int n, k;
int a[MAX_N];
vector<int> g[MAX_N];
bool bad[MAX_N];
int dp[MAX_N], sz[MAX_N], ans[MAX_N];
void dfs(int v, int pr = -1) {
  sz[v] = 1, dp[v] = 1;
  int maxi = 0;
  for (auto to : g[v])
    if (to != pr) {
      dfs(to, v);
      sz[v] += sz[to];
      if (dp[to] == sz[to])
        dp[v] += sz[to];
      else
        maxi = max(maxi, dp[to]);
    }
  dp[v] += maxi;
  if (bad[v]) dp[v] = 0;
}
void calc(int v, int pr = -1, int up = 0) {
  ans[v] = 1;
  int maxi = 0;
  if (up == n - sz[v])
    ans[v] += up;
  else
    maxi = max(maxi, up);
  for (auto to : g[v])
    if (to != pr) {
      if (dp[to] == sz[to])
        ans[v] += sz[to];
      else
        maxi = max(maxi, dp[to]);
    }
  ans[v] += maxi;
  if (bad[v]) ans[v] = 0;
  vector<int> h;
  for (auto to : g[v])
    if (to != pr) h.push_back(to);
  vector<pair<int, int> > pref, suff;
  for (auto to : h) {
    int sum = 0, mx = 0;
    if (!pref.empty()) sum = pref.back().first, mx = pref.back().second;
    if (dp[to] == sz[to])
      sum += sz[to];
    else
      mx = max(mx, dp[to]);
    pref.push_back(make_pair(sum, mx));
    suff.push_back(make_pair(0, 0));
  }
  for (int i = int((h).size()) - 1; i >= 0; i--) {
    int to = h[i];
    int sum = 0, mx = 0;
    if (i + 1 < int((h).size()))
      sum = suff[i + 1].first, mx = suff[i + 1].second;
    if (dp[to] == sz[to])
      sum += sz[to];
    else
      mx = max(mx, dp[to]);
    suff[i] = make_pair(sum, mx);
  }
  for (int i = 0; i < int((h).size()); i++) {
    int sum = 0, mx = 0;
    if (i > 0) sum += pref[i - 1].first, mx = max(mx, pref[i - 1].second);
    if (i + 1 < int((h).size()))
      sum += suff[i + 1].first, mx = max(mx, suff[i + 1].second);
    if (up == n - sz[v])
      sum += up;
    else
      mx = max(mx, up);
    sum += mx + 1;
    if (bad[v]) up = 0;
    calc(h[i], v, up);
  }
}
bool check(int x) {
  for (int i = 1; i <= n; i++) bad[i] = (a[i] < x);
  dfs(1);
  calc(1);
  for (int i = 1; i <= n; i++)
    if (ans[i] >= k) return 1;
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int l = 1, r = (int)1e6, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  assert(ans != -1);
  cout << ans;
  return 0;
}
