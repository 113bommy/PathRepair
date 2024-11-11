#include <bits/stdc++.h>
using namespace std;
long long n;
int m;
int main() {
  scanf("%lld%d", &n, &m);
  while (m--) {
    long long x;
    scanf("%d", &x);
    if (x & 1)
      printf("%lld\n", (x >> 1) + 1ll);
    else {
      long long y = n;
      while (!(x & 1)) x = y - (x >> 1), y = x;
      printf("%lld\n", n - x + (x + 1ll) / 2ll);
    }
  }
  return 0;
}
