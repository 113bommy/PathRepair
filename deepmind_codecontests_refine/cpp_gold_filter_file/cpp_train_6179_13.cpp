#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[1010][1010];
bool sq(int x, int y) {
  if (x > n - 3 || y > n - 3) return false;
  for (int i = x; i < x + 3; i++)
    for (int j = y; j < y + 3; j++)
      if (!a[i][j]) return false;
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x][y] = true;
    int sx = x - 2;
    if (x < 2) sx = 0;
    int sy = y - 2;
    if (y < 2) sy = 0;
    for (int j = sx; j < sx + 3; j++)
      for (int k = sy; k < sy + 3; k++) {
        if (sq(j, k)) {
          cout << i + 1;
          return 0;
        }
      }
  }
  cout << -1;
  return 0;
}
