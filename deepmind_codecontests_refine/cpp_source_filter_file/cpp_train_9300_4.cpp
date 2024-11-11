#include <bits/stdc++.h>
using namespace std;
long long mod_power(long long base, int exponent) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % 1000000007;
    exponent /= 2;
    base = (base * base) % 1000000007;
  }
  return result;
}
int main() {
  long long n;
  cin >> n;
  if (n == 0)
    cout << 1;
  else
    cout << (2 * mod_power(4, n - 1) % 1000000007 +
             mod_power(2, n - 1) % 1000000007) %
                1000000007;
  return 0;
}
