#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int q;
  while (~scanf("%lld%d", &n, &q)) {
    while (q--) {
      long long x;
      scanf("%lld", &x);
      x = 2 * n - x;
      while (x % 2 == 0) x >>= 1;
      long long i = (x + 1) / 2;
      printf("%lld\n", n - i + 1);
    }
  }
  return 0;
}
