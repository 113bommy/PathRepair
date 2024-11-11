#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
const int maxn = 1e5 + 5;
void bfs(int node, vector<int>& dist) {
  dist[node] = 0;
  queue<int> q;
  q.push(node);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    for (int i = 0; i < adj[front].size(); i++) {
      int v = adj[front][i];
      if (dist[v] == 1000000000) {
        dist[v] = dist[front] + 1;
        q.push(v);
      }
    }
  }
}
const string alice = "Alice";
const string bob = "Bob";
int main() {
  int tc, i, j, n, a, b, da, db;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
    adj.assign(n + 1, vector<int>());
    vector<int> dista, distb, distc;
    dista.assign(n + 1, 1000000000);
    distb.assign(n + 1, 1000000000);
    distc.assign(n + 1, 1000000000);
    for (i = 0; i < n - 1; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if (da >= db) {
      cout << alice << endl;
      continue;
    }
    if (2 * da >= db) {
      cout << alice << endl;
      continue;
    }
    bfs(a, dista);
    bfs(b, distb);
    if (dista[b] <= da) {
      cout << alice << endl;
      continue;
    }
    int nodeTerjauh = -1, jarakA = 0;
    for (i = 1; i <= n; i++) {
      if (jarakA < distb[i]) {
        jarakA = distb[i];
        nodeTerjauh = i;
      }
    }
    assert(nodeTerjauh != -1);
    bfs(nodeTerjauh, distc);
    int diameter = 0, nodeTerjauh2 = -1;
    for (i = 1; i <= n; i++) {
      if (diameter < distc[i]) {
        diameter = distc[i];
        nodeTerjauh2 = i;
      }
    }
    if (diameter <= 2 * da) {
      cout << alice << endl;
      continue;
    }
    if (diameter > db) {
      cout << bob << endl;
    } else {
      cout << alice << endl;
    }
  }
  return 0;
};
