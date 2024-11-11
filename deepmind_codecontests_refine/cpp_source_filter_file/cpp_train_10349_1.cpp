#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> G[1000000];
int dist[1000000];
int s, t;
list<int> q;
bool vis[1000000];
int mark[1000000];
void redge(int vv, int v) {
  if (vis[v]) return;
  mark[v]--;
  if (mark[v] == 0) {
    q.push_front(v);
    dist[v] = dist[vv];
  } else {
    if (dist[vv] == -1) {
      q.push_back(v);
      dist[v] = dist[vv] + 1;
    }
  }
}
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(mark, 0, sizeof mark);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[v - 1].push_back(u - 1);
    mark[u - 1]++;
  }
  cin >> s >> t;
  s--;
  t--;
  memset(vis, 0, sizeof vis);
  memset(dist, -1, sizeof dist);
  dist[t] = 0;
  q.push_back(t);
  while (!q.empty()) {
    int cq = q.front();
    q.pop_front();
    if (vis[cq]) continue;
    vis[cq] = true;
    for (int i = 0; i < G[cq].size(); i++) redge(cq, G[cq][i]);
  }
  cout << dist[s];
  return 0;
}
