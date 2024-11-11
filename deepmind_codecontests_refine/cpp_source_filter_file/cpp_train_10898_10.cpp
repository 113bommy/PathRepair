#include <bits/stdc++.h>
using namespace std;
const int N = 2197165;
const int C = 1000;
const double PI = acos(-1);
struct cplx {
  double r, i;
  inline cplx() {}
  inline cplx(const double _r, const double _i) {
    r = _r;
    i = _i;
  }
  inline cplx operator+(const cplx &w) const { return cplx(r + w.r, i + w.i); }
  inline cplx operator-(const cplx &w) const { return cplx(r - w.r, i - w.i); }
  inline cplx operator*(const cplx &w) const {
    return cplx(r * w.r - i * w.i, r * w.i + i * w.r);
  }
  inline cplx operator+=(const cplx &w) { return *this = *this + w; }
  inline cplx operator-=(const cplx &w) { return *this = *this - w; }
  inline cplx operator*=(const cplx &w) { return *this = *this * w; }
} A[N], t[N];
int n, m, L = 1, _rev[N], lb[N];
inline void fft(cplx a[], int type, int len) {
  for (int i = 0; i < len; i++) t[i] = a[(_rev[i] >> (lb[L] - lb[len]))];
  for (int i = 0; i < len; i++) a[i] = t[i];
  for (int i = 1; i < len; i <<= 1) {
    cplx w = cplx(cos(PI / i), type * sin(PI / i));
    for (int j = 0; j < len; j += (i << 1)) {
      cplx wn = cplx(1.0, 0.0);
      for (int k = j; k < j + i; k++) {
        cplx tmp = a[k + i] * wn;
        a[k + i] = a[k] - tmp;
        a[k] = a[k] + tmp;
        wn *= w;
      }
    }
  }
  if (type == -1)
    for (int i = 0; i < len; i++) a[i].r /= len, a[i].r += 0.5;
}
inline void init_fft() {
  while (L <= 1048576) L <<= 1;
  for (int i = 1; i < L; i <<= 1)
    for (int j = 0; j < i; j++) _rev[j + i] = _rev[j] + (L >> 1) / i;
  for (int i = 2; i <= L; i <<= 1) lb[i] = lb[i >> 1] + 1;
}
struct bign {
  long long a[N];
  int len;
  inline void update(int l) {
    long long w = 0;
    for (int i = 0; i <= l; i++) {
      a[i] += w;
      w = a[i] / C;
      a[i] %= C;
    }
    while (a[l] == 0) l--;
    len = l + 1;
  }
  inline void pow() {
    int l = 1;
    while (l <= len + len) l <<= 1;
    for (int i = 0; i < l; i++) A[i] = cplx(a[i], 0.0);
    fft(A, 1, l);
    for (int i = 0; i < l; i++) A[i] = A[i] * A[i];
    fft(A, -1, l);
    for (int i = 0; i < l; i++) a[i] = (int)(A[i].r);
    update(l << 1);
  }
  inline void multi(long long x) {
    for (int i = 0; i < len; i++) a[i] *= x;
    update(len + 3);
  }
  inline void div(long long x) {
    long long w = 0;
    for (int i = len - 1; i >= 0; i--) {
      a[i] += w;
      w = (a[i] % x) * C;
      a[i] /= x;
    }
    update(len + 3);
  }
  inline bool operator>(const bign &w) const {
    int l = ((w.len > len) ? w.len : len);
    for (int i = l; i >= 0; i--) {
      if (a[i] > w.a[i]) return true;
      if (a[i] < w.a[i]) return false;
    }
    return false;
  }
  inline void display() {
    for (int i = len; i >= 0; i--) {
      printf("%lld ", a[i]);
    }
    printf("\n");
  }
} D, E, F, G;
char str[N];
int exp3;
inline void msm(int x) {
  if (x == 0) {
    G.a[0] = 1;
    return;
  }
  if (x == 1) return;
  msm(x >> 1);
  G.pow();
  if (x & 1) G.multi(3);
}
inline int solve(bign &a) {
  while (a > G) {
    G.multi(3);
    exp3++;
  }
  return 3 * exp3;
}
void init() {
  int n1, n2, n3;
  scanf("%s", str);
  n = strlen(str);
  str[n] = str[n + 1] = str[n + 2] = str[n + 3] = '0';
  if (n == 1 && str[0] <= '3') {
    printf("%d\n", str[0] - '0');
    return;
  }
  init_fft();
  for (int i = n - 1; i >= 0; i -= 3) {
    int w = 0, base = 1;
    for (int j = 0; j > -3; j--) {
      if (i + j < 0) break;
      w += (str[i + j] - '0') * base;
      base *= 10;
    }
    F.a[m] = E.a[m] = D.a[m] = w;
    m++;
  }
  F.len = E.len = D.len = m;
  E.a[0] += 1;
  E.update(n + 1);
  E.div(2);
  F.a[0] += 3;
  F.update(n + 1);
  F.div(4);
  n1 = n2 = n3 = n - 1;
  if (str[0] <= '1') {
    n2--;
    n3--;
  } else if (str[0] <= '3') {
    n3--;
  }
  exp3 = (double)n3 / log10(3);
  G.a[0] = 3;
  G.len = 1;
  msm(exp3);
  int res1, res2, res3;
  res3 = solve(F);
  res2 = solve(E);
  res1 = solve(D);
  printf("%d\n", min(min(res3 + 4, res2 + 2), res1));
}
int main(int argc, char **argv) {
  init();
  return 0;
}
