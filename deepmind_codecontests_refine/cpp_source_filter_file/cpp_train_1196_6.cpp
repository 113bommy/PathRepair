#include <bits/stdc++.h>
using namespace std;
void gt(int &a, int b) {
  if (a < b) a = b;
}
string n2s(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
string getKey(int v, int h) { return n2s(v) + "-" + n2s(h); }
vector<int> g[500005];
int legs[500005]{0}, deg[500005]{0}, visited[500005]{0}, del[500005]{0};
void dfs(int u) {
  if (deg[u] <= 2) {
    del[u] = 1;
    for (int v : g[u])
      if (!del[u]) dfs(v);
  } else {
    legs[u]++;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1) dfs(i);
  for (int i = 1; i <= n; i++)
    if (deg[i] == 3 && legs[i] == 2) del[i] = 1;
  for (int i = 1; i <= n; i++)
    if (!del[i]) {
      int neighbour = 0;
      for (int v : g[i])
        if (!del[v]) neighbour++;
      if (neighbour > 2) {
        cout << "NO";
        return 0;
      }
    }
  cout << "YES";
  return 0;
}
