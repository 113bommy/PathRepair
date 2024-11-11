#include <bits/stdc++.h>
using namespace std;
const int P = 490019;
const int pa = 491, pb = 499;
const int ra = 2, rb = 7;
const int N = 1e5 + 10, M = 1050;
const double PI = acos(-1);
int n, m, c;
int rev[M];
complex<double> w[2][10][M];
void DFT(complex<double> *a, int f) {
  for (int i = 0; i <= n - 1; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int i = 1, p = 0; i < n; i <<= 1, ++p) {
    complex<double> *coe = w[f][p];
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; ++k) {
        complex<double> x = a[j + k], y = a[i + j + k] * coe[k];
        a[j + k] = x + y, a[i + j + k] = x - y;
      }
  }
}
int C[P];
int suma[P], sumb[P];
int Loga[pa], Logb[pb];
complex<double> A[2][M][M], B[2][M][M], a[M], b[M];
int f[2][M][M];
int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i <= n - 1; i++) {
    int x;
    scanf("%d", &x);
    suma[1ll * i * i % (P - 1)] += x;
  }
  for (int i = 0; i <= m - 1; i++) {
    int x;
    scanf("%d", &x);
    sumb[1ll * i * i * i % (P - 1)] += x;
  }
  vector<int> pos;
  for (int i = 0; i <= P - 2; i++)
    if (i % pa == 0 || i % pb == 0) pos.push_back(i);
  for (int i = 0; i <= P - 2; i++)
    if (sumb[i])
      for (int j : pos)
        if (suma[j]) {
          int x = 1ll * i * j % (P - 1);
          C[x] = (C[x] + 1ll * sumb[i] * suma[j]) % P;
        }
  for (int i = 0; i <= P - 2; i++)
    if (suma[i] && i % pa && i % pb)
      for (int j : pos)
        if (sumb[j]) {
          int x = 1ll * i * j % (P - 1);
          C[x] = (C[x] + 1ll * suma[i] * sumb[j]) % P;
        }
  int cur = 1;
  for (int i = 0; i <= pa - 2; i++) Loga[cur] = i, cur = cur * ra % pa;
  cur = 1;
  for (int i = 0; i <= pb - 2; i++) Logb[cur] = i, cur = cur * rb % pb;
  for (int i = 0; i <= P - 1; i++)
    if (i % pa && i % pb) {
      int x = i % 2, y = Loga[i % pa], z = Logb[i % pb];
      A[x][y][z] = suma[i] % P, B[x][y][z] = sumb[i] % P, f[x][y][z] = i;
    }
  for (int y = 0; y <= pa - 1; y++)
    for (int z = 0; z <= pb - 1; z++)
      A[0][y][z] += A[1][y][z], B[0][y][z] += B[1][y][z];
  n = 1024;
  for (int i = 0; i <= n - 1; i++)
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
  for (int x = 0; x <= 1; x++)
    for (int i = 0; i <= 9; i++) {
      double ang = PI / (1 << i);
      if (x) ang = -ang;
      w[x][i][0] = complex<double>(1, 0),
      w[x][i][1] = complex<double>(cos(ang), sin(ang));
      for (int j = 2; j <= (1 << i) - 1; j++)
        w[x][i][j] = w[x][i][j - 1] * w[x][i][1];
    }
  for (int x = 0; x <= 1; x++)
    for (int y = 0; y <= pa - 1; y++) DFT(A[x][y], 0);
  for (int x = 0; x <= 1; x++)
    for (int y = 0; y <= pb - 1; y++) DFT(B[x][y], 0);
  for (int x = 0; x <= 1; x++)
    for (int z = 0; z <= n - 1; z++) {
      for (int y = 0; y <= n - 1; y++) a[y] = A[x][y][z], b[y] = B[x][y][z];
      DFT(a, 0), DFT(b, 0);
      for (int y = 0; y <= n - 1; y++) a[y] = a[y] * b[y];
      DFT(a, 1);
      for (int y = 0; y <= n - 1; y++) A[x][y][z] = a[y] / double(n);
    }
  for (int x = 0; x <= 1; x++)
    for (int y = 0; y <= n - 1; y++) {
      DFT(A[x][y], 1);
      for (int z = 0; z <= n - 1; z++) A[x][y][z] /= double(n);
    }
  for (int y = 0; y <= n - 1; y++)
    for (int z = 0; z <= n - 1; z++) A[0][y][z] -= A[1][y][z];
  for (int x = 0; x <= 1; x++)
    for (int y = 0; y <= n - 1; y++)
      for (int z = 0; z <= n - 1; z++) {
        int &val = C[f[x][y % (pa - 1)][z % (pb - 1)]];
        val = (val + (long long)(A[x][y][z].real() + 0.5)) % P;
      }
  cur = 1;
  int ans = 0;
  for (int i = 0; i <= P - 1; i++)
    ans = (ans + 1ll * cur * C[i]) % P, cur = 1ll * cur * c % P;
  printf("%d\n", ans);
  return 0;
}
