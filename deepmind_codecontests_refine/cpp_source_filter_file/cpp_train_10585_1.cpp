#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int IT_MAX = 1 << 18;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
int a[405][405];
int mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
int visx[205], visy[205];
vector<int> vx, vy;
void uf(int y, int x1, int x2) {
  if (x1 > x2) return;
  if (y > vy[2]) return;
  if (y < vy[0]) return;
  for (int i = x1; i <= x2; i++) {
    a[y][i] += 2;
  }
  uf(y + 1, x1 + 1, x2 - 1);
}
void df(int y, int x1, int x2) {
  if (x1 > x2) return;
  if (y > vy[2]) return;
  if (y < vy[0]) return;
  for (int i = x1; i <= x2; i++) {
    a[y][i] += 2;
  }
  df(y - 1, x1 + 1, x2 - 1);
}
int main() {
  for (int i = 0; i < 4; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x += 100, y += 100;
    mnx = min(x, mnx);
    mny = min(y, mny);
    mxx = max(x, mxx);
    mxy = max(y, mxy);
  }
  for (int i = mny; i <= mxy; i++) {
    for (int j = mnx; j <= mxx; j++) {
      a[i][j] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x += 100, y += 100;
    if (!visx[x]) {
      vx.push_back(x);
      visx[x] = 1;
    }
    if (!visy[y]) {
      vy.push_back(y);
      visy[y] = 1;
    }
  }
  sort((vx).begin(), (vx).end());
  sort((vy).begin(), (vy).end());
  uf(vy[1], vx[0], vx[2]);
  df(vy[1], vx[0], vx[2]);
  for (int i = 0; i <= 400; i++) {
    for (int j = 0; j <= 400; j++) {
      if (a[i][j] == 3) {
        return !printf("YES");
      }
    }
  }
  puts("NO");
}
