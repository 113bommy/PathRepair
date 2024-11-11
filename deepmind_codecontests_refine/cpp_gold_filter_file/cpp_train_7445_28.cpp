#include <bits/stdc++.h>
using namespace std;
const int CO = -1000000000;
vector<int> g[200005];
vector<int> pref1[200005], suff1[200005], pref2[200005], suff2[200005],
    pref3[200005], suff3[200005];
vector<int> val1[200005], val2[200005];
int par[200005];
int dp1[200005], dp2[200005];
bool ok[200005];
int a[200005];
pair<int, int> dfs2(int u, int p, int mid) {
  if (!ok[u]) {
    if (par[u] == p) {
      return pair<int, int>(dp1[u], dp2[u]);
    } else {
      int v = par[u];
      pair<int, int> res = dfs2(v, u, mid);
      int j = lower_bound(g[u].begin(), g[u].end(), v) - g[u].begin();
      val1[u][j] = res.first;
      val2[u][j] = res.second;
      pref1[u][j] = res.first;
      suff1[u][j] = res.first;
      pref3[u][j] = max(0, res.first);
      suff3[u][j] = max(0, res.first);
      if (res.first >= 0)
        pref2[u][j] = 0, suff2[u][j] = 0;
      else
        pref2[u][j] = res.second, suff2[u][j] = res.second;
      ok[u] = 1;
      for (int i = 1; i < g[u].size(); i++) {
        pref1[u][i] = max(CO, pref1[u][i] + pref1[u][i - 1]);
        pref2[u][i] = max(pref2[u][i], pref2[u][i - 1]);
        pref3[u][i] += pref3[u][i - 1];
      }
      for (int i = g[u].size() - 2; i >= 0; i--) {
        suff1[u][i] = max(CO, suff1[u][i] + suff1[u][i + 1]);
        suff2[u][i] = max(suff2[u][i], suff2[u][i + 1]);
        suff3[u][i] += suff3[u][i + 1];
      }
    }
  }
  if (p == 0) return pair<int, int>(0, 0);
  int j = lower_bound(g[u].begin(), g[u].end(), p) - g[u].begin();
  pair<int, int> res;
  if (a[u] >= mid)
    res.first = 1, res.second = 1;
  else
    res.first = CO, res.second = 0;
  if (j != 0) {
    res.first = max(CO, res.first + pref1[u][j - 1]);
  }
  if (j != g[u].size() - 1) {
    res.first = max(CO, res.first + suff1[u][j + 1]);
  }
  if (j != 0 && res.second > 0) {
    res.second = max(res.second, pref2[u][j - 1] + 1);
  }
  if (j != g[u].size() - 1 && res.second > 0) {
    res.second = max(res.second, suff2[u][j + 1] + 1);
  }
  if (j != 0 && res.second > 0) {
    res.second += pref3[u][j - 1];
  }
  if (j != g[u].size() - 1 && res.second > 0) {
    res.second += suff3[u][j + 1];
  }
  return res;
}
void dfs1(int u, int p, int mid) {
  par[u] = p;
  if (a[u] >= mid)
    dp1[u] = 1, dp2[u] = 1;
  else
    dp1[u] = CO, dp2[u] = 0;
  int mx = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    dfs1(v, u, mid);
    dp1[u] = max(CO, dp1[u] + dp1[v]);
    if (dp2[u] != 0) {
      if (dp1[v] >= 0)
        dp2[u] += dp1[v];
      else
        mx = max(mx, dp2[v]);
    }
  }
  dp2[u] += mx;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    val1[u][i] = dp1[v];
    val2[u][i] = dp2[v];
    pref1[u][i] = dp1[v];
    suff1[u][i] = dp1[v];
    pref3[u][i] = max(0, dp1[v]);
    suff3[u][i] = max(0, dp1[v]);
    if (dp1[v] >= 0)
      pref2[u][i] = 0, suff2[u][i] = 0;
    else
      pref2[u][i] = dp2[v], suff2[u][i] = dp2[v];
  }
  if (p == 0) {
    ok[u] = 1;
    for (int i = 1; i < g[u].size(); i++) {
      pref1[u][i] = max(CO, pref1[u][i] + pref1[u][i - 1]);
      pref2[u][i] = max(pref2[u][i], pref2[u][i - 1]);
      pref3[u][i] += pref3[u][i - 1];
    }
    for (int i = g[u].size() - 2; i >= 0; i--) {
      suff1[u][i] = max(CO, suff1[u][i] + suff1[u][i + 1]);
      suff2[u][i] = max(suff2[u][i], suff2[u][i + 1]);
      suff3[u][i] += suff3[u][i + 1];
    }
  }
}
int n, k;
int solve(int mid) {
  for (int i = 1; i <= n; i++) {
    pref1[i].clear();
    suff1[i].clear();
    pref1[i].resize(g[i].size());
    suff1[i].resize(g[i].size());
    pref2[i].clear();
    suff2[i].clear();
    pref2[i].resize(g[i].size());
    suff2[i].resize(g[i].size());
    pref3[i].clear();
    suff3[i].clear();
    pref3[i].resize(g[i].size());
    suff3[i].resize(g[i].size());
    val1[i].clear();
    val1[i].resize(g[i].size());
    val2[i].clear();
    val2[i].resize(g[i].size());
    dp1[i] = 0;
    dp2[i] = 0;
    ok[i] = 0;
    par[i] = 0;
  }
  dfs1(1, 0, mid);
  for (int i = 1; i <= n; i++) dfs2(i, 0, mid);
  int ans = 0;
  int best = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= mid) {
      int res = pref3[i][g[i].size() - 1] + pref2[i][g[i].size() - 1] + 1;
      best = max(best, res);
    }
  }
  return best;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
  int lo = 1, hi = 1e6, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (solve(mid) >= k)
      ans = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  printf("%d\n", ans);
}
