#include <bits/stdc++.h>
using namespace std;
const long long MODM = 1000000007;
long long cal(long long a, long long b) {
  if (b == 0) return (1 % MODM);
  long long tmp = cal(a, b / 2);
  if (b % 2 == 0) return (tmp * tmp) % MODM;
  return (tmp * (tmp * a) % MODM) % MODM;
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 1;
  for (int i = n; i <= 2 * n - 1; ++i) ans = (ans * i) % MODM;
  for (int i = 2; i <= n; ++i) ans = (ans * cal(i, MODM - 2)) % MODM;
  ans = (((2 * ans) % MODM) - n + MODM) % MODM;
  cout << ans;
  return 0;
}
