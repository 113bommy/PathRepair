#include <bits/stdc++.h>
using namespace std;
inline bool equal(double _x, double _y) {
  return _x > _y - 1e-9 && _x < _y + 1e-9;
}
long long st[2000005];
long long fast(long long a, long long b) {
  long long res = 1, now = a;
  while (b) {
    if (b & 1) res = (res * now) % 1000000007;
    now = (now * now) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long CC(int n, int m) {
  if (m > n) return 0;
  return (st[n] * fast((st[m] * st[n - m]) % 1000000007, 1000000007 - 2)) %
         1000000007;
}
long long lucas(int n, int m) {
  if (m == 0) return 1;
  return (CC(n % 1000000007, m % 1000000007) *
          lucas(n / 1000000007, m / 1000000007)) %
         1000000007;
}
void build(int n) {
  st[0] = 1;
  for (int i = 1; i <= n; i++) {
    st[i] = (st[i - 1] * i) % 1000000007;
  }
}
int main() {
  long long sum = 1, ans = 1;
  int n;
  scanf("%d", &n);
  build(2 * n);
  for (int i = 1; i <= 2 * n; i++) {
    sum = (sum * 2) % 1000000007;
    if (sum > n) {
      sum -= (2 * lucas(i - 1, i - n - 1)) % 1000000007;
      sum = (sum + 2 * 1000000007) % 1000000007;
    }
    ans = (ans + sum) % 1000000007;
  }
  printf("%lld\n", ans);
}
