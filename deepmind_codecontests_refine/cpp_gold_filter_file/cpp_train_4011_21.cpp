#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main() {
  while (scanf("%I64d%I64d", &n, &m) != EOF) {
    long long k = n - m, tm = m;
    if (k % 2 || k < 0)
      puts("0");
    else {
      k /= 2;
      long long ans = 1;
      for (int i = 0; i < 41; i++) {
        if (k % 2 == m % 2) {
          if (k % 2) ans = 0;
        } else {
          if (k % 2 == 0) ans *= 2;
        }
        k /= 2, m /= 2;
      }
      if (n == tm) ans -= 2;
      printf("%I64d\n", ans);
    }
  }
}
