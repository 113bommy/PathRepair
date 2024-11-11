#include <bits/stdc++.h>
using namespace std;
const int Maxn = (1 << 16) + 10, Maxm = 110, Maxt = 20010, Maxp = 60;
const double PI = acos(-1.0);
const double INF = 1e199;
int n, m, t, x, rev[Maxn], from[Maxm], to[Maxm], cost[Maxm];
double p[Maxm][Maxt], res[Maxm][Maxt], dp[Maxp][Maxt], dis[Maxp][Maxp],
    sum[Maxt];
int Get() {
  char ch;
  int v = 0;
  bool f = false;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = true;
  v = ch - 48;
  while (isdigit(ch = getchar())) v = v * 10 + ch - 48;
  if (f)
    return -v;
  else
    return v;
}
struct Complex {
  double a, b;
  Complex() {}
  Complex(double _a, double _b) { a = _a, b = _b; }
} A[Maxn], B[Maxn];
Complex operator+(const Complex &x, const Complex &y) {
  return Complex(x.a + y.a, x.b + y.b);
}
Complex operator-(const Complex &x, const Complex &y) {
  return Complex(x.a - y.a, x.b - y.b);
}
Complex operator*(const Complex &x, const Complex &y) {
  return Complex(x.a * y.a - x.b * y.b, x.a * y.b + x.b * y.a);
}
Complex operator/(const Complex &x, const double &y) {
  return Complex(x.a / y, x.b / y);
}
void DFT(Complex *a, int n, int f) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k <= n - 1; k <<= 1) {
    Complex cur = Complex(cos(PI / k), f * sin(PI / k)), x, y, u;
    for (int i = 0; i <= n - 1; i += k << 1) {
      u = Complex(1, 0);
      for (int j = 0; j <= k - 1; j++, u = u * cur) {
        x = a[i + j], y = a[i + j + k] * u;
        a[i + j] = x + y, a[i + j + k] = x - y;
      }
    }
  }
  if (f == -1)
    for (int i = 0; i <= n - 1; i++) a[i] = a[i] / double(n);
}
void gmin(double &a, double b) {
  if (b < a) a = b;
}
void FFT(int n1, int n2, Complex *A, Complex *B) {
  int m = n1 + n2, n = 1, lim = 0;
  for (n = 1; n <= m; n <<= 1) lim++;
  for (int i = n1 + 1; i <= n; i++) A[i] = Complex(0, 0);
  for (int i = n2 + 1; i <= n; i++) B[i] = Complex(0, 0);
  rev[0] = 0;
  for (int i = 1; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << lim - 1);
  DFT(A, n, 1);
  DFT(B, n, 1);
  for (int i = 0; i < n; i++) A[i] = A[i] * B[i];
  DFT(A, n, -1);
}
void work(int id, int l, int mid, int r) {
  int x = from[id], y = to[id], tot = r - l;
  if (x == n) return;
  for (int i = mid + 1; i <= r; i++) A[i - mid - 1] = Complex(dp[y][i], 0);
  for (int i = 0; i <= tot; i++) B[i] = Complex(p[id][tot - i], 0);
  FFT(r - mid - 1, tot, A, B);
  for (int i = l; i <= mid; i++) res[id][i] += A[i + r - l - mid - 1].a;
}
void solve(int l, int r) {
  if (l == r) {
    for (int i = 1; i <= m; i++) {
      if (from[i] != n) {
        gmin(dp[from[i]][l], res[i][l] + cost[i]);
      }
    }
  } else {
    int mid = l + r >> 1;
    solve(mid + 1, r);
    for (int i = 1; i <= m; i++) work(i, l, mid, r);
    solve(l, mid);
  }
}
void Floyd() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dis[i][j] = INF;
    dis[i][i] = 0;
  }
  for (int i = 1; i <= m; i++) dis[from[i]][to[i]] = cost[i];
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) gmin(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 1; i <= n; i++) dp[i][t + 1] = dis[i][n] + x;
}
int main() {
  n = Get(), m = Get(), t = Get(), x = Get();
  for (int i = 1; i <= m; i++) {
    from[i] = Get(), to[i] = Get(), cost[i] = Get();
    int v;
    for (int j = 1; j <= t; j++) v = Get(), p[i][j] = double(v) / 100000;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t + 1; j++) dp[i][j] = INF;
  for (int i = 0; i <= t; i++) dp[n][i] = 0;
  Floyd();
  for (int i = 1; i <= m; i++) {
    int y = to[i];
    sum[t + 1] = 0;
    for (int j = t; j >= 0; j--) sum[j] = sum[j + 1] + p[i][j];
    for (int j = 0; j <= t; j++) res[i][j] = dp[y][t + 1] * sum[t + 1 - j];
  }
  solve(0, t);
  printf("%.10lf\n", dp[1][0]);
  return 0;
}
