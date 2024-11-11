#include <bits/stdc++.h>
using namespace std;
const long long mod = 1ll * 1e9 + 9ll;
char str[100005];
long long P(long long a, long long b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1ll) {
      ret = ret * a % mod;
    }
    b /= 2ll;
    a = a * a % mod;
  }
  return ret;
}
int main() {
  long long n, a, b, k;
  scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
  scanf("%s", str);
  long long aa = a, bb = b, sum = 0;
  for (int i = 0; i < k; i++) {
    aa = P(a, n - i);
    bb = P(b, i);
    if (str[i] == '+') {
      sum = sum + aa * bb % mod;
      sum %= mod;
    } else {
      sum = sum - aa * bb % mod;
      sum %= mod;
      sum += mod;
      sum %= mod;
    }
  }
  long long tmp = P(P(a, k), mod - 2) * P(b, k) % mod;
  int cnt = (n + 1) / k;
  if (tmp == 1) {
    return !printf("%lld", tmp * cnt % mod);
  }
  long long r = tmp;
  r = P(tmp, cnt);
  r = r - 1;
  r %= mod;
  r += mod;
  r %= mod;
  r = r * P((tmp - 1 + mod) % mod, mod - 2) % mod;
  printf("%lld\n", sum * r % mod);
}
