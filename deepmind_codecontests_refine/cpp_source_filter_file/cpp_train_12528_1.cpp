#include <bits/stdc++.h>
using namespace std;
vector<long long int> nodes, adj[10000], temp;
vector<string> a;
long long int n, m, z = 0, l = 0, vis[10000];
bool check() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (adj[m * i + j].size() == 1) return true;
  return false;
}
void find() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (adj[m * i + j].size() == 4) temp.push_back(m * i + j);
}
void dfs(long long int node, long long int res) {
  vis[node] = 1;
  l++;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!vis[adj[node][i]] && adj[node][i] != res) dfs(adj[node][i], res);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string b;
  for (int i = 0; i < n; i++) {
    cin >> b;
    a.push_back(b);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') continue;
      z++;
      if (i > 0 && a[i - 1][j] == '#') adj[m * i + j].push_back(m * i - m + j);
      if (j > 0 && a[i][j - 1] == '#') adj[m * i + j].push_back(m * i + j - 1);
      if (i < n - 1 && a[i + 1][j] == '#')
        adj[m * i + j].push_back(m * i + m + j);
      if (j < m - 1 && a[i][j + 1] == '#')
        adj[m * i + j].push_back(m * i + j + 1);
    }
  }
  if (z <= 2) {
    cout << "-1" << endl;
    return 0;
  }
  if (z == 3) {
    if (check())
      cout << "1" << endl;
    else
      cout << "-1" << endl;
    return 0;
  }
  if (check()) {
    cout << "1" << endl;
    return 0;
  }
  find();
  for (int q = 0; q < temp.size(); q++) {
    long long int fg = 0;
    l = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '#' && m * i + j != temp[q]) {
          fg = 1;
          dfs(m * i + j, temp[q]);
          break;
        }
      }
      if (fg) break;
    }
    if (l < z - 1) {
      cout << "1" << endl;
      return 0;
    }
    for (int i = 0; i < 10000; i++) vis[i] = 0;
  }
  cout << "2" << endl;
  return 0;
}
