#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, k;
vector<int> G[N];
int a[N];
int dp1[N], dp2[N];
int sum[N];
int cnt[N];
pair<int, int> pr[N];
void dfs1(int v, int p, int x) {
  cnt[v] = 1;
  pr[v] = make_pair(-1, -1);
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i];
    if (to == p) continue;
    dfs1(to, v, x);
    cnt[v] += cnt[to];
    if (cnt[to] == dp1[to])
      dp1[v] += dp1[to];
    else {
      if (pr[v].first == -1 || dp1[pr[v].first] < dp1[to]) {
        pr[v].second = pr[v].first;
        pr[v].first = to;
      } else if (pr[v].second == -1 || dp1[pr[v].second] < dp1[to])
        pr[v].second = to;
    }
  }
  if (a[v] < x)
    dp1[v] = sum[v] = 0;
  else {
    sum[v] = dp1[v];
    dp1[v] += 1;
    if (pr[v].first != -1) dp1[v] += dp1[pr[v].first];
  }
}
void dfs2(int v, int p, int x) {
  if (p == -1 || a[p] < x) {
    dp2[v] = 0;
  } else {
    int c = sum[p];
    int mx = 0;
    if (pr[p].first != -1 && pr[p].first != v)
      mx = dp1[pr[p].first];
    else if (pr[p].second != -1 && pr[p].second != v)
      mx = dp1[pr[p].second];
    if (dp1[v] == cnt[v]) c -= dp1[v];
    dp2[v] = c;
    if (dp2[p] == n - cnt[p])
      dp2[v] += dp2[p];
    else
      mx = max(mx, dp2[p]);
    dp2[v] += mx;
  }
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i];
    if (to == p) continue;
    dfs2(to, v, x);
  }
}
bool check(int x) {
  for (int i = 0; i < n; ++i) dp1[i] = dp2[i] = sum[i] = 0;
  dfs1(0, -1, x);
  dfs2(0, -1, x);
  for (int i = 0; i < n; ++i) {
    if (a[i] < x) continue;
    int ans = sum[i] + 1;
    int mx = 0;
    if (pr[i].first != -1) mx = dp1[pr[i].first];
    if (dp2[i] == n - cnt[i])
      ans += dp2[i];
    else
      mx = max(mx, dp2[i]);
    if (ans + mx >= k) return true;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int l = 0, r = 1000001;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
  return 0;
}
