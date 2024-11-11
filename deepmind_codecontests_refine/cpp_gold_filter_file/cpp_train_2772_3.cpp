#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool visited1[1000005], visited2[1000005];
long long counter = 0;
long long scc[1000005] = {0};
long long val[1000005] = {0};
long long dp[1000005];
vector<pair<long long, long long> > edg[1000005], redg[1000005];
stack<long long> dfsSatck;
vector<pair<long long, pair<long long, long long> > > ed;
vector<pair<long long, long long> > compg[1000005];
long long mushroomsCollected(long long m) {
  n = (sqrt(8ll * m + 1ll) - 1ll) / 2ll;
  long long ret = (12ll * m + 12ll * m * n - n * (n + 1ll) * (2ll * n + 1ll) -
                   3ll * n * (n + 1ll)) /
                  12ll;
  return ret;
}
void dfs1(long long n) {
  if (!visited1[n]) {
    visited1[n] = true;
    for (long long i = 0; i < edg[n].size(); i++) {
      dfs1(edg[n][i].first);
    }
    dfsSatck.push(n);
  }
}
void dfs2(long long n) {
  if (!visited2[n]) {
    visited2[n] = true;
    scc[n] = counter;
    for (long long i = 0; i < redg[n].size(); i++) {
      dfs2(redg[n][i].first);
    }
  }
}
long long finalVal(int n) {
  if (dp[n] == -1) {
    long long maximum = 0;
    for (long long i = 0; i < compg[n].size(); i++) {
      maximum = max(compg[n][i].second + finalVal(compg[n][i].first), maximum);
    }
    dp[n] = val[n] + maximum;
    return dp[n];
  } else {
    return dp[n];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int precision = numeric_limits<double>::digits10;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    edg[u].push_back(make_pair(v, w));
    redg[v].push_back(make_pair(u, w));
    ed.push_back(make_pair(u, make_pair(v, w)));
  }
  for (long long i = 1; i <= n; i++) {
    if (!visited1[i]) dfs1(i);
  }
  for (long long repeater = 1; repeater <= n; repeater++) {
    long long temp = dfsSatck.top();
    dfsSatck.pop();
    if (!visited2[temp]) {
      counter++;
      dfs2(temp);
    }
  }
  for (long long i = 0; i < ed.size(); i++) {
    long long u = scc[ed[i].first], v = scc[ed[i].second.first],
              w = ed[i].second.second;
    if (u == v) {
      val[u] += mushroomsCollected(w);
    } else {
      compg[u].push_back(make_pair(v, w));
    }
  }
  long long start;
  cin >> start;
  memset(dp, -1, sizeof(dp));
  cout << finalVal(scc[start]) << endl;
}
