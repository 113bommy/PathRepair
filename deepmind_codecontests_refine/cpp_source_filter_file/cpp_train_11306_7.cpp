#include <bits/stdc++.h>
using namespace std;
struct cpl {
  double r, i;
  cpl() { r = i = 0; }
  cpl(double a, double b) { r = a, i = b; }
  cpl operator+(cpl a) { return cpl(r + a.r, i + a.i); }
  cpl operator-(cpl a) { return cpl(r - a.r, i - a.i); }
  cpl operator*(cpl a) { return cpl(r * a.r - i * a.i, r * a.i + i * a.r); }
} A[2000000], B[2000000], x[2000000];
int l, r[2000000];
double pi = acos(-1);
void FFT(cpl *a, int tp) {
  for (int i = 0; i < l; i++) x[r[i]] = a[i];
  for (int i = 0; i < l; i++) a[i] = x[i];
  for (int i = 1; i < l; i <<= 1) {
    cpl w = cpl(cos(pi / i), tp * sin(pi / i));
    for (int j = 0; j < l; j += (i << 1)) {
      cpl wn = cpl(1, 0);
      for (int k = 0; k < i; k++) {
        cpl t = wn * a[i + j + k];
        a[i + j + k] = a[j + k] - t;
        a[j + k] = a[j + k] + t;
        wn = wn * w;
      }
    }
  }
}
char inp[2000000];
int v[2000000], k[2000000];
int vcnt = 0, kcnt = 0;
bool hv[2000000];
int ans[2000000];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    int len;
    scanf("%d", &len);
    scanf("%s", inp);
    for (int i = 1; i <= len; i++) hv[i] = 0;
    int mx1 = 0, mx2 = 0;
    vcnt = kcnt = 0;
    for (int i = 0; i < len; i++)
      if (inp[i] == 'V')
        v[vcnt++] = i, mx1 = i;
      else if (inp[i] == 'K')
        k[kcnt++] = i, mx2 = i;
    l = 1;
    while (l <= mx1 + mx2 + 1) l <<= 1;
    r[0] = 0;
    for (int i = 1; i < l; i <<= 1)
      for (int j = 0; j < i; j++) r[i + j] = r[j] + l / i / 2;
    for (int i = 0; i < l; i++) A[i].r = A[i].i = 0, B[i].r = B[i].i = 0;
    for (int i = 0; i < vcnt; i++) A[v[i]].r = 1;
    for (int j = 0; j < kcnt; j++) B[mx2 - k[j]].r = 1;
    FFT(A, 1), FFT(B, 1);
    for (int i = 0; i < l; i++) A[i] = A[i] * B[i];
    FFT(A, -1);
    for (int i = 0; i < l; i++)
      if (A[i].r / l + 0.5 >= 1) hv[abs(i - mx2)] = 1;
    int cnt = 0;
    for (int i = 1; i <= len; i++) {
      bool flag = 1;
      for (int j = 1; j * i <= l; j++)
        if (hv[i * j]) flag = 0;
      if (flag) ans[cnt++] = i;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
