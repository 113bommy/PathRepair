#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-7;
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
const int _M = 1024;
template <class V>
struct FT {
  struct cp {
    double x, y;
  } tmp[_M * 2 + 5];
  cp aa[_M][_M], bb[_M][_M];
  friend cp operator+(cp &a, cp &b) { return cp{a.x + b.x, a.y + b.y}; }
  friend cp operator-(cp &a, cp &b) { return cp{a.x - b.x, a.y - b.y}; }
  friend cp operator*(cp &a, cp &b) {
    return cp{a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
  }
  cp get(double x) { return cp{cos(x), sin(x)}; }
  void FFT(cp *a, int n, int op) {
    for (int i = (n >> 1), j = 1; j < n; j++) {
      if (i < j) swap(a[i], a[j]);
      int k;
      for (k = (n >> 1); k & i; i ^= k, k >>= 1)
        ;
      i ^= k;
    }
    for (int m = 2; m <= n; m <<= 1) {
      cp w = get(2 * PI * op / m);
      tmp[0] = cp{1, 0};
      for (int j = 1; j < (m >> 1); j++) tmp[j] = tmp[j - 1] * w;
      for (int i = 0; i < n; i += m)
        for (int j = i; j < i + (m >> 1); j++) {
          cp u = a[j], v = a[j + (m >> 1)] * tmp[j - i];
          a[j] = u + v, a[j + (m >> 1)] = u - v;
        }
    }
    if (op == -1)
      for (int i = (0); i < (n); i++) a[i] = cp{a[i].x / n, a[i].y / n};
  }
  void FFT(cp a[][_M], int n, int op) {
    for (int i = (0); i < (n); i++) FFT(a[i], n, op);
  }
  template <class T>
  void Transpose(T a[][_M], int n) {
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (i); j++) swap(a[i][j], a[j][i]);
  }
  void Reverse(V a[][_M], int n, int m) {
    for (int i = (0); i < ((n - 1 >> 1) + 1); i++)
      for (int j = (0); j < (m); j++) swap(a[i][j], a[n - 1 - i][j]);
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < ((m - 1 >> 1) + 1); j++)
        swap(a[i][j], a[i][m - 1 - j]);
  }
  void Shift(V a[][_M], int n, int m, int p, int q) {
    for (int i = (n); i < (n + p); i++)
      for (int j = (m); j < (m + q); j++) a[i - n][j - m] = a[i][j];
  }
  void In(cp p[][_M], int len, V a[][_M], int n, int m) {
    for (int i = (0); i < (len); i++)
      for (int j = (0); j < (len); j++)
        p[i][j] = cp{i < n && j < m ? (double)a[i][j] : 0, 0};
  }
  void Out(V a[][_M], int n, int m, cp p[][_M], int len) {
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) a[i][j] = (V)(p[i][j].x + eps) % 490019;
  }
  void Multiply(V A[][_M], int n, V B[][_M], int m, V C[][_M], int &len,
                int op = 0) {
    if (op) Reverse(A, n, n);
    len = 1;
    while (len < n + m - 1) len <<= 1;
    In(aa, len, A, n, n), In(bb, len, B, m, m), FFT(aa, len, 1),
        FFT(bb, len, 1);
    Transpose(aa, len), Transpose(bb, len), FFT(aa, len, 1), FFT(bb, len, 1);
    for (int i = (0); i < (len); i++)
      for (int j = (0); j < (len); j++) aa[i][j] = aa[i][j] * bb[i][j];
    FFT(aa, len, -1), Transpose(aa, len), FFT(aa, len, -1),
        Out(C, len, len, aa, len);
    if (op) Shift(C, n - 1, n - 1, m, m), len = m, Reverse(A, n, n);
  }
};
const int N = 5e5 + 5, M = 1024, P = 490019, _P = P - 1, pa = 491,
          push_back = 499, _pa = pa - 1, _pb = push_back - 1;
int n, m, c, Loga[505], Logb[505], x, len;
vector<int> pos;
FT<long long> T;
long long sa[N], sb[N], A[2][M][M], B[2][M][M], C[2][M][M], o[2][M][M], ret[N],
    ans = 0, t;
int main() {
  scanf("%d%d%d", &n, &m, &c);
  for (int i = (0); i < (n); i++)
    scanf("%d", &x), (sa[(long long)i * i % (P - 1)] += x) %= P;
  for (int i = (0); i < (m); i++)
    scanf("%d", &x), (sb[(long long)i * i % (P - 1) * i % (P - 1)] += x) %= P;
  for (int i = (0); i < (_P); i++)
    if (i % pa == 0 || i % push_back == 0) pos.push_back(i);
  for (auto i : pos)
    if (sa[i])
      for (int j = (0); j < (_P); j++)
        if (sb[j]) (ret[(long long)i * j % _P] += sa[i] * sb[j] % P) %= P;
  for (int i = (0); i < (_P); i++)
    if (sa[i] && i % pa && i % push_back)
      for (auto j : pos)
        if (sb[j]) (ret[(long long)i * j % _P] += sa[i] * sb[j] % P) %= P;
  for (int i = 0, t = 1; i < _pa; ++i, t = t * 7 % pa) Loga[t] = i;
  for (int i = 0, t = 1; i < _pb; ++i, t = t * 7 % push_back) Logb[t] = i;
  for (int i = (0); i < (_P); i++) {
    if (i % pa == 0 || i % push_back == 0) continue;
    int x = (i & 1), y = Loga[i % pa], z = Logb[i % push_back];
    A[x][y][z] = sa[i], B[x][y][z] = sb[i], o[x][y][z] = i;
  }
  for (int y = (0); y < (_pa); y++)
    for (int z = (0); z < (_pb); z++)
      (A[0][y][z] += A[1][y][z]) %= P, (B[0][y][z] += B[1][y][z]) %= P;
  for (int i = (0); i < (2); i++) T.Multiply(A[i], 500, B[i], 500, C[i], len);
  for (int y = (0); y < (M); y++)
    for (int z = (0); z < (M); z++) (C[0][y][z] -= C[1][y][z]) %= P;
  for (int x = (0); x < (2); x++)
    for (int y = (0); y < (M); y++)
      for (int z = (0); z < (M); z++)
        (ret[o[x][y % _pa][z % _pb]] += C[x][y][z]) %= P;
  for (long long t = 1, i = 0; i < _P; t = t * c % P, ++i)
    (ans += t * ret[i] % P) %= P;
  printf("%lld\n", (ans + P) % P);
  return 0;
}
