#include <bits/stdc++.h>
using namespace std;
int n, b;
vector<vector<int> > g;
vector<int> par;
vector<int> c;
vector<int> d;
bool read() {
  if (scanf("%d%d", &n, &b) < 2) {
    return 0;
  }
  g.clear();
  g.resize(n);
  par.assign(n, -1);
  c.resize(n);
  d.resize(n);
  for (int i = 0; i < int(n); ++i) {
    scanf("%d%d", &c[i], &d[i]);
    if (i > 0) {
      scanf("%d", &par[i]);
      --par[i];
      g[par[i]].push_back(i);
    }
  }
  return 1;
}
const int INF = 1e9 + 100;
int add(int x, int y) {
  if (x >= INF || y >= INF) {
    return INF;
  }
  return min(x + y, INF);
}
void remin(int& x, int y) {
  if (x > y) {
    x = y;
  }
}
void remax(int& x, int y) {
  if (x < y) {
    x = y;
  }
}
void norm(vector<int>& dyn) {
  while (!dyn.empty() && dyn.back() >= INF) {
    dyn.pop_back();
  }
  for (int i = int(((int)(dyn).size()) - 1) - 1; i >= 0; --i) {
    remin(dyn[i], dyn[i + 1]);
  }
}
vector<int> merge(const vector<int>& dp1, const vector<int>& dp2) {
  assert(dp1.at(0) == 0);
  assert(dp2.at(0) == 0);
  vector<int> dp(((int)(dp1).size()) + ((int)(dp2).size()), INF);
  for (int i = 0; i < int(((int)(dp1).size())); ++i)
    for (int j = 0; j < int(((int)(dp2).size())); ++j) {
      remin(dp[i + j], add(dp1[i], dp2[j]));
    }
  norm(dp);
  return dp;
}
vector<vector<vector<int> > > dp;
void dfs(int v) {
  for (int to : g[v]) {
    dfs(to);
  }
  vector<int> use(1, 0);
  for (int to : g[v]) {
    use = merge(dp[to][1], use);
  }
  vector<int> not_use(1, 0);
  for (int to : g[v]) {
    not_use = merge(dp[to][0], not_use);
  }
  const int sz = max(((int)(not_use).size()), ((int)(use).size()));
  dp[v].resize(2);
  dp[v][0].assign(sz + 1, INF);
  for (int i = 0; i < int(((int)(not_use).size())); ++i) {
    remin(dp[v][0][i + 1], add(not_use[i], c[v]));
  }
  for (int i = 0; i < int(((int)(not_use).size())); ++i) {
    remin(dp[v][0][i], not_use[i]);
  }
  norm(dp[v][0]);
  dp[v][1].assign(sz + 1, INF);
  for (int i = 0; i < int(((int)(use).size())); ++i) {
    remin(dp[v][1][i + 1], add(use[i], c[v] - d[v]));
  }
  for (int i = 0; i < int(((int)(not_use).size())); ++i) {
    remin(dp[v][1][i], not_use[i]);
  }
  norm(dp[v][1]);
}
int solve() {
  dp.clear();
  dp.resize(n);
  const int r = 0;
  dfs(r);
  int res = 0;
  for (int i = 0; i < int(((int)(dp[r][1]).size())); ++i) {
    if (dp[r][1][i] <= b) {
      res = i;
    }
  }
  return res;
}
int main() {
  while (read()) {
    printf("%d\n", solve());
  }
  return 0;
}
