#include <bits/stdc++.h>
const int N = 100005;
using namespace std;
inline int Getint() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const double pi = acos(-1);
struct Z {
  double r, i;
  Z(double _r = 0, double _i = 0) { r = _r, i = _i; }
  Z operator+(const Z &a) const { return Z(r + a.r, i + a.i); }
  Z operator-(const Z &a) const { return Z(r - a.r, i - a.i); }
  Z operator*(const Z &a) const {
    return Z(r * a.r - i * a.i, r * a.i + i * a.r);
  }
  Z operator/(const double &a) const { return Z(r / a, i / a); }
  Z operator/=(const double &a) { return *this = Z(r / a, i / a); }
};
void FFT(Z *a, int x, int K) {
  static int rev[N], lst;
  int n = 1 << x;
  if (n != lst) {
    for (int i = 0; i < n; i++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << x - 1);
    lst = n;
  }
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int tmp = i << 1;
    Z wn(cos(pi / i), sin(pi * K / i));
    for (int j = 0; j < n; j += tmp) {
      Z w(1, 0);
      for (int k = 0; k < i; k++, w = w * wn) {
        Z x = a[j + k], y = w * a[i + j + k];
        a[j + k] = x + y, a[i + j + k] = x - y;
      }
    }
  }
  if (K == -1)
    for (int i = 0; i < n; i++) a[i] /= n;
}
Z a[N], b[N];
int n, m, T, X;
double p[105][20005];
struct node {
  int x, y, z;
} s[105];
double mp[55][55], f[55][N], g[105][N];
void Floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
}
void Cal(int l, int mid, int r) {
  int len = r - l;
  for (int j = 1; j <= m; j++) {
    int x = ceil(log2(len + r - mid));
    fill(a, a + (1 << x), 0), fill(b, b + (1 << x), 0);
    for (int i = 0; i < r - mid + 1; i++) a[i].r = f[s[j].y][r - i];
    for (int i = 0; i < len; i++) b[i].r = p[j][i + 1];
    FFT(a, x, 1), FFT(b, x, 1);
    for (int i = 0; i < (1 << x); i++) a[i] = a[i] * b[i];
    FFT(a, x, -1);
    for (int i = mid - 1; i >= l; i--) g[j][i] += a[r - i - 1].r;
  }
}
void Binary(int l, int r) {
  if (l == r) {
    for (int i = 1; i <= m; i++)
      f[s[i].x][l] = min(f[s[i].x][l], s[i].z + g[i][l]);
    return;
  }
  int mid = l + r >> 1;
  Binary(mid + 1, r);
  Cal(l, mid + 1, r);
  Binary(l, mid);
}
int main() {
  n = Getint(), m = Getint(), T = Getint(), X = Getint();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i ^ j) mp[i][j] = 1 << 30;
  for (int i = 1; i <= m; i++) {
    int x = Getint(), y = Getint(), z = Getint();
    s[i] = (node){x, y, z};
    mp[x][y] = min(mp[x][y], 1.0 * z);
    for (int j = 1; j <= T; j++) p[i][j] = (double)Getint() / 100000;
  }
  Floyd();
  for (int j = T + 1; j <= 2 * T; j++) f[n][j] = X;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= T; j++) f[i][j] = 1 << 30;
    for (int j = T + 1; j <= 2 * T; j++) f[i][j] = X + mp[s[i].y][n];
  }
  Cal(1, T + 1, 2 * T);
  Binary(0, T);
  printf("%.6f", f[1][0]);
  return 0;
}
