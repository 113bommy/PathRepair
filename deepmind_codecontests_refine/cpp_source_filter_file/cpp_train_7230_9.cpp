#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 62;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pos[600100];
namespace FFT {
struct comp {
  double r, i;
  comp(double _r = 0, double _i = 0) : r(_r), i(_i) {}
  comp operator+(const comp &x) { return comp(r + x.r, i + x.i); }
  comp operator-(const comp &x) { return comp(r - x.r, i - x.i); }
  comp operator*(const comp &x) {
    return comp(r * x.r - i * x.i, i * x.r + r * x.i);
  }
  comp conj() { return comp(r, -i); }
} A[600100], B[600100];
const double pi = acos(-1.0);
void FFT(comp a[], int n, int t) {
  for (int i = 1; i < n; ++i)
    if (pos[i] > i) swap(a[i], a[pos[i]]);
  for (int d = 0; (1 << d) < n; ++d) {
    int m = 1 << d, m2 = m << 1;
    double o = pi * 2 / m2 * t;
    comp _w(cos(o), sin(o));
    for (int i = 0; i < n; i += m2) {
      comp w(1, 0);
      for (int j = 0; j < m; ++j) {
        comp &A = a[i + j + m], &B = a[i + j], t = w * A;
        A = B - t;
        B = B + t;
        w = w * _w;
      }
    }
  }
  if (t == -1)
    for (int i = 0; i < n; ++i) a[i].r /= n;
}
void mul(int *a, int *b, int *c, int k) {
  int i, j;
  for (i = 0; i < k; ++i) A[i] = comp(a[i], b[i]);
  j = __builtin_ctz(k) - 1;
  for (int i = 0; i < k; ++i) {
    pos[i] = pos[i >> 1] >> 1 | ((i & 1) << j);
  }
  FFT(A, k, 1);
  for (int i = 0; i < k; ++i) {
    j = (k - i) & (k - 1);
    B[i] = (A[i] * A[i] - (A[j] * A[j]).conj()) * comp(0, -0.25);
  }
  FFT(B, k, -1);
  for (int i = 0; i < k; ++i) {
    if (B[i].r >= 0)
      c[i] = (int)(B[i].r + 0.5);
    else
      c[i] = (int)(B[i].r - 0.5);
  }
}
}  // namespace FFT
int belong[201000];
int r[450], l[450];
short x[450][201000];
char a[201000], b[201000];
int x1[201000 << 1], x2[201000 << 1], x3[201000 << 1];
int main() {
  scanf("%s %s", a, b);
  int m = read();
  int tot = 0, n = strlen(a), nn = strlen(b);
  int blo = pow(n, 2.0 / 3);
  for (int i = 0; i < n; i++) {
    int rr = i;
    ++tot;
    l[tot] = i;
    while (rr < n && rr - i <= blo) {
      belong[rr] = tot;
      rr++;
    }
    r[tot] = rr - 1;
    i = rr - 1;
  }
  for (int i = 1; i <= tot; i++) {
    int ii = r[i] - l[i] + 1;
    int len = 1;
    while (len <= nn) len *= 2;
    for (int j = 0; j < len; j++) {
      if (l[i] + j <= r[i]) {
        if (a[l[i] + j] == '1')
          x1[j] = 1;
        else
          x1[j] = -1;
      } else
        x1[j] = 0;
      if (j < nn) {
        if (b[j] == '1')
          x2[j] = 1;
        else
          x2[j] = -1;
      } else
        x2[j] = 0;
    }
    FFT::mul(x1, x2, x3, len);
    for (int j = ii - 1; j < nn; j++) {
      x[i][j] = (ii - x3[j]) / 2;
    }
  }
  for (int i = 0; i < m; i++) {
    int s1 = read(), s2 = read(), len = read();
    int ans = 0;
    int ll = belong[s1];
    int rr = belong[s1 + len - 1];
    if (ll + 1 >= rr) {
      for (int j = s1; j < s1 + len; j++)
        if (a[j] != b[j - s1 + s2]) ans++;
    } else {
      for (int j = s1; j <= r[ll]; j++)
        if (a[j] != b[j - s1 + s2]) ans++;
      for (int j = ll + 1; j < rr; j++) {
        ans += x[j][nn - (l[j] - s1 + s2) - 1];
      }
      for (int j = l[rr]; j < s1 + len; j++)
        if (a[j] != b[j - s1 + s2]) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
