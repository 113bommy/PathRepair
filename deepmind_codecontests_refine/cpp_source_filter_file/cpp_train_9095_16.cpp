#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int flag[2201000], ans[2201000];
int n, m, len;
const complex<double> I = complex<double>(0, 1);
complex<double> A[2201000], B[2201000], C[2201000];
void fft(complex<double> A[], complex<double> B[], int len, bool inv) {
  double arg = 3.14159265358979323846;
  for (int n = len / 2; n >= 1; n /= 2) {
    complex<double> pow = complex<double>(1, 0);
    complex<double> mul = exp((inv ? 1.0 : -1.0) * I * arg);
    for (int j = 0; j < len; j += n) {
      for (int i = 0; i < n; ++i)
        B[i + j] = A[i + j * 2 % len] + A[i + n + j * 2 % len] * pow;
      pow = pow * mul;
    }
    for (int i = 0; i < len; ++i) A[i] = B[i];
    arg /= 2.0;
  }
}
void mul(complex<double> a[], complex<double> b[], int len) {
  memset(ans, 0, sizeof(ans));
  fft(a, C, len, false);
  fft(b, C, len, false);
  for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
  fft(a, C, len, true);
  for (int i = 0; i < len; i++) ans[i] = (int)(a[i].real() / len + 0.5);
}
int cau() {
  int i, j, tem, cnt;
  cnt = 0;
  for (i = 1; i <= m; i++)
    if (ans[i]) {
      if (flag[i] == 0) return -1;
      cnt++;
      flag[i] = 0;
    }
  return n - cnt;
}
int main() {
  int i, j, tem;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(flag, 0, sizeof(flag));
    memset(A, 0, sizeof(A));
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++) {
      scanf("%d", &tem);
      A[tem] = 1.0;
      flag[tem] = 1;
    }
    len = 1;
    while (len <= 2 * m) len <<= 1;
    fft(A, C, len, false);
    for (i = 1; i < len; i++) A[i] = A[i] * A[i];
    fft(A, C, len, true);
    for (i = 1; i <= m; i++) ans[i] = (int)(A[i].real() / len + 0.5);
    int cnt = cau();
    if (cnt == -1)
      printf("NO\n");
    else {
      printf("YES\n%d\n", cnt);
      tem = 0;
      for (i = 1; i <= m; i++)
        if (flag[i]) printf("%d%c", i, ++tem == cnt ? '\n' : ' ');
    }
  }
  return 0;
}
