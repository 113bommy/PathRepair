#include <bits/stdc++.h>
using namespace std;
long long Q, n, a, p, h;
long long solve(long long a, long long n, long long p) {
  if (a * n < p) return max(a, p - a * n);
  long long m = a * n / p - (a * n % p < a * (p / a - 1));
  return solve(min(p % a, a - p % a), m, a);
}
int main() {
  scanf("%lld", &Q);
  while (Q--) {
    scanf("%lld%lld%lld%lld", &a, &n, &p, &h);
    a %= p;
    if (a <= h || (a * n > p && solve(a, n, p) <= h))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
