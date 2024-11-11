#include <bits/stdc++.h>
using namespace std;
long long max_distance(const long long& a, const long long& n,
                       const long long& p) {
  if (a * n < p) return max(a, p - a * n);
  long long layers = a * n / p - (a * n % p < a * (p / a - 1));
  return max_distance(min(p % a, a - p % a), layers, a);
}
int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    long long a, n, p, h;
    scanf("%I64d%I64d%I64d%I64d", &a, &n, &p, &h);
    a %= p;
    long long d = (a * n < p) ? a : max_distance(a, n, p);
    printf("%s\n", (d > h) ? "NO" : "YES");
  }
  return 0;
}
