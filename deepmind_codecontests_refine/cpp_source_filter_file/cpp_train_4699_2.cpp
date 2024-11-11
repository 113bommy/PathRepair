#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int vis[1000 + 5][1000 + 5], pi[1000 + 5], ans[1000 + 5];
char mp[1000 + 5][1000 + 5];
struct node {
  int x, y, i;
};
queue<node> q[1000 + 5];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int bfs(int s) {
  int sum = q[s].size();
  queue<node> tmp;
  for (int i = 0; i < sum; i++) {
    tmp.push(q[s].front());
    q[s].pop();
  }
  while (!tmp.empty()) {
    node now = tmp.front();
    tmp.pop();
    for (int i = 0; i < 4; i++) {
      node next;
      next.x = now.x + dx[i], next.y = now.y + dy[i], next.i = now.i;
      if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
          mp[next.x][next.y] != '#' && vis[next.x][next.y] == 0) {
        vis[next.x][next.y] = now.i;
        q[s].push(next);
      }
    }
  }
  return q[s].size();
}
int main() {
  node tmp;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= p; i++) {
    scanf("%d", &pi[i]);
    if (pi[i] > 1000) pi[i] = 1000;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] >= '0' && mp[i][j] < '9') {
        node now;
        vis[i][j] = mp[i][j] - '0';
        now.x = i, now.y = j, now.i = mp[i][j] - '0';
        q[now.i].push(now);
      }
    }
  }
  int flag;
  while (1) {
    flag = 0;
    for (int i = 1; i <= p; i++) {
      for (int j = 1; j <= pi[i]; j++) {
        if (bfs(i))
          flag = 1;
        else
          break;
      }
    }
    if (!flag) break;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] != 0) {
        ans[vis[i][j]]++;
      }
    }
  }
  for (int i = 1; i <= p; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
