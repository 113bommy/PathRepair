#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<long long> > g;
vector<long long> dp;
vector<vector<long long> > pred;
long long t;
long long timer = 0;
vector<long long> tin, tout;
void dfs(long long v) {
  tin[v] = timer++;
  for (long long i = 0; i < g[v].size(); i++) {
    long long to = g[v][i];
    dfs(to);
    pred[to][0] = v;
  }
  tout[v] = timer++;
}
bool pr(long long a, long long b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
vector<vector<vector<long long> > > query;
vector<long long> ind;
vector<long long> fenv;
long long ans(long long x) {
  long long sum = 0;
  while (x >= 0) {
    sum += fenv[x];
    x = (x & (x + 1)) - 1;
  }
  return sum;
}
void update(long long x, long long val) {
  if (x == -1) {
    return;
  }
  while (x < 2 * n) {
    fenv[x] += val;
    x = x | (x + 1);
  }
}
void dfs1(long long v) {
  long long sum1 = 0;
  for (long long i = 0; i < g[v].size(); i++) {
    dfs1(g[v][i]);
    sum1 += dp[g[v][i]];
  }
  dp[v] = sum1;
  for (long long i = 0; i < query[v].size(); i++) {
    long long a = query[v][i][2];
    long long b = query[v][i][3];
    long long a1 = query[v][i][0];
    long long b1 = query[v][i][1];
    long long c = query[v][i][4];
    long long sum = c;
    if (a != v) {
      sum += ans(tin[a]) - ans(tin[v]);
    }
    if (b != v) {
      sum += ans(tin[b]) - ans(tin[v]);
    }
    sum += ans(tin[v]);
    if (v != 0) {
      sum -= ans(tin[pred[v][0]]);
    }
    dp[v] = max(dp[v], sum);
  }
  update(tin[v], -dp[v]);
  update(tout[v], dp[v]);
  update(tin[pred[v][0]], dp[v]);
  update(tout[pred[v][1]], -dp[v]);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  g.resize(n);
  fenv.resize(2 * n);
  ind.resize(n);
  t = log2(n) + 1;
  tin.resize(n);
  query.resize(n);
  tout.resize(n);
  pred.resize(n, vector<long long>(t));
  dp.resize(n);
  for (long long i = 1; i < n; i++) {
    long long x;
    cin >> x;
    x--;
    g[x].push_back(i);
  }
  pred[0][0] = 0;
  dfs(0);
  for (long long i = 1; i < t; i++) {
    for (long long j = 0; j < n; j++) {
      pred[j][i] = pred[pred[j][i - 1]][i - 1];
    }
  }
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    long long a2 = a, b2 = b;
    long long a1 = a;
    for (long long j = t - 1; j >= 0; j--) {
      if (!pr(pred[a1][j], b)) {
        a1 = pred[a1][j];
      }
    }
    if (!pr(a1, b)) {
      a1 = pred[a1][0];
    }
    for (long long j = t - 1; j >= 0; j--) {
      if (!pr(pred[a][j], b)) {
        a = pred[a][j];
      }
    }
    for (long long j = t - 1; j >= 0; j--) {
      if (!pr(pred[b][j], a)) {
        b = pred[b][j];
      }
    }
    query[a1].push_back({a, b, a2, b2, c});
  }
  dfs1(0);
  cout << dp[0];
  return 0;
}
