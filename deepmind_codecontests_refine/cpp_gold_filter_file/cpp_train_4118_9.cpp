#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long a[100005];
long long getPow(long long x, long long y, long long z) {
  if (y == 0) return 1;
  long long ans = getPow(x, y / 2, z);
  ans = (ans * ans) % z;
  if (y % 2) ans = (ans * x) % z;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  long long pmod = 1, pmod1 = 1, p2 = 1;
  bool d = false;
  for (int i = 0; i < n; i++) {
    pmod = (pmod * (a[i] % mod)) % mod;
    pmod1 = (pmod1 * (a[i] % (mod - 1))) % (mod - 1);
    p2 *= a[i] % 2;
    p2 %= 2;
    if (a[i] > 1) d = true;
  }
  if (d == false) {
    cout << "0/1" << endl;
    return 0;
  }
  long long inv3 = getPow(6, mod - 2, mod);
  long long num = getPow(2, pmod1, mod);
  if (p2 % 2)
    num -= 2;
  else
    num += 2;
  num += mod;
  num %= mod;
  num = num * inv3;
  num = num % mod;
  long long den = getPow(2, pmod1, mod);
  den *= getPow(2, mod - 2, mod);
  den %= mod;
  cout << num << "/" << den << endl;
  return 0;
}
