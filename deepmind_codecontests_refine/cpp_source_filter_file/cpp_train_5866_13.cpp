#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, h, i, j, k;
double F[3005][3005], g[3005][605];
double f[3005][2][605];
double u, v, w;
struct Point {
  int I, J;
  double x;
  Point() {}
  Point(int I, int J, double x) : I(I), J(J), x(x) {}
  friend bool operator<(const Point &x, const Point &y) { return x.x < y.x; }
};
Point ch;
priority_queue<Point> GG;
double an;
double make(int x, int y) {
  int ii, jj, kk;
  f[0][x & 1][y] = 0;
  for (ii = 1; ii <= a; ii++)
    f[ii][x & 1][y] = f[ii - 1][(x - 1) & 1][y] * g[ii][y] +
                      f[ii - 1][x & 1][y] * (1 - g[ii][y]);
  return f[a][x & 1][y];
}
int main() {
  scanf("%d%d", &a, &b);
  for (i = 1; i <= a; i++)
    for (j = 1; j <= b; j++) {
      scanf("%d", &d);
      g[i][j] = (double)d / 1000.0;
    }
  for (i = 1; i <= b; i++) {
    f[0][0][i] = 1;
    F[0][i] = 1;
  }
  for (i = 1; i <= a; i++)
    for (j = 1; j <= b; j++) f[i][0][j] = 1;
  for (i = 1; i <= a; i++) {
    F[1][i] = make(1, i);
    GG.push(Point(1, i, F[1][i]));
  }
  for (i = 1; i <= a; i++) {
    ch = GG.top();
    GG.pop();
    an += ch.x;
    F[ch.I + 1][ch.J] = make(ch.I + 1, ch.J);
    GG.push(Point(ch.I + 1, ch.J, F[ch.I + 1][ch.J]));
  }
  printf("%lf\n", an);
  return 0;
}
