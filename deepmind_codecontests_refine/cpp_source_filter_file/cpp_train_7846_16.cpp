#include <bits/stdc++.h>
using std::max;
int main() {
  long long n;
  while (~scanf("%I64d", &n)) {
    if (n % 3 != 0) {
      printf("0\n");
      continue;
    }
    n /= 3;
    long long ret = 0;
    for (long long i = 2; i * i * i <= n; i++) {
      if (n % i != 0) continue;
      long long nn = n / i;
      long long q = (-i + sqrt(double(i * i + 4 * nn))) / 2;
      for (long long j = max(i, q); j * j <= nn; j++) {
        if (nn % j != 0) continue;
        long long z = nn / j;
        if (i + j < z + 2) continue;
        if ((i + j - z) % 2 || (i + z - j) % 2 || (z + j - i) % 2) continue;
        long long a = (i + j - z) / 2, b = (j + z - i) / 2, c = (i + z - j) / 2;
        if (a == b) {
          if (b == c)
            ret++;
          else
            ret += 3;
        } else {
          if (b == c)
            ret += 3;
          else
            ret += 6;
        }
      }
    }
    printf("%I64d\n", ret);
  }
  return 0;
}
