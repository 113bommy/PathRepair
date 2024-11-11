#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, bc, c;
  scanf("%d", &n);
  long long sol_mx = 0, sol_mn = (long long)1e15;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      bc = n / i;
      for (int j = 1; j * j <= bc; ++j)
        if (bc % j == 0) {
          c = bc / j;
          long long p1 = (long long)(c + 1) * (i + 2) * (j + 2);
          long long p2 = (long long)(i + 1) * (c + 2) * (j + 2);
          long long p3 = (long long)(j + 1) * (c + 2) * (i + 2);
          sol_mx = max(max(sol_mx, p1), max(p2, p3));
          sol_mn = min(min(sol_mn, p1), min(p2, p3));
        }
    }
  }
  printf("%lld %lld\n", sol_mn - n, sol_mx - n);
  return 0;
}
