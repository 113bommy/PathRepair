#include <bits/stdc++.h>
using namespace std;
int vis[51];
vector<int> arr[51];
void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    for (int i = 0; i < arr[u].size(); i++) {
      if (vis[arr[u][i]] == 0) {
        vis[arr[u][i]] = 1;
        q.push(arr[u][i]);
      }
    }
    q.pop();
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    arr[x].push_back(y);
    arr[y].push_back(x);
  }
  int ctr = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      bfs(i);
      ctr++;
    }
  }
  cout << powl(2, n - ctr);
  return 0;
}
