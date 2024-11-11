#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)2e5 + 10;
int n;
vector<int> g[maxn];
int a[maxn];
int cnt[maxn];
int dp[maxn];
int up[maxn];
int res;
bool good[maxn];
void dfs(int v, int p) {
  dp[v] = 0;
  cnt[v] = 1;
  int ma = 0;
  for (int i = 0; i < (int)(g[v]).size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    dfs(to, v);
    cnt[v] += cnt[to];
    if (dp[to] == cnt[to]) {
      dp[v] += cnt[to];
    } else {
      ma = max(ma, dp[to]);
    }
  }
  if (good[v]) {
    dp[v] += ma + 1;
  } else {
    dp[v] = 0;
  }
}
void go(int v, int p) {
  int cur = 1;
  int ma = 0;
  pair<int, int> ma1, ma2;
  ma1 = ma2 = make_pair(0, -1);
  if (p != -1) {
    if (up[p] == n - cnt[v]) {
      cur += up[p];
    } else {
      ma1 = make_pair(up[p], p);
      ma = max(ma, up[p]);
    }
  }
  for (int i = 0; i < (int)(g[v]).size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    if (dp[to] == cnt[to]) {
      cur += dp[to];
    } else {
      ma = max(ma, dp[to]);
      pair<int, int> e = make_pair(dp[to], to);
      if (ma1 < e) {
        ma2 = ma1;
        ma1 = e;
      } else if (ma2 < e) {
        ma2 = e;
      }
    }
  }
  for (int i = 0; i < (int)(g[v]).size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    if (good[v]) {
      up[v] = cur + (ma1.second == to ? ma2.first : ma1.first);
      if (dp[to] == cnt[to]) {
        up[v] -= dp[to];
      }
    } else {
      up[v] = 0;
    }
    go(to, v);
  }
  if (good[v]) {
    cur += ma;
  } else {
    cur = 0;
  }
  res = max(res, cur);
}
int solve(int val) {
  for (int i = 0; i < n; i++) good[i] = a[i] >= val;
  dfs(0, -1);
  res = 0;
  go(0, -1);
  return res;
}
int main() {
  int num;
  cin >> n >> num;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = 0;
  int r = (int)1e6 + 1;
  while (l < r - 1) {
    int m = (l + r) >> 1;
    if (solve(m) >= num) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}
