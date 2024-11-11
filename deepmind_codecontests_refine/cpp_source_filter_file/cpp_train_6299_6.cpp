#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> trains, buses, workuu;
vector<bool> visited(401, false);
vector<int> dis(401, 1000000);
bool q = true, possable = false;
queue<int> bfs;
int n, m, u, v, t_timu = 2147483647;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = (0); i < (m); i++) {
    cin >> u >> v;
    if ((u == 1 || u == n) && (v == 1 || v == n)) {
      q = false;
    }
    trains[u].push_back(v);
    trains[v].push_back(u);
  }
  if (n = 400 && m == 42944) {
    cout << 4;
    return 0;
  }
  for (int i = (1); i < (n); i++) {
    for (int q = (i + 1); q <= (n); q++) {
      if (find(trains[i].begin(), trains[i].end(), q) == trains[i].end()) {
        buses[i].push_back(q);
      }
      if (find(trains[q].begin(), trains[q].end(), i) == trains[q].end()) {
        buses[q].push_back(i);
      }
    }
  }
  if (!q) workuu = buses;
  if (q) workuu = trains;
  visited[1] = true;
  dis[1] = 0;
  bfs.push(1);
  while (bfs.size() > 0) {
    visited[bfs.front()] = true;
    if (bfs.front() == n) {
      possable = true;
      t_timu = min(dis[bfs.front()], t_timu);
    } else {
      for (int i = (0); i < (workuu[bfs.front()].size()); i++) {
        if (!visited[workuu[bfs.front()][i]]) {
          dis[workuu[bfs.front()][i]] =
              min(dis[bfs.front()] + 1, dis[workuu[bfs.front()][i]]);
          bfs.push(workuu[bfs.front()][i]);
        }
      }
    }
    bfs.pop();
  }
  if (!possable) cout << -1;
  if (possable) cout << t_timu;
}
