#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int d = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; d = d * 10 + c - 48, c = getchar())
    ;
  return d * f;
}
const int N = 1 << 21;
const double pi = acos(-1);
int rev[N], sz, SZ, n, m, a[N];
bool ans[N];
class array {
 public:
  complex<double> a[N];
  void fft(int tp) {
    for (int i = 0; i <= SZ - 1; ++i)
      if (rev[i] < i) swap(a[rev[i]], a[i]);
    for (int i = 2; i <= SZ; i <<= 1) {
      int I = i >> 1;
      complex<double> w(cos(pi / I), tp * sin(pi / I));
      for (int j = 0; j < SZ; j += i) {
        complex<double> W(1, 0);
        for (int k = j; k < j + I; ++k, W = W * w) {
          complex<double> A = a[k], B = a[k + I];
          a[k] = A + B * W;
          a[k + I] = A - B * W;
        }
      }
    }
    if (tp == -1)
      for (int i = 0; i <= SZ - 1; ++i) a[i] /= SZ;
  }
} A;
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  while ((1 << sz) < m) ++sz;
  ++sz;
  SZ = 1 << sz;
  for (int i = 0; i <= SZ - 1; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
  for (int i = 1; i <= n; ++i) A.a[a[i]] = complex<double>(1, 0), ans[a[i]] = 1;
  A.fft(1);
  for (int i = 0; i <= SZ - 1; ++i) A.a[i] = A.a[i] * A.a[i];
  A.fft(-1);
  for (int i = 1; i <= m; ++i)
    if ((int)(A.a[i].real() + 0.5) == 1) {
      if (!ans[i]) {
        cout << "NO" << endl;
        return 0;
      }
      ans[i] = 0;
    }
  cout << "YES" << endl;
  int sum = 0;
  for (int i = 1; i <= m; ++i)
    if (ans[i]) sum++;
  printf("%d\n", sum);
  for (int i = 1; i <= m; ++i)
    if (ans[i]) printf("%d ", i);
  printf("\n");
}
