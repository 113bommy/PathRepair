#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, m, dist[maxn][2];
double javab = (double)0;
bool chek[maxn][2];
long long t[maxn][2], f[maxn][maxn];
vector<int> v[maxn];
queue<int> q;
void bfs(int x, int y) {
  q.push(x);
  chek[x][y] = true;
  t[x][y] = 1;
  dist[x][y] = 0;
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (int i = 0; i < v[x].size(); i++)
      if (chek[v[x][i]][y] == true && dist[v[x][i]][y] + 1 == dist[x][y])
        t[x][y] += t[v[x][i]][y];
    for (int i = 0; i < v[x].size(); i++)
      if (chek[v[x][i]][y] == false) {
        chek[v[x][i]][y] = true;
        q.push(v[x][i]);
        dist[v[x][i]][y] = dist[x][y] + 1;
      }
  }
}
int main() {
  int x, y;
  long long s, e;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  bfs(0, 0);
  bfs(n - 1, 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < v[i].size(); j++) {
      x = i;
      y = v[i][j];
      if (dist[x][0] < dist[y][0]) {
        if (dist[x][0] + dist[y][1] > dist[0][1]) continue;
        f[x][y] = t[x][0] * t[y][1];
      } else {
        if (dist[y][0] + dist[x][1] > dist[0][1]) continue;
        f[x][y] = t[y][0] * t[x][1];
      }
    }
  s = t[0][1];
  for (int i = 0; i < n; i++) {
    e = 0;
    for (int j = 0; j < v[i].size(); j++) e += f[i][v[i][j]];
    if (javab < (double)e / (double)s) javab = (double)e / (double)s;
  }
  cout << fixed << setprecision(10) << javab << endl;
  return 0;
}
