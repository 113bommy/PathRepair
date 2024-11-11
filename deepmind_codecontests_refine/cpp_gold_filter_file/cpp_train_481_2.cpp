#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long data = 0, w = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + ch - '0', ch = getchar();
  return data * w;
}
const long long mod = 1e9 + 7;
struct Mat {
  long long a[4][4];
  long long *operator[](long long x) { return a[x]; }
  void init(long long x) {
    memset(a, 0, sizeof(a));
    for (long long i = 1; i <= 3; i++) a[i][i] = x;
  }
  friend Mat operator*(Mat A, Mat B) {
    Mat C;
    C.init(0);
    for (long long i = 1; i <= 3; i++)
      for (long long j = 1; j <= 3; j++)
        for (long long k = 1; k <= 3; k++)
          C.a[i][k] += 1ll * A.a[i][j] * B.a[j][k];
    for (long long i = 1; i <= 3; i++)
      for (long long j = 1; j <= 3; j++) C.a[i][j] %= mod;
    return C;
  }
} B;
Mat Pow(Mat A, long long n) {
  Mat P;
  P.init(1);
  for (long long i = n; i; i >>= 1, A = A * A)
    if (i & 1) P = P * A;
  return P;
}
long long n, m, os[1000005];
struct point {
  long long y, x, op;
} p[1000005];
Mat T;
void Make() {
  T.init(0);
  for (long long i = 1; i <= 3; i++)
    for (long long j = 1; j <= 3; j++)
      if (abs(i - j) <= 1 && !os[j]) T.a[i][j] = 1;
}
int main() {
  Make();
  n = read(), m = read();
  long long N = 0;
  for (long long i = 1; i <= n; i++) {
    long long y = read(), l = read(), r = read();
    p[++N] = (point){y, l, 1};
    p[++N] = (point){y, r + 1, -1};
  }
  B.a[1][2] = 1;
  p[++N] = (point){0, m + 1, 0};
  sort(p + 1, p + N + 1, [](point A, point B) { return A.x < B.x; });
  p[0].x = 2;
  for (long long i = 1; i <= N; i++) {
    B = B * Pow(T, p[i].x - p[i - 1].x);
    os[p[i].y] += p[i].op;
    Make();
  }
  cout << B.a[1][2] << '\n';
  return 0;
}
