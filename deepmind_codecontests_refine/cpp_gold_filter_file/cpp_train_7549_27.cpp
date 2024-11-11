#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
void solve() {}
void gen() {
  freopen("output.txt", "w", stdout);
  exit(0);
}
vector<char> visited;
vector<int> tout;
int T = 0;
vector<int> order;
int n, m;
vector<vector<int>> G;
vector<vector<int>> Gtime;
vector<int> minTime;
void dfs(int v) {
  visited[v] = true;
  ++T;
  for (int to : G[v]) {
    if (visited[to]) {
      continue;
    }
    dfs(to);
  }
  tout[v] = T;
  order.push_back(v);
}
int calcMinTime(int v, int id) {
  if (id == 0) {
    minTime[v] = 0;
    return 0;
  }
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i];
    int toTime = Gtime[v][i];
    if (to == order[id - 1]) {
      minTime[v] = max(minTime[to], toTime);
    }
  }
  return minTime[v];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  G.resize(n);
  Gtime.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    G[u].push_back(v);
    Gtime[u].push_back(i + 1);
  }
  visited.assign(n, false);
  tout.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  minTime.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    int t = calcMinTime(order[i], i);
    if (t == -1) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << minTime[order[n - 1]] << endl;
  return 0;
}
