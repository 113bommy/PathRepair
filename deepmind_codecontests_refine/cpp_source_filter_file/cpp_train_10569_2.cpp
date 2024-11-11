#include <bits/stdc++.h>
using namespace std;
const int oo = 2139063143;
const int N = 1010000;
const int P = 1000000007;
const double eps = 1e-7;
template <typename T>
inline void sc(T &x) {
  x = 0;
  static int p;
  p = 1;
  static char c;
  c = getchar();
  while (!isdigit(c)) {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c - 48);
    c = getchar();
  }
  x *= p;
}
template <typename T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void pr(T x) {
  print(x), putchar('\n');
}
template <typename T1, typename T2>
void chkmax(T1 &A, T2 B) {
  A = A >= B ? A : B;
}
template <typename T1, typename T2>
void chkmin(T1 &A, T2 B) {
  A = A <= B ? A : B;
}
int n;
long long T = 0;
struct LY {
  int p, t, pt;
  long long l, r;
  double f;
} a[N];
bool check(double c) {
  double ma = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    if (a[i].p * (1 - c * a[i].r / T) < ma) return 0;
    if (i == n || a[i].p != a[i + 1].p)
      while (j <= i) chkmax(ma, a[j].p * (1 - c * a[j].l / T)), ++j;
  }
  return 1;
}
double b[N];
long long c[N];
int main() {
  sc(n);
  for (int i = 1; i <= n; i++) sc(a[i].p);
  for (int i = 1; i <= n; i++)
    sc(a[i].t), a[i].f = (double)a[i].p / a[i].t, T += a[i].t;
  sort(a + 1, a + n + 1, [](LY A, LY B) { return A.f > B.f; });
  int m = 0;
  for (int i = 1; i <= n; i++)
    a[i].pt = (i == 1 || abs(a[i].f - a[i - 1].f) > eps) ? (++m) : m;
  for (int i = 1; i <= n; i++) c[a[i].pt] += a[i].t;
  for (int i = 1; i <= m; i++) c[i] += c[i - 1];
  for (int i = 1; i <= n; i++)
    a[i].l = c[a[i].pt - 1] + a[i].t, a[i].r = c[a[i].pt];
  sort(a + 1, a + n + 1, [](LY A, LY B) { return A.p < B.p; });
  double L = 0, R = 1.01, mid = 0;
  while (L + eps < R) (check(mid = (L + R) / 2) ? L : R) = mid;
  printf("%.9lf\n", L);
  return 0;
}
