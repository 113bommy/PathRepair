#include <bits/stdc++.h>
using namespace std;
const int maxn = 1048576;
struct comp {
  double x, y;
  comp() {}
  comp(double a, double b) {
    x = a;
    y = b;
  }
  comp operator+(const comp &A) const { return comp(x + A.x, y + A.y); }
  comp operator-(const comp &A) const { return comp(x - A.x, y - A.y); }
  comp operator*(const comp &A) const {
    return comp(x * A.x - y * A.y, x * A.y + y * A.x);
  }
} a[maxn], b[maxn];
const double pi = acos(-1.0);
void fft(comp *a, int N, int sign) {
  for (int i = 1, j = 0, k = N; i < N; ++i, k = N) {
    do j ^= (k >>= 1);
    while (j < k);
    if (j < i) swap(a[i], a[j]);
  }
  for (int j = 2; j <= N; j <<= 1) {
    int m = j >> 1;
    comp wn(cos(2.0 * pi / j), sign * sin(2.0 * pi / j));
    for (comp *p = a; p != a + N; p = p + j) {
      comp w(1, 0);
      for (int k = 0; k < m; ++k, w = w * wn) {
        comp t = w * p[m + k];
        p[m + k] = p[k] - t;
        p[k] = p[k] + t;
      }
    }
  }
  if (sign == -1) {
    for (int i = 0; i < N; ++i) a[i].x /= N;
  }
}
int n;
char str[maxn];
int seq[maxn], revseq[maxn];
double sum[maxn];
bool check(int x) {
  for (int i = x; i < n; i += x) {
    if (fabs(sum[n - i - 1]) > 1e-6) return false;
  }
  return true;
}
void work() {
  scanf("%d%s", &n, str);
  for (int i = 0; i < n; ++i) {
    seq[i] = (str[i] == '?') ? 0 : (str[i] == 'V' ? 1 : 2);
  }
  for (int i = 0; i < n; ++i) {
    revseq[i] = seq[n - i - 1];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = comp(seq[i] * seq[i] * seq[i], 0);
    b[i] = comp(revseq[i], 0);
  }
  int N = 1;
  while (N <= n) N <<= 1;
  N <<= 1;
  for (int i = 0; i < N; ++i) sum[i] = 0;
  for (int i = n; i < N; ++i) a[i] = comp(0, 0);
  for (int i = n; i < N; ++i) b[i] = comp(0, 0);
  fft(a, N, 1);
  fft(b, N, 1);
  for (int i = 0; i < N; ++i) a[i] = a[i] * b[i];
  fft(a, N, -1);
  for (int i = 0; i < N; ++i) sum[i] += a[i].x;
  for (int i = 0; i < n; ++i) {
    a[i] = comp(seq[i], 0);
    b[i] = comp(revseq[i] * revseq[i] * revseq[i], 0);
  }
  for (int i = n; i < N; ++i) a[i] = comp(0, 0);
  for (int i = n; i < N; ++i) b[i] = comp(0, 0);
  fft(a, N, 1);
  fft(b, N, 1);
  for (int i = 0; i < N; ++i) a[i] = a[i] * b[i];
  fft(a, N, -1);
  for (int i = 0; i < N; ++i) sum[i] += a[i].x;
  for (int i = 0; i < n; ++i) {
    a[i] = comp(seq[i] * seq[i], 0);
    b[i] = comp(revseq[i] * revseq[i], 0);
  }
  for (int i = n; i < N; ++i) a[i] = comp(0, 0);
  for (int i = n; i < N; ++i) b[i] = comp(0, 0);
  fft(a, N, 1);
  fft(b, N, 1);
  for (int i = 0; i < N; ++i) a[i] = a[i] * b[i];
  fft(a, N, -1);
  for (int i = 0; i < N; ++i) sum[i] -= 2.0 * a[i].x;
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (check(i)) cnt++;
  }
  printf("%d\n", cnt);
  for (int i = 1; i < n; ++i) {
    if (check(i)) printf("%d ", i);
  }
  printf("%d\n", n);
}
int main() {
  a[0].x = 1;
  a[1].x = 1;
  int tests;
  scanf("%d", &tests);
  while (tests--) {
    work();
  }
  return 0;
}
