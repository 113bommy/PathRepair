#include <bits/stdc++.h>
using namespace std;
long long a, b, mod = 1e9 + 7;
int main() {
  scanf("%lld%lld", &a, &b);
  printf("%lld\n", ((a * (a + 1) / 2 % mod * b % mod + a) % mod *
                    ((b * (b - 1) / 2) % mod)) %
                       mod);
}
