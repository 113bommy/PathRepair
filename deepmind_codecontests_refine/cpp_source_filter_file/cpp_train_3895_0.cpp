#include <bits/stdc++.h>
using namespace std;
long long t, a, n, p, h;
long long get(long long a, long long n, long long p) {
  if (a * n > p)
    return get(p % a, (a * n + p % a) / p, a);
  else
    return max(a, p - a * (n - 1));
}
int main() {
  scanf("%I64d", &t);
  while (t--) {
    scanf("%I64d%I64d%I64d%I64d", &a, &n, &p, &h);
    a %= p;
    if (((a * n < p) ? a : get(a % p, n, p)) <= h)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
