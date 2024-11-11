#include <bits/stdc++.h>
using namespace std;
const int kCompMax = 4000100;
const int kDir = 8;
const int kDx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int kDy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kMinSize = 100;
const double PI = acos(-1);
const double kEps = 0.2;
inline double sqr(double x) { return x * x; }
struct Pixel {
  double x, y;
  Pixel(double xx, double yy) : x(xx), y(yy) {}
  Pixel() {}
};
vector<Pixel> pix[kCompMax];
int ds[kCompMax], size[kCompMax];
int a[2222][2222], b[2222][2222], belong[2222][2222];
int n, nComp;
int find(int x) { return ds[x] == x ? x : ds[x] = find(ds[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  size[y] += size[x];
  ds[x] = y;
}
double calcDist(Pixel A, Pixel B) {
  return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}
void noiseDeletion(int des) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      bool found = false;
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + kDx[dir], nj = j + kDy[dir];
        if (a[ni][nj] == des) found = true;
      }
      if (found)
        b[i][j] = des;
      else
        b[i][j] = a[i][j];
    }
  memcpy(a, b, sizeof(b));
}
void dfs(int i, int j, int curComp) {
  belong[i][j] = curComp;
  size[curComp]++;
  for (int dir = 0; dir < 4; dir++) {
    int ni = i + kDx[dir], nj = j + kDy[dir];
    if (1 <= ni && ni <= n)
      if (1 <= nj && nj <= n)
        if (a[ni][nj] && !belong[ni][nj]) dfs(ni, nj, curComp);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  noiseDeletion(0);
  noiseDeletion(1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!belong[i][j]) dfs(i, j, ++nComp);
  for (int i = 1; i <= nComp; i++) ds[i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j])
        for (int dir = 0; dir < kDir; dir++) {
          int ni = i + kDx[dir], nj = j + kDy[dir];
          if (1 <= ni && ni <= n && 1 <= nj && nj <= n)
            if (a[ni][nj] && size[belong[ni][nj]] >= kMinSize / 3)
              merge(belong[ni][nj], belong[i][j]);
        }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j]) pix[find(belong[i][j])].push_back(Pixel(i, j));
  int sqrCnt = 0, circCnt = 0;
  for (int i = 1; i <= nComp; i++)
    if ((int)pix[i].size() >= kMinSize) {
      static double dist[kCompMax];
      double totX = 0, totY = 0;
      int m = pix[i].size();
      for (int j = 0; j < m; j++) {
        totX += pix[i][j].x;
        totY += pix[i][j].y;
      }
      totX /= m, totY /= m;
      int nDist = 0;
      for (int j = 0; j < m; j++) {
        dist[nDist++] = calcDist(Pixel(totX, totY), pix[i][j]);
      }
      sort(dist, dist + nDist);
      int select = m / 20 + 1;
      double rad = 0;
      for (int j = nDist - 1; j >= nDist - select; j--) rad += dist[j];
      rad /= select;
      rad *= 1.05;
      double rad2 = rad * sqrt(2) / 2;
      int beyond = 0;
      for (int j = 0; j < nDist; j++)
        if (dist[j] >= rad2) beyond++;
      double diff = fabs((double)beyond / m - 0.5);
      if (diff < kEps)
        circCnt++;
      else
        sqrCnt++;
    }
  printf("%d %d\n", circCnt, sqrCnt);
}
