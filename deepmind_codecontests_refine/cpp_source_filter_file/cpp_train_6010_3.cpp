#include <bits/stdc++.h>
using namespace std;
long long GCD(long long x, long long y) { return y ? GCD(y, x % y) : x; }
int main() {
  int n;
  long long p, q, b;
  scanf("%d", &n);
  while (n--) {
    scanf("%I64d %I64d %I64d", &p, &q, &b);
    int k = GCD(p, q);
    q /= k;
    k = GCD(q, b);
    while (q > 1 && k > 1) {
      k = GCD(q, k);
      q /= k;
    }
    if (q == 1)
      printf("Finite\n");
    else
      printf("Infinite\n");
  }
  return 0;
}
