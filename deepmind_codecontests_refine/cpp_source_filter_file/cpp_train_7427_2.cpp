#include <bits/stdc++.h>
using namespace std;
const int maxn = 2009;
bool a[maxn][maxn];
int dist[maxn][maxn];
int n, m, k, ex, ey;
bool hanglie(int x, int y) {
  int left = max(x - dist[x][y], 1);
  int right = min(x + dist[x][y], n);
  for (int i = left; i <= right; i++) {
    int t = dist[x][y] - abs(i - x);
    if (y - t > 0 && !a[i][y - t]) {
      ex = i;
      ey = y - t;
      return false;
    }
    if (y + t <= m && !a[i][y + t]) {
      ex = i;
      ey = y + t;
      return false;
    }
  }
  return false;
}
int main() {
  int x, y;
  scanf("%d%d%d", &n, &m, &k);
  for (int ii = 0; ii < k; ii++) {
    scanf("%d%d", &x, &y);
    if (!a[x][y]) {
      printf("%d %d\n", x, y);
      a[x][y] = true;
      continue;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (x + i <= 0 || y + j <= 0 || x + i >= n || y + j >= m) continue;
        dist[x][y] = max(dist[x][y], dist[x + i][y + j] - abs(i) - abs(j));
      }
    }
    while (hanglie(x, y) == true) {
      dist[x][y]++;
    }
    a[ex][ey] = true;
    printf("%d %d\n", ex, ey);
  }
  return 0;
}
