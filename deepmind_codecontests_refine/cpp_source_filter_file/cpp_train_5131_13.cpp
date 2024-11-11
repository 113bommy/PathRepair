#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
int T;
long long a, b, c, d;
long long A, B, C, t, m1, m2, mid;
long long f(long long x) { return A * x * x + B * x + C; }
int main() {
  read(T);
  while (T--) {
    read(a), read(b), read(c), read(d);
    if (c < d) {
      if (b * c < a)
        printf("-1\n");
      else
        printf("%lld\n", a);
    } else {
      t = c / d;
      A = c * b - a, B = t * (t + 1) / 2 * d * b - c * b * t - a;
      A = -A, B = -B;
      if (A > 0) {
        printf("-1\n");
        continue;
      }
      m1 = B + A * t;
      A = d * b, B = d * b - 2 * a, C = -2 * a;
      A = -A, B = -B, C = -C;
      m2 = max(f(0), f(t - 1));
      double tmp = -B / (2 * A);
      if (B >= 0 && -B >= t * (2 * A)) {
        mid = B / (2 * A);
        for (long long i = mid - 5; i <= mid + 5; i++)
          if (0 <= i && i < t) m2 = max(m2, f(i));
      }
      printf("%lld\n", max(m1, m2 / 2));
    }
  }
  return 0;
}
