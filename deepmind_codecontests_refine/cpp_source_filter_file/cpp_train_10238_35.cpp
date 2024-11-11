#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-8;
const int INF = (1 << 30) - 1;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
struct point {
  int r, c;
  point(int r = 0, int c = 0) {
    this->r = r;
    this->c = c;
  };
};
int n, r;
int pnt;
point bp[8];
bool u[2000][2000];
bool uu[2000][2000];
int cum[2000][2000];
point p[4000000];
inline bool valid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < n); }
int sumsq(int r1, int c1, int r2, int c2) {
  return cum[r2][c2] + (r1 == 0 || c1 == 0 ? 0 : cum[r1 - 1][c1 - 1]) -
         (r1 == 0 ? 0 : cum[r1 - 1][c2]) - (c1 == 0 ? 0 : cum[r2][c1 - 1]);
}
double blackpc(int r1, int c1, int r2, int c2) {
  return double(sumsq((r1 > 0 ? r1 : 0), (c1 > 0 ? c1 : 0),
                      (r2 < n - 1 ? r2 : n - 1), (c2 < n - 1 ? c2 : n - 1))) /
         ((r2 < n - 1 ? r2 : n - 1) - (r1 > 0 ? r1 : 0) + 1) /
         ((c2 < n - 1 ? c2 : n - 1) - (c1 > 0 ? c1 : 0) + 1);
}
void clear() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cum[i][j] =
          u[i][j] + (i == 0 ? 0
                            : cum[i - 1][j] + (j == 0 ? 0 : cum[i][j - 1]) -
                                  (i == 0 || j == 0 ? 0 : cum[i - 1][j - 1]));
  const int d = 5;
  for (int count = 0; count < 1; ++count) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        double pc = blackpc(i - d, j - d, i + d, j + d);
        if (pc < 0.20)
          uu[i][j] = false;
        else if (pc > 0.30)
          uu[i][j] = true;
        else
          uu[i][j] = u[i][j];
      }
    memcpy(u, uu, sizeof(uu));
  }
}
void dfs(int r, int c) {
  if (!u[r][c]) return;
  u[r][c] = false;
  p[pnt++] = point(r, c);
  if (r < p[0].r || r == p[0].r && c < p[0].c) p[0] = point(r, c);
  if (r < p[1].r || r == p[1].r && c > p[1].c) p[1] = point(r, c);
  if (c > p[2].c || c == p[2].c && r < p[2].r) p[2] = point(r, c);
  if (c > p[3].c || c == p[3].c && r > p[3].r) p[3] = point(r, c);
  if (r > p[4].r || r == p[4].r && c < p[4].c) p[4] = point(r, c);
  if (r > p[5].r || r == p[5].r && c > p[5].c) p[5] = point(r, c);
  if (c < p[6].c || c == p[6].c && r < p[6].r) p[6] = point(r, c);
  if (c < p[7].c || c == p[7].c && r > p[7].r) p[7] = point(r, c);
  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (valid(nr, nc)) {
      dfs(nr, nc);
    }
  }
}
double getmaxd() {
  double res = 0;
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) {
      double d = sqrt(0. + (p[i].r - p[j].r) * (p[i].r - p[j].r) +
                      (p[i].c - p[j].c) * (p[i].c - p[j].c));
      res = (res > d ? res : d);
    }
  return res;
}
int isSq(int r, int c) {
  pnt = 0;
  for (int i = 0; i < 8; ++i) bp[i] = point(r, c);
  dfs(r, c);
  if (pnt < 100) return -1;
  double d = getmaxd() + 1.;
  double sqArea = d * d / 2;
  double circArea = (d / 2) * (d / 2) * PI;
  if (pnt < sqArea) return 1;
  if (pnt > circArea) return 0;
  if ((pnt - sqArea) < 2 * (circArea - pnt))
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &r);
      if (r == 1) u[i][j] = true;
    }
  clear();
  int circles = 0, squares = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (u[i][j]) {
        int res = isSq(i, j);
        if (res == 1)
          ++squares;
        else if (res == 0)
          ++circles;
      }
  cout << circles << " " << squares << endl;
  return 0;
};
