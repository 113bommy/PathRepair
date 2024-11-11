#include <bits/stdc++.h>
using namespace std;
const int N = 5e4;
vector<int> adj[N + 5];
int n, r1, r2;
bool vis[N + 5];
int arr[N + 5];
void DFS(int u, int p) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (!vis[v]) {
      arr[v] = u;
      DFS(v, u);
    }
  }
}
int main() {
  int u;
  cin >> n >> r1 >> r2;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    if (i == r1) {
      i++;
    }
    adj[i].push_back(u);
    adj[u].push_back(i);
  }
  DFS(r2, -1);
  for (int i = 1; i <= n; i++) {
    if (i == r2) {
      continue;
    }
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
