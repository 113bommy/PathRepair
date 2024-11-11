#include <bits/stdc++.h>
using namespace std;
int n, w;
bool g[444][444];
double x, y;
double dx[5], dy[5];
complex<double> deg(int d) {
  return exp(complex<double>(0, d / 180. * acos(-1.)));
}
int o[9999], l;
void dfs(int x) {
  for (int i = 1; i <= w; i++)
    if (g[x][i]) {
      g[x][i] = g[i][x] = false;
      dfs(i);
    }
  o[l++] = x;
}
int main() {
  complex<double> a[5];
  double L = 5 / sin(acos(-1.) / 5);
  a[1] = deg(90);
  a[4] = deg(90 - 72);
  a[3] = deg(90 - 72 - 72 + 360);
  a[2] = deg(90 - 72 - 72 - 72 + 360);
  a[0] = deg(90 + 72);
  for (int i = 0; i < 5; i++) {
    dx[i] = (a[i].real() - a[0].real()) * L;
    dy[i] = (a[i].imag() - a[0].imag()) * L;
  }
  scanf("%d", &n);
  x = y = 0;
  printf("%d\n", n * 4 + 1);
  w = 1;
  printf("0 0\n");
  for (int i = 0; i < n; i++) {
    g[w + 1][w + 2] = true;
    g[w + 2][w + 1] = true;
    g[w + 2][w + 4] = true;
    g[w + 4][w + 2] = true;
    g[w + 4][w] = true;
    g[w][w + 4] = true;
    g[w][w + 3] = true;
    g[w + 3][w] = true;
    g[w + 3][w + 1] = true;
    g[w + 1][w + 3] = true;
    for (int i = 1; i <= 4; i++)
      printf("%.19lf %.19lf\n", x + dx[i], y + dy[i]);
    x += dx[4];
    y += dy[4];
    w += 4;
  }
  w = 1;
  for (int i = 1; i <= n; i++) {
    printf("%d %d %d %d %d\n", w, w + 2, w + 3, w + 4, w + 1);
    w += 4;
  }
  dfs(1);
  for (int i = 0; i < l; i++) printf("%d%c", o[i], i < l - 1 ? ' ' : '\n');
  return 0;
}
