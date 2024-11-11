#include <bits/stdc++.h>
using namespace std;
int a[2020][2020], b[2020][2020];
const int LIM = 3, BLIM = 15;
int minx, miny, maxx, maxy, cn;
void dfs(int x, int y) {
  if (!b[x][y]) return;
  if (x < minx || (x == minx && y < miny)) minx = x, miny = y;
  if (x > maxx || (x == maxx && y > maxy)) maxx = x, maxy = y;
  b[x][y] = 0;
  cn++;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}
void lemon() {
  int n;
  scanf("%d", &n);
  for (int i = (LIM); i <= (n + LIM - 1); i++)
    for (int j = (LIM); j <= (n + LIM - 1); j++) scanf("%d", &a[i][j]);
  for (int i = (LIM); i <= (n - LIM + 1); i++)
    for (int j = (LIM); j <= (n - LIM + 1); j++)
      for (int k = (i - LIM + 1); k <= (i + LIM - 1); k++)
        for (int L = (j - LIM + 1); L <= (j + LIM - 1); L++)
          if (a[k][L]) b[i - LIM + 1][j - LIM + 1]++;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (b[i][j] >= BLIM)
        b[i][j] = 1;
      else
        b[i][j] = 0;
  int circle = 0, square = 0;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (b[i][j]) {
        minx = miny = 1000000000;
        maxx = maxy = -1000000000;
        cn = 0;
        dfs(i, j);
        double dis =
            sqrt((maxx - minx) * (maxx - minx) + (maxy - miny) * (maxy - miny));
        double square_area = dis * dis / 2;
        double circle_area = dis * dis / 4 * 3.14159;
        if (circle_area < 20 && square_area < 20) continue;
        if (abs(cn - circle_area) < abs(cn - square_area))
          circle++;
        else
          square++;
      }
  cout << circle << " " << square << endl;
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
