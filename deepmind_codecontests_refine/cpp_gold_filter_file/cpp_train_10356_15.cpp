#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  while (~scanf("%I64d%I64d", &n, &m)) {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      long long mm = min(i * i, m);
      long long add;
      if (mm == i * i)
        add = 2 * mm - 1;
      else
        add = 2 * mm;
      ans += add;
    }
    for (long long x = 2 * n - 1; x > 0; x--) {
      long long r = (x * x + m) / (2 * x);
      long long l = (x * x + 1) / (2 * x);
      if ((x * x + 1) % (2 * x) != 0) l++;
      l = max(l, 1LL);
      r = min(r, n);
      long long temp = r - l + 1;
      if (temp > 1) ans -= temp - 1;
    }
    printf("%I64d\n", ans);
  }
}
