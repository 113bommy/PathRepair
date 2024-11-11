#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int> adj[], int vis[]) {
  vis[s] = 1;
  for (int i = 0; i < adj[s].size(); i++) {
    int x = adj[s][i];
    if (vis[x] == 0) {
      dfs(x, adj, vis);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> adj[1000];
  int vis[1000] = {0};
  long long r = 0;
  int n, m, c = 0, t, k;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t;
    r += t;
    for (int j = 0; j < t; j++) {
      cin >> k;
      adj[101 + i].push_back(k);
      adj[k].push_back(101 + i);
    }
  }
  if (r != 0) {
    for (int i = 101; i < 101 + n; i++) {
      if (vis[i] == 0) {
        dfs(i, adj, vis);
        c++;
      }
    }
    cout << c - 1;
  } else {
    cout << n;
  }
}
