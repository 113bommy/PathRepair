#include <bits/stdc++.h>
using namespace std;
int degree[200001];
vector<int> adj[200001];
vector<pair<int, int>> edge;
int uf[200001];
int find(int x) {
  if (uf[x] < 0) {
    return x;
  }
  return uf[x] = find(uf[x]);
}
bool merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return false;
  }
  uf[b] = a;
  return true;
}
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  memset(degree, 0, sizeof(degree));
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    degree[a]++;
    degree[b]++;
    edge.push_back(make_pair(a, b));
  }
  vector<pair<int, int>> res;
  int Max = 0;
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (Max < degree[i]) {
      Max = degree[i];
      num = i;
    }
  }
  memset(uf, -1, sizeof(uf));
  for (int i = 0; i < adj[num].size(); i++) {
    merge(i, adj[num][i]);
    res.push_back(make_pair(num, adj[num][i]));
  }
  for (int i = 0; i < m; i++) {
    if (res.size() == n - 1) {
      break;
    }
    if (merge(edge[i].first, edge[i].second)) {
      res.push_back(edge[i]);
    }
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << ' ' << res[i].second << '\n';
  }
  return 0;
}
