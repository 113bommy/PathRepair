#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long mmul(long long a, long long b) { return a * b % mod; }
long long mpow(long long a, int b) {
  if (!b) return 1;
  if (b & 1) return mmul(a, mpow(a, b - 1));
  return mpow(mmul(a, a), b / 2);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = mpow(2, n);
  ans = mmul(ans, mpow(m + 1, n - 1));
  ans = mmul(ans, m - n + 1);
  printf("%lld\n", ans);
}
