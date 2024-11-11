#include <bits/stdc++.h>
using namespace std;
vector<int> adj[112];
int vis[112], pai[112], ciclo = 0;
void dfs(int a) {
  vis[a] = 1;
  for (int i = 0; i < adj[a].size(); i++) {
    int b = adj[a][i];
    if (vis[b] == 0) {
      pai[b] = a;
      dfs(b);
    } else {
      if (pai[a] != b && pai[a] != 0) {
        ciclo += 1;
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ok = false;
    }
  }
  if (ciclo > 0 && ciclo < 3 && ok) {
    cout << "FHTAGN!\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
