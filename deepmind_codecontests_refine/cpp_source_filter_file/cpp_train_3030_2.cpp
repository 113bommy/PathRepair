#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], pos[N], mark[N];
vector<int> adj[N], bfs;
bool cmp(int a, int b) { return pos[a] < pos[b]; }
int main() {
  scanf("%d", &n);
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v), adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), pos[a[i]] = i;
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), cmp);
  queue<int> q;
  q.push(1), bfs.push_back(1);
  while (!q.empty()) {
    int v = q.front();
    mark[v] = 1;
    q.pop();
    for (auto &u : adj[v])
      if (!mark[u]) q.push(u), bfs.push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (bfs[i] != a[i]) puts("no"), exit(0);
  puts("yes");
}
