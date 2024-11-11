#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const double pi = acos(-1.0);
struct virt {
  double x, y;
  virt(double xx = 0.0, double yy = 0.0) { x = xx, y = yy; }
  virt operator+(virt a) { return virt(x + a.x, y + a.y); }
  virt operator-(virt a) { return virt(x - a.x, y - a.y); }
  virt operator*(virt a) { return virt(x * a.x - y * a.y, x * a.y + y * a.x); }
} G[2][25], a[131075], b[131075];
int s, l, rev[131075];
void Pre() {
  for (int i = 22; i; --i) {
    G[0][i] = virt(cos(pi / (1 << i - 1)), sin(pi / (1 << i - 1)));
    G[1][i] = virt(G[0][i].x, -G[0][i].y);
  }
}
void solve(int n) {
  s = 1, l = 0;
  while (s < n) s <<= 1, ++l;
  for (int i = 0; i < s; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l - 1);
}
void FFT(virt *a, int t) {
  for (int i = 0; i < s; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int mid = 1, o = 1; mid < s; mid <<= 1, ++o)
    for (int j = 0; j < s; j += mid << 1) {
      virt g(1.0, 0.0);
      for (int k = 0; k < mid; ++k, g = g * G[t][o]) {
        virt x = a[j + k], y = g * a[j + k + mid];
        a[j + k] = x + y, a[j + k + mid] = x - y;
      }
    }
}
int n, m, t, x, xx;
int mc[55][55];
double dp[55][20005 << 1], g[105][20005 << 1];
struct edge {
  int x, y, cost;
  double t[20005 << 1];
  double &operator[](int x) { return t[x]; }
} e[105];
template <typename orz>
void ckmin(orz &x, orz y) {
  x = (x < y) ? x : y;
}
void cdq(int l, int r) {
  if (l == r) {
    for (int i = 1; i <= m; ++i)
      if (e[i].x != n) ckmin(dp[e[i].x][l], e[i].cost + g[i][l]);
    return;
  }
  int mid = (l + r) >> 1;
  if (r < t) cdq(mid + 1, r);
  int Len1 = r - l, Len2 = r - mid;
  for (int i = 1; i <= m; ++i)
    if (e[i].x != n) {
      int u = e[i].x, v = e[i].y;
      for (int j = 0; j < Len1; ++j) a[j] = virt(e[i][j + 1], 0.0);
      for (int j = 0; j < Len2; ++j) b[j] = virt(dp[v][r - j], 0.0);
      solve(Len1 + Len2);
      FFT(a, 0), FFT(b, 0);
      for (int j = 0; j < s; ++j) a[j] = a[j] * b[j];
      FFT(a, 1);
      for (int j = l; j <= mid; ++j) g[i][j] += a[r - j - 1].x / s;
      for (int j = 0; j < s; ++j) a[j] = b[j] = virt();
    }
  cdq(l, mid);
}
int main() {
  Pre();
  scanf("%d%d%d%d", &n, &m, &t, &x);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      if (i == j)
        mc[i][j] = 0;
      else
        mc[i][j] = INF;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].cost);
    ckmin(mc[e[i].x][e[i].y], e[i].cost);
    for (int j = 1; j <= t; ++j)
      scanf("%d", &xx), e[i][j] = (double)xx / 100000;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) ckmin(mc[i][j], mc[i][k] + mc[k][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < (t << 1); ++j) dp[i][j] = 191919191919191919.1919191919;
  for (int i = 0; i < (t << 1); ++i) dp[n][i] = (i <= t) ? 0 : x;
  for (int i = 1; i < n; ++i)
    for (int j = t; j < (t << 1); ++j) dp[i][j] = mc[i][n] + x;
  cdq(0, (t << 1) - 1);
  printf("%.12lf\n", dp[1][0]);
  return 0;
}
