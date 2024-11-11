#include <bits/stdc++.h>
using namespace std;
const int B = 21, N = 1 << B;
const double PI = acos(-1);
void fft(complex<double> a[], int p = 1) {
  for (int i = 0; i < N; i++) {
    int r = 0;
    for (int j = 0; j < B; j++)
      if (i >> j & 1) r |= 1 << (B - 1 - j);
    if (r < i) swap(a[i], a[r]);
  }
  for (int l = 2; l <= N; l *= 2) {
    complex<double> wn = polar(1.0, 2 * PI / l * p);
    for (int i = 0; i < N; i += l) {
      complex<double> w(1.0, 0.0);
      for (int j = 0; j < l / 2; j++) {
        complex<double> A = a[i + j], B = w * a[i + j + l / 2];
        a[i + j] = A + B;
        a[i + j + l / 2] = A - B;
        w *= wn;
      }
    }
  }
  if (p == -1)
    for (int i = 0; i < N; i++) a[i] /= N;
}
complex<double> a[N];
bool have[N];
int ans[N], ansN;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    have[x] = true;
    a[x] = complex<double>(1, 0);
  }
  fft(a, 1);
  for (int i = 0; i < N; i++) a[i] *= a[i];
  fft(a, -1);
  for (int i = 0; i < m; i++)
    if (have[i] && a[i].real() < 0.1)
      ans[ansN++] = i;
    else if (!have[i] && a[i].real() > 0.5)
      printf("NO\n"), exit(0);
  printf("YES\n%d\n", ansN);
  for (int i = 0; i < ansN; i++) printf("%d ", ans[i]);
}
