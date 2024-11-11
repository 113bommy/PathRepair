#include <bits/stdc++.h>
using namespace std;
int n, cir, squ, minx, maxx, miny, maxy, amo;
int a[3000][3000], w[3000][3000];
void dfs(int x, int y) {
  w[x][y] = 1;
  amo++;
  minx = min(minx, x);
  maxx = max(maxx, x);
  miny = min(miny, y);
  maxy = max(maxy, y);
  for (int idx = -4; idx < 5; idx++)
    for (int idy = -4; idy < 5; idy++) {
      if (x + idx < 0 || x + idx >= n || y + idy < 0 || y + idy >= n) continue;
      if (!a[x + idx][y + idy] || w[x + idx][y + idy]) continue;
      dfs(x + idx, y + idy);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] && !w[i][j]) {
        minx = maxx = i;
        miny = maxy = j;
        amo = 0;
        dfs(i, j);
        int a = max(maxx - minx + 1, maxy - miny + 1);
        if (fabs(a * a / 4. * acos(-1.) - amo) / (a * a / 4. * acos(-1.)) <
            0.10)
          cir++;
        else
          squ++;
      }
  cout << cir << " " << squ << endl;
  return 0;
}
