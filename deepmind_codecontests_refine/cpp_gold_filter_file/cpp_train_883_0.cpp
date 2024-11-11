#include <bits/stdc++.h>
using namespace std;
bool roads[405][405];
int bfs(int n, bool road_type) {
  queue<int> towns;
  towns.push(1);
  bool visited[405];
  int road_length[405];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
    road_length[i] = -1;
  }
  road_length[1] = 0;
  visited[1] = true;
  while (!towns.empty()) {
    int current = towns.front();
    towns.pop();
    for (int town = 1; town <= n; town++) {
      if (roads[current][town] == road_type && !visited[town]) {
        visited[town] = true;
        towns.push(town);
        road_length[town] = road_length[current] + 1;
      }
    }
  }
  return road_length[n];
}
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  while (m--) {
    cin >> x >> y;
    roads[x][y] = true;
    roads[y][x] = true;
  }
  int ans1 = bfs(n, false);
  int ans2 = bfs(n, true);
  if (ans1 == -1 || ans2 == -1) {
    cout << "-1" << endl;
  } else {
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}
