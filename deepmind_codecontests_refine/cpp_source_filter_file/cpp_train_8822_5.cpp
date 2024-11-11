#include <bits/stdc++.h>
using namespace std;
const long long int md = 1e9 + 7;
const long long int M1 = 998244353;
long long int mod(long long int n) { return ((n % md) + md) % md; }
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = mod(x);
  while (y > 0) {
    if (y & 1) res = mod(res * x);
    x = mod(x * x);
    y = y >> 1;
  }
  return mod(res);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int s, k;
  cin >> s >> k;
  if (s == 0) {
    cout << 0 << '\n';
    return 0;
  } else if (k == 0) {
    cout << 2 * s << '\n';
    return 0;
  }
  long long int res = mod(2 * s - 1);
  cout << mod(res * power(2, k) + 1) << '\n';
}
