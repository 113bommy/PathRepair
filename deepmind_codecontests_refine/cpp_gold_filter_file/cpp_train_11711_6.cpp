#include <bits/stdc++.h>
const int maxn = 105, maxm = 4e4 + 5;
const int maxz = 1e5;
const int inf = 1e9 + 7;
template <typename T>
inline T min(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
struct complex {
  double i, r;
  complex(double R = 0.0, double I = 0.0) : i(I), r(R) {}
  complex operator+(complex Chris) { return complex(r + Chris.r, i + Chris.i); }
  complex operator-(complex Chris) { return complex(r - Chris.r, i - Chris.i); }
  complex operator*(complex Chris) {
    return complex(r * Chris.r - i * Chris.i, i * Chris.r + r * Chris.i);
  }
};
namespace Poly {
using std::cos;
using std::sin;
const double Pi = std::acos(-1);
const double eps = 5e-7;
int lim, lg, sing[maxz];
void init(int len) {
  lim = 1, lg = 0;
  while (lim < len) lim <<= 1, lg++;
  for (int i = 1; i < lim; i++)
    sing[i] = (sing[i >> 1] >> 1) | ((i & 1) << (lg - 1));
}
void FFT(complex *Steins, int type) {
  for (int i = 1; i < lim; i++)
    if (sing[i] < i) swap(Steins[i], Steins[sing[i]]);
  for (int len = 1; len < lim; len <<= 1) {
    complex unit(cos(Pi / len), type * sin(Pi / len));
    for (int i = 0; i < lim; i += (len << 1)) {
      complex w(1, 0);
      for (int k = 0; k < len; k++, w = w * unit) {
        complex x = Steins[i + k], y = w * Steins[i + k + len];
        Steins[i + k] = x + y, Steins[i + k + len] = x - y;
      }
    }
  }
  if (type == -1) {
    for (int i = 0; i < lim; i++) Steins[i].r = (Steins[i].r / lim);
  }
}
void convolution(complex *Alpha, int la, complex *Beta, int lb, complex *Zeta) {
  init(la + lb - 1);
  for (int i = la; i < lim; i++) Alpha[i].r = Alpha[i].i = 0;
  for (int i = lb; i < lim; i++) Beta[i].r = Beta[i].i = 0;
  FFT(Alpha, 1), FFT(Beta, 1);
  for (int i = 0; i < lim; i++) Zeta[i] = Alpha[i] * Beta[i];
  FFT(Zeta, -1);
}
}  // namespace Poly
struct edge {
  int u, v, c;
} e[maxn];
int n, m, t, fine;
double p[maxn][maxm], f[maxn][maxm], g[maxn][maxm];
int dis[maxn][maxn];
double P[maxn][maxm];
complex Alpha[maxz], Beta[maxz];
void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j && j != k && i != k)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
void divide(int l, int r) {
  if (l == r) {
    for (int i = 1; i <= m; i++) {
      int u = e[i].u;
      f[u][l] = min(f[u][l], g[i][l]);
    }
    return;
  }
  int mid = (l + r) >> 1;
  divide(mid + 1, r);
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    for (int j = 0; j <= r - l - 1; j++)
      Alpha[j].r = p[i][t + l - r + j], Alpha[j].i = 0;
    for (int j = 0; j <= r - mid - 1; j++)
      Beta[j].r = f[v][j + mid + 1], Beta[j].i = 0;
    Poly::convolution(Alpha, r - l, Beta, r - mid, Alpha);
    for (int j = l; j <= mid; j++)
      g[i][j] = g[i][j] + Alpha[j - (l - r + mid + 1)].r;
  }
  divide(l, mid);
}
void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
      printf("f[%d][%d]:%.6lf\n", i, j, f[i][j]);
      printf("g[%d][%d]:%.6lf\n", i, j, g[i][j]);
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &t, &fine);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) dis[i][j] = inf;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= t; j++) f[i][j] = inf;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
    dis[e[i].u][e[i].v] = e[i].c;
    for (int k = 1; k <= t; k++) {
      int val;
      scanf("%d", &val);
      P[i][k] = P[i][k - 1] + (1.0 * val / 1e5);
      p[i][t - k] = 1.0 * val / 1e5;
    }
    for (int k = 0; k <= t; k++) g[i][k] = e[i].c;
  }
  floyd();
  for (int i = 1; i <= m; i++) {
    int v = e[i].v;
    for (int k = 0; k <= t; k++)
      g[i][k] += (P[i][t] - P[i][t - k]) * (dis[v][n] + fine);
  }
  divide(0, t);
  printf("%.6lf\n", min(f[1][0], (double)(dis[1][n] + fine)));
  return 0;
}
