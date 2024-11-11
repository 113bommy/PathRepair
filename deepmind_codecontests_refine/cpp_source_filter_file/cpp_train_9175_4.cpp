#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-11;
int n, k, m;
int nn;
vector<int> g[32];
int c[32][32];
double a[256][256];
double b[256][256];
double z[256][256];
int xy[256][2];
double p[256];
double ans[256];
void mult(double a[][256]) {
  int n = nn;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(n); j++) {
      b[i][j] = a[j][i];
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(n); j++) {
      z[i][j] = 0.0;
      for (int k = 0; k < (int)(n); k++) {
        z[i][j] += a[i][k] * b[j][k];
      }
      if (z[i][j] < 1e-30) z[i][j] = 0.0;
    }
  }
  memcpy(a, z, sizeof(z));
}
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  k = 0;
  int x1, x2;
  scanf("%d%d%d%d", &n, &m, &x1, &x2);
  x1--;
  x2--;
  for (int i = 0; i < (int)(m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < (int)(n); i++) {
    scanf("%lf", &p[i]);
  }
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(i + 1); j++) {
      c[i][j] = c[j][i] = k;
      xy[k][0] = i;
      xy[k][1] = j;
      k++;
    }
  }
  memset((a), 0, sizeof(a));
  for (int i = 0; i < (int)(k); i++) {
    int x = xy[i][0];
    int y = xy[i][1];
    if (x == y) {
      a[i][i] = 1.0;
      continue;
    }
    double px = p[x];
    double py = p[y];
    double qx = (1.0 - px) / g[x].size();
    double qy = (1.0 - py) / g[y].size();
    for (int jx = 0; jx < (int)(g[x].size() + 1); jx++) {
      int xn = (jx == (int)g[x].size()) ? x : g[x][jx];
      double vx = (jx == (int)g[x].size()) ? px : qx;
      for (int jy = 0; jy < (int)(g[y].size() + 1); jy++) {
        int yn = (jy == (int)g[y].size()) ? y : g[y][jy];
        double vy = (jy == (int)g[y].size()) ? py : qy;
        int j = c[xn][yn];
        a[i][j] += vx * vy;
      }
    }
  }
  nn = k;
  for (int i = 0; i < (int)(16); i++) {
    mult(a);
  }
  memset((p), 0, sizeof(p));
  p[c[x1][x2]] = 1.0;
  memset((ans), 0, sizeof(ans));
  for (int i = 0; i < (int)(k); i++) {
    for (int j = 0; j < (int)(k); j++) {
      ans[i] += p[j] * a[j][i];
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    if (i) putchar(' ');
    printf("%0.9lf", ans[c[i][i]]);
  }
  puts("");
  return 0;
}
