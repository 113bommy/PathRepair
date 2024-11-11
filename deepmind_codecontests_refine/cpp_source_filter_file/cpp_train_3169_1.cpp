#include <bits/stdc++.h>
using namespace std;
vector<int> adj[102400];
bool vis[102400];
void dfs(int np) {
  if (vis[np]) {
    return;
  }
  vis[np] = true;
  for (auto it : adj[np]) {
    if (!vis[it]) {
      dfs(it);
    }
  }
  cout << np + 1 << " ";
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  cout << endl;
  return 0;
}
