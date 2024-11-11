#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
long long ok(long long x) {
  for (long long i = 1; i * (i - 1) <= x; i++)
    if (x == i * (i - 1)) return i;
  return 0;
}
int main() {
  int T;
  while (scanf("%lld%lld%lld%lld", &a, &b, &c, &d) != EOF) {
    long long sum = a + b + c + d;
    long long len = ok(sum * 2);
    long long x1 = ok(a * 2), x2 = ok(d * 2);
    if (!sum) {
      printf("0\n");
      continue;
    }
    if (len && (sum == a || sum == d)) {
      for (int i = 0; i < len; i++) printf("%d", sum == a ? 0 : 1);
      printf("\n");
      continue;
    }
    if (!len || !x1 || !x2 || x1 + x2 != len) {
      printf("Impossible\n");
      continue;
    }
    long long bb = x1 * x2, cc = 0;
    if (bb + cc != b + c) {
      printf("Impossible\n");
      continue;
    }
    long long A = x1;
    for (long long i = 0; i < len; i++) {
      if (c - cc >= A) {
        cc += A;
        printf("1");
      } else {
        A--;
        printf("0");
      }
    }
    printf("\n");
  }
  return 0;
}
