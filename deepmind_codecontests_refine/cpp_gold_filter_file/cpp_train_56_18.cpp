#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 998244353;
const int N = 50005;
const double PI = acos(-1.0);
const double eps = 1e-8;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
struct cp {
  double x, y;
};
inline cp operator+(cp &a, cp &b) { return cp{a.x + b.x, a.y + b.y}; }
inline cp operator-(cp &a, cp &b) { return cp{a.x - b.x, a.y - b.y}; }
inline cp operator*(cp &a, cp &b) {
  return cp{a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
inline cp get(double x) { return cp{cos(x), sin(x)}; }
inline ostream &operator<<(ostream &out, const cp &t) {
  out << "(" << t.x << "," << t.y << ")";
  return out;
}
const int _M = 2048, _N = N;
template <class V>
struct FT {
  cp tmp[_M * 2 + 5], aa[_M][_M], bb[_M][_M];
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
      for (int i = (0); i <= (n - 1); ++i) a[i] = cp{a[i].x / n, a[i].y / n};
  }
  void FFT(cp a[][_M], int n, int op) {
    for (int i = (0); i <= (n - 1); ++i) FFT(a[i], n, op);
  }
  template <class T>
  void Transpose(T a[][_M], int n) {
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (i - 1); ++j) swap(a[i][j], a[j][i]);
  }
  void Reverse(V a[][_M], int n, int m) {
    for (int i = (0); i <= (n - 1 >> 1); ++i)
      for (int j = (0); j <= (m - 1); ++j) swap(a[i][j], a[n - 1 - i][j]);
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 1 >> 1); ++j) swap(a[i][j], a[i][m - 1 - j]);
  }
  void Shift(int a[][_M], int n, int m, int p, int q) {
    for (int i = (n); i <= (n + p - 1); ++i)
      for (int j = (m); j <= (m + q - 1); ++j) a[i - n][j - m] = a[i][j];
  }
  void In(cp p[][_M], int len, V a[][_M], int n, int m) {
    for (int i = (0); i <= (len - 1); ++i)
      for (int j = (0); j <= (len - 1); ++j)
        p[i][j] = i < n && j < m ? a[i][j] : cp{0, 0};
  }
  void Out(int a[][_M], int n, int m, cp p[][_M], int len) {
    for (int i = (0); i <= (n - 1); ++i)
      for (int j = (0); j <= (m - 1); ++j) a[i][j] = (int)(p[i][j].x + eps);
  }
  void Multiply(V A[][_M], int n, V B[][_M], int m, int C[][_M], int &len,
                int op = 0) {
    if (op) Reverse(A, n, n);
    len = 1;
    while (len < n + m - 1) len <<= 1;
    In(aa, len, A, n, n), In(bb, len, B, m, m), FFT(aa, len, 1),
        FFT(bb, len, 1);
    Transpose(aa, len), Transpose(bb, len), FFT(aa, len, 1), FFT(bb, len, 1);
    for (int i = (0); i <= (len - 1); ++i)
      for (int j = (0); j <= (len - 1); ++j) aa[i][j] = aa[i][j] * bb[i][j];
    FFT(aa, len, -1), Transpose(aa, len), FFT(aa, len, -1),
        Out(C, len, len, aa, len);
    if (op) Shift(C, n - 1, n - 1, m, m), len = m, Reverse(A, n, n);
  }
};
void Build(cp A[][_M], int n, int m, char s[][405], int M, int op,
           int cc = 'a') {
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j)
      A[i][j] =
          (s[i][j] == '?') ? cp{0, 0} : get(2 * PI / M * (s[i][j] - cc) * op);
}
int n1, n2, m1, m2, nn, mm, len, tot = 0;
char s[405][405], t[405][405];
FT<cp> T;
cp A[_M][_M], B[_M][_M];
int C[_M][_M];
int main() {
  scanf("%d%d", &n1, &m1);
  for (int i = (0); i <= (n1 - 1); ++i) scanf("%s", s[i]);
  scanf("%d%d", &n2, &m2), nn = n1 + n2, mm = m1 + m2;
  for (int i = (0); i <= (n2 - 1); ++i) scanf("%s", t[i]);
  for (int i = (0); i <= (n2 - 1); ++i)
    for (int j = (0); j <= (m2 - 1); ++j) tot += (t[i][j] != '?');
  Build(A, n1, m1, s, 26, 1), Build(B, n2, m2, t, 26, -1);
  for (int i = (0); i <= (nn - 1); ++i)
    for (int j = (0); j <= (mm - 1); ++j) {
      if (i < n1 && j < m1) continue;
      A[i][j] = A[i % n1][j % m1];
    }
  T.Multiply(B, ((n2) > (m2) ? (n2) : (m2)), A, ((nn) > (mm) ? (nn) : (mm)), C,
             len, 1);
  for (int i = (0); i <= (n1 - 1); ++i) {
    for (int j = (0); j <= (m1 - 1); ++j) printf("%c", "01"[C[i][j] >= tot]);
    printf("\n");
  }
  return 0;
}
