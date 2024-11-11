#include <bits/stdc++.h>
using namespace std;
long n, x, maxv, f[long(2e6 + 100)];
int main() {
  scanf("%ld", &n);
  long res = 0;
  for (long i = 1; i <= n; ++i) scanf("%ld", &x), ++f[x], maxv = max(maxv, x);
  for (long i = 0; i <= long(2e6 + 100) - 2; ++i) {
    if (f[i] % 2) ++res;
    f[i + 1] += f[i] / 2;
    if (f[i + 1]) maxv = max(maxv, i + 1);
  }
  printf("%ld", max(res, 1L));
  return 0;
}
