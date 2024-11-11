#include <bits/stdc++.h>
using namespace std;
vector<int> g[200002];
vector<pair<int, int> > edges;
int p[200002];
long long snode[200002];
long long plsum = 0;
long long n, k;
void dfs(int s) {
  snode[s] = 1;
  for (int i = 0; i < g[s].size(); i++) {
    int v = g[s][i];
    if (v != p[s]) {
      p[v] = s;
      dfs(v);
      snode[s] = snode[s] + snode[v];
    }
  }
}
void cmp_pathlensum() {
  for (int i = 0; i < edges.size(); i++) {
    int a, b;
    a = edges[i].first;
    b = edges[i].second;
    if (b == p[a]) swap(a, b);
    plsum = plsum + snode[b] * (n - snode[b]);
  }
}
long long dp[200002][2][5];
void cmp_rem(int s) {
  long long child = 0;
  for (int i = 0; i < g[s].size(); i++) {
    int v = g[s][i];
    if (v != p[s]) {
      cmp_rem(v);
      child++;
    }
  }
  for (int rem = 0; rem < k; rem++) {
    for (int i = 0; i < g[s].size(); i++) {
      int v = g[s][i];
      if (v != p[s]) {
        dp[s][0][rem] += dp[v][0][(rem - 1 + k) % k];
      }
    }
  }
  dp[s][0][1] += child;
  for (int r = 0; r < k; r++) {
    for (int i = 0; i < g[s].size(); i++) {
      int v = g[s][i];
      if (v != p[s]) {
        for (int rem = 0; rem < k; rem++) {
          int rv = (r - rem + k) % k;
          long long val1 = dp[v][0][(rem - 1 + k) % k];
          if (rem == 1) val1++;
          long long val2 = dp[s][0][rv] - dp[v][0][(rv - 1 + k) % k];
          if (rv == 1) val2--;
          dp[s][1][r] += val1 * val2;
        }
      }
    }
  }
  for (int rem = 0; rem < k; rem++) {
    dp[s][1][rem] /= 2;
    dp[s][1][rem] += dp[s][0][rem];
    for (int i = 0; i < g[s].size(); i++) {
      int v = g[s][i];
      if (v != p[s]) {
        dp[s][1][rem] += dp[v][1][rem];
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back(make_pair(a, b));
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  cmp_pathlensum();
  if (k == 1) {
    cout << plsum << endl;
    return 0;
  }
  cmp_rem(1);
  long long sum = 0;
  for (int r = 0; r < k; r++) {
    sum = sum + ((k - r) % k) * dp[1][1][r];
  }
  sum = sum + plsum;
  assert(sum % k == 0);
  long long ans = sum / k;
  cout << ans << endl;
  return 0;
}
