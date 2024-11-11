#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k, w = 0;
long long tab[21][21];
map<long long, long long> pos[21][21];
void DFS(int y, int x, long long v) {
  if (y + x - 2 == (n + m - 2) / 2) {
    pos[y][x][v]++;
    return;
  }
  if (y < n) DFS(y + 1, x, v ^ tab[y + 1][x]);
  if (x < m) DFS(y, x + 1, v ^ tab[y][x + 1]);
}
void DFS2(int y, int x, long long v) {
  if (y + x - 2 == (n + m - 2) / 2) {
    w += pos[y][x][v ^ k];
    return;
  }
  if (y > 1) DFS2(y - 1, x, v ^ tab[y][x]);
  if (x > 1) DFS2(y, x - 1, v ^ tab[y][x]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> tab[i][j];
  DFS(1, 1, tab[1][1]);
  DFS2(n, m, 0);
  cout << w;
  return 0;
}
