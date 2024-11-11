#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
const int N = 1 << LOG;
struct FFTALGO {
 private:
 public:
  complex<double> w[N], F[2][N];
  int rev[N];
  FFTALGO() {
    const double pi = acos(-1);
    for (int i = 0; i < N; ++i) {
      w[i] = complex<double>(cos(2 * pi * i / N), sin(2 * pi * i / N));
    }
    rev[0] = 0;
    for (int mask = 1, p = 0; mask < N; ++mask) {
      if (mask == (1 << (p + 1))) ++p;
      rev[mask] = rev[mask ^ (1 << p)] ^ (1 << (LOG - p - 1));
    }
  }
  void fft(complex<double> A[], int k) {
    int n = (1 << k);
    for (int i = 0; i < n; ++i) {
      F[0][i] = A[rev[i] >> (LOG - k)];
    }
    int t = 0, nt = 1;
    for (int lvl = 0; lvl < k; ++lvl) {
      int len = 1 << lvl;
      for (int st = 0; st < n; st += len << 1) {
        for (int i = 0; i < len; ++i) {
          complex<double> add = F[t][st + i + len] * w[i << (LOG - lvl - 1)];
          F[nt][st + i] = F[t][st + i] + add;
          F[nt][st + i + len] = F[t][st + i] - add;
        }
      }
      swap(t, nt);
    }
    for (int i = 0; i < n; ++i) {
      A[i] = F[t][i];
    }
  }
  void inverseFFT(complex<double> A[], int k) {
    int n = (1 << k);
    fft(A, k);
    reverse(A + 1, A + n);
    for (int i = 0; i < n; ++i) {
      A[i] /= n;
    }
  }
} FFT;
char buf[N];
complex<double> a[N];
complex<double> b[N];
bool ans[N];
void solve() {
  int n;
  scanf("%d\n%s\n", &n, buf);
  int k = 0;
  while ((1 << k) < n) ++k;
  ++k;
  for (int i = 0; i < (1 << k); ++i) {
    a[i] = b[i] = 0;
    ans[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (buf[i] == 'V') a[i] = 1;
    if (buf[i] == 'K') b[n - i - 1] = 1;
  }
  FFT.fft(a, k);
  FFT.fft(b, k);
  for (int i = 0; i < (1 << k); ++i) {
    a[i] *= b[i];
  }
  FFT.inverseFFT(a, k);
  for (int p = 1; p <= n; ++p) {
    int c = round(a[n - 1 - p].real()) + round(a[n - 1 + p].real());
    if (c > 0) ans[p] = 0;
  }
  int res = 0;
  for (int x = 1; x <= n; ++x) {
    for (int y = x + x; y <= n; y += x) {
      ans[x] &= ans[y];
    }
    res += ans[x];
  }
  printf("%d\n", res);
  for (int i = 1; i <= n; ++i) {
    if (ans[i]) printf("%d ", i);
  }
  puts("");
}
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
