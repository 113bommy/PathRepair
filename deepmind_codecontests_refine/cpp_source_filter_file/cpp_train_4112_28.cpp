#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e) {
  long long p = 1;
  while (e > 0) {
    if (e & 1) {
      p = (p * b) % 1000000007;
    }
    e = e >> 1;
    b = (b * b) % 1000000007;
  }
  return p;
}
int main() {
  long long n, i, j, k, q, x, y, m, ans = 0;
  scanf("%lld", &n);
  for (i = j = 1; i * 10 < n; i *= 10, j++) ans += 9 * i * j;
  ans += (n - i + 1) * j;
  printf("%lld\n", ans);
  return 0;
}
