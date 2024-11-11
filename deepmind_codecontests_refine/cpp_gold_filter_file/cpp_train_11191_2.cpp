#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int a, b;
int main() {
  cin >> a >> b;
  if (a < b) {
    cout << "-1" << endl;
    return 0;
  }
  int k1 = (a - b) / (2 * b), k2 = (a + b) / (2 * b);
  double d1 = (a == b)    ? a
              : (k1 == 0) ? 9987654321
                          : (a - b) / double(2 * k1),
         d2 = (a + b) / double(2 * k2);
  double d3 = min(d1, d2);
  printf("%.12lf\n", d3);
  return 0;
}
