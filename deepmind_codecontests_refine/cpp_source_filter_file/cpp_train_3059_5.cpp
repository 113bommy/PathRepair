#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int p;
int pow_mod(int base, int power) {
  if (power <= 0) return 1;
  if (power == 1) return base;
  if (power & 1) return (base * pow_mod(base, power - 1) % p) % p;
  return pow_mod((base * base) % p, power >> 1) % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> p;
  int res = 0;
  for (__typeof(p) i = (2) - ((2) > (p)); i != (p) - ((2) > (p));
       i += 1 - 2 * ((2) > (p))) {
    bool can = true;
    for (__typeof(p - 1) j = (1) - ((1) > (p - 1));
         j != (p - 1) - ((1) > (p - 1)); j += 1 - 2 * ((1) > (p - 1))) {
      if (pow_mod(i, j) == 1) {
        can = false;
        break;
      }
    }
    can &= pow_mod(i, p - 1) == 1;
    res += can;
  }
  cout << res;
  return 0;
}
