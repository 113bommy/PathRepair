#include <bits/stdc++.h>
using namespace std;
const int siz = 1e5 + 10;
const long long modu = 1e9 + 7;
long long power(long long x, long long y, long long modu) {
  if (!y) return 1LL;
  long long ans = 1LL;
  x = x % modu;
  while (y) {
    if (y & 1LL) ans = (ans * x) % modu;
    y >>= 1LL;
    x = (x * x) % modu;
  }
  return ans;
}
int main() {
  long long x, k;
  scanf("%lld%lld", &x, &k);
  if (x == 0) {
    printf("0\n");
    return 0;
  }
  long long k1 = k + 1ll;
  long long val1 = power(2ll, k1, modu);
  val1 = (val1 * (x % modu)) % modu;
  val1 = (val1 - power(2ll, k, modu) + modu) % modu;
  val1 = (val1 + 1ll + modu) % modu;
  cout << val1 << endl;
  return 0;
}
