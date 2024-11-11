#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 10, maxM = 1000 * 100 + 10;
int n, m, par[maxN];
vector<pair<pair<int, int>, bool> > edge;
bool edg[maxM];
int find_par(int v) {
  if (par[v] == v) return v;
  par[v] = find_par(par[v]);
  return par[v];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    v--;
    u--;
    bool cc = false;
    if (c == 'S') cc = true;
    edge.push_back({{u, v}, cc});
  }
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    bool cc = edge[i].second;
    if (cc) {
      int bsv = find_par(v), bsu = find_par(u);
      if (bsv != bsu) par[bsv] = bsu;
    }
  }
  int M = 0;
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    bool cc = edge[i].second;
    if (!cc) {
      int bsv = find_par(v), bsu = find_par(u);
      if (bsv != bsu) {
        par[bsv] = bsu;
        edg[i] = true;
        M++;
      }
    }
  }
  if (M > (n - 1) / 2) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    bool cc = edge[i].second;
    if (!cc) {
      int bsv = find_par(v), bsu = find_par(u);
      par[bsv] = bsu;
    }
  }
  int S = 0;
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    bool cc = edge[i].second;
    if (cc) {
      int bsv = find_par(v), bsu = find_par(u);
      if (bsv != bsu) {
        par[bsv] = bsu;
        edg[i] = true;
        S++;
      }
    }
  }
  if (S > (n - 1) / 2) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) par[i] = i;
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    if (edg[i]) {
      int bsv = find_par(v), bsu = find_par(u);
      par[bsv] = bsu;
    }
  }
  for (int i = 0; i < m; i++) {
    int u = edge[i].first.first, v = edge[i].first.second;
    bool cc = edge[i].second;
    int bsv = find_par(v), bsu = find_par(u);
    if (bsv != bsu) {
      if (cc && S < (n - 1) / 2) {
        par[bsv] = bsu;
        edg[i] = true;
        S++;
      }
      if (!cc && M < (n - 1) / 2) {
        par[bsv] = bsu;
        edg[i] = true;
        M++;
      }
    }
  }
  if (S + M != n - 1 && n % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << n - 1 << endl;
  for (int i = 0; i < m; i++)
    if (edg[i]) cout << i + 1 << ' ';
  cout << endl;
  return 0;
}
