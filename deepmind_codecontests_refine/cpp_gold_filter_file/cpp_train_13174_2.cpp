#include <bits/stdc++.h>
using namespace std;
int n, k;
int d[181];
vector<int> adj[181];
int cost[181][181][181];
int sum_min_branch[181][181][181];
int single_min[181][181][181], get_min[181][181][181],
    closest_branch[181][181][181];
int par[181] = {};
int deg[181] = {};
int depth[181] = {};
queue<int> q;
vector<int> center;
void init() {
  int u, v;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) scanf("%d", &d[i]);
  d[0] = k;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  deg[1]++;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int ii = 0; ii <= n; ii++) {
        sum_min_branch[i][j][ii] = 0;
        single_min[i][j][ii] = 1 << 30;
        closest_branch[i][j][ii] = -1;
      }
    }
  }
}
void dfs(int v) {
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == par[v]) continue;
    par[adj[v][i]] = v;
    dfs(adj[v][i]);
  }
}
void depth_search() {
  queue<int> q2;
  int deg2[181], fr, ma;
  for (int i = 1; i <= n; i++) {
    deg2[i] = deg[i];
    if (deg[i] == 1) q2.push(i);
  }
  while (!q2.empty()) {
    fr = q2.front();
    q2.pop();
    deg2[par[fr]]--;
    if (deg2[par[fr]] == 1) q2.push(par[fr]);
    ma = -1;
    for (int i = 0; i < adj[fr].size(); i++) {
      if (par[fr] == adj[fr][i]) continue;
      ma = max(ma, depth[adj[fr][i]]);
    }
    depth[fr] = ma + 1;
  }
}
int single_update(int ver, int out, int in) {
  int ans = 0, temp, mi = 1 << 30;
  if ((in < n && in > depth[ver]) || (out < n && out > n - 1 - depth[ver]) ||
      (in >= n && out >= n) || (!out && in))
    return cost[ver][out][in] = 1 << 30;
  if (in >= n) {
    ans = d[out];
    for (int i = 0; i < adj[ver].size(); i++) {
      if (adj[ver][i] == par[ver]) continue;
      ans += cost[adj[ver][i]][out + 1][in];
    }
    return cost[ver][out][in] = ans;
  }
  if (!in) {
    return cost[ver][out][in] = k + sum_min_branch[ver][1][0];
  }
  if (out >= n) {
    ans = d[in];
    for (int i = 0; i < adj[ver].size(); i++) {
      if (adj[ver][i] == par[ver]) continue;
      if (depth[adj[ver][i]] < in - 1) continue;
      temp = cost[adj[ver][i]][out][in - 1] -
             single_min[adj[ver][i]][in + 1][in - 1] +
             sum_min_branch[ver][in + 1][in - 1];
      if (temp < mi) {
        mi = temp;
        closest_branch[ver][out][in] = adj[ver][i];
      }
    }
    return cost[ver][out][in] = ans + mi;
  }
  ans = d[min(out, in)];
  for (int i = 0; i < adj[ver].size(); i++) {
    if (adj[ver][i] == par[ver]) continue;
    if (depth[adj[ver][i]] < in - 1) continue;
    temp = cost[adj[ver][i]][out + 1][in - 1] -
           single_min[adj[ver][i]][min(out, in) + 1][in - 1] +
           sum_min_branch[ver][min(out, in) + 1][in - 1];
    if (temp < mi) {
      mi = temp;
      closest_branch[ver][out][in] = adj[ver][i];
    }
  }
  return cost[ver][out][in] = ans + mi;
}
void solve(int v) {
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == par[v]) continue;
    for (int ii = 0; ii <= n; ii++) {
      for (int j = 0; j <= n; j++) {
        sum_min_branch[v][ii][j] += single_min[adj[v][i]][ii][j];
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      single_update(v, i, j);
    }
  }
  for (int i = 0; i <= n; i++) {
    single_min[v][i][n] = cost[v][i][n];
    get_min[v][i][n] = n;
    for (int j = n - 1; j >= 0; j--) {
      if (cost[v][i][j] < single_min[v][i][j + 1]) {
        get_min[v][i][j] = j;
        single_min[v][i][j] = cost[v][i][j];
      } else {
        get_min[v][i][j] = get_min[v][i][j + 1];
        single_min[v][i][j] = single_min[v][i][j + 1];
      }
    }
  }
}
void find_center(int v, int out, int in) {
  if (!in) center.push_back(v);
  if (in == n) return;
  if (!in) {
    for (int i = 0; i < adj[v].size(); i++) {
      if (adj[v][i] == par[v]) continue;
      find_center(adj[v][i], 1, get_min[adj[v][i]][1][0]);
    }
    return;
  }
  find_center(closest_branch[v][out][in], min(out + 1, n), in - 1);
  for (int i = 0; i < adj[v].size(); i++) {
    if (adj[v][i] == par[v] || adj[v][i] == closest_branch[v][out][in])
      continue;
    find_center(adj[v][i], min(out, in) + 1,
                get_min[adj[v][i]][min(out, in) + 1][in - 1]);
  }
}
int dist[181][181];
int get_dist(int u, int v) {
  if (u == v || dist[u][v]) return dist[u][v];
  if (depth[u] <= depth[v])
    return dist[u][v] = dist[v][u] = 1 + get_dist(par[u], v);
  return dist[u][v] = dist[v][u] = 1 + get_dist(u, par[v]);
}
int main() {
  int fr;
  init();
  dfs(1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = 0;
    }
  }
  depth_search();
  while (!q.empty()) {
    fr = q.front();
    q.pop();
    deg[par[fr]]--;
    if (deg[par[fr]] == 1) q.push(par[fr]);
    solve(fr);
  }
  int ans = cost[1][0][0];
  int out = 0, in = 0;
  for (int i = 0; i < n; i++) {
    if (cost[1][n][i] < ans) {
      ans = cost[1][n][i];
      out = n;
      in = i;
    }
  }
  printf("%d\n", ans);
  find_center(1, out, in);
  int di, des;
  for (int i = 1; i <= n; i++) {
    di = 1 << 30;
    des = 0;
    for (int j = 0; j < center.size(); j++) {
      if (di > get_dist(i, center[j])) {
        di = get_dist(i, center[j]);
        des = center[j];
      }
    }
    printf("%d ", des);
  }
}
