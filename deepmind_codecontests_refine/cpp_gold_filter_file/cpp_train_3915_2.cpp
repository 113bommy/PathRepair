#include <bits/stdc++.h>
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
vector<int> v[300005];
int vis[500005], dis[500005], dis1[500005];
int n, x, a, b;
void bfs(int s) {
  for (int i = (1); i < (n + 1); i++) {
    vis[i] = 0;
  }
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  if (s == 1)
    dis[s] = 0;
  else
    dis1[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = (0); i < (v[u].size()); i++) {
      int y = v[u][i];
      if (vis[y] == 0) {
        vis[y] = 1;
        if (s == 1) {
          dis[y] = dis[u] + 1;
        } else
          dis1[y] = dis1[u] + 1;
        q.push(y);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int mini = 0, maxi = 0, flag = 0, mini1 = INT_MAX;
  cin >> n >> x;
  for (int i = (0); i < (n - 1); i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = (1); i < (n + 1); i++) {
    dis[i] = INT_MAX;
    dis1[i] = INT_MAX;
  }
  bfs(1);
  bfs(x);
  for (int i = (1); i < (n + 1); i++) {
    int e = i;
    int o = v[e].size();
    if (dis[e] != INT_MAX && dis1[e] != INT_MAX && dis[e] > dis1[e] &&
        dis[e] >= mini && o == 1) {
      mini = dis[e];
      mini1 = dis1[e];
    }
  }
  cout << mini * 2;
  return 0;
}
