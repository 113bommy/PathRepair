#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
long long n, b, q, a;
int main() {
  scanf("%I64d", &n);
  n >>= 2;
  for (q = 1, b = 1; n; n--) {
    a = (a + 2 * b * q + 2 * b) % mod;
    b = (b * q) % mod;
    q = (2 * q + 3) % mod;
  }
  a = (a + 2 * b) % mod;
  a = ((a * a + 1) * 2) % mod;
  printf("%I64d\n", a);
  return 0;
}
