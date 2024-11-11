#include <bits/stdc++.h>
using namespace std;
vector<int> adj[50004];
int parent[50004];
bool vis[50004];
void DFS(int n) {
  vis[n] = true;
  for (int i = 0; i < adj[n].size(); i++) {
    if (!vis[adj[n][i]]) {
      parent[adj[n][i]] = n;
      DFS(adj[n][i]);
    }
  }
}
int main() {
  int i, j, k, N, r1, r2;
  cin >> N >> r1 >> r2;
  for (i = 1; i <= N; i++) {
    cin >> j;
    if (i == r1) i++;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  parent[r2] = -1;
  for (i = 1; i <= N; i++) vis[i] = false;
  DFS(r2);
  for (i = 1, j = 0; i <= N; i++) {
    if (i == r2) continue;
    j++;
    cout << parent[i];
    if (j < N - 1) cout << " ";
  }
  cout << endl;
}
