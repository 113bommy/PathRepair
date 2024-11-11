#include <bits/stdc++.h>
using namespace std;
int m;
long long n;
long long a, b, c, x[2];
long long f[10000];
int Solve(long long a, long long b, long long c, long long x[]) {
  long long D = b * b - 4 * a * c, d;
  if (D < 0) return 0;
  if (D == 0) {
    x[0] = -b / 2 / a;
    if (x[0] <= 0 || x[0] * -2 * a != b) return 0;
    return 1;
  } else {
    d = (long long)sqrt(D * 1.);
    while (d * d < D) ++d;
    while (d * d > D) --d;
    if (d * d == D) {
      int m = 0;
      for (int j = -1; j <= 1; j += 2) {
        x[m] = (-b + j * d) / 2 / a;
        if (x[m] > 0 && x[m] * 2 * a == -b + j * d) ++m;
      }
      return m;
    }
    return 0;
  }
}
int ret = 0;
int main() {
  scanf("%I64d", &n);
  if (n % 3 != 0)
    ret = 0;
  else {
    n /= 3;
    for (long long i = 1; i <= 40000; i++)
      if (n % i == 0) f[m++] = i;
    for (long long i = 1; i <= 17000; i++) {
      for (int jj = (0); jj <= (m); jj++) {
        long long j = f[jj] - i;
        if (j < i) continue;
        a = i + j;
        b = 2 * i * j + i * i + j * j;
        c = i * i * j + i * j * j - n;
        if (c > 0) break;
        int t = Solve(a, b, c, x);
        if (t && x[0] >= j) {
          if (i == j && j == x[0])
            ++ret;
          else if (i != j && j != x[0])
            ret += 6;
          else
            ret += 3;
        }
        if (t == 2 && x[1] >= j) {
          if (i == j && j == x[1])
            ++ret;
          else if (i != j && j != x[1])
            ret += 6;
          else
            ret += 3;
        }
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}
