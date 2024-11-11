#include <bits/stdc++.h>
using namespace std;
const int FFTN = 1 << 19;
const int N = FFTN + 5;
int n, m, mo;
struct E {
  long double r, i;
  E() {}
  E(long double _r, long double _i) {
    r = _r;
    i = _i;
  }
  E operator+(const E &a) const { return E(r + a.r, i + a.i); }
  E operator-(const E &a) const { return E(r - a.r, i - a.i); }
  E operator*(const E &a) const {
    return E(r * a.r - i * a.i, r * a.i + i * a.r);
  }
  E conj() { return E(r, -i); }
};
E W[N], w[N];
void FFTinit() {
  long double pi = 2 * acos(-1), ang = pi / FFTN;
  for (int i = (int)(0); i <= (int)(FFTN); i++)
    W[i] = E(cos(i * ang), sin(i * ang));
}
int R[N];
int FFTinit(int n) {
  int L = 1;
  for (; L <= n; L <<= 1)
    ;
  for (int i = (int)(0); i <= (int)(L - 1); i++)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0);
  return L;
}
void DFT(E *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = 0; i < d; i++, j += len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        E y = a[i + j + d] * w[j];
        a[i + j + d] = a[i + j] - y;
        a[i + j] = a[i + j] + y;
      }
  }
}
void IDFT(E *a, int n) {
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int d = 1; d < n; d <<= 1) {
    int len = FFTN / (d << 1);
    for (int i = 0, j = FFTN; i < d; i++, j -= len) w[i] = W[j];
    for (int i = 0; i < n; i += (d << 1))
      for (int j = 0; j < d; j++) {
        E y = a[i + j + d] * w[j];
        a[i + j + d] = a[i + j] - y;
        a[i + j] = a[i + j] + y;
      }
  }
}
E A[N], B[N], C[N], D[N];
void mul(int *a, int *b, int *c, int la, int lb) {
  int L = FFTinit(la + lb);
  for (int i = (int)(0); i <= (int)(L - 1); i++) A[i] = B[i] = E(0, 0);
  for (int i = (int)(0); i <= (int)(la); i++) A[i] = E(a[i] & 1023, a[i] >> 10);
  for (int i = (int)(0); i <= (int)(lb); i++) B[i] = E(b[i] & 1023, b[i] >> 10);
  DFT(A, L);
  DFT(B, L);
  for (int i = (int)(0); i <= (int)(L - 1); i++) {
    int ano = (L - i) & (L - 1);
    E v1 = (A[i] + A[ano].conj()) * E(0.5, 0);
    E v2 = (A[i] - A[ano].conj()) * E(0, -0.5);
    E v3 = (B[i] + B[ano].conj()) * E(0.5, 0);
    E v4 = (B[i] - B[ano].conj()) * E(0, -0.5);
    C[i] = v1 * v3 + v2 * v4 * E(0, 1);
    D[i] = v1 * v4 + v2 * v3;
  }
  IDFT(C, L);
  IDFT(D, L);
  for (int i = (int)(0); i <= (int)(la + lb); i++) {
    int v1 = (long long)(C[i].r / L + 0.5) % mo;
    int v2 = (long long)(C[i].i / L + 0.5) % mo;
    int v3 = (long long)(D[i].r / L + 0.5) % mo;
    c[i] = ((1ll << 20) * v2 + (1ll << 10) * v3 + v1) % mo;
  }
}
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
int get_g(int x) {
  int di[105], X = x - 1;
  *di = 0;
  for (int i = 2; i * i <= X; i++)
    if (X % i == 0) {
      di[++*di] = i;
      for (; X % i == 0; X /= i)
        ;
    }
  if (X != 1) di[++*di] = X;
  for (int g = 2;; g++) {
    bool flag = 0;
    for (int i = (int)(1); i <= (int)(*di); i++)
      if (power(g, (mo - 1) / di[i]) == 1) flag = 1;
    if (!flag) return g;
  }
}
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int S(int x) { return 1ll * x * (x + 1) % (mo - 1); }
int WW[N], RWW[N];
char s1[N], s2[N];
int a[N], b[N], c[N];
int main() {
  FFTinit();
  scanf("%d%d", &n, &mo);
  scanf("%s%s", s1, s2);
  mo = max(n, mo) + 5;
  for (;; mo++) {
    if (!isprime(mo)) continue;
    int p = mo - 1;
    WW[0] = 1;
    WW[1] = get_g(mo);
    for (int i = (int)(2); i <= (int)(p); i++)
      WW[i] = 1ll * WW[i - 1] * WW[1] % mo;
    for (int i = (int)(0); i <= (int)(p); i++) RWW[i] = WW[p - i];
    for (int i = (int)(0); i <= (int)(p); i++)
      c[p - i] = (s1[i] - s2[i] + 10 * mo) % mo;
    for (int i = (int)(0); i <= (int)(p); i++)
      c[p - i] = 1ll * c[p - i] * RWW[S(i)] % mo;
    for (int i = (int)(0); i <= (int)(2 * p); i++) a[i] = WW[S(i)];
    mul(c, a, b, p, 2 * p);
    for (int i = (int)(0); i <= (int)(p - 1); i++) {
      int ans = 1ll * b[p + i] * RWW[S(i)] % mo;
      if (ans == 0 && WW[i] > 1 && WW[i] < p) {
        printf("%d %d\n", mo, WW[i]);
        exit(0);
      }
    }
  }
}
