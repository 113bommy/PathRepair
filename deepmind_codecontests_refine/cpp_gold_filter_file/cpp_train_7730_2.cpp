#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int w[300010];
int c[300010];
int sp[300010];
vector<pair<int, int>> adj[300010];
int visit[300010];
int ti[300010];
int tib[300010];
int at = 0;
int bridge[300010];
int root[300010];
vector<pair<int, int>> adj_big[300010];
long long c_big[300010];
int sp_big[300010];
long long child_dp[300010];
long long dp[300010];
int node_count;
int bridge_count;
void dfs1(int idx, int p) {
  visit[idx] = 1;
  ti[idx] = ++at;
  tib[idx] = ti[idx];
  for (auto it : adj[idx]) {
    int y = it.first;
    int i = it.second;
    if (y == p) continue;
    if (visit[y])
      ti[idx] = min(ti[idx], tib[y]);
    else {
      dfs1(y, idx);
      if (ti[y] > tib[idx]) {
        bridge[i] = 1;
        bridge_count++;
      } else
        ti[idx] = min(ti[idx], ti[y]);
    }
  }
  return;
}
void dfs2(int idx, int p) {
  visit[idx] = 1;
  root[idx] = node_count;
  c_big[node_count] += c[idx];
  for (auto it : adj[idx]) {
    int y = it.first;
    int i = it.second;
    if (y == p) continue;
    if (!bridge[i] && !visit[y]) dfs2(y, idx);
  }
  return;
}
void dfs3(int idx, int p) {
  child_dp[idx] = c_big[idx];
  for (auto it : adj_big[idx]) {
    int y = it.first;
    int i = it.second;
    if (y == p) continue;
    dfs3(y, idx);
    sp_big[idx] += sp_big[y];
    if (sp_big[y] > 0 && sp_big[y] < k) {
      child_dp[idx] += max(1ll * 0, child_dp[y] - w[i]);
    } else
      child_dp[idx] += child_dp[y];
  }
  return;
}
void dfs4(int idx, int p, long long val) {
  long long all_val = child_dp[idx] + val;
  dp[idx] = all_val;
  for (auto it : adj_big[idx]) {
    int y = it.first, i = it.second;
    if (y == p) continue;
    long long p_val;
    int weight;
    if (sp_big[y] > 0 && sp_big[y] < k)
      weight = w[i];
    else
      weight = 0;
    if (child_dp[y] - weight > 0)
      p_val = max(1ll * 0, all_val - child_dp[y]);
    else
      p_val = max(1ll * 0, all_val - weight);
    dfs4(y, idx, p_val);
  }
  return;
}
int main() {
  int debug = 0, debug1 = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &sp[i]);
    sp[i]--;
  }
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) scanf("%d", &w[i]);
  for (int i = 0; i < m; i++) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    t1--;
    t2--;
    adj[t1].push_back(make_pair(t2, i));
    adj[t2].push_back(make_pair(t1, i));
  }
  if (c[0] == 76096) debug1 = 0;
  dfs1(0, -1);
  if (debug) {
    for (int i = 0; i < n; i++) cout << ti[i] << " ";
    cout << endl;
    cout << "at " << at << endl;
  }
  node_count = 0;
  memset(visit, 0, sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    if (!visit[i]) {
      dfs2(i, -1);
      node_count++;
    }
  }
  if (debug) {
    cout << "root ";
    for (int i = 0; i < node_count; i++) cout << root[i] << " ";
    cout << endl;
    cout << "c_big ";
    for (int i = 0; i < node_count; i++) cout << c_big[i] << " ";
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int v1 = i, v2 = adj[i][j].first;
      int idx = adj[i][j].second;
      if (bridge[idx]) adj_big[root[v1]].push_back(make_pair(root[v2], idx));
    }
  }
  for (int i = 0; i < k; i++) sp_big[root[sp[i]]]++;
  if (debug) {
    cout << "sp_big ";
    for (int i = 0; i < node_count; i++) cout << sp_big[i] << " ";
    cout << endl;
  }
  dfs3(0, -1);
  if (debug) {
    cout << "child_dp ";
    for (int i = 0; i < node_count; i++) cout << child_dp[i] << " ";
    cout << endl;
  }
  dfs4(0, -1, 0);
  if (debug) {
    cout << "dp ";
    for (int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << endl;
  }
  if (debug1) {
    cout << "node_count " << node_count << endl;
    cout << "bridge_count " << bridge_count << endl;
    long long sum = 0, sum1 = 0;
    for (int i = 0; i < n; i++) sum += c[i];
    for (int i = 0; i < node_count; i++) sum1 += c_big[i];
    cout << "sum " << sum << " " << sum1 << endl;
    cout << "root " << root[0] << " " << root[1] << " " << root[2] << " "
         << root[80532] << endl;
    cout << "c_big " << c_big[0] << " " << c_big[1] << " " << c_big[root[80532]]
         << endl;
    cout << "child_dp " << child_dp[0] << endl;
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", dp[root[i]]);
  }
  return 0;
}
