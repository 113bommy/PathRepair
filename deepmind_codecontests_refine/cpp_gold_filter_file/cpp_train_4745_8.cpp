#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long n, l, r;
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long res = ksm(a, b / 2);
  res *= res;
  if (b % 2 == 1) res *= a;
  return res;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &l, &r);
  if (n == 1) {
    printf("%I64d\n", r - l + 1);
    return 0;
  }
  if (n == 2) {
    printf("%I64d\n", (r - l) * (r - l + 1));
    return 0;
  }
  if (n >= 25) {
    printf("0\n");
    return 0;
  }
  long long ans = 0, i, j;
  long long pl2 = 1;
  while (ksm(pl2, n - 1) <= r) {
    pl2++;
  }
  pl2--;
  for (i = 1; i <= pl2; i++) {
    for (j = i + 1; j <= pl2; j++) {
      if (gcd(i, j) != 1) {
        continue;
      }
      long long tp1 = ksm(i, n - 1), tp2 = ksm(j, n - 1);
      long long minn = l / tp1;
      if (l % tp1 != 0) {
        minn++;
      }
      long long maxn = r / tp2;
      ans += max(0ll, (maxn - minn + 1));
    }
  }
  printf("%I64d\n", ans * 2);
  return 0;
}
