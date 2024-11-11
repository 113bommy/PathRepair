#include <bits/stdc++.h>
using namespace std;
int ar[2004], sz[2004], ans[2004];
bool vis[2004];
vector<vector<int>> gr(2004), ord(2004);
void dfs(int v) {
  if (vis[v]) {
    return;
  }
  vis[v] = true;
  sz[v] = 0;
  for (int i : gr[v]) {
    if (vis[i]) {
      continue;
    }
    dfs(i);
    for (int j : ord[i]) {
      ord[v].push_back(j);
    }
    sz[v] += sz[i];
  }
  if (sz[v] < ar[v]) {
    cout << "No\n";
    exit(0);
  }
  ord[v].insert(ord[v].begin() + ar[v], v);
}
void solve() {
  int n, root, p, c;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p >> c;
    ar[i] = c;
    if (p != 0) {
      gr[i].push_back(p);
      gr[p].push_back(i);
    } else {
      root = i;
    }
  }
  dfs(root);
  c = 1;
  for (int i : ord[root]) {
    ans[i] = c++;
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
