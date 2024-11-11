#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const double eps = 1e-12;
int n, a[N], b[N], rk[N], q[N], h, t;
double p[N], f[N], mx;
long long T;
bool cmp(int u, int v) {
  return fabs(p[u] - p[v]) > eps ? (p[u] < p[v])
                                 : ((p[u] * a[u]) < (p[v] * a[v]));
}
long double slope(int u, int v) {
  return ((p[u] * a[u]) - (p[v] * a[v])) / (p[u] - p[v]);
}
struct matrix {
  double arr[3][3];
  matrix() { memset(arr, 0, sizeof(arr)); }
  double* operator[](int x) { return arr[x]; }
  void build(int x) {
    memset(arr, 0, sizeof(arr));
    arr[0][0] = -p[x] + 1, arr[1][0] = mx * p[x], arr[2][0] = (p[x] * a[x]);
    arr[1][1] = arr[2][1] = arr[2][2] = 1;
  }
} F, tmp, bit[40];
matrix operator*(matrix A, matrix B) {
  matrix ret;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      ret[i][j] = 0;
      for (int k = 0; k < 3; ++k) ret[i][j] += A[i][k] * B[k][j];
    }
  return ret;
}
int main() {
  scanf("%d%lld", &n, &T);
  for (int i = 1; i <= n; ++i) scanf("%d%d%lf", &a[i], &b[i], &p[i]), rk[i] = i;
  for (int i = 1; i <= n; ++i) mx = max(mx, b[i] * p[i]);
  sort(rk + 1, rk + n + 1, cmp);
  h = 1, t = 0;
  for (int i = 1; i <= n; ++i) {
    int id = rk[i];
    if (i < n && fabs(p[id] - p[rk[i + 1]]) < eps) continue;
    while (h < t && slope(q[t - 1], q[t]) <= slope(q[t], id)) --t;
    q[++t] = id;
  }
  long long cur = 0;
  F[0][2] = 1;
  while (233) {
    while (h < t && F[0][0] - mx * cur >= slope(q[h], q[h + 1])) ++h;
    double K;
    if (h != t) K = slope(q[h], q[h + 1]);
    bit[0].build(q[h]);
    for (int i = 1; i <= 35; ++i) bit[i] = bit[i - 1] * bit[i - 1];
    for (int i = 35; i >= 0; --i) {
      if (cur + (1ll << i) >= T) continue;
      tmp = F * bit[i];
      if (h == t || tmp[0][0] - mx * (cur + (1ll << i)) > K)
        F = F * bit[i], cur += (1ll << i);
    }
    ++cur, F = F * bit[0];
    if (cur == T) break;
  }
  printf("%.12lf", F[0][0]);
  return 0;
}
