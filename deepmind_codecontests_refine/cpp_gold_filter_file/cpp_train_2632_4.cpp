#include <bits/stdc++.h>
using namespace std;
long long n, ans0, ans1;
void pd(long long m) {
  ans0 = min(ans0, m - n);
  ans1 = max(ans1, m - n);
}
void pd(long long x, long long y, long long z) {
  pd((x + 1) * (y + 2) * (z + 2));
}
int main() {
  long long m;
  int i, j, k, x, y, z, nn;
  ans0 = 1LL << 60, ans1 = 0;
  scanf("%I64d", &n);
  pd(n, 1, 1);
  pd(1, n, 1);
  for (i = 2; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      x = i;
      nn = n / i;
      pd(x, 1, nn);
      pd(nn, x, 1);
      pd(1, x, nn);
      for (j = 2; 1LL * j * j <= nn; j++) {
        if (nn % j == 0) {
          y = j;
          z = nn / j;
          pd(x, y, z);
          pd(y, x, z);
          pd(z, x, y);
        }
      }
      x = nn;
      for (j = 2; 1LL * j * j <= i; j++) {
        if (i % j == 0) {
          y = j;
          z = i / j;
          pd(x, y, z);
          pd(y, x, z);
          pd(z, x, y);
        }
      }
    }
  }
  printf("%I64d %I64d\n", ans0, ans1);
  return 0;
}
