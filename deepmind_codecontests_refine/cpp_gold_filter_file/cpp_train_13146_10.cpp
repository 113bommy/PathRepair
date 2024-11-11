#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  scanf("%I64d", &n);
  long long mn = 1LL << 40, mx = 1;
  for (long long i = 1; i * i * i <= n; ++i)
    if (n % i == 0) {
      long long nn = n / i;
      for (long long j = 1; j * j <= nn; ++j)
        if (nn % j == 0) {
          long long k = nn / j;
          long long val1 = (i + 1) * (j + 2) * (k + 2);
          long long val2 = (i + 2) * (j + 1) * (k + 2);
          long long val3 = (i + 2) * (j + 2) * (k + 1);
          mn = min(mn, min(val1, min(val2, val3)));
          mx = max(mx, max(val1, max(val2, val3)));
        }
    }
  printf("%I64d %I64d", mn - n, mx - n);
}
