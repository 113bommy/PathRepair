#include <bits/stdc++.h>
using namespace std;
const int N = 51;
bool mark[N][N];
char a[N][N];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool vert(int x, int y, int vx, int vy) {
  while (x < vx)
    if (a[++x][y] != 'B') return false;
  while (x > vx)
    if (a[--x][y] != 'B') return false;
  return true;
}
bool hori(int x, int y, int vx, int vy) {
  while (y < vy)
    if (a[x][++y] != 'B') return false;
  while (y > vy)
    if (a[x][--y] != 'B') return false;
  return true;
}
bool ok(int x, int y, int vx, int vy) {
  return (hori(x, y, vx, vy) && vert(x, vy, vx, vy)) ||
         (vert(x, y, vx, vy) && hori(vx, y, vx, vy));
}
int main() {
  cin >> n >> m;
  int x = -1, y = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < n; k++)
        for (int l = 0; l < m; l++)
          if (a[i][j] == 'B' && a[k][l] == 'B' && !ok(i, j, k, l))
            return cout << "NO" << endl, 0;
  cout << "YES" << endl;
}
