#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
vector<pair<int, int> > group;
vector<int> na;
vector<int> parent;
int ma[500 + 10][500 + 10];
int find_parent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find_parent(parent[x]);
}
bool check() {
  int f;
  for (int i = 0; i < group.size(); i++) {
    int x = find_parent(group[i].first);
    for (int j = group[i].first + 1; j <= group[i].second; j++) {
      if (find_parent(j) != x) return 0;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, k, tmp, start, endd, u, v, x;
  cin >> n >> m >> k;
  parent.resize(n + 10);
  na.resize(n + 10);
  for (int i = 0; i <= n; i++) parent[i] = i;
  start = 1;
  endd = 0;
  for (int i = 1; i <= k; i++) {
    cin >> tmp;
    endd += tmp;
    for (int j = start; j <= endd; j++) {
      na[j] = i;
    }
    group.push_back(make_pair(start, endd));
    start = endd + 1;
  }
  for (int i = 0; i < 500 + 10; i++)
    for (int j = 0; j < 500 + 10; j++) ma[i][j] = 1000000000;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> x;
    if (!x) parent[find_parent(u)] = find_parent(v);
    if (na[u] != na[v])
      ma[na[u]][na[v]] = ma[na[v]][na[u]] =
          min(x, min(ma[na[u]][na[v]], ma[na[v]][na[u]]));
  }
  if (!check()) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      for (int t = 1; t <= k; t++) {
        ma[j][t] = min(ma[j][t], ma[j][i] + ma[i][t]);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      if (i == j)
        cout << 0 << ' ';
      else if (ma[i][j] == 1000000000)
        cout << -1 << ' ';
      else
        cout << ma[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
