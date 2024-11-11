#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[1000005];
vector<long long> grp;
vector<vector<long long> > cycle;
long long visited[1000005];
void dfs(long long x) {
  visited[x] = 1;
  grp.push_back(x);
  for (int i = 0; i < adj[x].size(); i++) {
    int u = adj[x][i];
    if (visited[u] == 0) {
      dfs(u);
    }
  }
}
int main() {
  int n, k, m;
  cin >> n >> k;
  int p, q, r = 0;
  for (int i = 0; i < k; i++) {
    cin >> p >> q;
    adj[p].push_back(q);
    adj[q].push_back(p);
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      grp.clear();
      dfs(i);
      cycle.push_back(grp);
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> p >> q;
    for (int j = 0; j < cycle.size(); j++) {
      int a = 0, b = 0;
      for (int k = 0; k < cycle[j].size(); k++) {
        if (cycle[j][k] == p) a = 1;
        if (cycle[j][k] == q) b = 1;
      }
      if (a == 1 && b == 1) cycle[j][0] = n + 10;
    }
  }
  int max = 0;
  for (int i = 0; i < cycle.size(); i++) {
    if (cycle[i].size() > max && cycle[i][0] != n + 10) max = cycle[i].size();
  }
  cout << max << endl;
  return 0;
}
