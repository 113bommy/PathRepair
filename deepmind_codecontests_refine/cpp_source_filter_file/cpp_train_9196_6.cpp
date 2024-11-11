#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, wat, lev;
};
char graph[2][100005];
bool visited[2][100005];
int n, k;
int bfs(int x0, int y0) {
  queue<node> q;
  node nd;
  nd.x = x0;
  nd.y = y0;
  nd.wat = 0;
  nd.lev = 1;
  q.push(nd);
  visited[x0][y0] = 1;
  while (q.size() > 0) {
    int x, y, lev, wat;
    x = q.front().x;
    y = q.front().y;
    wat = q.front().wat;
    q.pop();
    if (y >= n) return 1;
    if (visited[x][y - 1] == 0 && graph[x][y - 1] == '-' && y - 1 > wat + 1) {
      node xx;
      visited[x][y - 1] = 1;
      xx.x = x;
      xx.y = y - 1;
      xx.wat = wat + 1;
      q.push(xx);
    }
    if (y + 1 >= n) return 1;
    if (visited[x][y + 1] == 0 && graph[x][y + 1] == '-' && y + 1 > wat + 1) {
      node xx;
      visited[x][y + 1] = 1;
      xx.x = x;
      xx.y = y + 1;
      xx.wat = wat + 1;
      q.push(xx);
    }
    if (y + k >= n) return 1;
    if (visited[(x + 1) % 2][y + k] == 0 && graph[(x + 1) % 2][y + k] == '-' &&
        y + k > wat + 1) {
      node xx;
      visited[(x + 1) % 2][y + k] = 1;
      xx.x = (x + 1) % 2;
      xx.y = y + k;
      xx.wat = wat + 1;
      q.push(xx);
    }
  }
  return 0;
}
int main() {
  cin >> n >> k;
  graph[0][0] = 'X';
  graph[1][0] = 'X';
  for (int i = 1; i <= n; i++) {
    cin >> graph[0][i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> graph[1][i];
  }
  graph[0][n + 1] = 'X';
  graph[1][n + 1] = 'X';
  bfs(0, 1) == 1 ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
