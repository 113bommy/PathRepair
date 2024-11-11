#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n, k;
vector<pair<int, int> > g[maxn];
int dp[maxn], ddp[maxn];
void dfs(int t, int fa) {
  for (auto e : g[t]) {
    int v = e.first;
    if (v == fa) continue;
    dfs(v, t);
  }
  vector<int> vec;
  for (auto e : g[t]) {
    int v = e.first, c = e.second;
    if (v == fa) continue;
    vec.push_back(dp[v] + c);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int m = min(k - 1, (int)vec.size());
  for (int i = 0; i < m; ++i) dp[t] += vec[i];
  ddp[t] = dp[t];
  for (auto e : g[t]) {
    int v = e.first, c = e.second;
    if (v == fa) continue;
    if (m && dp[v] + c >= vec[m - 1])
      ddp[t] = max(ddp[t], dp[t] - (dp[v] + c) + (m < vec.size() ? vec[m] : 0) +
                               (ddp[v] + c));
    else
      ddp[t] = max(ddp[t], dp[t] + (ddp[v] + c));
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) {
    static int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    g[u].push_back(make_pair(v, c));
    g[v].push_back(make_pair(u, c));
  }
  dfs(0, -1);
  printf("%d\n", ddp[0]);
  return 0;
}
