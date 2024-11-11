#include <bits/stdc++.h>
using namespace std;
int gcd(int u, int v) { return (v != 0) ? gcd(v, u % v) : u; }
int cost[4][4];
int n;
vector<int> adj[210];
int comp[210];
int inDegree[210];
vector<int> q[4];
int order[4][4];
int rec(int prev, int total) {
  if (!total) return 0;
  int ret;
  for (int i = 0; i < 3; i++) {
    int a = order[comp[prev]][i];
    if (!q[a].empty()) {
      int cur = q[a].back();
      q[a].pop_back();
      for (int j = 0; j < adj[cur].size(); j++) {
        int nxt = adj[cur][j];
        inDegree[nxt]--;
        if (!inDegree[nxt]) q[comp[nxt]].push_back(nxt);
      }
      ret = rec(cur, total - 1) + cost[comp[prev]][comp[cur]] + 1;
      for (int j = 0; j < adj[cur].size(); j++) {
        int nxt = adj[cur][j];
        if (!inDegree[nxt]) q[comp[nxt]].pop_back();
        inDegree[nxt]++;
      }
      q[a].push_back(cur);
      return ret;
    }
  }
}
int main() {
  cost[1][1] = cost[2][2] = cost[3][3] = 0;
  cost[1][2] = cost[2][3] = cost[3][1] = 1;
  cost[1][3] = cost[2][1] = cost[3][2] = 2;
  order[1][0] = 1;
  order[1][1] = 2;
  order[1][2] = 3;
  order[2][0] = 2;
  order[2][1] = 3;
  order[2][2] = 1;
  order[3][0] = 3;
  order[3][1] = 1;
  order[3][2] = 2;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> comp[i];
  int a, b;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    a = i;
    for (int j = 0; j < k; j++) {
      cin >> b;
      adj[b].push_back(a);
      inDegree[a]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!inDegree[i]) q[comp[i]].push_back(i);
  }
  bool vis[4] = {0};
  int res = 1e9;
  for (int i = 1; i <= 3; i++) {
    if (!q[i].empty()) {
      int cur = q[i].back();
      q[i].pop_back();
      for (int j = 0; j < adj[cur].size(); j++) {
        int nxt = adj[cur][j];
        inDegree[nxt]--;
        if (!inDegree[nxt]) q[comp[nxt]].push_back(nxt);
      }
      res = min(res, rec(cur, n - 1) + 1);
      for (int j = 0; j < adj[cur].size(); j++) {
        int nxt = adj[cur][j];
        if (!inDegree[nxt]) q[comp[nxt]].pop_back();
        inDegree[nxt]++;
      }
      q[i].push_back(cur);
    }
  }
  cout << res << endl;
}
