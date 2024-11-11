#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > adj;
const int NM = 1e5 + 1;
int timer;
int tin[NM], tout[NM];
int parent[NM][22];
void dfs(int cur, int p) {
  tin[cur] = timer++;
  parent[cur][0] = p;
  for (int i = 1; i < 22; ++i) {
    int v = parent[cur][i - 1];
    if (v != -1) {
      parent[cur][i] = parent[v][i - 1];
    } else {
      parent[cur][i] = -1;
    }
  }
  for (int u : adj[cur]) {
    if (u != p) {
      dfs(u, cur);
    }
  }
  tout[cur] = timer++;
}
bool isAnc(int child, int p) {
  if (p == -1) return true;
  if (tin[child] >= tin[p] && tout[child] <= tout[p]) return true;
  return false;
}
int lca(int u, int v) {
  if (isAnc(u, v)) return v;
  if (isAnc(v, u)) return u;
  for (int i = 21; i >= 0; --i) {
    int p = parent[u][i];
    if (!isAnc(v, p)) {
      u = p;
    }
  }
  return parent[u][0];
}
int start[NM];
int finish[NM];
void propagate(int cur, int p) {
  for (int u : adj[cur])
    if (u != p) {
      propagate(u, cur);
      start[cur] += start[u];
      finish[cur] += finish[u];
    }
}
int main(int, char**) {
  std::ios::sync_with_stdio(false);
  cin >> n;
  adj.resize(n);
  vector<pair<int, int> > edges(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edges[i] = {u, v};
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    int curLca = lca(u, v);
    if (curLca == u) {
      ++finish[curLca];
      ++start[v];
    } else if (curLca == v) {
      ++finish[curLca];
      ++start[u];
    } else {
      finish[curLca] += 2;
      ++start[u];
      ++start[v];
    }
  }
  propagate(0, -1);
  for (auto e : edges) {
    int v = e.first;
    if (tin[v] < tin[e.second]) v = e.second;
    cout << start[v] - finish[v] << endl;
  }
  return 0;
}
