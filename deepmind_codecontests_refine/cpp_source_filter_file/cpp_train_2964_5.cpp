#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
vector<pair<int, int> > g[N];
bool dead[N];
int sz[N];
long long dp_down[N];
long long dp_up[N];
long long dis[N];
int root[N];
queue<int> q;
vector<int> cycle;
vector<int> weight;
long long sumw;
long long sumd;
long long sumr;
long long suml;
long long L = 0;
long long R = 0;
long long ans[N];
void find_cycle() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    sz[i] = ((int)g[i].size());
    if (sz[i] == 1) q.push(i);
  }
  while (((int)q.size()) && sz[q.front()] == 1) {
    int v = q.front();
    q.pop();
    dead[v] = true;
    cnt++;
    for (auto nei : g[v]) {
      int u = nei.first;
      if (!dead[u]) {
        sz[v]--;
        sz[u]--;
        if (sz[u] == 1) q.push(u);
        break;
      }
    }
  }
  int v = 0;
  for (int i = 0; i < n; ++i) {
    if (!dead[i]) {
      v = i;
      break;
    }
  }
  while (sz[v]) {
    for (auto nei : g[v]) {
      int u = nei.first;
      int w = nei.second;
      if ((cnt < n - 1 && !dead[u]) || (cnt == n - 1 && sz[u] == sz[v])) {
        cycle.push_back(u);
        weight.push_back(w);
        sumw += w;
        sz[v]--;
        sz[u]--;
        dead[v] = true;
        cnt++;
        v = u;
        break;
      }
    }
  }
  for (int v : cycle) dead[v] = false;
}
void dfs_down(int v, int p) {
  root[v] = root[p];
  sz[v] = 1;
  for (pair<int, int> nei : g[v]) {
    int u = nei.first;
    int w = nei.second;
    if (u == p || !dead[u]) continue;
    dis[u] = dis[v] + w;
    dfs_down(u, v);
    dp_down[v] = dp_down[u] + 1LL * sz[u] * w;
    sz[v] += sz[u];
  }
}
void dfs_up(int v, int p) {
  long long sum = 0;
  for (pair<int, int> nei : g[v]) {
    int u = nei.first;
    int w = nei.second;
    if (u == p || !dead[u]) continue;
    sum += dp_down[u] + 1LL * sz[u] * w;
  }
  for (pair<int, int> nei : g[v]) {
    int u = nei.first;
    int w = nei.second;
    if (u == p || !dead[u]) continue;
    dp_up[u] = dp_up[v] + (sum - (dp_down[u] + 1LL * sz[u] * w)) +
               1LL * (sz[root[u]] - sz[u]) * w;
    dfs_up(u, v);
  }
}
inline int st(int x) {
  x %= ((int)cycle.size());
  x += ((int)cycle.size());
  x %= ((int)cycle.size());
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  find_cycle();
  for (int v : cycle) root[v] = v, dfs_down(v, v), sumd += dp_down[v];
  for (int v : cycle) dfs_up(v, v);
  int kr = 1;
  int kl = 0;
  int szr = 0;
  int szl = sz[cycle[0]];
  while (R + weight[kr] <= sumw - R - weight[kr]) {
    R += weight[kr];
    szr += sz[cycle[kr]];
    sumr += R * sz[cycle[kr]];
    kr = st(kr + 1);
  }
  while (L + weight[kl] < sumw - L - weight[kl]) {
    L += weight[kl];
    kl = st(kl - 1);
    szl += sz[cycle[kr]];
    suml += L * sz[cycle[kl]];
  }
  ans[cycle[0]] = suml + sumr + sumd;
  for (int i = 1; i < ((int)cycle.size()); ++i) {
    if (szr != 0) {
      sumr -= szr * weight[i];
      R -= weight[i];
      szr -= sz[cycle[i]];
      suml += szl * weight[i];
      L += weight[i];
      szl += sz[cycle[i]];
    } else {
      suml -= L * sz[cycle[i]];
      suml += (szl - sz[cycle[i]]) * weight[i];
      L += weight[i];
      L -= weight[st(i + 1)];
      kr = st(kr + 1);
      kl = st(kl + 1);
    }
    while (R + weight[kr] <= sumw - R - weight[kr]) {
      R += weight[kr];
      szr += sz[cycle[kr]];
      sumr += R * sz[cycle[kr]];
      kr = st(kr + 1);
      suml -= L * sz[cycle[kl]];
      szl -= sz[cycle[kl]];
      kl = st(kl + 1);
      L -= weight[kl];
    }
    ans[cycle[i]] = suml + sumr + sumd;
  }
  for (int i = 0; i < n; ++i) {
    if (dead[i])
      ans[i] = ans[root[i]] - dp_down[root[i]] + dp_down[i] + dp_up[i] +
               dis[i] * (n - sz[root[i]]);
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
