#include <bits/stdc++.h>
using namespace std;
int read() {
  char x = getchar();
  int ans = 0, flag = 1;
  while (!isdigit(x))
    if (x == '-')
      flag = -1, x = getchar();
    else
      x = getchar();
  while (isdigit(x)) ans = ans * 10 + x - '0', x = getchar();
  return ans * flag;
}
int n, m, t, x, rev[1 << 16], dis[55][55];
double dp[55][1 << 16], g[105][1 << 16], p[1 << 16];
const double pi = acos(-1);
struct edge {
  int u, v, w;
  double p[1 << 16];
} Edge[105];
struct comp {
  double x, y;
  comp operator+(comp a) const { return comp{x + a.x, y + a.y}; }
  comp operator-(comp a) const { return comp{x - a.x, y - a.y}; }
  comp operator*(comp a) const {
    return comp{x * a.x - y * a.y, x * a.y + y * a.x};
  }
} A[1 << 18], B[1 << 18], omega[1 << 18], inv[1 << 18];
void init(int lim) {
  omega[0] = inv[0] = comp{1, 0};
  comp tmp = comp{cos(2 * pi / lim), sin(2 * pi / lim)};
  for (int i = 1; i < lim; i++) omega[i] = omega[i - 1] * tmp;
  for (int i = 1; i < lim; i++) inv[i] = omega[lim - i];
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
}
void fft(comp *a, comp *omega, int lim) {
  for (int i = 0; i < lim; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < lim; i <<= 1) {
    int t = lim / (i << 1);
    for (int j = 0; j < lim; j += (i << 1)) {
      for (int k = 0; k < i; k++) {
        comp tmp = omega[t * k] * a[i + j + k];
        a[j + k + i] = a[j + k] - tmp;
        a[j + k] = a[j + k] + tmp;
      }
    }
  }
}
void cdq(int l, int r) {
  if (l == t) return;
  if (l == r) {
    for (int i = 1; i <= m; i++)
      if (Edge[i].u != n)
        dp[Edge[i].u][l] = min(dp[Edge[i].u][l], g[i][l] + Edge[i].w);
    return;
  }
  int mid = (l + r) >> 1;
  cdq(mid + 1, r);
  int lim = 1;
  while (lim <= r - l - 1 + r - mid - 1) lim <<= 1;
  assert(lim <= 65536);
  init(lim);
  for (int i = 1; i <= m; i++) {
    if (Edge[i].u == n) continue;
    int v = Edge[i].v;
    for (int j = 0; j < lim; j++) A[j].x = A[j].y = B[j].x = B[j].y = 0;
    for (int j = mid + 1; j <= r; j++)
      A[j - mid - 1].x = dp[v][r - j + mid + 1];
    for (int j = l; j < r; j++) B[j - l].x = Edge[i].p[j - l + 1];
    fft(A, omega, lim);
    fft(B, omega, lim);
    for (int j = 0; j < lim; j++) A[j] = A[j] * B[j];
    fft(A, inv, lim);
    for (int j = 0; j < lim; j++) A[j].x /= lim;
    for (int j = l; j <= mid; j++) g[i][j] += A[r - j - 1].x;
  }
  cdq(l, mid);
}
signed main() {
  memset(dis, 0x3f, sizeof(dis));
  n = read(), m = read(), t = read(), x = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    dis[u][v] = min(dis[u][v], w);
    Edge[i].u = u, Edge[i].v = v, Edge[i].w = w;
    for (int j = 1; j <= t; j++) Edge[i].p[j] = (1.0 * read()) / 100000;
  }
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = t; i <= 2 * t; i++)
    for (int j = 1; j <= n; j++) dp[j][i] = dis[j][n] + x;
  dp[n][t] = 0;
  for (int i = 0; i < t; i++)
    for (int j = 1; j < n; j++) dp[j][i] = 1e18;
  cdq(0, 2 * t - 1);
  printf("%.12f\n", dp[1][0]);
  return 0;
}
