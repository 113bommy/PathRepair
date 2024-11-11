#include <bits/stdc++.h>
using namespace std;
char A[543][543];
int n, m, k;
struct T {
  int x, y;
};
vector<T> Q;
bool vis[543][543];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void dfs(T p) {
  vis[p.x][p.y] = 1;
  for (int i = 0; i < 4; i++) {
    T p1 = {p.x + dir[i][0], p.y + dir[i][1]};
    if (p1.x < 0 || p1.x >= n || p1.y < 0 || p1.y >= m) continue;
    if (vis[p1.x][p1.y] || A[p1.x][p1.y] == '#') continue;
    dfs({p1.x, p1.y});
  }
  Q.push_back(p);
}
int main() {
  scanf("%d%d%d ", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", A[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (A[i][j] == '.') {
        dfs({i, j});
        break;
      }
  for (int i = 0; i < k; i++) {
    T u = Q[i];
    A[u.x][u.y] = 'X';
  }
  for (int i = 0; i < n; i++) cout << A[i] << '\n';
}
