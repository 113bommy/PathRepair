#include <bits/stdc++.h>
using namespace std;
const short NMAX = 55;
char a[NMAX][NMAX];
int n, m;
bool b[NMAX][NMAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void DFS(int i, int j, int k, int p) {
  int x, y;
  b[i][j] = true;
  for (int k = 0; k < 4; k++) {
    x = i + dx[k];
    y = j + dy[k];
    if (!(1 <= x && x <= n && 1 <= y && y <= m)) continue;
    if (a[i][j] != a[x][y]) continue;
    if (!b[x][y])
      DFS(x, y, i, j);
    else if (x != k && y != p) {
      cout << "Yes\n";
      exit(0);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> (a[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!b[i][j]) DFS(i, j, 0, 0);
  cout << "No\n";
  return 0;
}
