#include <bits/stdc++.h>
using namespace std;
long long dp[2 * 100002][20], height[2 * 100002];
long long start[100002], en[100002], cnt;
long long bit[2 * 100002];
vector<long long> gr[100002];
vector<pair<long long, long long> > edg;
void update(long long in, long long val) {
  while (in <= 200000) {
    bit[in] += val;
    in += in & -in;
  }
}
long long get(long long in) {
  long long sum = 0;
  while (in) {
    sum += bit[in];
    in -= in & -in;
  }
  return sum;
}
void dfs(int i, int par) {
  dp[i][0] = par;
  if (par + 1) height[i] = height[par] + 1;
  start[i] = ++cnt;
  for (int j = 1; j < 20; j++)
    if (dp[i][j - 1] + 1) dp[i][j] = dp[dp[i][j - 1]][j - 1];
  for (int j = 0; j < gr[i].size(); j++)
    if (gr[i][j] != par) dfs(gr[i][j], i);
  en[i] = cnt;
}
long long lca(long long v, long long u) {
  if (height[v] < height[u]) swap(u, v);
  for (long long i = 19; i >= 0; i--)
    if (dp[v][i] + 1 && height[dp[v][i]] >= height[u]) v = dp[v][i];
  if (v == u) return v;
  for (long long i = 19; i >= 0; i--)
    if (dp[v][i] != dp[u][i]) {
      v = dp[v][i];
      u = dp[u][i];
    }
  return dp[v][0];
}
long long dist(long long u, long long v) {
  long long x = lca(u, v);
  return height[u] + height[v] - 2LL * height[x];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  long long n, i, j, a, b, x, y, el, m, typ;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    gr[a].push_back(b);
    gr[b].push_back(a);
    edg.push_back(make_pair(a, b));
  }
  dfs(0, -1);
  cin >> m;
  while (m--) {
    cin >> a;
    if (a < 3) {
      cin >> b;
      b--;
      if (a == 1)
        typ = 1;
      else
        typ = -1;
      el = edg[b].second;
      if (height[edg[b].first] > height[edg[b].second]) el = edg[b].first;
      update(start[el], -1 * typ);
      update(en[el], 1 * typ);
      continue;
    }
    cin >> x >> y;
    x--;
    y--;
    b = lca(x, y);
    if (get(start[x]) + get(start[y]) - 2 * get(start[b]))
      cout << "-1\n";
    else
      cout << dist(x, y) << "\n";
  }
}
