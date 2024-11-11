#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (!y) ? x : gcd(y, x % y); }
int main() {
  long long a, b, n, k, mi = 1e18, mx = 0, w;
  scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
  for (int i = 1; i <= n; i++) {
    w = (n * k) / gcd((i * k - a + b), (n * k));
    mi = min(w, mi), mx = max(w, mx);
    w = (n * k) / gcd((i * k - (k - a) + b), (n * k));
    mi = min(w, mi), mx = max(w, mx);
    w = (n * k) / gcd((i * k - a + (k - b)), (n * k));
    mi = min(w, mi), mx = max(w, mx);
    w = (n * k) / gcd((i * k - (k - a) + (k - b)), (n * k));
    mi = min(w, mi), mx = max(w, mx);
  }
  printf("%lld %lld\n", mi, mx);
  return 0;
}
