#include <bits/stdc++.h>
using namespace std;
namespace RA {
int r(int p) { return 1ll * rand() * rand() % p; }
int r(int L, int R) { return r(R - L + 1) + L; }
}  // namespace RA
namespace IO {
char nc() {
  static char bf[100000], *p1 = bf, *p2 = bf;
  return p1 == p2 && (p2 = (p1 = bf) + fread(bf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int rd() {
  int res = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}
}  // namespace IO
const int N = 1e5 + 5, M = 1e5 + 5;
int n, m, p;
long long d[N], a[N], A[N];
long long f[M], g[M];
int q[N], ql, qr;
inline long long X(int k) { return k; }
inline long long K(int i) { return a[i]; }
inline long long Y(int k) { return g[k] + A[k]; }
inline double slope(int p1, int p2) {
  return (Y(p1) - Y(p2)) * 1.0 / (X(p1) - X(p2));
}
int main() {
  cin >> n >> m >> p;
  for (int i = (2); i <= (n); ++i) cin >> d[i], d[i] += d[i - 1];
  for (int i = (1); i <= (m); ++i) {
    int h, t;
    cin >> h >> t;
    a[i] = t - d[h];
  }
  sort(a + 1, a + m + 1);
  for (int i = (1); i <= (m); ++i) A[i] = A[i - 1] + a[i];
  for (int i = (1); i <= (m); ++i) {
    g[i] = a[i] * i - A[i];
  }
  g[0] = 0;
  for (int j = (2); j <= (p); ++j) {
    ql = 1, qr = 0;
    q[++qr] = 0;
    for (int i = (1); i <= (m); ++i) {
      while (ql < qr && slope(q[ql], q[ql + 1]) < K(i)) ++ql;
      const int k = q[ql];
      f[i] = -K(i) * X(k) + Y(k);
      f[i] += a[i] * i - A[i];
      while (ql < qr && slope(q[qr - 1], q[qr]) > slope(q[qr], i)) --qr;
      q[++qr] = i;
    }
    swap(f, g);
  }
  cout << g[m];
  return 0;
}
