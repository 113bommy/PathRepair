#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e3 + 7;
const long long int mod = 1e9 + 7;
const long long int infi = 1e16;
long long int i, j, ans, k, n, y, m, mymax = LLONG_MIN, mymin = LLONG_MAX, b, c,
                                     z, sum;
long long int binpow(long long int base, long long int pow,
                     long long int modulus) {
  long long int ans = 1;
  base = base % modulus;
  while (pow > 0) {
    while (pow % 2 == 0) {
      base = (base * base) % modulus;
      pow /= 2;
    }
    ans = (ans * base) % modulus;
    pow--;
  }
  return ans;
}
long long int check(long long int x) {
  y = (m - k * x) / (k - 1);
  if ((m - k * x) % (k - 1) != 0) y++;
  y += m;
  if (y <= n + 1) {
    return 1;
  }
  return 0;
}
int main() {
  long long int x;
  scanf("%lld %lld %lld", &n, &m, &k);
  long long int l, r, mid;
  r = min(m / k, n / k);
  l = 1;
  mid = (l + r) / 2;
  x = m / (k - 1);
  if (m % (k - 1) != 0) x++;
  if (m + x <= n + 1) {
    printf("%lld\n", m);
    return 0;
  } else {
    while (l <= r) {
      if (check(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
      mid = (l + r) / 2;
    }
    ans = binpow(2, l + 1, mod);
    ans = (ans - 2 + mod) % mod;
    ans = (ans * k) % mod;
    ans = (ans + m - k * l) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
  }
  return 0;
}
