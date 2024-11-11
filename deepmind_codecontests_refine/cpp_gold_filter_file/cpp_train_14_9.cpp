#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<int> conn[200100];
bool oka = true;
void dfs(int u, int par) {
  if (par == -1 && conn[u].size() == 1)
    ;
  else {
    if (conn[u].size() == 1) return;
    if (conn[u].size() < 3 || oka == false) {
      oka = false;
      return;
    }
  }
  for (int v : conn[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
int main() {
  int n;
  cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    conn[u].push_back(v);
    conn[v].push_back(u);
  }
  dfs(1, -1);
  if (oka)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
