#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void mian() {
  long long x;
  scanf("%lld", &x);
  printf("%lld\n", (((x / 4 + 1) % mod * ((x / 2 + 1) % mod) -
                     (x / 4) % mod * ((x / 4 + 1) % mod)) %
                        mod +
                    mod) %
                       mod);
}
int main() {
  int testnum;
  cin >> testnum;
  while (testnum--) mian();
  return 0;
}
