#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
int n, k, b[N], dp[N], mxu[N], dp2[N], a[N], sz[N];
bool allOnes[N];
vector<int> g[N];
void dfs0(int u, int p) {
  allOnes[u] = b[u];
  sz[u] = 1;
  for (auto v : g[u])
    if (v != p) {
      dfs0(v, u);
      allOnes[u] &= allOnes[v];
      sz[u] += sz[v];
    }
}
void dfs1(int u, int p) {
  int mx = 0;
  dp[u] = b[u];
  for (auto v : g[u])
    if (v != p) {
      dfs1(v, u);
      if (b[u]) {
        if (allOnes[v])
          dp[u] += sz[v];
        else
          mx = max(mx, dp[v]);
      }
    }
  if (b[u]) {
    dp[u] += mx;
    mxu[u] = mx;
  }
}
int getSecondMax(priority_queue<int> &pq) {
  if (pq.size() < 2) return -1;
  int tmp = pq.top();
  pq.pop();
  int ans = pq.top();
  pq.push(tmp);
  return ans;
}
void dfs2(int u, int p, int parDpVal) {
  int sumOnes = 0;
  priority_queue<int> dps;
  if (b[u]) {
    if (parDpVal == n - sz[u]) {
      dp2[u] = dp[u] + parDpVal;
      sumOnes += parDpVal;
    } else {
      dp2[u] = dp[u] - mxu[u] + max(mxu[u], parDpVal);
      dps.push(parDpVal);
    }
  } else
    dp2[u] = 0;
  for (auto v : g[u])
    if (v != p) {
      if (allOnes[v])
        sumOnes += dp[v];
      else
        dps.push(dp[v]);
    }
  for (auto v : g[u])
    if (v != p) {
      int valu = dp2[u];
      if (!b[u])
        valu = 0;
      else {
        if (allOnes[v])
          valu -= sz[v];
        else {
          if (dp[v] == dps.top()) {
            valu -= dp[v];
            valu += getSecondMax(dps);
          }
        }
      }
      dfs2(v, u, valu);
    }
}
bool check(int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] >= x)
      b[i] = 1;
    else
      b[i] = 0;
  }
  dfs0(0, -1);
  dfs1(0, -1);
  dfs2(0, -1, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp2[i]);
  }
  if (ans >= k) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int l = 1, r = 1e6;
  while (l < r) {
    int m = (l + r) >> 1;
    if (check(m + 1))
      l = m + 1;
    else
      r = m;
  }
  cout << l;
  return 0;
}
