#include <bits/stdc++.h>
using namespace std;
namespace FFT {
const int N = 1 << 21;
struct Complex {
  double r, i;
};
inline Complex operator+(const Complex &a, const Complex &b) {
  return {a.r + b.r, a.i + b.i};
}
inline Complex operator-(const Complex &a, const Complex &b) {
  return {a.r - b.r, a.i - b.i};
}
inline Complex operator*(const Complex &a, const Complex &b) {
  return {a.r * b.r - a.i * b.i, a.i * b.r + a.r * b.i};
}
int rev[N];
const double PI = acos(-1);
void FFT(Complex a[], int n, int fl) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int s = 1; s < n; s <<= 1) {
    Complex wn = {cos(PI / s), sin(PI / s) * fl};
    for (int i = 0; i < n; i += s << 1) {
      Complex w = {1, 0};
      for (int j = 0; j < s; j++, w = w * wn) {
        Complex x = a[i + j], y = w * a[i + s + j];
        a[i + j] = x + y;
        a[i + s + j] = x - y;
      }
    }
  }
  if (fl == -1)
    for (int i = 0; i < n; i++) a[i].r /= n, a[i].i /= n;
}
Complex f[N], g[N];
int n, m;
void solve() {
  int lim = 1, d = 0;
  while (lim <= n + m) ++d, lim <<= 1;
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (d - 1));
  for (int i = n + 1; i < lim; i++) f[i] = {0, 0};
  for (int i = m + 1; i < lim; i++) g[i] = {0, 0};
  FFT(f, lim, 1);
  FFT(g, lim, 1);
  for (int i = 0; i < lim; i++) f[i] = f[i] * g[i];
  FFT(f, lim, -1);
}
}  // namespace FFT
const int N = 55, M = 105, K = 20005;
const double INF = 1e18;
int n, m, t, x, a[N], b[M];
double dis[N][N], c[M], p[M][K * 2], f[N][K * 2], g[M][K];
void solve(int l, int r) {
  if (l == t) return;
  if (l == r) {
    for (int i = 1; i < n; i++) f[i][l] = INF;
    for (int i = 1; i <= m; i++)
      if (a[i] != n) f[a[i]][l] = min(f[a[i]][l], g[i][l] + c[i]);
    return;
  }
  int mid = (l + r) >> 1;
  solve(mid + 1, r);
  FFT::n = r - l - 1;
  FFT::m = r - mid - 1;
  for (int i = 1; i <= m; i++)
    if (a[i] != n) {
      for (int j = 0; j <= FFT::n; j++) FFT::f[j] = {p[i][j + 1], 0};
      for (int j = 0; j <= FFT::m; j++) FFT::g[j] = {f[b[i]][r - j], 0};
      FFT::solve();
      for (int j = l; j <= mid; j++) g[i][j] += FFT::f[r - j - 1].r;
    }
  solve(l, mid);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> t >> x;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) dis[i][j] = INF;
  int t1;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> t1;
    c[i] = dis[a[i]][b[i]] = t1;
    for (int j = 1; j <= t; j++) cin >> t1, p[i][j] = t1 / 1e5;
  }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
  for (int i = 0; i < t * 2; i++) f[n][i] = i <= t ? 0 : x;
  for (int i = 1; i < n; i++)
    for (int j = t; j < t * 2; j++) f[i][j] = dis[i][n] + x;
  solve(0, t * 2 - 1);
  printf("%.10lf\n", f[1][0]);
  return 0;
}
