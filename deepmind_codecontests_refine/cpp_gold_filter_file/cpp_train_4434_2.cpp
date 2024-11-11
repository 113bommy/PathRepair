#include <bits/stdc++.h>
const int kMaxN = 100000;
int x[kMaxN], y[kMaxN];
int n;
inline long long Sqr(long long x) { return x * x; }
long long Calc(int *x) {
  long long l = 0, lsum = 0, r = 0, rsum = 0;
  long long result = 0;
  std::sort(x, x + n);
  for (int i = 1; i < n; ++i) {
    r += Sqr(x[0] - x[i]);
    rsum += x[i] - x[0];
  }
  result += l + r;
  for (int i = 1; i < n; ++i) {
    l += 2 * lsum * (x[i] - x[i - 1]) + i * Sqr(x[i] - x[i - 1]);
    lsum += i * (x[i] - x[i - 1]);
    r += -2 * rsum * (x[i] - x[i - 1]) + (n - i) * Sqr(x[i] - x[i - 1]);
    rsum -= (n - i) * (x[i] - x[i - 1]);
    result += l + r;
  }
  return result;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
  }
  long long result = 0;
  result += Calc(x);
  result += Calc(y);
  printf("%I64d\n", result / 2);
  return 0;
}
