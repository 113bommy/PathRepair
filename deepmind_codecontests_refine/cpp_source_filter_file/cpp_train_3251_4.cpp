#include <bits/stdc++.h>
using namespace std;
const int max_n = 200005;
const int INF = 0x3f3f3f3f;
int dis[max_n];
int vis[max_n];
int lu[max_n];
int V, E, s;
struct Edge {
  int to;
};
vector<Edge> e[max_n];
queue<int> q;
void add(int u, int v) { e[u].push_back({v}); }
void bfs(int x) {
  dis[x] = 0;
  q.push(x);
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < e[x].size(); i++) {
      if (dis[e[x][i].to] == INF) {
        q.push(e[x][i].to);
        dis[e[x][i].to] = dis[x] + 1;
      } else if (dis[e[x][i].to] == dis[x] + 1) {
        vis[e[x][i].to] = 1;
      }
    }
  }
}
int max1, min1;
int main() {
  scanf("%d%d", &V, &E);
  int x1, x2, bu;
  for (int i = 0; i < E; i++) {
    scanf("%d%d", &x1, &x2);
    add(x2, x1);
  }
  for (int i = 0; i < max_n; i++) {
    dis[i] = INF;
  }
  cin >> bu;
  for (int i = 1; i <= bu; i++) {
    scanf("%d", &lu[i]);
  }
  s = lu[bu];
  bfs(s);
  for (int i = 1; i < bu; i++) {
    if (dis[lu[i + 1]] + 1 > dis[lu[i]]) {
      min1++;
      max1++;
    } else {
      if (dis[lu[i + 1]] + 1 > dis[lu[i]] && vis[lu[i]] == 1) {
        max1++;
      }
    }
  }
  cout << min1 << ' ' << max1;
  return 0;
}
