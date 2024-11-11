#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int MAXN = (1 << 16) + 5;
const int maxn = 1 << 16;
const double pi = acos(-1);
int Maxn, Maxa, mo;
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
long long dec(long long x, long long y) { return x < y ? x - y + mo : x - y; }
long long quickmi(long long x, long long tim) {
  long long ret = 1;
  for (; tim; tim /= 2, x = x * x % mo)
    if (tim & 1) ret = ret * x % mo;
  return ret;
}
struct comp {
  double x, y;
  comp(const double x_ = 0, const double y_ = 0) {
    x = x_;
    y = y_;
  }
} A[MAXN], B[MAXN], mi[MAXN];
comp operator*(comp a, comp b) {
  return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
comp operator+(comp a, comp b) { return comp(a.x + b.x, a.y + b.y); }
comp operator-(comp a, comp b) { return comp(a.x - b.x, a.y - b.y); }
comp conj(comp a) { return comp(a.x, -a.y); }
int N;
void prepare() {
  for (int i = 0; i <= maxn; i++)
    mi[i] = comp(cos(pi * 2 / maxn * i), sin(pi * 2 / maxn * i));
}
void DFT(comp *a) {
  for (int i = 0, j = 0; i < N; i++) {
    if (i < j) swap(a[i], a[j]);
    int x = N >> 1;
    for (; (j ^ x) < j; x >>= 1) j ^= x;
    j ^= x;
  }
  for (int i = 1, d = 1; i < N; i <<= 1, d++)
    for (int j = 0; j < N; j += (i << 1))
      for (int k = 0; k < i; k++) {
        comp l = a[j + k], r = a[i + j + k] * mi[(maxn >> d) * k];
        a[i + j + k] = l - r;
        a[j + k] = l + r;
      }
}
void IDFT(comp *a) {
  DFT(a);
  reverse(a + 1, a + N);
  for (int i = 0; i <= N - 1; i++) a[i] = comp(a[i].x / N, a[i].y / N);
}
long long f0[MAXN], f1[MAXN], g0[MAXN], g1[MAXN];
int main() {
  prepare();
  Maxn = get();
  Maxa = get();
  mo = get();
  int w = 1;
  for (; w * 2 <= Maxa; w <<= 1)
    ;
  f0[0] = 1;
  f1[1] = 1;
  N = 1;
  while (N <= Maxn * 2) N <<= 1;
  long long ans = (Maxa > 1);
  for (w >>= 1; w; w >>= 1) {
    for (int i = 0; i <= Maxn; i++) g0[i] = f0[i], g1[i] = f1[i];
    for (int i = 0; i <= N - 1; i++) A[i] = B[i] = comp(0, 0);
    for (int i = 0; i <= Maxn; i++) A[i] = comp((f0[i] + f1[i]) % mo, 0);
    for (int i = 1; i <= Maxn; i++) B[i] = comp(f0[i], 0);
    DFT(A), DFT(B);
    for (int i = 0; i <= N - 1; i++) B[i] = A[i] * B[i];
    IDFT(B);
    int p = ((Maxa & (w << 1)) > 0);
    if (p)
      for (int i = 0; i <= Maxn; i++) {
        long long tmp = B[i].x + 0.3;
        tmp = tmp % mo;
        g1[i] = add(g1[i], tmp);
      }
    else
      for (int i = 0; i <= Maxn; i++) {
        long long tmp = B[i].x + 0.3;
        tmp = tmp % mo;
        g0[i] = add(g0[i], tmp);
      }
    for (int i = 0; i <= N - 1; i++) B[i] = 0;
    for (int i = 1; i <= Maxn; i++) B[i] = comp(f1[i], 0);
    DFT(B);
    for (int i = 0; i <= N - 1; i++) B[i] = A[i] * B[i];
    IDFT(B);
    p ^= 1;
    if (p)
      for (int i = 0; i <= Maxn; i++) {
        long long tmp = B[i].x + 0.3;
        tmp = tmp % mo;
        g1[i] = add(g1[i], tmp);
      }
    else
      for (int i = 0; i <= Maxn; i++) {
        long long tmp = B[i].x + 0.3;
        tmp = tmp % mo;
        g0[i] = add(g0[i], tmp);
      }
    for (int i = 0; i <= Maxn; i++) f0[i] = g0[i], f1[i] = g1[i];
    if ((Maxa & w) > 0) {
      for (int i = Maxn - 1; i >= 0; i--)
        f1[i + 1] = add(f1[i + 1], add(f0[i], f1[i]));
    }
    if (w != 1)
      for (int i = 0; i <= Maxn; i++)
        if (i & 1) ans = add(ans, f1[i]);
  }
  cout << ans << endl;
  return 0;
}
