#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001];
int vis[100001], dist[100001];
void bfs(int src) {
  vis[src] = 1;
  dist[src] = 0;
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < ar[curr].size(); i++) {
      int child = ar[curr][i];
      if (vis[child] == 0) {
        vis[child] = 1;
        dist[child] = dist[curr] + 1;
        q.push(child);
      }
    }
  }
}
void optimize() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  optimize();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
    dist[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      ar[0].push_back(i);
    } else {
      ar[x].push_back(i);
    }
  }
  bfs(0);
  sort(dist, dist + n, greater<int>());
  cout << dist[0] << "\n";
  return 0;
}
